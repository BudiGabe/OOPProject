#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include "Chord.h"
#include "AudioRecording.h"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Song: public AudioRecording
{
protected:
	const int songNum;
	char* key = nullptr;
	int progressionLength = 0;
	int* mainChordProgression = nullptr;
	bool likedStatus;
	char tier;
	float rating;
	int variationPeriod = 0;
	float* ratingVariation = nullptr;
	int numOfSimilarSongs = 0;
	string* similarSongs = nullptr;
    vector<Chord> chords;

    template <typename T>
    static bool dynamicArraysAreEqual(T &x, T &y);
    static void createProgression(int &length, int *&progression, const int premadeProgression[],
                           map<int, Chord> keyMap, vector<Chord> &chords);

    static void createProgression(Song &song, const int premadeProgression[], map<int, Chord> keyMap);

public:
	const static string JAZZ;
	const static string CITY_POP;
	const static string BLUES;
	const static vector<string> GENRES;
	const static int JAZZ_PROGRESSION[];
	const static int CITY_POP_PROGRESSION[];
	const static int BLUES_PROGRESSION[];

	Song(int length, string name, int num, char* key, int* mainChordProgression, int progressionLength,
		double views, vector<Chord> chords);
        Song(string name="", vector<Chord> chords={}, int length=0, int* mainChordProgression=nullptr,
            int progressionLength=0, bool likedStatus=false, char tier='F', char* key=nullptr, float rating=0,
            float* ratingVariation=nullptr, int variationPeriod=0, double views=0, string* similarSongs=nullptr,
            int numOfSimilarSongs=0, int num=-1);
	Song(int num);
	Song(const Song& song);
	~Song();

	bool getLikedStatus() { return likedStatus; }
	void setLikedStatus(bool status) { likedStatus = status; }

	char getTier() { return tier; }
	void setTier(char newTier) { tier = newTier; }

	float getRating() { return rating; }
	void setRating(float rating) { this->rating = rating; }

	int getSongNum() { return songNum; }

	int getProgressionLength() { return progressionLength; }
	void setProgressionLength(int length) { progressionLength = length; }

	int getVariationPeriod() { return variationPeriod; }
	void setVariationPeriod(int period) { variationPeriod = period; }

	int getNumOfSimilarSongs() { return numOfSimilarSongs; }
	void setNumOfSimilarSongs(int num) { numOfSimilarSongs = num; }

	int* getMainChordProgression() { return this->mainChordProgression; }
	void setMainChordProgression(int* chordProgression, int length);

	float* getRatingVariation() { return this->ratingVariation; }
	void setRatingVariation(float* variation, int period);

	string* getSimilarSongs() { return this->similarSongs; }
	void setSimilarSongs(string* songs, int num);

	char* getKey() { return key; };
	void setKey(char* newKey);

	vector<Chord>& getChords() { return chords; }
	void setChords(const vector<Chord>& newChords) { chords = newChords; }

	Song& operator =(const Song& song);
    virtual ostream& virtualPrint(ostream& out)const;
    virtual istream& virtualRead (istream& in);
	int& operator[](int index);
	Song& operator++();
	Song operator++(int);
	Song operator+(const Song& song);
	Song operator-(const Song& song);
	operator string() const { return name; }
	friend bool operator<(const Song& song1, const Song& song2) { return song1.views < song2.views; }
	friend bool operator==(const Song& song1, const Song& song2);

	static Song generateSong(string key, string tonality, string genre, int id);
	void play();
};

