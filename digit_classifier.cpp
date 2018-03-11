//
// Created by P_Cat on 3/8/2018.
//
#include "digit_classifier.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <fstream>

void digit_classifier::Init() {
    for (int i = 0; i < 10; i++) {
        digit_maps_[i] = digit_map();
    }
}

void digit_classifier::Train() {

    Init();
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
