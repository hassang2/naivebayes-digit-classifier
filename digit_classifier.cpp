//
// Created by P_Cat on 3/8/2018.
//
#include "digit_classifier.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

std::istream &operator>>(std::istream &is, char image[28][29]) {
    for (int i = 0; i < 28; i++) {
        is.getline(image[i], 29);
        std::cout << image[i] << std::endl;
    }

    return is;
}

int main() {



    std::train();

    std::map<int, std::map<std::pair<int, int>, int> > feature_maps ;


    char image[28][29];

    while (std::cin) {
        std::cin >> image;
    }

//    char word[29][29];
//
//    for (int i = 0; i < 29; i++) {
//        std::cin.getline(word[i], 29);
//        std::cout << word[i] <<std::endl;
//    }


}


