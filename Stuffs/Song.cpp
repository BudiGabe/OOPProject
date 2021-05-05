#include "Song.h"

const string Song::JAZZ = "Jazz";
const string Song::CITY_POP = "City pop";
const string Song::BLUES = "Blues";
const vector<string> Song::GENRES{"Jazz", "City pop", "Blues"};
const int Song::JAZZ_PROGRESSION[] = {2, 5, 1};
const int Song::CITY_POP_PROGRESSION[] = {4, 5, 3, 6};
const int Song::BLUES_PROGRESSION[] = {1, 4, 5};


Song::Song(string name, vector<Chord> chords, int length, int *mainChordProgression, int progressionLength,
           bool likedStatus, char tier, char *key, float rating, float *ratingVariation, int variationPeriod,
           double views, string *similarSongs, int numOfSimilarSongs, int num) : AudioRecording(name, length, views),
           songNum(num), likedStatus(likedStatus), tier(tier), rating(rating), progressionLength(progressionLength),
           numOfSimilarSongs(numOfSimilarSongs), variationPeriod(variationPeriod), chords(chords){
    this->mainChordProgression = new int[progressionLength];
    for (int i = 0; i < progressionLength; i++) {
        this->mainChordProgression[i] = mainChordProgression[i];
    }

    if(key != nullptr){
        this->key = new char[strlen(key) + 1];
        strcpy(this->key, key);
    }

    this->ratingVariation = new float[variationPeriod];
    for (int i = 0; i < variationPeriod; i++) {
        this->ratingVariation[i] = ratingVariation[i];
    }

    this->similarSongs = new string[numOfSimilarSongs];
    for (int i = 0; i < numOfSimilarSongs; i++) {
        this->similarSongs[i] = similarSongs[i];
    }
}

Song::Song(int length, string name, int num, char* key, int *mainChordProgression, int progressionLength,
           double views, vector<Chord> chords) : AudioRecording(name, length, views), songNum(-1) {
    this->progressionLength = progressionLength;
    this->chords = chords;
    this->key = nullptr;
    this->likedStatus = 0;
    this->tier = 'F';
    this->rating = 0;
    this->variationPeriod = 0;
    this->ratingVariation = nullptr;
    this->numOfSimilarSongs = 0;
    this->similarSongs = nullptr;

    if(key != nullptr) {
        this->key = new char[strlen(key) + 1];
        strcpy(this->key, key);
    }

    this->mainChordProgression = new int[progressionLength];
    for (int i = 0; i < progressionLength; i++) {
        this->mainChordProgression[i] = mainChordProgression[i];
    }
}

Song::Song(int num) : AudioRecording("", 0, 0), songNum(num) {
    likedStatus = false;
    tier = 'F';
    rating = 0;
    mainChordProgression = nullptr;
    progressionLength = 0;
    key = nullptr;
    ratingVariation = nullptr;
    variationPeriod = 0;
    similarSongs = nullptr;
    numOfSimilarSongs = 0;
    chords = {};
}

Song::Song(const Song &song) :AudioRecording(song), songNum(song.songNum) {
    this->likedStatus = song.likedStatus;
    this->tier = song.tier;
    this->rating = song.rating;
    this->progressionLength = song.progressionLength;
    this->variationPeriod = song.variationPeriod;
    this->numOfSimilarSongs = song.numOfSimilarSongs;
    this->chords = song.chords;

    this->mainChordProgression = new int[song.progressionLength];
    for (int i = 0; i < song.progressionLength; i++) {
        this->mainChordProgression[i] = song.mainChordProgression[i];
    }
    if (song.key == nullptr) {
        this->key = nullptr;
    } else {
        this->key = new char[strlen(song.key) + 1];
        strcpy(this->key, song.key);
    }

    this->ratingVariation = new float[song.variationPeriod];
    for (int i = 0; i < song.variationPeriod; i++) {
        this->ratingVariation[i] = song.ratingVariation[i];
    }

    this->similarSongs = new string[song.numOfSimilarSongs];
    for (int i = 0; i < song.numOfSimilarSongs; i++) {
        this->similarSongs[i] = song.similarSongs[i];
    }
}

Song::~Song() {
    if (this->mainChordProgression != nullptr) {
        delete[] this->mainChordProgression;
    }

    if (this->key != nullptr) {
        delete[] key;
    }

    if (this->ratingVariation != nullptr) {
        delete[] ratingVariation;
    }

    if (this->similarSongs != nullptr) {
        delete[] similarSongs;
    }
}

void Song::setMainChordProgression(int *chordProgression, int length) {
    progressionLength = length;
    if (mainChordProgression != nullptr) {
        delete[] mainChordProgression;
    }

    mainChordProgression = new int[progressionLength];
    for (int i = 0; i < progressionLength; i++) {
        mainChordProgression[i] = chordProgression[i];
    }
}

