#ifndef NAIVEBAYES_DigitMap_H
#define NAIVEBAYES_DigitMap_H

#include <utility>
#include <map>
#include <vector>


class DigitFeature {


private:
    int digit_;
    std::vector<std::vector<std::vector<int> > > feature_matrix_;
    int frequency_ = 0;
    int width_;
    int height_;

public:

    static double constexpr kSmoothing = .1;
    static int const kNumOfData = 5000;
    static int const kNumOfTypes = 3;

    explicit DigitFeature(int number, int h, int w);

    int GetFrequency();

    void SetFrequency(int freq);

    std::vector<std::vector<std::vector<int> > > GetFeature_map();

    void SetFeature_matrixValue(int r, int c, int type, int value);

    DigitFeature() = default;

    double Evaluate(std::vector<std::vector<char> > input);

    void Process(std::vector<std::vector<char> > input);

    int GetDigit();

    int GetHeight();

    int GetWidth();


};

int GetValueOf(char c);

#endif //NAIVEBAYES_DigitMap_H
