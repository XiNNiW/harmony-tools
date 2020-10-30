#ifndef _TINTINTABULATION_H
#define _TINTINTABULATION_H

#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

set<set<int>> findPossibleTintintabulationHarmony(const vector<int> scale, const vector<int> triad){
    set<set<int>> chords = set<set<int>>();

    vector<int> notesVector(scale);
    notesVector.insert(notesVector.end(),triad.begin(),triad.end());
    set<int> _pitchClass(notesVector.begin(),notesVector.end());
    notesVector = vector<int>(_pitchClass.begin(),_pitchClass.end());

    sort(notesVector.begin(),notesVector.end(),[](const int & left, const int & right){
        return left<right;
    });

    do{
        set<int> chordAccumulator = set<int>();
        vector<int> currentPermutation(notesVector);
        for(const int note:currentPermutation){
            chordAccumulator.insert(note);
            bool triadNoteFound = false;
            for(const int triadNote:triad){
                if(find(chordAccumulator.begin(),chordAccumulator.end(),triadNote)!=chordAccumulator.end())
                    triadNoteFound=true;
            };
            if(triadNoteFound){
                chords.insert(chordAccumulator);
            }
              
        }
     

    }while(next_permutation(notesVector.begin(),notesVector.end()));

    return chords;
}


#endif //_TINTINTABULATION_H