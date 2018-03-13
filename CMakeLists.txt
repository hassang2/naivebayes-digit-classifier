cmake_minimum_required(VERSION 3.5)
project(naivebayes)

set(CMAKE_CXX_STANDARD 14)

add_executable(naivebayes digit_map.h digit_classifier.cpp digit_classifier.h main.cpp digit_map.cpp )