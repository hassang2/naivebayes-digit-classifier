#include "digit_classifier.cpp"
//#include "digit_map.cpp"

int main() {

    digit_classifier classifier = digit_classifier();

    classifier.Train();

    char image[28][29];
    int result;
    while (std::cin) {
        std::cin >> image;
        result = classifier.Evaluate(image);
        std::cout << result << std::endl;
    }
}