void Song::setRatingVariation(float *variation, int period) {
    variationPeriod = period;
    if (ratingVariation != nullptr) {
        delete[] ratingVariation;
    }

    ratingVariation = new float[variationPeriod];
    for (int i = 0; i < variationPeriod; i++) {
        ratingVariation[i] = variation[i];
    }
}

void Song::setSimilarSongs(string *songs, int num) {
    numOfSimilarSongs = num;
    if (similarSongs != nullptr) {
        delete[] similarSongs;
    }

    similarSongs = new string[numOfSimilarSongs];
    for (int i = 0; i < numOfSimilarSongs; i++) {
        similarSongs[i] = songs[i];
    }
}

void Song::setKey(char *newKey) {
    if (key != nullptr) {
        delete[] key;
    }

    key = new char[strlen(newKey) + 1];
    strcpy(key, newKey);
}

Song &Song::operator=(const Song &song) {
    if (this == &song) {
        return *this;
    }

    if (this->mainChordProgression != nullptr) {
        delete[] this->mainChordProgression;
    }

    if (this->key != nullptr) {
        delete[] key;
    }

    if (this->ratingVariation != nullptr) {
        delete[] ratingVariation;
    }

    if (this->similarSongs != nullptr) {
        delete[] similarSongs;
    }

    AudioRecording::operator=(song);

    this->likedStatus = song.likedStatus;
    this->tier = song.tier;
    this->rating = song.rating;
    this->progressionLength = song.progressionLength;
    this->variationPeriod = song.variationPeriod;
    this->numOfSimilarSongs = song.numOfSimilarSongs;
    this->chords = song.chords;

    this->mainChordProgression = new int[song.progressionLength];
    for (int i = 0; i < song.progressionLength; i++) {
        this->mainChordProgression[i] = song.mainChordProgression[i];
    }

    if (song.key == nullptr) {
        this->key = nullptr;
    } else {
        this->key = new char[strlen(song.key) + 1];
        strcpy(this->key, song.key);
    }

    this->ratingVariation = new float[song.variationPeriod];
    for (int i = 0; i < song.variationPeriod; i++) {
        this->ratingVariation[i] = song.ratingVariation[i];
    }

    this->similarSongs = new string[song.numOfSimilarSongs];
    for (int i = 0; i < song.numOfSimilarSongs; i++) {
        this->similarSongs[i] = song.similarSongs[i];
    }

    return *this;
}

ostream &Song::virtualPrint(ostream &out) const{
    out << "\nSong num: " << songNum;

    AudioRecording::virtualPrint(out);

    out << "\nKey: ";
    if (key != nullptr) {
        for (int i = 0; i < strlen(key); i++) {
            out << key[i];
        }
    } else {
        out << "nullptr";
    }

    out << "\nChords: ";
    for (auto chord:chords) {
        out << chord.getName() << " ";
    }

    out << "\nMain chord progression: ";
    if (mainChordProgression != nullptr) {
        for (int i = 0; i < progressionLength; i++) {
            out << mainChordProgression[i] << ", ";
        }
    } else {
        out << "nullptr";
    }

    out << "\nLiked: ";
    if (likedStatus) {
        out << "Yes";
    } else {
        out << "No";
    }

    out << "\nTier: " << tier;
    out << "\nRating: " << rating;
    out << "\nVariation period length: " << variationPeriod;
    out << "\nRating variation: ";

    if (ratingVariation != nullptr) {
        for (int i = 0; i < variationPeriod; i++) {
            out << ratingVariation[i] << ", ";
        }
    } else {
        out << "nullptr";
    }

    out << "\nNumber of similar songs: " << numOfSimilarSongs;
    out << "\nSimilar songs: ";
    if (similarSongs != nullptr) {
        for (int i = 0; i < numOfSimilarSongs; i++) {
            out << similarSongs[i] << ", ";
        }
    } else {
        out << "nullptr";
    }

    return out;
}

istream &Song::virtualRead(istream &in) {
    AudioRecording::virtualRead(in);

    cout << "\nKey: ";
    char temp[8];
    in >> temp;
    if (key != nullptr) {
        delete[] key;
    }
    key = new char[strlen(temp) + 1];
    strcpy(key, temp);

    cout << "\nProgression length: ";
    in >> progressionLength;
    cout << "\nMain chord progression";
    if (mainChordProgression != nullptr) {
        delete[] mainChordProgression;
    }
    mainChordProgression = new int[progressionLength];
    for (int i = 0; i < progressionLength; i++) {
        in >> mainChordProgression[i];
    }

    cout << "\nChords: ";
    for (int i = 0; i < progressionLength; i++) {
        Chord chord;
        cout << "\nChord " << i+1 << endl;
        in >> chord;
        chords.push_back(chord);
    }

    cout << "\nLiked(1/0): ";
    in >> likedStatus;
    cout << "\nTier: ";
    in >> tier;
    cout << "\nRating: ";
    in >> rating;

    cout << "\nVariation period(in months): ";
    in >> variationPeriod;
    cout << "\nRating variation: ";
    if (ratingVariation != nullptr) {
        delete[] ratingVariation;
    }
    ratingVariation = new float[variationPeriod];
    for (int i = 0; i < variationPeriod; i++) {
        in >> ratingVariation[i];
    }

    cout << "\nNumber of similar songs: ";
    in >> numOfSimilarSongs;
    cout << "\nSimilar songs: ";
    if (similarSongs != nullptr) {
        delete[] similarSongs;
    }
    similarSongs = new string[numOfSimilarSongs];
    for (int i = 0; i < numOfSimilarSongs; i++) {
        in >> similarSongs[i];
    }

    return in;
}

