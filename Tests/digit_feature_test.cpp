#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../digit_feature.h"
#include "../digit_classifier.h"
#include <fstream>
#include <iostream>
#include <cmath>


TEST_CASE("simple_evaluate", "[evaluate]") {
    DigitFeature digit = DigitFeature(0, 2, 2);

    digit.SetFeature_matrixValue(0, 0, 0, 1);
    digit.SetFeature_matrixValue(0, 1, 1, 3);
    digit.SetFeature_matrixValue(1, 0, 2, 4);
    digit.SetFeature_matrixValue(1, 1, 2, 3);

    std::vector<std::vector<char>> testInput(2, std::vector<char> (2));

    std::ifstream inFile;

    inFile.open("twoXtwo");
    inFile >> testInput;

    digit.SetFrequency(5);
    double actual_prob = digit.Evaluate(testInput);
    double expected_prob = log((1 + .1) / (5 + 3*.1)) + log((3 + .1) / (5 + 3*.1)) + log((4 + .1) / (5 + 3*.1)) + log(5.0 / 5000);

    REQUIRE(actual_prob == expected_prob);
}

TEST_CASE("simple_process", "[process]") {
    DigitFeature digit = DigitFeature(0, 2, 2);

    std::vector<std::vector<char>> testInput(2, std::vector<char> (2));


    std::ifstream inFile;

    inFile.open("twoXtwo");
    inFile >> testInput;
    digit.Process(testInput);



    REQUIRE(digit.GetFeature_map()[0][0][2] == 1);
    REQUIRE(digit.GetFeature_map()[1][0][2] == 1);

}

TEST_CASE("GetFrequency", "[process]") {
    DigitFeature digit = DigitFeature(0, 2, 2);
    std::vector<std::vector<char>> testInput(2, std::vector<char> (2));

    std::ifstream inFile;

    inFile.open("twoXtwo");
    inFile >> testInput;

    REQUIRE(digit.GetFrequency() == 0);
    digit.Process(testInput);
    REQUIRE(digit.GetFrequency() == 1);
}


TEST_CASE("dimensions", "[process]") {
    DigitFeature digit = DigitFeature(0, 4, 2);

    REQUIRE(digit.GetHeight() == 4);
    REQUIRE(digit.GetWidth() == 2);
}

TEST_CASE("SetFeature_matrix", "[process]") {
    DigitFeature digit = DigitFeature(0, 4, 2);

    digit.SetFeature_matrixValue(0, 1, 1, 5);

    REQUIRE(digit.GetFeature_map()[0][1][1] == 5);
}

TEST_CASE("SetFrequency", "[process]") {
    DigitFeature digit = DigitFeature(0, 4, 2);

    digit.SetFrequency(11);
    REQUIRE(digit.GetFrequency() == 11);
}
