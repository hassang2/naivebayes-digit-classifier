#ifndef NAIVEBAYES_DigitMap_H
#define NAIVEBAYES_DigitMap_H

#include <utility>
#include <map>
//#include "digit_classifier.h"



class DigitMap {


private:
    int digit_;
    int*** feature_map_;
    int frequency_ = 0;

public:

    explicit DigitMap(int number);

    int GetFrequency() const;

    void SetFrequency(int freq);

    int*** GetFeature_map();

    void SetFeature_mapValue(int r, int c, int type, int value);

    DigitMap() = default;

    double Evaluate(char input[28][29]);

    void Process(char input[28][29]);

    int GetDigit();


};

int GetValueOf(char c);

#endif //NAIVEBAYES_DigitMap_H
