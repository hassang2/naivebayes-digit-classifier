#include "digit_feature.h"
//#include "digit_classifier.h"
#include <cmath>
#include <iostream>


DigitFeature::DigitFeature(int number, int h, int w) {
    height_ = h;
    width_ = w;

    feature_matrix_ = std::vector<std::vector<std::vector<int> > >(height_,
                                                                   std::vector<std::vector<int> >(width_,
                                                                                                  std::vector<int>(3)));
//    for (int i = 0; i < height_; i++) {
//        feature_matrix_[i] = std::vector<std::vector<int> > (width_);
//        for (int k = 0; k < width_; k++) {
//        }
//    }
//}

    digit_ = number;
}


double DigitFeature::Evaluate(std::vector<std::vector<char> > input) {
    double probability = 0;
    for (int r = 0; r < height_; r++) {
        for (int c = 0; c < width_; c++) {
            probability += log((feature_matrix_[r][c][GetValueOf(input[r][c])] + kSmoothing)
                               / (frequency_ + kNumOfTypes * kSmoothing));
        }
    }
    probability += (double) frequency_ / kNumOfData;

    return probability;
}


void DigitFeature::Process(std::vector<std::vector<char> > input) {
    frequency_ += 1;

    for (int r = 0; r < height_; r++) {
        for (int c = 0; c < width_; c++) {
            feature_matrix_[r][c][GetValueOf(input[r][c])] += 1;
        }
    }
}

int DigitFeature::GetDigit() {
    return digit_;
}

int DigitFeature::GetFrequency() {
    return frequency_;
}

std::vector<std::vector<std::vector<int> > > DigitFeature::GetFeature_map() {
    return feature_matrix_;
}


void DigitFeature::SetFrequency(int freq) {
    frequency_ = freq;
}

void DigitFeature::SetFeature_matrixValue(int r, int c, int type, int value) {
    feature_matrix_[r][c][type] = value;
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

    std::cout << "what";
    return -1;
}

