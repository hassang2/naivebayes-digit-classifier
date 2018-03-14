#include "digit_feature.h"
#include "digit_classifier.h"
int main() {

    std::cout<< "beep ";

    DigitClassifier classifier = DigitClassifier();

    classifier.Train("digitdata/trainingimages", "digitdata/traininglabels");

    std::cout<< "boop ";

//    classifier.SaveToFile("boop");

//    classifier.LoadFromFile("boop");

    for (int i = 0; i < 4; i ++) {
        classifier.Test("digitdata/trainingimages", "digitdata/traininglabels");

    }
    classifier.Test("digitdata/testimages", "digitdata/testlabels");

    std::cout << "Accuracy: " << classifier.GetAccuracy() << std::endl;

    return 0;

}



