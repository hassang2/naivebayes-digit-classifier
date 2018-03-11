#ifndef NAIVEBAYES_DIGIT_MAP_H
#define NAIVEBAYES_DIGIT_MAP_H

#include <utility>
#include <map>

class digit_map {
    double kSmoothing_ = .1;
    int frequency_ = 0;
    std::map<std::pair<int, int>, std::map<int, int> > feature_map_;

public:

    double Evaluate(char input[28][29]);

    int Process(char input[28][29]);
};

int GetValueOf(char c);

#endif //NAIVEBAYES_DIGIT_MAP_H
