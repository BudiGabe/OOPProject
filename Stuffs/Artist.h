#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Song.h"
#include "Podcast.h"
#include "RandomHelper.h"

using namespace std;

class Artist
{
protected:
	string name;
	vector<Song> songs;
	vector<Podcast> podcasts;
	int followers;
	
public:
	Artist();
	Artist(string name, vector<Song> songs, vector<Podcast> podcasts, int followers);
	Artist(string name, int followers);
	Artist(const Artist& artist);
	~Artist();
	Artist& operator=(const Artist& artist);
	virtual ostream& virtualPrint(ostream& out) const;
	virtual istream& virtualRead(istream& in);
	friend ostream& operator <<(ostream& out, const Artist& artist);
	friend istream& operator >>(istream& in, Artist& artist);
    Song& operator[](int index);
    Artist& operator++();
    Artist operator++(int);
    Artist operator+(const Artist& artist);
    Artist operator-(const Artist& artist);
    operator string() const { return name; }
    friend bool operator <(const Artist& artist1, const Artist& artist2) { return artist1.followers < artist2.followers; }
    friend bool operator ==(const Artist& artist1, const Artist& artist2);

    static Artist generateArtist(const string& name, int followers);
};