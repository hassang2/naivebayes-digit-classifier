#include "digit_classifier.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>
#include <climits>


digit_classifier::digit_classifier() {
    for (int i = 0; i < 10; i++) {
        digit_maps_[i] = DigitMap(i);
    }

}

void digit_classifier::Train() {

    std::ifstream inFileTrainingData;
    std::ifstream inFileLabels;

    inFileTrainingData.open("digitdata/trainingimages");
    inFileLabels.open("digitdata/traininglabels");

    char image[28][29];
    int label;

    while (inFileTrainingData && inFileLabels) {
        inFileTrainingData >> image;
        inFileLabels >> label;

        digit_maps_[label].Process(image);
        total_num_of_data += 1;
    }
}

int digit_classifier::Evaluate(char input[28][29]) {
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

void digit_classifier::Test(std::string test) {
    std::ifstream inFileTestData;
    std::ifstream inFileLabels;

    if (test == "test") {
        inFileTestData.open("digitdata/testimages");
        inFileLabels.open("digitdata/testlabels");
    } else {
        inFileTestData.open("digitdata/trainingimages");
        inFileLabels.open("digitdata/traininglabels");
    }

    char image[28][29];
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

double digit_classifier::GetAccuracy() {
    return accuracy_;
}


void digit_classifier::SaveToFile(std::string name) {

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

void digit_classifier::LoadFromFile(std::string name) {
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
                    digit_maps_[digit].SetFeature_mapValue(r, c, type, value);
                }
            }
        }

    }

    inFile.close();
}

int digit_classifier::GetTotalNumOfData() {
    return total_num_of_data;
}

