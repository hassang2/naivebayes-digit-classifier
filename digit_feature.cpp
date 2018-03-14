#include "digit_feature.h"
#include <cmath>
#include <iostream>


DigitFeature::DigitFeature(int number, int h, int w) {
    height_ = h;
    width_ = w;
    feature_map_ = new int **[height_];
    for (int i = 0; i < height_; i++) {
        feature_map_[i] = new int *[width_];
        for (int k = 0; k < width_; k++) feature_map_[i][k] = new int[kNumOfTypes];
    }
    digit_ = number;
}


double DigitFeature::Evaluate(char **input) {
    double probability = 0;
    for (int r = 0; r < height_; r++) {
        for (int c = 0; c < width_; c++) {
            probability += log((feature_map_[r][c][GetValueOf(input[r][c])] + kSmoothing)
                               / (frequency_ + kNumOfTypes * kSmoothing));
        }
    }
    probability += (double) frequency_ / 5000;

    return probability;
}


void DigitFeature::Process(char **input) {
    frequency_ += 1;

    for (int r = 0; r < height_; r++) {
        for (int c = 0; c < width_; c++) {
            feature_map_[r][c][GetValueOf(input[r][c])] += 1;
        }
    }
}

int DigitFeature::GetFrequency() const {
    return frequency_;
}

int*** DigitFeature::GetFeature_map() {
    return feature_map_;
}


void DigitFeature::SetFrequency(int freq) {
    frequency_ = freq;
}

void DigitFeature::SetFeature_matrixValue(int r, int c, int type, int value) {
    feature_map_[r][c][type] = value;
}

int DigitFeature::GetWidth() {
    return width_;
}

int DigitFeature::GetHeight() {
    return height_;
}


int GetValueOf(char c) {
    //one line if statements comply with google style guide
    if (c == ' ') return 0;
    if (c == '#') return 1;
    if (c == '+') return 2;

    return -1;
}

