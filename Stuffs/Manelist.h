#pragma once
#include "Artist.h"

/*
 * Credits to https://github.com/emanuelcepoi/manea
 */
class Manelist: public Artist {
private:
    int valoare;
    static const string YOUTUBE;
public:
    Manelist(const string &name, const vector<Song> &songs, const vector<Podcast> &podcasts, int followers,
             int valoare);
    Manelist(const Manelist& manelist);
    ~Manelist();

    int getValoare() const;
    void setValoare(int valoare);

    Manelist& operator =(const Manelist& manelist);
    ostream& virtualPrint(ostream& out) const;
    istream& virtualRead(istream& in);

    static void playManea();
};