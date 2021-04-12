#include <gtest/gtest.h>
#include "Stuffs/Note.h"
#include "Stuffs/TraditionalSong.h"
#include "Stuffs/Manelist.h"
#include "Stuffs/AudioRecording.h"

using namespace std;

int main() {
    testing::InitGoogleTest();

//    Note note1(36, 1);
//    Note note2(32, 2);
//    cout << "------------------------------------------------------------------------------------";
//    note1.calculateInterval(note2);

//    TraditionalSong tradSong("Romania");
//    tradSong.openWikiLink();

//    Manelist manelist("Generic Manelist", {}, {}, 100, 99999);
//    manelist.playManea();
    const string E_MAJOR_NAME = "Emaj";
    const string A_MAJOR_NAME = "Amaj";
    const string D_MAJOR_NAME = "Dmaj";
    const vector<string> NOTES_A_MAJOR{ "A", "C#", "E"};
    const vector<string> NOTES_D_MAJOR{ "D", "F#", "A"};
    const vector<string> NOTES_E_MAJOR{ "E", "G#", "B"};
    const vector<string> NOTES_B_MINOR{ "B", "D", "F#"};
    const vector<string> NOTES_E_MINOR{ "E", "G", "B" };
    const vector<string> NOTES_FSHARP_DIMINISHED{ "F#", "A", "C"};
    const vector<string> MINOR_INTERVALS{ "P1", "m3", "P5" };
    const vector<string> MAJOR_INTERVALS{ "P1", "M3", "P5" };
    const vector<string> DIMINISHED_INTERVALS{"P1", "m3", "TT"};
    int CHORD_PROGRESSION_BLUES[3] = { 1, 4, 5 };
    int CHORD_PROGRESSION_JAZZ[3] = { 2, 5, 1 };

    Chord aMajor(A_MAJOR_NAME, NOTES_A_MAJOR, MAJOR_INTERVALS);
    Chord dMajor(D_MAJOR_NAME, NOTES_D_MAJOR, MAJOR_INTERVALS);
    Chord eMajor(E_MAJOR_NAME, NOTES_E_MAJOR, MAJOR_INTERVALS);
    Chord fSDim("F#dim", NOTES_FSHARP_DIMINISHED, DIMINISHED_INTERVALS);
    Chord bMinor("Bm", NOTES_B_MINOR, MINOR_INTERVALS);
    Chord eMinor("Em", NOTES_E_MINOR, MINOR_INTERVALS);

    vector<Chord> chords;

    chords.push_back(aMajor);
    chords.push_back(dMajor);
    chords.push_back(eMajor);
    Song song1(0, "Song1", 1, nullptr, CHORD_PROGRESSION_BLUES, 3, 0, chords);
    chords.clear();


    chords.push_back(fSDim);
    chords.push_back(bMinor);
    chords.push_back(eMinor);
    Song song2(0, "Generic Song 5", -1, "Em", CHORD_PROGRESSION_JAZZ, 3, 0, chords);
    chords.clear();

    Podcast podcast1(122, "ARTIST_NAME", "Teo", {"Feminism", "Contrabas", "Global warming",
                                               "Youtube algorithm", "Stand-up", "Acordeon", "Video games"});
    Podcast podcast2(157, "ARTIST_NAME", "Dan Avidan", {"Stand-up", "Global warming", "Neo-nazism", "Manele", "Cobza",
                                                      "Video games", "Dad jokes", "Books", "Feminism", "Youtube algorithm"});

    AudioRecording** audios = new AudioRecording*[4];
    audios[0] = &song1;
    audios[1] = &song2;
    audios[2] = &podcast1;
    audios[3] = &podcast2;

    for(int i = 0; i < 4; i++) {
        audios[i]->play();
    }
    return RUN_ALL_TESTS();
}