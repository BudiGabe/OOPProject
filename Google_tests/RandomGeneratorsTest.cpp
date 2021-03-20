
#include "gtest/gtest.h"
#include "../Stuffs/RandomHelper.h"
#include "../Stuffs/Artist.h"


class RandomGeneratorsTestFixture: public ::testing::Test {
protected:
    const string HOST = "Host";
    const string GUEST = "Guest";
    const string ARTIST_NAME = "Name";
    const size_t SEED = 42;
    const int FOLLOWERS = 100;
    const int LENGTH = 100;
    const vector<string> RANDOM_TOPICS = { "Youtube algorithm", "Contrabas", "Video games", "Stand-up", "Tambal"};
    int CHORD_PROGRESSION_JAZZ[3] = { 2, 5, 1 };
    int CHORD_PROGRESSION_CITYPOP[4] = { 4, 5, 3, 6 };
    int CHORD_PROGRESSION_BLUES[3] = { 1, 4, 5 };
    const string C_MINOR_NAME = "Cm";
    const string D_DIM_NAME = "Ddim";
    const string F_MAJOR_NAME = "Fmaj";
    const string F_DIMINISHED_NAME = "Fdim";
    const string E_MINOR_NAME = "Em";
    const string E_MAJOR_NAME = "Emaj";
    const string C_MAJOR_NAME = "Cmaj";
    const string G_MINOR_NAME = "Gm";
    const string G_MAJOR_NAME = "Gmaj";
    const string D_MINOR_NAME = "Dm";
    const string D_MAJOR_NAME = "Dmaj";
    const string A_MINOR_NAME = "Am";
    const string A_MAJOR_NAME = "Amaj";
    const string B_MINOR_NAME = "Bm";
    const string ASHARP_MAJOR_NAME = "A#maj";
    const string ASHARP_MINOR_NAME = "A#m";
    const string ASHARP_DIMINISHED_NAME = "A#dim";
    const string FSHARP_MAJOR_NAME = "F#maj";
    const string FSHARP_MINOR_NAME = "F#m";
    const string CSHARP_MINOR_NAME = "C#m";
    const string GSHARP_MINOR_NAME = "G#m";
    const string GSHARP_MAJOR_NAME = "G#maj";
    const string FSHARP_DIMINISHED_NAME = "F#dim";
    const string DSHARP_MINOR_NAME = "D#m";
    const vector<string> NOTES_C_MINOR{ "C","D#","G" };
    const vector<string> NOTES_F_MAJOR{ "F", "A", "C" };
    const vector<string> NOTES_F_DIMINISHED{ "F", "G#", "B"};
    const vector<string> NOTES_D_DIM{ "D", "F", "G#" };
    const vector<string> NOTES_D_MINOR{ "D", "F", "A" };
    const vector<string> NOTES_D_MAJOR{ "D", "F#", "A"};
    const vector<string> NOTES_E_MINOR{ "E", "G", "B" };
    const vector<string> NOTES_E_MAJOR{ "E", "G#", "B"};
    const vector<string> NOTES_C_MAJOR{ "C", "E", "G" };
    const vector<string> NOTES_G_MINOR{ "G", "A#", "D"};
    const vector<string> NOTES_G_MAJOR{ "G", "B", "D"};
    const vector<string> NOTES_A_MINOR{ "A", "C", "E" };
    const vector<string> NOTES_A_MAJOR{ "A", "C#", "E"};
    const vector<string> NOTES_B_MINOR{ "B", "D", "F#"};
    const vector<string> NOTES_FSHARP_MAJOR{ "F#", "A#", "C#"};
    const vector<string> NOTES_FSHARP_MINOR{ "F#", "A", "C#"};
    const vector<string> NOTES_FSHARP_DIMINISHED{ "F#", "A", "C"};
    const vector<string> NOTES_ASHARP_MAJOR{ "A#", "D", "F"};
    const vector<string> NOTES_ASHARP_MINOR{ "A#", "C#", "F"};
    const vector<string> NOTES_ASHARP_DIMINISHED{ "A#", "C#", "E"};
    const vector<string> NOTES_CSHARP_MINOR{ "C#", "E", "G#" };
    const vector<string> NOTES_GSHARP_MINOR{ "G#", "B", "D#"};
    const vector<string> NOTES_GSHARP_MAJOR{ "G#", "B", "E"};
    const vector<string> NOTES_DSHARP_MINOR{ "D#", "F#", "A#"};
    const vector<string> MINOR_INTERVALS{ "P1", "m3", "P5" };
    const vector<string> MAJOR_INTERVALS{ "P1", "M3", "P5" };
    const vector<string> DIMINISHED_INTERVALS{"P1", "m3", "TT"};
public:
    void SetUp( ) {
        RandomHelper::setSeed(SEED);
    }

