#include "digit_map.h"
#include <cmath>
#include <iostream>
#include <climits>



double digit_map::Evaluate(char input[28][29]) {
    double probability = 0;
    for (int r = 0; r < sizeof(&input); r++) {
        for (int c = 0; c < sizeof(input[0]) - 1; c++) {
            std::pair<int, int> coordinate(r, c);
            probability += log((feature_map_[coordinate][GetValueOf(input[r][c])] + kSmoothing_)
                               / (frequency_ + 3 * kSmoothing_));
        }
    }
    probability += frequency_ / 5000;

    return probability;
}


int digit_map::Process(char input[28][29]) {
    frequency_ += 1;
    for (int r = 0; r < sizeof(&input); r++) {
        for (int c = 0; c < sizeof(input[0]) - 1; c++) {
            std::pair<int, int> coordinate(r, c);
            if (GetValueOf(input[r][c]) == -1) return 22;

            feature_map_[coordinate][GetValueOf(input[r][c])] += 1;
        }
    }
    return 0;
}

int GetValueOf(char c) {
    //one line if statements comply with google style guide
    if (c == ' ') return 0;
    if (c == '#') return 1;
    if (c == '+') return 2;

    return -1;
}





