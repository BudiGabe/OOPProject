#include "TraditionalSong.h"

const string TraditionalSong::WIKI = "https://en.wikipedia.org/wiki/";

TraditionalSong::TraditionalSong(string country, string name, vector<Chord> chords, int length, int *mainChordProgression,
                                 int progressionLength, bool likedStatus, char tier, char *key, float rating,
                                 float *ratingVariation, int variationPeriod, double views, string *similarSongs,
                                 int numOfSimilarSongs, int num):
                                 Song(name, chords, length, mainChordProgression, progressionLength, likedStatus, tier,
                                      key, rating, ratingVariation, variationPeriod, views, similarSongs, numOfSimilarSongs,
                                      num), country(country){}

TraditionalSong::TraditionalSong(const TraditionalSong &song): Song(song) {
    this->country = song.country;
}

const string &TraditionalSong::getCountry() const {
    return country;
}

void TraditionalSong::setCountry(const string &country) {
    this->country = country;
}

TraditionalSong &TraditionalSong::operator=(const TraditionalSong &song) {
    if(this == &song) {
        return *this;
    }

    Song::operator=(song);

    this->country = song.country;

    return *this;
}

ostream &TraditionalSong::virtualPrint(ostream &os) const{
    Song::virtualPrint(os);
    cout << "\nCountry: " << country;
    return os;
}

istream &TraditionalSong::virtualRead(istream &is) {
    Song::virtualRead(is);

    cout << "\nCountry: ";
    is >> country;

    return is;
}

TraditionalSong::~TraditionalSong() = default;

void TraditionalSong::openWikiLink() {
    const string START_COMMAND = "start ";
    std::system((START_COMMAND + WIKI + country).c_str());
}