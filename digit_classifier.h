
#ifndef NAIVEBAYES_DIGIT_CLASSIFIER_H
#define NAIVEBAYES_DIGIT_CLASSIFIER_H

#include <vector>
#include <iostream>
#include <fstream>
#include "digit_feature.h"


inline std::istream &operator>>(std::istream &is, char **image) {
    for (int i = 0; i < 28; i++) {
        is.getline(image[i], 29);
    }
    return is;
}

class DigitClassifier {

private:
    std::map<int, DigitFeature> digit_maps_;
    double **confusion_matrix_;
    double accuracy_ = 0;

public:

    static int const kWidth = 28;
    static int const kHeight = 28;

    explicit DigitClassifier(int h, int w);

    /**
     * train the classifier on the given files.
     * @param images_dir the relative directory of the training images.
     * @param labels_dir the relative directory of training labels.
     */
    void Train(std::string images_dir, std::string labels_dir);

    /**
     * test the classifier on the given files.
     * @param images_dir the relative directory of the testing images.
     * @param labels_dir the relative directory of the testing labels.
     */
    void Test(std::string images_dir, std::string labels_dir);

    /**
     * evaluate the given image and returns what the prediction of it's digit
     * @param input the image we want to classify
     * @return the number that the classifier predicted
     */
    int Evaluate(char **input);

    double GetAccuracy();

    /**
     * encodes and saves the feature_matrix of each digit into a file
     * @param name the name of the file we want to save out data
     */
    void SaveToFile(std::string name);

    /**
     * decodes and assigns the data from the given file.
     * @param name the name of the file we want to load data from.
     */
    void LoadFromFile(std::string name);

    std::map<int, DigitFeature> GetDigit_map();

    double **GetConfusionMatrix();
};


#endif //NAIVEBAYES_DIGIT_CLASSIFIER_H
