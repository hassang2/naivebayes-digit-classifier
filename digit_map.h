//
// Created by P_Cat on 3/10/2018.
//

#ifndef NAIVEBAYES_DIGIT_MAP_H
#define NAIVEBAYES_DIGIT_MAP_H

#include <utility>
#include <map>

class digit_map {
    int digit_;
    std::map<std::pair<int, int>, double> feature_map_;

public:
    digit_map() = default;
    explicit digit_map(int dig);

    double Evaluate(char number[28][29]);
};

#endif //NAIVEBAYES_DIGIT_MAP_H
