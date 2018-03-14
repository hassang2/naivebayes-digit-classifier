
#ifndef NAIVEBAYES_DIGIT_CLASSIFIER_H
#define NAIVEBAYES_DIGIT_CLASSIFIER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "digit_feature.h"

inline std::istream &operator>>(std::istream &is, std::vector<std::vector<char> > &image) {
    std::cout << "what";

    auto *chars = new char[29];
    for (int i = 0; i < 28; i++) {
        is.getline(chars, 29);
    }

    image.push_back(std::vector<char> (chars, chars + 29));

    return is;
}

class DigitClassifier {

private:
    std::map<int, DigitFeature> digit_maps_;
    double accuracy_ = 0;

public:

    int const kHeight = 28;
    int const kWidth = 28;

    explicit DigitClassifier();

    void Train(std::string images_dir, std::string labels_dir);

    void Test(std::string images_dir, std::string labels_dir);

    int Evaluate(std::vector<std::vector<char> > input);

    double GetAccuracy();

    void SaveToFile(std::string name);

    void LoadFromFile(std::string name);

    std::map<int, DigitFeature> GetDigit_map();
};


#endif //NAIVEBAYES_DIGIT_CLASSIFIER_H
