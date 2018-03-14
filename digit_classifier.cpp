#include "digit_classifier.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <climits>
#include <vector>

DigitClassifier::DigitClassifier() {
    for (int i = 0; i < 10; i++) {
        digit_maps_[i] = DigitFeature(i, kHeight, kWidth);
    }
}

void DigitClassifier::Train(std::string images_dir, std::string labels_dir) {

    std::ifstream inFileTrainingData;
    std::ifstream inFileLabels;

    inFileTrainingData.open(images_dir);
    inFileLabels.open(labels_dir);

    std::vector<std::vector<char> > image;
    int label;

    while (inFileTrainingData && inFileLabels) {
        inFileTrainingData >> image;
        inFileLabels >> label;

        digit_maps_[label].Process(image);
    }
}

int DigitClassifier::Evaluate(std::vector<std::vector<char> > input) {
    std::pair<int, double> most_probable(-1, INT_MIN);
    for (auto DigitMap : digit_maps_) {
        double probability = DigitMap.second.Evaluate(input);

        if (probability > most_probable.second) {
            most_probable.first = DigitMap.first;
            most_probable.second = probability;
        }
    }

    return most_probable.first;
}

void DigitClassifier::Test(std::string images_dir, std::string labels_dir) {
    std::ifstream inFileTestData;
    std::ifstream inFileLabels;

    inFileTestData.open(images_dir);
    inFileLabels.open(labels_dir);


    std::vector<std::vector<char> > image;
    int label;

    int result;
    int correct = 0;
    int total = 0;

    while (inFileLabels && inFileTestData) {
        inFileTestData >> image;
        inFileLabels >> label;

        result = Evaluate(image);
        if (result == label) correct += 1;
        else {
            digit_maps_[label].Process(image);
        }
        total += 1;
    }

    accuracy_ = (double) correct / total;
}

double DigitClassifier::GetAccuracy() {
    return accuracy_;
}


void DigitClassifier::SaveToFile(std::string name) {

    std::ofstream ofs(name, std::ios::out);

    for (auto map : digit_maps_) {
        ofs << map.first << std::endl;;
        ofs << map.second.GetFrequency() << std::endl;;

        for (int r = 0; r < 28; r++) {
            for (int c = 0; c < 28; c++) {
                ofs << map.second.GetFeature_map()[r][c][0] << ' ';
                ofs << map.second.GetFeature_map()[r][c][1] << ' ';
                ofs << map.second.GetFeature_map()[r][c][2] << ' ';
            }
            ofs << std::endl;
        }
    }
    ofs.close();
}

void DigitClassifier::LoadFromFile(std::string name) {
    std::ifstream inFile;
    inFile.open(name);

    int digit;
    int frequency;
    int value;

    while (inFile) {
        inFile >> digit;
        std::cout << digit << std::endl;
        inFile >> frequency;
        digit_maps_[digit].SetFrequency(frequency);

        for (int r = 0; r < 28; r++) {
            for (int c = 0; c < 28; c++) {
                for (int type = 0; type < 3; type++) {
                    inFile >> value;
                    digit_maps_[digit].SetFeature_matrixValue(r, c, type, value);
                }
            }
        }

    }

    inFile.close();
}

std::map<int, DigitFeature> DigitClassifier::GetDigit_map() {
    return digit_maps_;
}



