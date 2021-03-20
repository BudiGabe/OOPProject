#include "gtest/gtest.h"
#include "../Stuffs/Song.h"

class SongTestFixture: public ::testing::Test {
protected:
    const int PROGRESSION_LENGTH_JAZZ = 3;
    const int PROGRESSION_LENGTH_CITYPOP = 4;
    int CHORD_PROGRESSION_JAZZ[3] = { 2, 5, 1 };
    int CHORD_PROGRESSION_CITYPOP[4] = { 4, 5, 3, 6 };
    int CHORD_PROGRESSION_BLUES[3] = { 1, 4, 5 };
    const int SONG_LENGTH1 = 200;
    const int SONG_LENGTH2 = 300;
    const bool LIKED = true;
    const bool DISLIKED = false;
    char KEY_C[2] = { "C" };
    char KEY_CMINOR[7] = { "Cminor" };
    char KEY_A[3] = { "A" };
    char KEY_AMINOR[7] = { "Aminor" };
    const float RATING_HIGH = 4.9;
    const float RATING_LOW = 2.3;
    const int VARIATION_PERIOD_LONG = 5;
    const int VARIATION_PERIOD_SHORT = 2;
    float RATING_VARIATION_LONG[5] = { 2.5, 3.4, 4.1, 3.5, 4 };
    float RATING_VARIATION_SHORT[2] = {1.2, 4.5};
    const int VIEWS_HIGH = 100000;
    const int VIEWS_LOW = 1234;
    const string SONG_NAME1 = "GenericSongName1";
    const string SONG_NAME2 = "GenericSongName2";
    const int NUM_OF_SIMILAR_SONGS_HIGH = 5;
    const int NUM_OF_SIMILAR_SONGS_LOW = 2;
    string SIMILAR_SONGS_HIGH[5] = { "song1", "song2", "song3", "song4", "song5" };
    string SIMILAR_SONGS_LOW[2] = { "song1", "song2" };
    const char TIER_S = 'S';
    const char TIER_A = 'A';
    const int SONG_NUM_DEFAULT = 0;
    const string C_MINOR_NAME = "Cm";
    const string D_DIM_NAME = "Ddim";
    const string F_MAJOR_NAME = "Fmaj";
    const string E_MINOR_NAME = "Em";
    const string C_MAJOR_NAME = "Cmaj";
    const string G_MINOR_NAME = "Gm";
    const string D_MINOR_NAME = "Dm";
    const string A_MINOR_NAME = "Am";
    const vector<string> NOTES_C_MINOR{ "C","D#","G" };
    const vector<string> NOTES_F_MAJOR{ "F", "A", "C" };
    const vector<string> NOTES_D_DIM{ "D", "F", "G#" };
    const vector<string> NOTES_D_MINOR{ "D", "F", "A" };
    const vector<string> NOTES_E_MINOR{ "E", "G", "B" };
    const vector<string> NOTES_C_MAJOR{ "C", "E", "G" };
    const vector<string> NOTES_G_MINOR{ "G", "A#", "D"};
    const vector<string> NOTES_A_MINOR{ "A", "C", "E" };
    const vector<string> MINOR_INTERVALS{ "P1", "m3", "P5" };
    const vector<string> MAJOR_INTERVALS{ "P1", "M3", "P5" };
    const vector<string> DIMINISHED_INTERVALS{"P1", "m3", "TT"};
    const string SONG_JAZZ_OUTPUT_STRING = "\nSong num: 0\n"
                                           "Name: GenericSongName1\n"
                                           "Views: 100000\n"
                                           "Length: 200\n"
                                           "Key: C\n"
                                           "Chords: Ddim Gm Cm \n"
                                           "Main chord progression: 2, 5, 1, \n"
                                           "Liked: Yes\n"
                                           "Tier: S\n"
                                           "Rating: 4.9\n"
                                           "Variation period length: 5\n"
                                           "Rating variation: 2.5, 3.4, 4.1, 3.5, 4, \n"
                                           "Number of similar songs: 5\n"
                                           "Similar songs: song1, song2, song3, song4, song5, ";
    const string SONG_JAZZ_INPUT_STRING = "GenericSongName1\n"
                                          "100000\n"
                                          "200\n"
                                          "C\n"
                                          "3\n"
                                          "2\n"
                                          "5\n"
                                          "1\n"

