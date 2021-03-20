#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include "Chord.h"
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Song
{
private:
	const int songNum;
	string name;
	double views;
	int length;
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

	Song();
	Song(int length, string name, int num, char* key, int* mainChordProgression, int progressionLength,
		double views, vector<Chord> chords);
	Song(int length, int* mainChordProgression, int progressionLength, bool likedStatus,
		char tier, char* key, float rating, float* ratingVariation, int variationPeriod,
		double views, string name, string* similarSongs, int numOfSimilarSongs,
		int num, vector<Chord> chords);
	Song(int num);
	Song(const Song& song);
	~Song();

	int getLength() { return length; }
	void setLength(int value) { length = value; }

	bool getLikedStatus() { return likedStatus; }
	void setLikedStatus(bool status) { likedStatus = status; }

	char getTier() { return tier; }
	void setTier(char newTier) { tier = newTier; }

	float getRating() { return rating; }
	void setRating(float rating) { this->rating = rating; }

	double getViews() { return views; }
	void setViews(double value) { views = value; }

	int getSongNum() { return songNum; }

	string getName() { return name; }
	void setName(string newName) { name = newName; }

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
	friend ostream& operator <<(ostream& out, const Song& song);
	friend istream& operator >>(istream& in, Song& song);
	int& operator[](int index);
	Song& operator++();
	Song operator++(int);
	Song operator+(const Song& song);
	Song operator-(const Song& song);
	operator string() const { return name; }
	friend bool operator<(const Song& song1, const Song& song2) { return song1.views < song2.views; }
	friend bool operator==(const Song& song1, const Song& song2);

	static Song generateSong(string key, string tonality, string genre, int id);
};

