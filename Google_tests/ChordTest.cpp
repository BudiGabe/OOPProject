#include "gtest/gtest.h"
#include "../Stuffs/Chord.h"
#include <sstream>

class ChordTestFixture: public ::testing::Test {
protected:
    const vector<string> NOTES_C_MINOR{ "C","D#","G" };
    const vector<string> NOTES_F_MAJOR{ "F", "A", "C" };
    const vector<string> NOTES_D_MINOR{ "D", "F", "A" };
    const vector<string> NOTES_C_DIMINISHED{"C", "D#", "F#"};
    const vector<string> NOTES_SLASH_CHORD{"F", "C", "D#", "G"};
    const vector<string> NOTES_PROLONGED_CHORD{"C", "D#", "G", "G"};
    const vector<string> NOTES_CHORD_SUM{"C", "D#", "G", "F", "A", "C"};
    const vector<string> MINOR_INTERVALS{ "P1", "m3", "P5" };
    const vector<string> MAJOR_INTERVALS{ "P1", "M3", "P5" };
    const vector<string> DIMINISHED_INTERVALS{"P1", "m3", "TT"};
    const vector<string> PROLONGED_INTERVALS{"P1", "m3", "P5", "P5"};
    const vector<string> INTERVALS_CHORD_SUM{"P1", "m3", "P5", "P1", "M3", "P5"};
    const vector<string> EMPTY_INTERVALS{};
    const string MINOR_TONALITY = "m";
    const string MAJOR_TONALITY = "maj";
    const string DIMINISHED = "dim";
    const string C_MINOR_NAME = "Cm";
    const string F_MAJOR_NAME = "Fmaj";
    const string D_MINOR_NAME = "Dm";
    const string C_DIMINISHED_NAME = "Cdim";
    const string GENERIC_CHORD_NAME = "Generic Chord Name";
    const string C_MINOR_OUTPUT_STRING = "\nChord name: Cm\n"
                                         "Notes: C, D#, G, \n"
                                         "Intervals: P1, m3, P5, ";
    const string C_MINOR_INPUT_STRING = "Cm\n"
                                        "3\n"
                                        "C D# G\n"
                                        "P1 m3 P5";
    const string NOTE_C = "C";
    const string NOTE_F = "F";
    const string NOTE_INEXISTENT = "H";
    Chord* minorChord;
    Chord* majorChord;
public:
    void SetUp( ) {
        minorChord = new Chord(C_MINOR_NAME, NOTES_C_MINOR, MINOR_INTERVALS);
        majorChord = new Chord(F_MAJOR_NAME, NOTES_F_MAJOR, MAJOR_INTERVALS);
    }

    void TearDown( ) {
        delete minorChord;
        delete majorChord;
    }

    /*
     * Helper to test overloaded cast operator
     */
    void printVector(vector<string> vector, std::stringstream& out) {
        for(auto elem : vector) {
            out << elem;
        }
    }
};

TEST_F(ChordTestFixture, GetNameTest) {
    ASSERT_EQ(minorChord->getName(), C_MINOR_NAME);
}

TEST_F(ChordTestFixture, GetNotesTest) {
    ASSERT_EQ(minorChord->getNotes(), NOTES_C_MINOR);
}

TEST_F(ChordTestFixture, GetIntervalsTest) {
    ASSERT_EQ(minorChord->getIntervals(), MINOR_INTERVALS);
}

TEST_F(ChordTestFixture, SetNameTest) {
    minorChord->setName(F_MAJOR_NAME);
    ASSERT_EQ(minorChord->getName(), F_MAJOR_NAME);
}

TEST_F(ChordTestFixture, SetNotesTest) {
    minorChord->setNotes(NOTES_F_MAJOR);
    ASSERT_EQ(minorChord->getNotes(), NOTES_F_MAJOR);
}

TEST_F(ChordTestFixture, SetIntervalsTest) {
    minorChord->setIntervals(MAJOR_INTERVALS);
    ASSERT_EQ(minorChord->getIntervals(), MAJOR_INTERVALS);
}

TEST_F(ChordTestFixture, OperatorEqualSameChord) {
    *minorChord = *minorChord;
    ASSERT_EQ(*minorChord, *minorChord);
}

TEST_F(ChordTestFixture, OperatorEqualDifferentChord) {
    *minorChord = *majorChord;
    ASSERT_EQ(*minorChord, *majorChord);
}

TEST_F(ChordTestFixture, OutputOperator) {
    std::stringstream out;
    out << *minorChord;

    ASSERT_EQ(out.str(), C_MINOR_OUTPUT_STRING);
}

TEST_F(ChordTestFixture, InputOperator) {
    Chord dummyChord;

    std::istringstream in;
    in.str(C_MINOR_INPUT_STRING);
    in >> dummyChord;

    ASSERT_EQ(dummyChord, *minorChord);
}

