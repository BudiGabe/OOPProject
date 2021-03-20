#include "Chord.h"

const vector<string> Chord::allNotes = { "A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#" };
map<string, string> Chord::relatives = { 
	{"Cbmaj", "Abm"},
	{"Gbmaj", "Ebm"},
	{"Dbmaj", "Bbm"},
	{"Abmaj", "Fm"},
	{"Ebmaj", "Cm"},
	{"Bbmaj", "Gm"},
	{"Fmaj", "Dm"},
	{"Cmaj", "Am"},
	{"Gmaj", "Em"},
	{"Dmaj", "Bm"},
	{"Amaj", "F#m"},
	{"Emaj", "C#m"},
	{"Bmaj", "G#m"},
	{"F#maj", "D#m"},
	{"C#maj", "A#m"}
};
const string Chord::ROOT = "P1";
const string Chord::MINOR_THIRD = "m3";
const string Chord::MAJOR_THIRD = "M3";
const string Chord::PERFECT_FIFTH = "P5";
const string Chord::TRITONE = "TT";
const string Chord::MINOR = "minor";
const string Chord::MINOR_SHORTENED = "m";
const string Chord::MAJOR = "major";
const string Chord::MAJOR_SHORTENED = "maj";
const string Chord::DIMINISHED = "diminished";
const string Chord::DIMINISHED_SHORTENED = "dim";
const string Chord::MAJOR_KEY[] = { "maj", "m", "m", "maj", "maj", "m", "dim" };
const string Chord::MINOR_KEY[] = { "m", "dim", "maj", "m", "m", "maj", "maj" };

Chord::Chord() {
	name = "Generic Chord Name";
	notes = {};
	intervals = {};
}

Chord::Chord(string name, vector<string> notes, vector<string> intervals) {
	this->name = name;
	this->notes = notes;
	this->intervals = intervals;
}

Chord::Chord(string name, vector<string> notes) {
	this->name = name;
	this->notes = notes;
	this->intervals = {};
}

Chord::Chord(const Chord& chord) {
	name = chord.name;
	notes = chord.notes;
	intervals = chord.intervals;
}

Chord::~Chord(){}

Chord& Chord::operator=(const Chord& chord) {
	if (this == &chord) {
		return *this;
	}

	this->name = chord.name;
	this->notes = chord.notes;
	this->intervals = chord.intervals;

	return *this;
}

ostream& operator <<(ostream& out, const Chord& chord) {
	out << "\nChord name: " << chord.name;

	out << "\nNotes: ";
	for (auto i = chord.notes.begin(); i < chord.notes.end(); i++){
		out << *i << ", ";
	}

	out << "\nIntervals: ";
	for (auto i = chord.intervals.begin(); i < chord.intervals.end(); i++){
		out << *i << ", ";
	}

	return out;
}

istream& operator >>(istream& in, Chord& chord) {
	cout << "\nChord name: ";
	in >> chord.name;

	cout << "\nHow many notes are in your chord?: ";
	int noteCount;
	in >> noteCount;

	cout << "\nNotes: ";
	string note;
	for (int i = 0; i < noteCount; i++) {
		in >> note;
		chord.notes.push_back(note);
	}

	cout << "\nIntervals: ";
	string interval;
	for (int i = 0; i < noteCount; i++) {
		in >> interval;
		chord.intervals.push_back(interval);
	}

	return in;
}

string& Chord::operator[](int index) {
	if (index > notes.size()) {
        throw invalid_argument("Array out of bounds");
	}

	return notes[index];
}


/*
 * ++ operator will repeat the last note of a chord.
 */
Chord Chord::operator++() {
	this->notes.push_back(notes[notes.size() - 1]);
	this->intervals.push_back(intervals[intervals.size() - 1]);
	return *this;
}

Chord Chord::operator++(int) {
	Chord temp(*this);

	this->notes.push_back(notes[notes.size() - 1]);
	this->intervals.push_back(intervals[intervals.size() - 1]);

	return temp;
}

/*
 * Operator will merge 2 chords, with notes and intervals.
 */
Chord Chord::operator+(const Chord& chord) {
	Chord tempChord;

	tempChord.notes.insert(tempChord.notes.end(), this->notes.begin(), this->notes.end());
	tempChord.notes.insert(tempChord.notes.end(), chord.notes.begin(), chord.notes.end());

	tempChord.intervals.insert(tempChord.intervals.end(), this->intervals.begin(), this->intervals.end());
	tempChord.intervals.insert(tempChord.intervals.end(), chord.intervals.begin(), chord.intervals.end());

	return tempChord;
}

/*
 * Operator / will no longer do the usual arithmetic operation.
 * Instead, it will form slash chords(e.g. C/D);
 */
Chord Chord::operator/(const Chord& chord) {
	Chord tempChord;

	tempChord.notes.insert(tempChord.notes.begin(), chord.notes.front());
	tempChord.notes.insert(tempChord.notes.end(), this->notes.begin(), this->notes.end());

	return tempChord;
}

/*
 * Operator < will no longer do the usual binary operation.
 * Instead, it verifies if the left chord is the major relative
 * of the right chord.
 */
