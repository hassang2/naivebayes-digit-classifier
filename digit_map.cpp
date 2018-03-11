#include "digit_map.h"
#include <cmath>
#include <iostream>
#include <climits>

digit_map::digit_map(int number) {
//    digit_ = number;
}

void digit_map::Add(int x, int y, int value) {
    std::pair<int, int> coordinate(x, y);
    feature_map_[coordinate][value] += 1;
}

double digit_map::Evaluate(char input[28][29]) {
    double probability = 0;
    for (int y = 0; y < sizeof(&input); y++) {
        for (int x = 0; x < sizeof(input[0]) - 1; x++) {
            std::pair<int, int> coordinate(x, y);
            probability += log((feature_map_[coordinate][GetValueOf(input[x][y])] + kSmoothing_)
                                                          / (frequency_ + 3 * kSmoothing_));
        }
    }
    probability += frequency_ / 5000;

    return probability;
}

void digit_map::AddFrequency() {
    frequency_ += 1;
}

void digit_map::Process(char input[28][29]) {
    frequency_ += 1;
    for (int y = 0; y < sizeof(&input); y++) {
        for (int x = 0; x < sizeof(input[0]) - 1; x++) {
            std::pair<int, int> coordinate(x, y);
            feature_map_[coordinate][GetValueOf(input[y][x])] += 1;
        }
    }
}

//int digit_map::GetDigit() {
//    return digit_;
//}

int GetValueOf(char c) {
    //one line if statements comply with google style guide
    if (c == ' ') return 0;
    if (c == '#') return 1;
    if (c == '+') return 2;

    std::cout << "invalid char" << c;
    return -1;
}





