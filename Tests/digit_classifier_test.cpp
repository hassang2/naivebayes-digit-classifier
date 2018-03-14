#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../digit_classifier.h"


TEST_CASE("operator_overload", "[operator_overload]") {

    std::vector<std::vector<char> > testInput(2, std::vector<char> (2));
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

    classifier.Train("twoXtwo", "testLabel");

    std::vector<std::vector<char>> testInput(2, std::vector<char> (2));


    std::ifstream inFile;

    inFile.open("twoXtwo");
    inFile >> testInput;

    int result = classifier.Evaluate(testInput);
    REQUIRE(result == 3);
}

TEST_CASE("test", "[test]") {
    DigitClassifier classifier = DigitClassifier();

    classifier.Train("twoXtwo", "testLabel");
    classifier.Test("twoXtwo", "testLabel");

    REQUIRE(classifier.GetAccuracy() == 1.0);
}

TEST_CASE("save_to_file", "[save]") {
    DigitClassifier classifier = DigitClassifier();

    classifier.Train("twoXtwo", "testLabel");
    classifier.SaveToFile("testSave");

    std::ifstream f("testSave");
    REQUIRE(f.good());
}


TEST_CASE("load_from_file", "[load]") {
    DigitClassifier classifier = DigitClassifier();

    classifier.Train("twoXtwo", "testLabel");
    classifier.SaveToFile("testSave");
    classifier.LoadFromFile("testSave");

    classifier.Test("twoXtwo", "testLabel");

    REQUIRE(classifier.GetAccuracy() == 1.0);
}