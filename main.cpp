#include <gtest/gtest.h>
#include "Stuffs/Note.h"
#include "Stuffs/TraditionalSong.h"
#include "Stuffs/Manelist.h"
using namespace std;

int main() {
    testing::InitGoogleTest();

    Note note1(36, 1);
    Note note2(32, 2);

    cout << "------------------------------------------------------------------------------------";
    note1.calculateInterval(note2);

//    TraditionalSong tradSong("Romania");
//    tradSong.openWikiLink();

//    Manelist manelist("Generic Manelist", {}, {}, 100, 99999);
//    manelist.playManea();
//
    return RUN_ALL_TESTS();
}