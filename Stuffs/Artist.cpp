#include "Artist.h"


Artist::Artist() {
    name = "";
    songs = {};
    podcasts = {};
    followers = 0;
}

Artist::Artist(string name, vector<Song> songs, vector<Podcast> podcasts, int followers) {
    this->name = name;
    this->songs = songs;
    this->podcasts = podcasts;
    this->followers = followers;
}

Artist::Artist(string name, int followers) {
    this->name = name;
    this->followers = followers;
    this->songs = {};
    this->podcasts = {};
}

Artist::Artist(const Artist &artist) {
    name = artist.name;
    songs = artist.songs;
    podcasts = artist.podcasts;
    followers = artist.followers;
}

Artist::~Artist() {}

Artist& Artist::operator =(const Artist& artist) {
    if(this == &artist){
        return *this;
    }

    this->name =artist.name;
    this->podcasts = artist.podcasts;
    this->songs = artist.songs;
    this->followers = artist.followers;

    return *this;
}

ostream& Artist::virtualPrint(ostream& out) const {
    out << "\nArtist name: " << name;

    out << "\nSongs: ";
    for(auto song : songs) {
        out << "\n" << song.getName() << endl;
        out << "\nKey: " << song.getKey();
        out << "\nProgression: ";
        for(int i = 0; i < song.getProgressionLength(); i++) {
            out << song.getMainChordProgression()[i] << " ";
        }
        out << "\nChords:" << endl;
        for(auto chord : song.getChords())
            out << chord << endl;
    }

    out << "\nPodcasts: ";
    for(auto podcast : podcasts) {
        out << podcast << endl;
    }

    out << "\nFollowers: " << followers;
    return out;
}

istream& Artist::virtualRead(istream& in) {
    cout << "\nArtist name: ";
    in >> name;

    cout << "\nNumber of artist songs: ";
    int audioNum;
    in >> audioNum;
    Song song;
    for(int i = 0; i < audioNum; i++) {
        cout << "Song " << i << endl;
        in >> song;
        songs.push_back(song);
    }

    cout << "\nNumber of artist podcasts";
    in >> audioNum;
    Podcast podcast;
    for(int i = 0; i <audioNum; i++) {
        in >> podcast;
        podcasts.push_back(podcast);
    }

    cout << "\nFollowers: ";
    in >> followers;

    return in;
}

ostream &operator<<(ostream &out, const Artist &artist) {
    artist.virtualPrint(out);
    return out;
}

istream &operator>>(istream &in, Artist &artist) {
    artist.virtualRead(in);
    return in;
}

Song& Artist::operator[](int index) {
    if(index > songs.size()) {
        cout << "\nInvalid index";
        exit(0);
    }
    return songs[index];
}

Artist& Artist::operator++() {
    followers++;

    return *this;
}

Artist Artist::operator++(int) {
    Artist tempArtist;
    this->followers++;

    return tempArtist;
}

Artist Artist::operator+(const Artist& artist) {
    Artist tempArtist;
    tempArtist.followers = this->followers + artist.followers;

    return tempArtist;
}

Artist Artist::operator-(const Artist& artist){
    Artist tempArtist;
    if(this->followers > artist.followers) {
        tempArtist.followers = this->followers - artist.followers;
    } else {
        cout << "\nResulting followers negative.";
        exit(0);
    }

    return tempArtist;
}

/*
 * Generates a random artist with a whole set of randomly generated songs and podcasts.
 */
Artist Artist::generateArtist(const string& name, int followers) {
    Artist artist(name, followers);

    int randNumOfSongs = RandomHelper::getRandomNumberOfAudio();
    for(int i = 0; i < randNumOfSongs; i++){
        string randKey = RandomHelper::getRandomKey();
        string randTonality = RandomHelper::getRandomTonality();
        string randGenre = RandomHelper::getRandomGenre();

        Song newSong = Song::generateSong(randKey, randTonality, randGenre, i);
        artist.songs.push_back(newSong);
    }

    int randNumOfPodcasts = RandomHelper::getRandomNumberOfAudio();
    for(int i = 0; i <randNumOfPodcasts; i++) {
        string randGuest = RandomHelper::getRandomGuest();
        int randLength = RandomHelper::getRandomLength();

        Podcast newPodcast = Podcast::recordPodcast(artist.name, randGuest, randLength);
        artist.podcasts.push_back(newPodcast);
    }

    return artist;
}

bool operator==(const Artist &artist1, const Artist &artist2) {

    return artist1.name == artist2.name
        && artist1.followers == artist2.followers
        && artist1.songs == artist2.songs
        && artist1.podcasts == artist2.podcasts;
}
