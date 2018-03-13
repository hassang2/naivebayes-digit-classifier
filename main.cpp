#include "digit_feature.h"
#include "digit_classifier.h"
int main() {

    digit_classifier classifier = digit_classifier();
    classifier.Train();


    classifier.SaveToFile("boop");

//    classifier.LoadFromFile("boop");

    for (int i = 0; i < 4; i ++) {
        classifier.Test("train");

    }

    classifier.Test("test");

    std::cout << "test Accuracy: " << classifier.GetAccuracy() << std::endl;




    std::cout << "Accuracy: " << classifier.GetAccuracy() << std::endl;

    return 0;

}



