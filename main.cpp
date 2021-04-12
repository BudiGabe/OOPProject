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

    int num;
    cin >> num;
    AudioRecording** audios = new AudioRecording*[num];

    for(int i = 0; i < num; i++) {
        if(i % 3 == 0) {
            Song songTemp = Song::generateSong(Chord::allNotes[rand()%12], Chord::MINOR, Song::JAZZ, i);
            Song* song = new Song(songTemp);
            audios[i] = song;
        }

        if(i % 3 == 1) {
            Song songTemp = Song::generateSong(Chord::allNotes[rand()%12], Chord::MINOR, Song::JAZZ, i);
            Song* song = new Song(songTemp);
            audios[i] = song;
        }

        if(i % 3 == 2) {
            Podcast podcastTemp = Podcast::recordPodcast("GenericHost", "GenericGuest", rand()%180);
            Podcast* podcast = new Podcast(podcastTemp);
            audios[i] = podcast;
        }
    }

    for(int i = 0; i < num; i++) {
        audios[i]->play();
        cout << endl;
    }

    return RUN_ALL_TESTS();
}