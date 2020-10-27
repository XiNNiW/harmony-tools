#ifndef _TINTINTABULATION_H
#define _TINTINTABULATION_H

#include <vector>
#include <map>

// #include std::vector;

using namespace std;

vector<vector<int>> findPossibleTintintabulationHarmony_4NoteChords(const vector<int> scale, const vector<int> triad){
    int scaleLength = scale.size();
    int triadLength = triad.size();
    vector<vector<int>> chords = vector<vector<int>>();

    for(int i=0; i<scaleLength; i++){
        chords.push_back({scale[i], scale[(i+2)%scaleLength], scale[(i+4)%scaleLength], triad[0]});
        chords.push_back({scale[i], scale[(i+2)%scaleLength], scale[(i+4)%scaleLength], triad[1]});
        chords.push_back({scale[i], scale[(i+2)%scaleLength], scale[(i+4)%scaleLength], triad[2]});
        chords.push_back({triad[0], triad[1], triad[2], scale[i]});
    }

    return chords;
}

#endif //_TINTINTABULATION_H