                                          "Ddim\n"
                                          "3\n"
                                          "D F G#\n"
                                          "P1 m3 TT\n"

                                          "Gm\n"
                                          "3\n"
                                          "G A# D\n"
                                          "P1 m3 P5\n"

                                          "Cm\n"
                                          "3\n"
                                          "C D# G\n"
                                          "P1 m3 P5\n"

                                          "1\n"
                                          "S\n"
                                          "4.9\n"
                                          "5\n"
                                          "2.5\n"
                                          "3.4\n"
                                          "4.1\n"
                                          "3.5\n"
                                          "4\n"
                                          "5\n"
                                          "song1\n"
                                          "song2\n"
                                          "song3\n"
                                          "song4\n"
                                          "song5";
    Chord* cMinor;
    Chord* dMinor;
    Chord* fMajor;
    Chord* eMinor;
    Chord* cMajor;
    Chord* dDim;
    Chord* gMinor;
    vector<Chord> chordsJazz;
    vector<Chord> chordsCityPop;
    Song* songJazz;
    Song* songCityPop;
public:
    void SetUp( ) {
        cMinor = new Chord(C_MINOR_NAME, NOTES_C_MINOR, MINOR_INTERVALS);
        dDim = new Chord(D_DIM_NAME, NOTES_D_DIM, DIMINISHED_INTERVALS);
        dMinor = new Chord(D_MINOR_NAME, NOTES_D_MINOR, MINOR_INTERVALS);
        gMinor = new Chord(G_MINOR_NAME, NOTES_G_MINOR, MINOR_INTERVALS);
        fMajor = new Chord(F_MAJOR_NAME, NOTES_F_MAJOR, MAJOR_INTERVALS);
        eMinor = new Chord(E_MINOR_NAME, NOTES_E_MINOR, MINOR_INTERVALS);
        cMajor = new Chord(C_MAJOR_NAME, NOTES_C_MAJOR, MAJOR_INTERVALS);

        chordsJazz.push_back(*dDim);
        chordsJazz.push_back(*gMinor);
        chordsJazz.push_back(*cMinor);

        chordsCityPop.push_back(*dMinor);
        chordsCityPop.push_back(*eMinor);
        chordsCityPop.push_back(*cMajor);
        chordsCityPop.push_back(*fMajor);


        songJazz = new Song(SONG_LENGTH1, CHORD_PROGRESSION_JAZZ, PROGRESSION_LENGTH_JAZZ, LIKED, TIER_S, KEY_C,
                RATING_HIGH, RATING_VARIATION_LONG, VARIATION_PERIOD_LONG, VIEWS_HIGH, SONG_NAME1,
                SIMILAR_SONGS_HIGH, NUM_OF_SIMILAR_SONGS_HIGH, SONG_NUM_DEFAULT, chordsJazz);
        songCityPop = new Song(SONG_LENGTH2, CHORD_PROGRESSION_CITYPOP, PROGRESSION_LENGTH_CITYPOP, DISLIKED,
                               TIER_A, KEY_A, RATING_LOW, RATING_VARIATION_SHORT, VARIATION_PERIOD_SHORT, VIEWS_LOW,
                               SONG_NAME2, SIMILAR_SONGS_LOW, NUM_OF_SIMILAR_SONGS_LOW, SONG_NUM_DEFAULT + 1, chordsCityPop);
    }