TEST_F(ChordTestFixture, IndexOperatorTest) {
    ASSERT_EQ((*minorChord)[0], NOTE_C);
}

TEST_F(ChordTestFixture, IndexOperatorOutOfBoundsTest) {
    ASSERT_ANY_THROW((*minorChord)[15]);
}

TEST_F(ChordTestFixture, PreIncrementTest) {
    ++(*minorChord);

    ASSERT_EQ(minorChord->getNotes(), NOTES_PROLONGED_CHORD);
    ASSERT_EQ(minorChord->getIntervals(), PROLONGED_INTERVALS);
}

TEST_F(ChordTestFixture, PostIncrementTest) {
    ASSERT_EQ(((*minorChord)++).getNotes(), NOTES_C_MINOR);
    ASSERT_EQ((*minorChord).getIntervals(), PROLONGED_INTERVALS);
}

TEST_F(ChordTestFixture, SumTest) {
    Chord tempChord(GENERIC_CHORD_NAME, NOTES_CHORD_SUM, INTERVALS_CHORD_SUM);
    Chord sumChord = *minorChord + *majorChord;

    ASSERT_EQ(sumChord, tempChord);
}

TEST_F(ChordTestFixture, DividingChordsTest) {
    Chord tempChord;
    Chord slashChord(GENERIC_CHORD_NAME, NOTES_SLASH_CHORD, EMPTY_INTERVALS);
    tempChord = (*minorChord) / (*majorChord);

    ASSERT_EQ(tempChord, slashChord);
}

TEST_F(ChordTestFixture, LessThanOperatorTest) {
    Chord minorRelative(D_MINOR_NAME, NOTES_D_MINOR, MINOR_INTERVALS);
    ASSERT_TRUE(*majorChord < minorRelative);
}

TEST_F(ChordTestFixture, GetValidMinorTriadTest) {
    Chord triad = Chord::getTriad(NOTE_C, MINOR_TONALITY);
    Chord expectedTriad(C_MINOR_NAME, NOTES_C_MINOR, MINOR_INTERVALS);

    ASSERT_EQ(triad, expectedTriad);
}

TEST_F(ChordTestFixture, GetValidDiminishedTriadTest) {
    Chord triad = Chord::getTriad(NOTE_C, DIMINISHED);
    Chord expectedTriad(C_DIMINISHED_NAME, NOTES_C_DIMINISHED, DIMINISHED_INTERVALS);

    ASSERT_EQ(triad, expectedTriad);
}

TEST_F(ChordTestFixture, GetValidMajorTriadTest) {
    Chord triad = Chord::getTriad(NOTE_F, MAJOR_TONALITY);
    Chord expectedTriad(F_MAJOR_NAME, NOTES_F_MAJOR, MAJOR_INTERVALS);

    ASSERT_EQ(triad, expectedTriad);
}

TEST_F(ChordTestFixture, GetTriadWrongRootTest) {
    ASSERT_ANY_THROW(Chord::getTriad(NOTE_INEXISTENT, MINOR_TONALITY));
}

TEST_F(ChordTestFixture, GenerateKeyChordsTest) {
    map<int, Chord> keyMap = Chord::generateKeyChords(NOTE_C, MINOR_TONALITY);
    Chord cMinor("Cm", NOTES_C_MINOR, MINOR_INTERVALS);
    Chord dDim("Ddim", {"D", "F", "G#"}, DIMINISHED_INTERVALS);
    Chord eFlatMaj("D#maj", {"D#", "G", "A#"}, MAJOR_INTERVALS);
    Chord fMinor("Fm", {"F", "G#", "C"}, MINOR_INTERVALS);
    Chord gMinor("Gm", {"G", "A#", "D"}, MINOR_INTERVALS);
    Chord aFlatMaj("G#maj", {"G#", "C", "D#"}, MAJOR_INTERVALS);
    Chord bFlatMaj("A#maj", {"A#", "D", "F"}, {MAJOR_INTERVALS});
    map<int,Chord> expectedMap{{1, cMinor}, {2, dDim}, {3, eFlatMaj}, {4, fMinor}, {5, gMinor},
                               {6, aFlatMaj}, {7, bFlatMaj}};

    ASSERT_EQ(keyMap, expectedMap);
}

TEST_F(ChordTestFixture, GenerateKeyChordWrongRootTest) {
    ASSERT_ANY_THROW(Chord::generateKeyChords(NOTE_INEXISTENT, MINOR_TONALITY));
}

TEST_F(ChordTestFixture, CastOperatorTest) {
    std::stringstream out;
    printVector(*minorChord, out);
    string expectedOutput = "CD#G";
    ASSERT_EQ(out.str(), expectedOutput);
}