int &Song::operator[](int index) {
    if (index >= progressionLength) {
        throw invalid_argument("Progression not long enough");
    }

    return mainChordProgression[index];
}

Song &Song::operator++() {
    this->views++;
    return *this;
}

Song Song::operator++(int) {
    Song tmp(*this);
    this->views++;
    return tmp;
}

Song Song::operator+(const Song &song) {
    Song tempSong(*this);
    tempSong.length = song.length + this->length;

    return tempSong;
}

Song Song::operator-(const Song &song) {
    Song tempSong(*this);

    if (this->length < song.length) {
        throw invalid_argument("Resulting length is negative");
    }

    tempSong.length = this->length - song.length;
    return tempSong;
}

template<typename T>
bool Song::dynamicArraysAreEqual(T &arr1, T &arr2) {
    int length1 = sizeof(arr1) / sizeof(T);
    int length2 = sizeof(arr2) / sizeof(T);

    // Length 1 and 2 are 1 if arrays are empty. Just let them pass.
    if(length2 == 1 || length1 == 1) {
        return true;
    }

    if (length1 != length2)
        return false;

    for (int i = 0; i < length1; i++) {
        if (arr1[i] != arr2[i])
            return false;
    }

    return true;
}

bool operator==(const Song &song1, const Song &song2) {
     return song1.name == song2.name && song1.views == song2.views
           && song1.length == song2.length && song1.likedStatus == song2.likedStatus
           && song1.tier == song2.tier
           && song1.rating == song2.rating && song1.variationPeriod == song2.variationPeriod
           && song1.numOfSimilarSongs == song2.numOfSimilarSongs
           && Song::dynamicArraysAreEqual(song1.mainChordProgression, song2.mainChordProgression)
           && Song::dynamicArraysAreEqual(song1.ratingVariation, song2.ratingVariation)
           && Song::dynamicArraysAreEqual(song1.similarSongs, song2.similarSongs)
           && song1.chords == song2.chords
           && (strcmp(song1.key, song2.key) == 0);

}

/*
 * Helper function which returns a progression of chords based on premade progressions.
 */
void Song::createProgression(int &length, int *&progression, const int premadeProgression[],
                       map<int, Chord> keyMap, vector<Chord> &chords) {
    progression = new int[length];

    for (int i = 0; i < length; i++) {
        progression[i] = premadeProgression[i];
        Chord chord = keyMap[premadeProgression[i]];
        chords.push_back(chord);
    }
}

/*
 * Variation of previous helper function with different parameters.
 */
void Song::createProgression(Song &song, const int premadeProgression[], map<int, Chord> keyMap) {
    int *progression = new int[song.getProgressionLength()];

    for (int i = 0; i < song.getProgressionLength(); i++) {
        progression[i] = premadeProgression[i];
        Chord chord = keyMap[premadeProgression[i]];
        song.getChords().push_back(chord);
    }

    song.setMainChordProgression(progression, song.getProgressionLength());
    delete[] progression;
}

/*
 * Returns a randomly made song based on key and genre.
 * Generates all the chords of a given key, then selects the needed chords based on the selected
 * progression.
 */
Song Song::generateSong(string key, string tonality, string genre, int id) {
    Song song(id);
    map<int, Chord> keyMap = Chord::generateKeyChords(key, tonality);

    song.name = "Generic Song " + to_string(id);

    key = key + tonality;
    song.key = new char[key.length() + 1];
    strcpy(song.key, key.c_str());

    if (genre == JAZZ) {
        song.progressionLength = sizeof(JAZZ_PROGRESSION) / sizeof(int);
        createProgression(song, JAZZ_PROGRESSION, keyMap);
    }

    if (genre == CITY_POP) {
        song.progressionLength = sizeof(CITY_POP_PROGRESSION) / sizeof(int);
        createProgression(song.progressionLength, song.mainChordProgression, CITY_POP_PROGRESSION,
                          keyMap, song.chords);
    }

    if (genre == BLUES) {
        song.progressionLength = sizeof(BLUES_PROGRESSION) / sizeof(int);
        createProgression(song.progressionLength, song.mainChordProgression, BLUES_PROGRESSION,
                          keyMap, song.chords);
    }

    return song;
}

void Song::play() {
    cout << endl;
    for(Chord chord : chords) {
        cout << chord << " ";
    }
}

/*
 * TODO Method to change key of song.
 */