#include "digit_classifier.cpp"
//#include "digit_map.cpp"

int main() {

    digit_classifier classifier = digit_classifier();
    classifier.Train();


    classifier.SaveToFile("boop");

//    classifier.LoadFromFile("boop");

    classifier.Test();

    std::cout << "Accuracy: " << classifier.GetAccuracy() << std::endl;

    return 0;

}



