#ifndef NAIVEBAYES_DIGIT_MAP_H
#define NAIVEBAYES_DIGIT_MAP_H

#include <utility>
#include <map>


class digit_map {

private:
    int digit_;
    int*** feature_map_;
    int frequency_ = 0;

public:

    explicit digit_map(int number);

    int GetFrequency() const;

    void SetFrequency(int freq);

    int*** GetFeature_map();

    void SetFeature_mapValue(int r, int c, int type, int value);

    digit_map() = default;

    double Evaluate(char input[28][29]);

    void Process(char input[28][29]);

    int GetDigit();


};

int GetValueOf(char c);

#endif //NAIVEBAYES_DIGIT_MAP_H
