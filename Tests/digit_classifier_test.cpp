#include "catch.hpp"
#include "../digit_classifier.h"


TEST_CASE("operator_overload", "[operator_overload]") {
    auto **testInput = new char *[2];
    for (int i = 0; i < 2; i++) {
        testInput[i] = new char[3];
    }

    std::ifstream inFile;
    inFile.open("twoXtwo");

    inFile >> testInput;

    REQUIRE(testInput[0][0] == 0);

}

TEST_CASE("train", "[train]") {

    DigitClassifier classifier = DigitClassifier(2, 2);

    classifier.Train("twoXtwo", "testLabel");
    REQUIRE(classifier.GetDigit_map()[3].GetFrequency() == 0);
}

TEST_CASE("evaluate", "[eval]") {

    DigitClassifier classifier = DigitClassifier(2, 2);

    classifier.Train("../", "testLabel");
    REQUIRE(classifier.GetDigit_map()[3].GetFrequency() == 0);
}