#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "RandomHelper.h"

using namespace std;

class Podcast
{
private:
	// In minutes
	int length;
	string host;
	string guest;
	vector<string> topics;

public:
	const static vector<string> ALL_TOPICS;
    const static vector<string> GUESTS;
    const static int TOPIC_LENGTH = 15;
	Podcast();
	Podcast(int length, string host, string guest, vector<string> topics);
	Podcast(int length, string host, string guest);
	Podcast(const Podcast& podcast);
	~Podcast();

	int getLength() const { return length; }
	void setLength(int newLength) { length = newLength; }

	string getHost() const { return host; }
	void setHost(string newHost) { host = newHost; }

	string getGuest() const { return guest; }
	void setGuest(string newGuest) { guest = newGuest; }

	vector<string> getTopics() const { return topics; }
	void setTopics(vector<string>& newTopics) { topics = newTopics; }

	Podcast& operator=(const Podcast& podcast);
	friend ostream& operator <<(ostream& out, const Podcast& podcast);
	friend istream& operator >>(istream& in, Podcast& podcast);
	string& operator[](int index);
	Podcast& operator ++();
	Podcast operator ++(int);
	Podcast operator +(const Podcast& podcast);
	Podcast operator -(const Podcast& podcast);
	operator vector<string>() const { return topics; }
	friend bool operator <(const Podcast& podcast1, const Podcast& podcast2);
	friend bool operator ==(const Podcast& podcast1, const Podcast& podcast2);

	static Podcast recordPodcast(string host, string guest, int length);
};

