#include "RandomHelper.h"

/*
 * Initialization of our random generator
 */
std::random_device randomSeed;
std::mt19937 mt(randomSeed());

void RandomHelper::setSeed(size_t seed) {
    mt.seed(seed);
}

int RandomHelper::getRandomNumberOfAudio(){
    std::uniform_real_distribution<double> dist(1, 11);
    return (int)dist(mt);
}

std::string RandomHelper::getRandomKey() {
    std::uniform_real_distribution<double> dist(0, Chord::allNotes.size());
    int randInt = int(dist(mt));
    return Chord::allNotes[randInt];
}

std::string RandomHelper::getRandomTonality() {
    std::uniform_real_distribution<double> dist(0, 2);
    int randInt = int(dist(mt));
    return (randInt == 0) ? Chord::MINOR_SHORTENED : Chord::MAJOR_SHORTENED;
}

std::string RandomHelper::getRandomGenre() {
    std::uniform_real_distribution<double> dist(0, Song::GENRES.size());
    int randInt = int(dist(mt));
    return Song::GENRES[randInt];
}

std::string RandomHelper::getRandomGuest() {
    std::uniform_real_distribution<double> dist(1, Podcast::GUESTS.size());
    int randInt = int(dist(mt));
    return Podcast::GUESTS[randInt];
}

int RandomHelper::getRandomLength() {
    std::uniform_real_distribution<double> dist(30, 181);
    int randInt = int(dist(mt));
    return randInt;
}

std::string RandomHelper::getRandomTopic() {
    std::uniform_real_distribution<double> dist(0, Podcast::ALL_TOPICS.size());
    return Podcast::ALL_TOPICS[dist(mt)];
}

int RandomHelper::getRandomNumInRange(int l, int r) {
    std::uniform_real_distribution<double> dist(l, r+1);
    return dist(mt);
}