    void TearDown( ) {
        delete songJazz;
        delete cMinor;
        delete dMinor;
        delete fMajor;
        delete eMinor;
        delete cMajor;
        delete dDim;
        delete gMinor;
    }

    /*
     * Helper function to test cast operator
     */
    void printString(string s, std::stringstream& out) {
        out << s;
    }
};

TEST_F(SongTestFixture, GetNameTest) {
    ASSERT_EQ(songJazz->getName(), SONG_NAME1);
}

TEST_F(SongTestFixture, SetNameTest) {
    songJazz->setName(SONG_NAME2);
    ASSERT_EQ(songJazz->getName(), SONG_NAME2);
}

TEST_F(SongTestFixture, GetLengthTest) {
    ASSERT_EQ(songJazz->getLength(), SONG_LENGTH1);
}

TEST_F(SongTestFixture, SetLengthTest) {
    songJazz->setLength(SONG_LENGTH2);
    ASSERT_EQ(songJazz->getLength(), SONG_LENGTH2);
}

TEST_F(SongTestFixture, GetLikedStatusTest) {
    ASSERT_EQ(songJazz->getLikedStatus(), LIKED);
}

TEST_F(SongTestFixture, SetLikedStatusTest) {
    songJazz->setLikedStatus(DISLIKED);
    ASSERT_EQ(songJazz->getLikedStatus(), DISLIKED);
}

TEST_F(SongTestFixture, GetTierTest) {
    ASSERT_EQ(songJazz->getTier(), TIER_S);
}

TEST_F(SongTestFixture, SetTierTest) {
    songJazz->setTier(TIER_A);
    ASSERT_EQ(songJazz->getTier(), TIER_A);
}

TEST_F(SongTestFixture, GetRatingTest) {
    ASSERT_EQ(songJazz->getRating(), RATING_HIGH);
}

TEST_F(SongTestFixture, SetRatingTest) {
    songJazz->setRating(RATING_LOW);
    ASSERT_EQ(songJazz->getRating(), RATING_LOW);
}

TEST_F(SongTestFixture, GetSongNumTest) {
    ASSERT_EQ(songJazz->getSongNum(), SONG_NUM_DEFAULT);
}

TEST_F(SongTestFixture, GetViewsTest) {
    ASSERT_EQ(songJazz->getViews(), VIEWS_HIGH);
}

TEST_F(SongTestFixture, SetViewsTest) {
    songJazz->setViews(VIEWS_LOW);
    ASSERT_EQ(songJazz->getViews(), VIEWS_LOW);
}

TEST_F(SongTestFixture, GetProgressionLengthTest) {
    ASSERT_EQ(songJazz->getProgressionLength(), PROGRESSION_LENGTH_JAZZ);
}

TEST_F(SongTestFixture, SetProgressionLengthTest) {
    songJazz->setProgressionLength(PROGRESSION_LENGTH_CITYPOP);
    ASSERT_EQ(songJazz->getProgressionLength(), PROGRESSION_LENGTH_CITYPOP);
}

TEST_F(SongTestFixture, GetVariationPeriodTest) {
    ASSERT_EQ(songJazz->getVariationPeriod(), VARIATION_PERIOD_LONG);
}

TEST_F(SongTestFixture, SetVariationPeriodTest) {
    songJazz->setVariationPeriod(VARIATION_PERIOD_SHORT);
    ASSERT_EQ(songJazz->getVariationPeriod(), VARIATION_PERIOD_SHORT);
}

TEST_F(SongTestFixture, GetNumOfSimilarSongsTest) {
    ASSERT_EQ(songJazz->getNumOfSimilarSongs(), NUM_OF_SIMILAR_SONGS_HIGH);
}

TEST_F(SongTestFixture, SetNumOfSimilarSongsTest) {
    songJazz->setNumOfSimilarSongs(NUM_OF_SIMILAR_SONGS_LOW);
    ASSERT_EQ(songJazz->getNumOfSimilarSongs(), NUM_OF_SIMILAR_SONGS_LOW);
}

