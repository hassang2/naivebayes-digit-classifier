#ifndef NAIVEBAYES_DigitMap_H
#define NAIVEBAYES_DigitMap_H

#include <utility>
#include <map>
class DigitFeature {

private:
    int ***feature_map_;
    int frequency_ = 0;
    int height_;
    int width_;

public:

    static int const kNumOfTypes = 3;
    static double constexpr kSmoothing = .1;


    explicit DigitFeature(int h, int w);

    int GetFrequency() const;

    void SetFrequency(int freq);

    int ***GetFeature_map();

    /**
     * sets the value of the feature_matrix at the given location
     * @param r  the row number
     * @param c  the comumn number
     * @param type the type of char (' ', # or +)
     * @param value the value we want to put
     */
    void SetFeature_matrixValue(int r, int c, int type, int value);

    DigitFeature() = default;

    /**
     * evaluates the given image and returns the probability that the image is this digit
     * @param input the image we want to get the probability of
     * @return the probability
     */
    double Evaluate(char **input);

    /**
     * process the image. It goes through all the pixels of the input and increments the corresponsing location in the
     * feature matrix
     * @param input the image we want to process
     */
    void Process(char **input);

    int GetHeight();

    int GetWidth();
};

/**
 * translates char to int int.
 * @param c  the char value we want to translate
 * @return the int corresponding to the char.
 */
int GetValueOf(char c);

#endif //NAIVEBAYES_DigitMap_H
