#pragma once
#include "Artist.h"

/*
 * Credits to https://github.com/emanuelcepoi/manea
 */
class Manelist: public Artist {
private:
    long long valoare;
    static const string YOUTUBE;
public:
    Manelist(const string &name="", const vector<Song> &songs={}, const vector<Podcast> &podcasts={}, int followers=0,
             long long valoare=99999999);
    Manelist(const Manelist& manelist);
    ~Manelist();

    long long getValoare() const;
    void setValoare(long long valoare);

    Manelist& operator =(const Manelist& manelist);
    ostream& virtualPrint(ostream& out) const;
    istream& virtualRead(istream& in);

    static void playManea();
};