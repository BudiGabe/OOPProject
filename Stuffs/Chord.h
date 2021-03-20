#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;

class Chord
{
private:
	string name;
	vector<string> notes;
	vector<string> intervals;

    static int getRootPosition(string root);
    static void generateTriadAttributes(int rootIndex, int& thirdIndex, int semitonesThird, string& triadName,
                                 string tonality, vector<string>& triadIntervals, string third, int& fifthIndex, int semitonesFifth);
    static void insertChord(int keyIndex, int rootIndex, string tonality, map<int, Chord>& keyMap);
    static void advanceRoot(string tonality, int& rootIndex, int keyIndex);
public:
	static map<string, string> relatives;
	const static vector<string> allNotes;
	const static string MAJOR_KEY[];
	const static string MINOR_KEY[];
	const static int SIX_SEMITONES = 6;
	const static int SEVEN_SEMITONES = 7;
	const static int THREE_SEMITONES = 3;
	const static int FOUR_SEMITONES = 4;
	const static int WHOLE_STEP = 2;
	const static int HALF_STEP = 1;
	const static string ROOT;
	const static string MINOR_THIRD;
	const static string MAJOR_THIRD;
	const static string PERFECT_FIFTH;
	const static string TRITONE;
	const static string MINOR;
	const static string MINOR_SHORTENED;
	const static string MAJOR;
	const static string MAJOR_SHORTENED;
	const static string DIMINISHED;
	const static string DIMINISHED_SHORTENED;

	Chord();
	Chord(string name, vector<string> notes, vector<string> intervals);
	Chord(string name, vector<string> notes);
	Chord(const Chord& chord);
	~Chord();

	string getName() const { return name; }
	void setName(string newName) { name = newName; }

	vector<string> getNotes() const { return notes; }
	void setNotes(const vector<string>& newNotes) { notes = newNotes; }
	
	vector<string> getIntervals() const { return intervals; }
	void setIntervals(vector<string> newIntervals) { intervals = move(newIntervals); }

	Chord& operator=(const Chord& chord);
	friend ostream& operator <<(ostream& out, const Chord& chord);
	friend istream& operator >>(istream& in, Chord& chord);
	string& operator[](int index);
	Chord operator++();
	Chord operator++(int);
	Chord operator+(const Chord& chord);
	Chord operator/(const Chord& chord);
	operator vector<string>() const { return notes; };
	friend bool operator<(const Chord& chord1, const Chord& chord2);
	friend bool operator==(const Chord& chord1, const Chord& chord2);


	static Chord getTriad(string root, string tonality);
	static map<int, Chord> generateKeyChords(string key, string tonality);
};

