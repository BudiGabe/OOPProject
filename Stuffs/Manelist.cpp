#include "Manelist.h"
#include <fstream>
#include <regex>
#include "JsonHelper.h"

const string Manelist::YOUTUBE = "https://www.youtube.com/watch?v=";

Manelist::Manelist(const string &name, const vector<Song> &songs, const vector<Podcast> &podcasts, int followers,
                   long long valoare) : Artist(name, songs, podcasts, followers), valoare(valoare) {}

Manelist::Manelist(const Manelist &manelist) : Artist(manelist) {
    this->valoare = manelist.valoare;
}

Manelist::~Manelist()= default;

long long Manelist::getValoare() const {
    return valoare;
}

void Manelist::setValoare(long long valoare) {
    this->valoare = valoare;
}

Manelist &Manelist::operator=(const Manelist &manelist) {
    if(*this == manelist) {
        return *this;
    }

    Artist::operator=(manelist);

    this->valoare = manelist.valoare;

    return *this;
}

ostream &Manelist::virtualPrint(ostream &out) const {
    Artist::virtualPrint(out);

    cout << "\nValoare: " << valoare;
    return out;
}

istream &Manelist::virtualRead(istream &in) {
    Artist::virtualRead(in);

    cout << "Valoare: ";
    in >> valoare;

    return in;
}

void Manelist::playManea() {
    vector<string> maneleIds = JsonHelper::getYoutubeIds("../res/manele.json", "\"[a-zA-Z0-9]{11}\"");
    ofstream fout("manele.out");
    for(string id: maneleIds) {
        fout << id << endl;
    }
    string randomManea = maneleIds[RandomHelper::getRandomNumInRange(0, maneleIds.size())];
    std::system(("start " + YOUTUBE + randomManea).c_str());
}




