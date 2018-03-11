//
// Created by P_Cat on 3/10/2018.
//

#ifndef NAIVEBAYES_DIGIT_MAP_H
#define NAIVEBAYES_DIGIT_MAP_H

#include <utility>
#include <map>

class digit_map {
    double kSmoothing_ = .1;
//    int digit_;
    int frequency_ = 0;
    std::map<std::pair<int, int>, std::map<int, int> > feature_map_;

public:
    digit_map() = default;

    explicit digit_map(int dig);

//    int GetDigit();

    double Evaluate(char input[28][29]);

    void Process(char input[28][29]);

    void Add(int i, int j, int value);

    void AddFrequency();

};

int GetValueOf(char c);

#endif //NAIVEBAYES_DIGIT_MAP_H
