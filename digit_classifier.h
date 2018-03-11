
#ifndef NAIVEBAYES_DIGIT_CLASSIFIER_H
#define NAIVEBAYES_DIGIT_CLASSIFIER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "digit_map.cpp"

std::istream &operator>>(std::istream &is, char image[28][29]) {
    for (int i = 0; i < 28; i++) {
        is.getline(image[i], 29);
    }
    return is;
}

class digit_classifier {

    std::map<int, digit_map> digit_maps_;
    double accuracy_ = 0;

public:

    explicit digit_classifier();

    void Train();

    void Test();

    int Evaluate(char input[28][29]);

    double GetAccuracy();

};


#endif //NAIVEBAYES_DIGIT_CLASSIFIER_H
