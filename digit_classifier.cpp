//
// Created by P_Cat on 3/8/2018.
//
#include "digit_classifier.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <fstream>


digit_classifier::digit_classifier() {
    for (int i = 0; i < 10; i++) {
        digit_maps_[i] = digit_map();
    }

}

void digit_classifier::Train() {

    std::ifstream inFileTrainingData;
    std::ifstream inFileLabels;

    inFileTrainingData.open("digitdata/trainingimages");
    inFileLabels.open("digitdata/traininglabels");

    char image[28][29];
    int label;

    int lnumber = 1;
    while (inFileTrainingData && inFileLabels) {
        inFileTrainingData >> image;
        inFileLabels >> label;
        if (22 == digit_maps_[label].Process(image)) std::cout << lnumber;
        lnumber += 28;
    }
}

int digit_classifier::Evaluate(char input[28][29]) {
    std::pair<int, double> most_probable(-1, INT_MIN);
    for (auto digit_map : digit_maps_) {
        double probability = digit_map.second.Evaluate(input);

        if (probability > most_probable.second) {
            most_probable.first = digit_map.first;
            most_probable.second = probability;
        }
    }

    return most_probable.first;
}

void digit_classifier::Test() {
    std::ifstream inFileTestData;
    std::ifstream inFileLabels;

    inFileTestData.open("digitdata/testimages");
    inFileLabels.open("digitdata/testlabels");

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
        total += 1;
    }

    accuracy_ = (double) correct / total;
}

double digit_classifier::GetAccuracy() {
    return accuracy_;
}

