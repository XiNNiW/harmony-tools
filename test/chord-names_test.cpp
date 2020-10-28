#include <gtest/gtest.h>
#include "../src/chord-names.h"

void compareNames(string expected, string actual){
    EXPECT_STREQ(expected.c_str(),actual.c_str());
}

void compareChordNames(string expected, pair<string,string> actual){
    EXPECT_STREQ(expected.c_str(),(actual.first+actual.second).c_str());
}

TEST(NameChord_TEST, shouldProvideNameForChord) {

   compareChordNames("Gm9",nameChord({7,10,2,9})); 
   compareChordNames("Gm11",nameChord({7,10,2,0})); 
   compareChordNames("Gadd4",nameChord({7,11,2,0}));

   compareChordNames("C7", nameChord({0,4,7,10}));

   compareChordNames("Fdim7", nameChord({5,8,11,2}));

   compareChordNames("Bbaug", nameChord({10,14,18}));

   compareChordNames("Eb", nameChord({3,7,10}));
   compareChordNames("Eb", nameChord({3,7,10,3,19,22}));

   compareChordNames("Abm", nameChord({8,11,3})); //ab cb eb

   compareChordNames("Dbm9", nameChord({1,4,8,15}));
   compareChordNames("Dbm7b5", nameChord({1,4,7,11}));
   compareChordNames("Dbm6", nameChord({1,4,8,10}));

   compareChordNames("Gbmaj7", nameChord({6,10,1,5}));
   compareChordNames("Gb69", nameChord({6,10,1,8,3}));

   compareChordNames("B13", nameChord({11,3,6,8,9}));
   compareChordNames("B6", nameChord({11,3,6,8}));
   compareChordNames("B7", nameChord({11,3,6,9}));

   compareChordNames("E11", nameChord({4,8,11,9,2}));
   compareChordNames("Eadd4", nameChord({4,8,11,9}));
   compareChordNames("Esus4", nameChord({4,9,11}));
   compareChordNames("Esus2", nameChord({4,6,11}));

   compareChordNames("Amaj7", nameChord({9,1,4,8}));

   compareChordNames("Dm7", nameChord({2,5,9,0}));
   const string NOT_FOUND = "?";

   compareChordNames(NOT_FOUND, nameChord({2,5}));
   compareChordNames(NOT_FOUND, nameChord({4,7,11,3,2,5,2,1,0}));

}   

TEST(ChordToIntervals_TEST, shouldConvertChordToIntervals) {
    vector<int> intervals = chordToIntervals({0,4,7});
    ASSERT_EQ(2,intervals.size());
    ASSERT_EQ(4,intervals[0]);
    ASSERT_EQ(3,intervals[1]);
}

TEST(ReduceChord_TEST, shouldReduceToUniqueNotes) {
    vector<int> reduced = reduceChord({0,4,7,12,16});
    ASSERT_EQ(3,reduced.size());
    ASSERT_EQ(0,reduced[0]);
    ASSERT_EQ(4,reduced[1]);
    ASSERT_EQ(7,reduced[2]);
}

TEST(FindPossibleChordNames_TEST, shouldTryAllInversions){
    vector<pair<string,string>> names = findPossibleChordNames({0,4,7,11});
    compareChordNames("Cmaj7",names[0]); 
    compareChordNames("?",names[1]); 
    compareChordNames("?",names[2]); 
    compareChordNames("?",names[3]); 

    names = findPossibleChordNames({0,4,7,9});
    compareChordNames("C6",names[0]); 
    compareChordNames("?",names[1]); 
    compareChordNames("?",names[2]); 
    compareChordNames("Am7",names[3]); 
}

TEST(SPELLING_TEST, shouldSpellArbitraryChord){
    compareNames("C E G B ", spellNotes<vector<int>>({0,4,7,11})); 
    compareNames("G B D Ab ",spellNotes<set<int>>({7, 11, 2, 8})); 
    compareNames("C Db D Eb E F Gb G Ab A Bb B ", spellNotes<vector<int>>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11})); 
    compareNames("C Db D Eb E F Gb G Ab A Bb B ", spellNotes<set<int>>({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11})); 
}