    void TearDown( ) {

    }
};

TEST_F(RandomGeneratorsTestFixture, RandomAudioTest) {
    ASSERT_EQ(RandomHelper::getRandomNumberOfAudio(), 8);
}

TEST_F(RandomGeneratorsTestFixture, RandomKeyTest) {
    ASSERT_EQ(RandomHelper::getRandomKey(), "F#");
}

TEST_F(RandomGeneratorsTestFixture, RandomTonalityTest) {
    ASSERT_EQ(RandomHelper::getRandomTonality(), "maj");
}

TEST_F(RandomGeneratorsTestFixture, RandomGenreTest) {
    ASSERT_EQ(RandomHelper::getRandomGenre(), "Blues");
}

TEST_F(RandomGeneratorsTestFixture, RandomGuestTest) {
    ASSERT_EQ(RandomHelper::getRandomGuest(), "Vio");
}

TEST_F(RandomGeneratorsTestFixture, RandomLengthTest) {
    ASSERT_EQ(RandomHelper::getRandomLength(), 150);
}

TEST_F(RandomGeneratorsTestFixture, RandomTopicTest) {
    ASSERT_EQ(RandomHelper::getRandomTopic(), "Youtube algorithm");
}

TEST_F(RandomGeneratorsTestFixture, RandomPodcastGeneratorTest) {
    Podcast actualPodcast = Podcast::recordPodcast(HOST, GUEST, LENGTH);
    Podcast expectedPodcast(100, HOST, GUEST, RANDOM_TOPICS);

    ASSERT_EQ(actualPodcast, expectedPodcast);
}

