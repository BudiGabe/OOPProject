// PooProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stuffs/Song.h"
#include "Stuffs/Chord.h"
#include "Stuffs/Podcast.h"
#include "Stuffs/Artist.h"
#include <gtest/gtest.h>

using namespace std;

int main() {
    testing::InitGoogleTest();
    int chordProgression[] = { 2, 5, 1 };
    float ratingVariation[] = {1.2, 3.4, 4.5};
    string similarSongs[] = {"asd", "sdf", "dfg" };
    char key[] = { "C" };

    string tonality = "m";
    vector<string> notes{ "C","D#","G" };
    vector<string> notes2{ "D", "F#", "A" };
    vector<string> notesFMajor{ "F, A, C" };
    vector<string> minorIntervals{ "P1", "m3", "P5" };
    vector<string> majorIntervals{ "P1", "M3", "P5" };
    string name = "C minor";
    string name2 = "D minor";
    string nameFMajor = "F major";

    Chord cMinor(name, notes, minorIntervals);
    Chord dMinor(name2, notes2, minorIntervals);
    Chord fMajor(nameFMajor, notesFMajor, majorIntervals);

    vector<Chord> chords;
    chords.push_back(cMinor);
    chords.push_back(dMinor);
    chords.push_back(fMajor);

    Song song(200, chordProgression, 3, true, 'S', key, 4, ratingVariation,
              3, 100,"Generic Song Name", similarSongs, 3, 0, chords);
    //map<int, Chord> keyMap = Chord::generateKeyChords("C", "major");
    vector<Song> songs;
    songs.push_back(song);

    Podcast podcast(100, name, name2, { "asd", "sdf" });
    Podcast podcast2(200, nameFMajor, name, {"topic1", "topic2"});
    Podcast podcast3(300, name2, name, {"topic3", "topic4"});

    vector<Podcast> podcasts;
    podcasts.push_back(podcast);
    podcasts.push_back(podcast2);
    podcasts.push_back(podcast3);

    Artist artist1(name, songs, podcasts, 100);
    Artist artist2(name, songs, podcasts, 200);



    cout << Artist::generateArtist("name", 100);
    return RUN_ALL_TESTS();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
