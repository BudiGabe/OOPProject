#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "RandomHelper.h"

using namespace std;

class Podcast: public AudioRecording
{
private:
	string host;
	string guest;
	vector<string> topics;

public:
	const static vector<string> ALL_TOPICS;
    const static vector<string> GUESTS;
    const static int TOPIC_LENGTH = 15;
	Podcast();
	Podcast(int length, string host, string guest, vector<string> topics);
    Podcast(string name, int length, double views, string host, string guest, vector<string> topics);
    Podcast(int length, string host, string guest);
	Podcast(const Podcast& podcast);
	~Podcast();

	string getHost() const { return host; }
	void setHost(string newHost) { host = newHost; }

	string getGuest() const { return guest; }
	void setGuest(string newGuest) { guest = newGuest; }

	vector<string> getTopics() const { return topics; }
	void setTopics(vector<string>& newTopics) { topics = newTopics; }

	Podcast& operator=(const Podcast& podcast);
	ostream& virtualPrint(ostream& out)const;
	istream& virtualRead(istream& in);
	string& operator[](int index);
	Podcast& operator ++();
	Podcast operator ++(int);
	Podcast operator +(const Podcast& podcast);
	Podcast operator -(const Podcast& podcast);
	operator vector<string>() const { return topics; }
	friend bool operator <(const Podcast& podcast1, const Podcast& podcast2);
	friend bool operator ==(const Podcast& podcast1, const Podcast& podcast2);

	static Podcast recordPodcast(string host, string guest, int length);
	void play();
};