TEST_F(RandomGeneratorsTestFixture, RandomArtistGeneratorTest) {
    vector<Chord> chords;
    Artist actualArtist = Artist::generateArtist(ARTIST_NAME, FOLLOWERS);

    Chord bMinor(B_MINOR_NAME, NOTES_B_MINOR, MINOR_INTERVALS);
    Chord eMinor(E_MINOR_NAME, NOTES_E_MINOR, MINOR_INTERVALS);
    Chord fSMinor(FSHARP_MINOR_NAME, NOTES_FSHARP_MINOR, MINOR_INTERVALS);
    Chord gMinor(G_MINOR_NAME, NOTES_G_MINOR, MINOR_INTERVALS);
    Chord aMinor(A_MINOR_NAME, NOTES_A_MINOR, MINOR_INTERVALS);
    Chord fMajor(F_MAJOR_NAME, NOTES_F_MAJOR, MAJOR_INTERVALS);
    Chord aSMajor(ASHARP_MAJOR_NAME, NOTES_ASHARP_MAJOR, MAJOR_INTERVALS);
    Chord cSMinor(CSHARP_MINOR_NAME, NOTES_CSHARP_MINOR, MINOR_INTERVALS);
    Chord gSMinor(GSHARP_MINOR_NAME, NOTES_GSHARP_MINOR, MINOR_INTERVALS);
    Chord dMinor(D_MINOR_NAME, NOTES_D_MINOR, MINOR_INTERVALS);
    Chord dMajor(D_MAJOR_NAME, NOTES_D_MAJOR, MAJOR_INTERVALS);
    Chord gMajor(G_MAJOR_NAME, NOTES_G_MAJOR, MAJOR_INTERVALS);
    Chord eMajor(E_MAJOR_NAME, NOTES_E_MAJOR, MAJOR_INTERVALS);
    Chord aMajor(A_MAJOR_NAME, NOTES_A_MAJOR, MAJOR_INTERVALS);
    Chord cMajor(C_MAJOR_NAME, NOTES_C_MAJOR, MAJOR_INTERVALS);
    Chord fSDim(FSHARP_DIMINISHED_NAME, NOTES_FSHARP_DIMINISHED, DIMINISHED_INTERVALS);
    Chord fDim(F_DIMINISHED_NAME, NOTES_F_DIMINISHED, DIMINISHED_INTERVALS);
    Chord aSMinor(ASHARP_MINOR_NAME, NOTES_ASHARP_MINOR, MINOR_INTERVALS);
    Chord dSMinor(DSHARP_MINOR_NAME, NOTES_DSHARP_MINOR, MINOR_INTERVALS);
    Chord aSDim(ASHARP_DIMINISHED_NAME, NOTES_ASHARP_DIMINISHED, DIMINISHED_INTERVALS);
    Chord fSMajor(FSHARP_MAJOR_NAME, NOTES_FSHARP_MAJOR, MAJOR_INTERVALS);

    chords.push_back(eMajor);
    chords.push_back(fSMajor);
    chords.push_back(dSMinor);
    chords.push_back(gSMinor);
    Song song1(0, "Generic Song 0", -1, "Bmaj", CHORD_PROGRESSION_CITYPOP, 4, 0, chords);
    chords.clear();

    chords.push_back(gMinor);
    chords.push_back(aMinor);
    chords.push_back(fMajor);
    chords.push_back(aSMajor);
    Song song2(0, "Generic Song 1", -1, "Dm", CHORD_PROGRESSION_CITYPOP, 4, 0, chords);
    chords.clear();

    chords.push_back(fSMinor);
    chords.push_back(gSMinor);
    chords.push_back(eMajor);
    chords.push_back(aMajor);
    Song song3(0, "Generic Song 2", -1, "C#m", CHORD_PROGRESSION_CITYPOP, 4, 0, chords);
    chords.clear();

    chords.push_back(aMajor);
    chords.push_back(dMajor);
    chords.push_back(eMajor);
    Song song4(0, "Generic Song 3", -1, "Amaj", CHORD_PROGRESSION_BLUES, 3, 0, chords);
    chords.clear();

    chords.push_back(dMajor);
    chords.push_back(eMajor);
    chords.push_back(cSMinor);
    chords.push_back(fSMinor);
    Song song5(0, "Generic Song 4", -1, "Amaj", CHORD_PROGRESSION_CITYPOP, 4, 0, chords);
    chords.clear();

    chords.push_back(fSDim);
    chords.push_back(bMinor);
    chords.push_back(eMinor);
    Song song6(0, "Generic Song 5", -1, "Em", CHORD_PROGRESSION_JAZZ, 3, 0, chords);
    chords.clear();

    chords.push_back(fDim);
    chords.push_back(aSMinor);
    chords.push_back(dSMinor);
    Song song7(0, "Generic Song 6", -1, "D#m", CHORD_PROGRESSION_JAZZ, 3, 0, chords);
    chords.clear();

    chords.push_back(aSDim);
    chords.push_back(dSMinor);
    chords.push_back(gSMinor);
    Song song8(0, "Generic Song 7", -1, "G#m", CHORD_PROGRESSION_JAZZ, 3, 0, chords);

    Podcast podcast1(178, ARTIST_NAME, "Cazaciuc Valentin", {"Dad jokes", "Feminism",
                                                             "Manele", "Stand-up", "Aliens", "Books", "Video games",
                                                             "Global warming", "Acordeon"});
    Podcast podcast2(122, ARTIST_NAME, "Teo", {"Feminism", "Contrabas", "Global warming",
                                               "Youtube algorithm", "Stand-up", "Acordeon", "Video games"});
    Podcast podcast3(157, ARTIST_NAME, "Dan Avidan", {"Stand-up", "Global warming", "Neo-nazism", "Manele", "Cobza",
                                                      "Video games", "Dad jokes", "Books", "Feminism", "Youtube algorithm"});
    Podcast podcast4(118, ARTIST_NAME, "Matei Anechitei", {"Books", "Cancel culture", "Cobza", "Contrabas",
                                                           "Aliens", "Stand-up"});
    Podcast podcast5(74, ARTIST_NAME, "Cazaciuc Valentin", {"Aliens", "Contrabas", "Manele", "Youtube algorithm"});
    Podcast podcast6(169, ARTIST_NAME, "Jimmy Carr", {"Cancel culture", "Neo-nazism", "Feminism", "Stand-up", "Tambal", "Global warming", "Manele",
                                                      "Video games", "Cobza"});
    Podcast podcast7(176, ARTIST_NAME, "Cazaciuc Valentin", {"Feminism", "Manele", "Acordeon",
                                                             "Aliens", "Tambal", "Stand-up", "Neo-nazism", "Dad jokes"});

    vector<Song> songs;
    songs.push_back(song1);
    songs.push_back(song2);
    songs.push_back(song3);
    songs.push_back(song4);
    songs.push_back(song5);
    songs.push_back(song6);
    songs.push_back(song7);
    songs.push_back(song8);

    vector<Podcast> podcasts;
    podcasts.push_back(podcast1);
    podcasts.push_back(podcast2);
    podcasts.push_back(podcast3);
    podcasts.push_back(podcast4);
    podcasts.push_back(podcast5);
    podcasts.push_back(podcast6);
    podcasts.push_back(podcast7);


    Artist expectedArtist(ARTIST_NAME, songs, podcasts, FOLLOWERS);

    ASSERT_EQ(actualArtist, expectedArtist);
}