bool operator<(const Chord& chord1, const Chord& chord2) {
	string name1 = chord1.name;
	string name2 = chord2.name;

	string relMinor = Chord::relatives[name1];

	return (name2 == relMinor);
}

bool operator==(const Chord& chord1, const Chord& chord2) {
    return chord1.name == chord2.name
        && chord1.notes == chord2.notes
        && chord1.intervals == chord2.intervals;

}

int Chord::getRootPosition(string root) {
	auto it = find(Chord::allNotes.begin(), Chord::allNotes.end(), root);

	if (it != Chord::allNotes.end()) {
		int rootIndex = it - Chord::allNotes.begin();
		return rootIndex;
	}
	else {
		throw invalid_argument("Root does not exist");
	}
}

void Chord::generateTriadAttributes(int rootIndex, int& thirdIndex, int semitonesThird, string& triadName,
	string tonality, vector<string>& triadIntervals, string third, int& fifthIndex, int semitonesFifth) {
	thirdIndex = (rootIndex + semitonesThird) % 12;
	fifthIndex = (rootIndex + semitonesFifth) % 12;

	triadName = triadName + tonality;
	triadIntervals.insert(triadIntervals.end() - 1, third);

	if (tonality == Chord::DIMINISHED_SHORTENED) {
		triadIntervals[2] = Chord::TRITONE;
	}
}

/*
 * Generates any triad based on root note and tonality.
 * It finds the root position of the triad, then inserts in our chord the second and third notes
 * based on the selected tonality.
 *
 * Example input: C minor
 * Returns an object with the following attributes:
 * triadName: Cm
 * notes: C, D#, G
 * intervals: P1, m3, P5
 */
Chord Chord::getTriad(string root, string tonality) {
	Chord triad;
	string triadName = root;
	vector<string> triadIntervals = {ROOT, PERFECT_FIFTH};

	int rootIndex = getRootPosition(root);
	int thirdIndex;
	int fifthIndex;

	if (tonality == MINOR || tonality == MINOR_SHORTENED) {
		generateTriadAttributes(rootIndex, thirdIndex, THREE_SEMITONES, triadName, MINOR_SHORTENED, triadIntervals,
			MINOR_THIRD, fifthIndex, SEVEN_SEMITONES);
	}
	
	if(tonality == MAJOR || tonality == MAJOR_SHORTENED){
		generateTriadAttributes(rootIndex, thirdIndex, FOUR_SEMITONES, triadName, MAJOR_SHORTENED, triadIntervals, 
			MAJOR_THIRD, fifthIndex, SEVEN_SEMITONES);
	}

	if (tonality == DIMINISHED || tonality == DIMINISHED_SHORTENED) {
		generateTriadAttributes(rootIndex, thirdIndex, THREE_SEMITONES, triadName, DIMINISHED_SHORTENED, triadIntervals, 
			MINOR_THIRD, fifthIndex, SIX_SEMITONES);
	}

	triad.notes.push_back(Chord::allNotes[rootIndex]);
	triad.notes.push_back(Chord::allNotes[thirdIndex]);
	triad.notes.push_back(Chord::allNotes[fifthIndex]);
	triad.name = triadName;
	triad.intervals = triadIntervals;

	return triad;
}

/*
 * Helper function to insert chord in our keyMap.
 */
void Chord::insertChord(int keyIndex, int rootIndex, string tonality, map<int, Chord>& keyMap) {
	if (tonality == Chord::MAJOR || tonality == Chord::MAJOR_SHORTENED) {
		keyMap.insert({ keyIndex + 1, Chord::getTriad(Chord::allNotes[rootIndex], Chord::MAJOR_KEY[keyIndex]) });
	}
	else {
		keyMap.insert({ keyIndex + 1, Chord::getTriad(Chord::allNotes[rootIndex], Chord::MINOR_KEY[keyIndex]) });
	}
}

/*
 * Helper function which advances our Chord root note based on the tonality of the key.
 */
void Chord::advanceRoot(string tonality, int& rootIndex, int keyIndex) {
	if (tonality == Chord::MAJOR || tonality == Chord::MAJOR_SHORTENED) {
		if (keyIndex == 2) {
			rootIndex = (rootIndex + Chord::HALF_STEP) % 12;
		}
		else {
			rootIndex = (rootIndex + Chord::WHOLE_STEP) % 12;
		}
	}
	else {
		if (keyIndex == 1 || keyIndex == 4) {
			rootIndex = (rootIndex + Chord::HALF_STEP) % 12;
		}
		else {
			rootIndex = (rootIndex + Chord::WHOLE_STEP) % 12;
		}
	}
}

/*
 * Generates all the chords in a given key.
 */
map<int, Chord> Chord::generateKeyChords(string root, string tonality) {
	map<int, Chord> keyMap;
	int rootIndex = getRootPosition(root);
	int keyIndex = 0;

	while (keyIndex < 7) {
		insertChord(keyIndex, rootIndex, tonality, keyMap);
		advanceRoot(tonality, rootIndex, keyIndex);
		keyIndex++;
	}

	return keyMap;
}

/*
 * TODO Increase or decrease by x num of steps.
 */