TEST_F(SongTestFixture, GetMainChordProgressionTest) {
    int* progression = songJazz->getMainChordProgression();

    for (int i =0; i < songJazz->getProgressionLength(); i++)
        ASSERT_EQ(progression[i], CHORD_PROGRESSION_JAZZ[i]);
}

TEST_F(SongTestFixture, SetMainChordProgressionTest) {
    songJazz->setMainChordProgression(CHORD_PROGRESSION_CITYPOP, PROGRESSION_LENGTH_CITYPOP);
    int* progression = songJazz->getMainChordProgression();

    for (int i =0; i < songJazz->getProgressionLength(); i++)
        ASSERT_EQ(progression[i], CHORD_PROGRESSION_CITYPOP[i]);
}

TEST_F(SongTestFixture, GetRatingVariationTest) {
    float* ratingVariation = songJazz->getRatingVariation();
    for (int i =0; i < songJazz->getVariationPeriod(); i++)
        ASSERT_EQ(ratingVariation[i], RATING_VARIATION_LONG[i]);
}

TEST_F(SongTestFixture, SetRatingVariationTest) {
    songJazz->setRatingVariation(RATING_VARIATION_SHORT, VARIATION_PERIOD_SHORT);
    float* ratingVariation = songJazz->getRatingVariation();

    for (int i =0; i < songJazz->getVariationPeriod(); i++)
        ASSERT_EQ(ratingVariation[i], RATING_VARIATION_SHORT[i]);
}

TEST_F(SongTestFixture, GetSimilarSongsTest) {
    string* similarSongs = songJazz->getSimilarSongs();
    for (int i =0; i < songJazz->getNumOfSimilarSongs(); i++)
        ASSERT_EQ(similarSongs[i], SIMILAR_SONGS_HIGH[i]);
}

TEST_F(SongTestFixture, SetSimilarSongsTest) {
    songJazz->setSimilarSongs(SIMILAR_SONGS_LOW, NUM_OF_SIMILAR_SONGS_LOW);
    string* similarSongs = songJazz->getSimilarSongs();

    for (int i =0; i < songJazz->getNumOfSimilarSongs(); i++)
        ASSERT_EQ(similarSongs[i], SIMILAR_SONGS_LOW[i]);
}

TEST_F(SongTestFixture, GetKeyTest) {
    char* key = songJazz->getKey();
    for(int i = 0; i < strlen(key); i++)
    ASSERT_EQ(key[i], KEY_C[i]);
}

TEST_F(SongTestFixture, SetKeyTest) {
    songJazz->setKey(KEY_A);
    char* key = songJazz->getKey();
    for(int i = 0; i < strlen(key); i++)
        ASSERT_EQ(key[i], KEY_A[i]);
}

TEST_F(SongTestFixture, GetChordsTest) {
    ASSERT_EQ(songJazz->getChords(), chordsJazz);
}

TEST_F(SongTestFixture, SetChordsTest) {
    songJazz->setChords(chordsCityPop);
    ASSERT_EQ(songJazz->getChords(), chordsCityPop);
}

TEST_F(SongTestFixture, OperatorEqualSameSong) {
    *songJazz = *songJazz;
    ASSERT_EQ(*songJazz, *songJazz);
}

TEST_F(SongTestFixture, OperatorEqualDifferentSong) {
    *songJazz = *songCityPop;
    ASSERT_EQ(*songJazz, *songCityPop);
}

TEST_F(SongTestFixture, OutputOperator) {
    std::stringstream out;
    out << *songJazz;

    ASSERT_EQ(out.str(), SONG_JAZZ_OUTPUT_STRING);
}

TEST_F(SongTestFixture, InputOperator) {
    Song dummySong;

    std::istringstream in;
    in.str(SONG_JAZZ_INPUT_STRING);
    in >> dummySong;

    ASSERT_EQ(dummySong, *songJazz);
}

