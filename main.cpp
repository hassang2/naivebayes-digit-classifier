#include <iomanip>
#include "digit_feature.h"
#include "digit_classifier.h"
int main() {

    DigitClassifier classifier = DigitClassifier(28, 28);
//    classifier.Train("digitdata/trainingimages", "digitdata/traininglabels");


//    classifier.SaveToFile("boop");

    classifier.LoadFromFile("boop");

//    for (int i = 0; i < 1; i ++) {
//        classifier.Test("train");
//
//    }

    classifier.Test("digitdata/testimages", "digitdata/testlabels");

    std::cout << "Accuracy: " << classifier.GetAccuracy() << std::endl;

    std::cout << "Confusion Matrix: " << std::endl;

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++) {
            std::cout << classifier.GetConfusionMatrix()[i][j] << "\t";
        }
        std::cout << std::endl;
    }


    return 0;

}



