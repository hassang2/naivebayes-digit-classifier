#include "digit_feature.h"
#include "digit_classifier.h"
#include <cmath>
#include <iostream>


DigitMap::DigitMap(int number) {
    feature_map_ = new int **[digit_classifier::kHeight];
    for (int i = 0; i < digit_classifier::kHeight; i++) {
        feature_map_[i] = new int *[digit_classifier::kWidth];
        for (int k = 0; k < digit_classifier::kWidth; k++) feature_map_[i][k] = new int[digit_classifier::kNumOfTypes];
    }
    digit_ = number;
}


double DigitMap::Evaluate(char input[28][29]) {
    double probability = 0;
    for (int r = 0; r < digit_classifier::kHeight; r++) {
        for (int c = 0; c < digit_classifier::kWidth; c++) {
            probability += log((feature_map_[r][c][GetValueOf(input[r][c])] + digit_classifier::kSmoothing)
                               / (frequency_ + digit_classifier::kNumOfTypes * digit_classifier::kSmoothing));
        }
    }
    probability += (double) frequency_ / digit_classifier::GetTotalNumOfData();

    return probability;
}


void DigitMap::Process(char input[28][29]) {
    frequency_ += 1;

    for (int r = 0; r < digit_classifier::kHeight; r++) {
        for (int c = 0; c < digit_classifier::kWidth; c++) {
            feature_map_[r][c][GetValueOf(input[r][c])] += 1;
        }
    }
}

int DigitMap::GetDigit() {
    return digit_;
}

int DigitMap::GetFrequency() const {
    return frequency_;
}

int*** DigitMap::GetFeature_map() {
    return feature_map_;
}


void DigitMap::SetFrequency(int freq) {
    frequency_ = freq;
}

void DigitMap::SetFeature_mapValue(int r, int c, int type, int value) {
    feature_map_[r][c][type] = value;
}


int GetValueOf(char c) {
    //one line if statements comply with google style guide
    if (c == ' ') return 0;
    if (c == '#') return 1;
    if (c == '+') return 2;

    std::cout << "what";
    return -1;
}
