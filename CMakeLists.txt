cmake_minimum_required(VERSION 3.5)
project(naivebayes)

set(CMAKE_CXX_STANDARD 14)

add_executable(naivebayes digit_feature.h digit_classifier.cpp digit_classifier.h main.cpp digit_feature.cpp)
add_executable(testunit Tests/digit_feature_test.cpp Tests/digit_classifier_test.cpp)