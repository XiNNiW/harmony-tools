#ifndef _TINTINTABULATION_H
#define _TINTINTABULATION_H

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> findPossibleTintintabulationHarmony_4NoteChords(const vector<int> scale, const vector<int> triad){
    int scaleLength = scale.size();
    int triadLength = triad.size();
    vector<vector<int>> chords = vector<vector<int>>();


    for_each(scale.begin(),scale.end(),[&](const int & scaleNote1){
        chords.push_back({triad[0], triad[1], triad[2], scaleNote1});
        for_each(scale.begin(),scale.end(),[&](const int & scaleNote2){
            chords.push_back({triad[0], triad[1], scaleNote2, scaleNote1});
            chords.push_back({triad[0], scaleNote2, triad[2], scaleNote1});
            chords.push_back({scaleNote2, triad[1], triad[2], scaleNote1});

            for_each(scale.begin(),scale.end(),[&](const int & scaleNote3){
                chords.push_back({triad[0], scaleNote3, scaleNote2, scaleNote1});
                chords.push_back({triad[1], scaleNote3, scaleNote2, scaleNote1});
                chords.push_back({triad[2], scaleNote3, scaleNote2, scaleNote1});
            });
        });
    });

    return chords;
}

#endif //_TINTINTABULATION_H