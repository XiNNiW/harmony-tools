#include <gtest/gtest.h>
#include "../src/chord-names.h"

void compareNames(string expected, string actual){
    EXPECT_STREQ(expected.c_str(),actual.c_str());
}

TEST(NameChord_TEST, shouldProvideNameForChord) {

   compareNames("Gm9",nameChord({7,10,2,9})); 
   compareNames("Gm11",nameChord({7,10,2,0})); 
   compareNames("Gadd4",nameChord({7,11,2,0}));

   compareNames("C7", nameChord({0,4,7,10}));

   compareNames("Fdim7", nameChord({5,8,11,2}));

   compareNames("Bbaug", nameChord({10,14,18}));

   compareNames("Eb", nameChord({3,7,10}));
   compareNames("Eb", nameChord({3,7,10,3,19,22}));

   compareNames("Abm", nameChord({8,11,3})); //ab cb eb

   compareNames("Dbm9", nameChord({1,4,8,15}));
   compareNames("Dbm7b5", nameChord({1,4,7,11}));
   compareNames("Dbm6", nameChord({1,4,8,10}));

   compareNames("Gbmaj7", nameChord({6,10,1,5}));
   compareNames("Gb69", nameChord({6,10,1,8,3}));

   compareNames("B13", nameChord({11,3,6,8,9}));
   compareNames("B6", nameChord({11,3,6,8}));
   compareNames("B7", nameChord({11,3,6,9}));

   compareNames("E11", nameChord({4,8,11,9,2}));
   compareNames("Eadd4", nameChord({4,8,11,9}));
   compareNames("Esus4", nameChord({4,9,11}));
   compareNames("Esus2", nameChord({4,6,11}));

   compareNames("Amaj7", nameChord({9,1,4,8}));

   compareNames("Dm7", nameChord({2,5,9,0}));
   const string NOT_FOUND = "?";

   compareNames(NOT_FOUND, nameChord({2,5}));
   compareNames(NOT_FOUND, nameChord({4,7,11,3,2,5,2,1,0}));

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
    vector<string> names = findPossibleChordNames({0,4,7,11});
    compareNames("Cmaj7",names[0]); 
    compareNames("?",names[1]); 
    compareNames("?",names[2]); 
    compareNames("?",names[3]); 

    names = findPossibleChordNames({0,4,7,9});
    compareNames("C6",names[0]); 
    compareNames("?",names[1]); 
    compareNames("?",names[2]); 
    compareNames("Am7",names[3]); 
}


TEST(FindUniqueNames, shouldTryAllInversions){
    vector<string> names = findPossibleChordNames({0,4,7,11});
    compareNames("Cmaj7",names[0]); 
    compareNames("?",names[1]); 
    compareNames("?",names[2]); 
    compareNames("?",names[3]); 

    names = findPossibleChordNames({0,4,7,9});
    compareNames("C6",names[0]); 
    compareNames("?",names[1]); 
    compareNames("?",names[2]); 
    compareNames("Am7",names[3]); 
}
