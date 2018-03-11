
#ifndef NAIVEBAYES_DIGIT_CLASSIFIER_H
#define NAIVEBAYES_DIGIT_CLASSIFIER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "digit_map.cpp"


//std::ifstream &operator>>(std::ifstream &is, char image[28][29]) {
//    for (int i = 0; i < 28; i++) {
//        is.getline(image[i], 29);
//        std::cout << image[i] << std::endl;
//    }
//    return is;
//}

std::istream &operator>>(std::istream &is, char image[28][29]) {
    for (int i = 0; i < 28; i++) {
        is.getline(image[i], 29);
        std::cout << image[i] << std::endl;
    }
    return is;
}

class digit_classifier {

    std::map<int, digit_map> digit_maps_;

public:
    void Train();

    void Init();

    int Evaluate(char input[28][29]);

};


#endif //NAIVEBAYES_DIGIT_CLASSIFIER_H
