#include <gtest/gtest.h>
#include "../src/tintintabulation.h"

TEST(TINTAB_TEST, shouldMakeListOfChords) {
    vector<vector<int>> chords = findPossibleTintintabulationHarmony_4NoteChords({0,2,4,5,7,9,11},{3,7,11});
    int idx=0;

    ASSERT_EQ(0,  chords[idx][0]);
    ASSERT_EQ(4,  chords[idx][1]);
    ASSERT_EQ(7,  chords[idx][2]);
    ASSERT_EQ(3,  chords[idx][3]);
    idx++;
    
    ASSERT_EQ(0,  chords[idx][0]);
    ASSERT_EQ(4,  chords[idx][1]);
    ASSERT_EQ(7,  chords[idx][2]);
    ASSERT_EQ(7,  chords[idx][3]);
    idx++;

    ASSERT_EQ(0,  chords[idx][0]);
    ASSERT_EQ(4,  chords[idx][1]);
    ASSERT_EQ(7,  chords[idx][2]);
    ASSERT_EQ(11, chords[idx][3]);
    idx++;

    ASSERT_EQ(3,  chords[idx][0]);
    ASSERT_EQ(7,  chords[idx][1]);
    ASSERT_EQ(11, chords[idx][2]);
    ASSERT_EQ(0,  chords[idx][3]);
    idx++;

    //---

    ASSERT_EQ(2,  chords[idx][0]);
    ASSERT_EQ(5,  chords[idx][1]);
    ASSERT_EQ(9,  chords[idx][2]);
    ASSERT_EQ(3,  chords[idx][3]);
    idx++;
    
    ASSERT_EQ(2,  chords[idx][0]);
    ASSERT_EQ(5,  chords[idx][1]);
    ASSERT_EQ(9,  chords[idx][2]);
    ASSERT_EQ(7,  chords[idx][3]);
    idx++;

    ASSERT_EQ(2,  chords[idx][0]);
    ASSERT_EQ(5,  chords[idx][1]);
    ASSERT_EQ(9,  chords[idx][2]);
    ASSERT_EQ(11, chords[idx][3]);
    idx++;

    ASSERT_EQ(3,  chords[idx][0]);
    ASSERT_EQ(7,  chords[idx][1]);
    ASSERT_EQ(11, chords[idx][2]);
    ASSERT_EQ(2,  chords[idx][3]);
    idx++;

    //---

    ASSERT_EQ(4,  chords[idx][0]);
    ASSERT_EQ(7,  chords[idx][1]);
    ASSERT_EQ(11,  chords[idx][2]);
    ASSERT_EQ(3,  chords[idx][3]);
    idx++;
    
    ASSERT_EQ(4,  chords[idx][0]);
    ASSERT_EQ(7,  chords[idx][1]);
    ASSERT_EQ(11,  chords[idx][2]);
    ASSERT_EQ(7,  chords[idx][3]);
    idx++;

    ASSERT_EQ(4,  chords[idx][0]);
    ASSERT_EQ(7,  chords[idx][1]);
    ASSERT_EQ(11,  chords[idx][2]);
    ASSERT_EQ(11, chords[idx][3]);
    idx++;

    ASSERT_EQ(3,  chords[idx][0]);
    ASSERT_EQ(7,  chords[idx][1]);
    ASSERT_EQ(11, chords[idx][2]);
    ASSERT_EQ(4,  chords[idx][3]);
    idx++;
    
    //---

    ASSERT_EQ(5,  chords[idx][0]);
    ASSERT_EQ(9,  chords[idx][1]);
    ASSERT_EQ(0,  chords[idx][2]);
    ASSERT_EQ(3,  chords[idx][3]);
    idx++;
    
    ASSERT_EQ(5,  chords[idx][0]);
    ASSERT_EQ(9,  chords[idx][1]);
    ASSERT_EQ(0,  chords[idx][2]);
    ASSERT_EQ(7,  chords[idx][3]);
    idx++;

    ASSERT_EQ(5,  chords[idx][0]);
    ASSERT_EQ(9,  chords[idx][1]);
    ASSERT_EQ(0,  chords[idx][2]);
    ASSERT_EQ(11, chords[idx][3]);
    idx++;

    ASSERT_EQ(3,  chords[idx][0]);
    ASSERT_EQ(7,  chords[idx][1]);
    ASSERT_EQ(11, chords[idx][2]);
    ASSERT_EQ(5,  chords[idx][3]);
    idx++;

    //---

    ASSERT_EQ(7,  chords[idx][0]);
    ASSERT_EQ(11,  chords[idx][1]);
    ASSERT_EQ(2,  chords[idx][2]);
    ASSERT_EQ(3,  chords[idx][3]);
    idx++;
    
    ASSERT_EQ(7,  chords[idx][0]);
    ASSERT_EQ(11,  chords[idx][1]);
    ASSERT_EQ(2,  chords[idx][2]);
    ASSERT_EQ(7,  chords[idx][3]);
    idx++;

    ASSERT_EQ(7,  chords[idx][0]);
    ASSERT_EQ(11,  chords[idx][1]);
    ASSERT_EQ(2,  chords[idx][2]);
    ASSERT_EQ(11, chords[idx][3]);
    idx++;

    ASSERT_EQ(3,  chords[idx][0]);
    ASSERT_EQ(7,  chords[idx][1]);
    ASSERT_EQ(11, chords[idx][2]);
    ASSERT_EQ(7,  chords[idx][3]);
    idx++;

    //---

    ASSERT_EQ(9,  chords[idx][0]);
    ASSERT_EQ(0,  chords[idx][1]);
    ASSERT_EQ(4,  chords[idx][2]);
    ASSERT_EQ(3,  chords[idx][3]);
    idx++;
    
    ASSERT_EQ(9,  chords[idx][0]);
    ASSERT_EQ(0,  chords[idx][1]);
    ASSERT_EQ(4,  chords[idx][2]);
    ASSERT_EQ(7,  chords[idx][3]);
    idx++;

    ASSERT_EQ(9,  chords[idx][0]);
    ASSERT_EQ(0,  chords[idx][1]);
    ASSERT_EQ(4,  chords[idx][2]);
    ASSERT_EQ(11, chords[idx][3]);
    idx++;

    ASSERT_EQ(3,  chords[idx][0]);
    ASSERT_EQ(7,  chords[idx][1]);
    ASSERT_EQ(11, chords[idx][2]);
    ASSERT_EQ(9,  chords[idx][3]);
    idx++;

    //---

    ASSERT_EQ(11,  chords[idx][0]);
    ASSERT_EQ(2,  chords[idx][1]);
    ASSERT_EQ(5,  chords[idx][2]);
    ASSERT_EQ(3,  chords[idx][3]);
    idx++;
    
    ASSERT_EQ(11,  chords[idx][0]);
    ASSERT_EQ(2,  chords[idx][1]);
    ASSERT_EQ(5,  chords[idx][2]);
    ASSERT_EQ(7,  chords[idx][3]);
    idx++;

    ASSERT_EQ(11,  chords[idx][0]);
    ASSERT_EQ(2,  chords[idx][1]);
    ASSERT_EQ(5,  chords[idx][2]);
    ASSERT_EQ(11, chords[idx][3]);
    idx++;

    ASSERT_EQ(3,  chords[idx][0]);
    ASSERT_EQ(7,  chords[idx][1]);
    ASSERT_EQ(11, chords[idx][2]);
    ASSERT_EQ(11,  chords[idx][3]);
    idx++;

}   
