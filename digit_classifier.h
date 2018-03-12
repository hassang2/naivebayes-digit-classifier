
#ifndef NAIVEBAYES_DIGIT_CLASSIFIER_H
#define NAIVEBAYES_DIGIT_CLASSIFIER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "digit_map.h"

std::istream &operator>>(std::istream &is, char image[28][29]) {
    for (int i = 0; i < 28; i++) {
        is.getline(image[i], 29);
    }
    return is;
}

static int total_num_of_data = 0;

class digit_classifier {


private:
    std::map<int, digit_map> digit_maps_;
    double accuracy_ = 0;

public:

    static int const kWidth = 28;
    static int const kHeight = 28;
    static int const kNumOfTypes = 3;
    static double constexpr kSmoothing = .1;

    explicit digit_classifier();

    static int GetTotalNumOfData();

    void Train();

    void Test();

    int Evaluate(char input[28][29]);

    double GetAccuracy();

    void SaveToFile(std::string name);

    void LoadFromFile(std::string name);
};


#endif //NAIVEBAYES_DIGIT_CLASSIFIER_H
