#pragma once
#include <random>
#include <iostream>
#include <string>
#include "Chord.h"
#include "Song.h"
#include "Podcast.h"

/*
 * Helper class which holds random generation methods.
 */
class RandomHelper {
public:
    static void setSeed(size_t seed);
    static int getRandomNumberOfAudio();
    static std::string getRandomKey();
    static std::string getRandomTonality();
    static std::string getRandomGenre();
    static std::string getRandomGuest();
    static int getRandomLength();
    static std::string getRandomTopic();
    static int getRandomNumInRange(int l, int r);
};


