#pragma once
#include "Song.h"

class TraditionalSong: public Song {
private:
    string country;
    static const string WIKI;
public:
    TraditionalSong(string country = "", string name = "", vector<Chord> chords = {}, int length=0, int* mainChordProgression=nullptr,
                    int progressionLength=0, bool likedStatus=false, char tier='F', char* key=nullptr, float rating=0,
                    float* ratingVariation=nullptr, int variationPeriod=0, double views=0, string* similarSongs=nullptr,
                    int numOfSimilarSongs=0, int num=-1);
    TraditionalSong(const TraditionalSong& song);
    ~TraditionalSong();
    const string &getCountry() const;
    void setCountry(const string &country);

    TraditionalSong& operator =(const TraditionalSong& song);
    virtual ostream& virtualPrint(ostream &os) const;
    virtual istream& virtualRead(istream &is);

    void openWikiLink();
};