TEST_F(SongTestFixture, IndexOperatorTest) {
    ASSERT_EQ((*songJazz)[0], CHORD_PROGRESSION_JAZZ[0]);
}

TEST_F(SongTestFixture, IndexOperatorOutOfBoundsTest) {
    ASSERT_ANY_THROW((*songJazz)[15]);
}

TEST_F(SongTestFixture, PreIncrementTest) {
    ++(*songJazz);

    ASSERT_EQ(songJazz->getViews(), VIEWS_HIGH + 1);
}

TEST_F(SongTestFixture, PostIncrementTest) {
    ASSERT_EQ(((*songJazz)++).getViews(), VIEWS_HIGH);
    ASSERT_EQ((*songJazz).getViews(), VIEWS_HIGH + 1);
}

TEST_F(SongTestFixture, SumTest) {
    Song sumSong = *songJazz + *songCityPop;
    songJazz->setLength(SONG_LENGTH1 + SONG_LENGTH2);

    ASSERT_EQ(sumSong, *songJazz);
}

TEST_F(SongTestFixture, DIffTestSuccessful) {
    Song sumSong = *songCityPop - *songJazz;
    songCityPop->setLength(SONG_LENGTH2 - SONG_LENGTH1);

    ASSERT_EQ(sumSong, *songCityPop);
}

TEST_F(SongTestFixture, DIffTestFails) {
    ASSERT_ANY_THROW(*songJazz - *songCityPop);
}

TEST_F(SongTestFixture, CastOperatorTest) {
    std::stringstream out;
    printString(*songJazz, out);
    string expectedOutput = "GenericSongName1";
    ASSERT_EQ(out.str(), expectedOutput);
}

TEST_F(SongTestFixture, LessThanTest) {
    ASSERT_TRUE(*songCityPop < *songJazz);
}

TEST_F(SongTestFixture, GenerateSongJazzTest) {
    Song actualJazzSong = Song::generateSong(KEY_C, "minor", "Jazz", 1);
    Song expectedJazzSong(0, CHORD_PROGRESSION_JAZZ, 3, false, 'F', KEY_CMINOR,
                          0, nullptr, 0, 0, "Generic Song 1",
                          nullptr, 0, 1,chordsJazz);

    ASSERT_EQ(actualJazzSong, expectedJazzSong);
}

TEST_F(SongTestFixture, GenerateSongCityPopTest) {
    Song actualCityPopSong = Song::generateSong(KEY_A, "minor", "City pop", 1);
    Song expectedCityPopSong(0, CHORD_PROGRESSION_CITYPOP, 4, false, 'F', KEY_AMINOR,
                             0, nullptr, 0, 0, "Generic Song 1",
                              nullptr, 0, 1,chordsCityPop);

    ASSERT_EQ(actualCityPopSong, expectedCityPopSong);
}

TEST_F(SongTestFixture, GenerateSongBluesTest) {
    Chord aMinor(A_MINOR_NAME, NOTES_A_MINOR, MINOR_INTERVALS);
    vector<Chord> chordsBlues;
    chordsBlues.push_back(aMinor);
    chordsBlues.push_back(*dMinor);
    chordsBlues.push_back(*eMinor);

    Song actualBluesSong = Song::generateSong(KEY_A, "minor", "Blues", 1);
    Song expectedBluesSong(0, CHORD_PROGRESSION_BLUES, 4, false, 'F', KEY_AMINOR,
                           0, nullptr, 0, 0, "Generic Song 1",
                            nullptr, 0, 1, chordsBlues);

    ASSERT_EQ(actualBluesSong, expectedBluesSong);
}

TEST_F(SongTestFixture, GenerateSongWrongKeyTest) {
    ASSERT_ANY_THROW(Song::generateSong("H", "minor", "City pop", 1));
    cout << (nullptr == nullptr);
}
