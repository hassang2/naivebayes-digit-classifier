cmake_minimum_required(VERSION 3.5)
project(naivebayes)

set(CMAKE_CXX_STANDARD 14)

add_executable(naivebayes digit_classifier.cpp main.cpp digit_feature.cpp)
add_executable(testunit Tests/digit_feature_test.cpp Tests/digit_classifier_test.cpp digit_feature.cpp digit_classifier.cpp)