#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../digit_classifier.h"


TEST_CASE("operator_overload", "[operator_overload]") {

    std::vector<std::vector<int> > testInput(2, std::vector<int> (2));
    std::ifstream inFile;
    inFile.open("twoXtwo");

    inFile >> testInput;

    REQUIRE(testInput[0][0] == ' ');

}

TEST_CASE("train", "[train]") {

    DigitClassifier classifier = DigitClassifier();

    classifier.Train("twoXtwo", "testLabel");
    REQUIRE(classifier.GetDigit_map()[3].GetFrequency() == 1);
}

TEST_CASE("evaluate", "[eval]") {

    DigitClassifier classifier = DigitClassifier();

    classifier.Train("../", "testLabel");
    REQUIRE(classifier.GetDigit_map()[3].GetFrequency() == 1);
}