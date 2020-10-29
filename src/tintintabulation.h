#ifndef _TINTINTABULATION_H
#define _TINTINTABULATION_H

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> findPossibleTintintabulationHarmony(const vector<int> scale, const vector<int> triad){
    int scaleLength = scale.size();
    int triadLength = triad.size();
    vector<vector<int>> chords = vector<vector<int>>();


    for_each(scale.begin(),scale.end(),[&](const int & scaleNote1){
       for_each(scale.begin(),scale.end(),[&](const int & scaleNote2){
           for_each(scale.begin(),scale.end(),[&](const int & scaleNote3){
               for_each(scale.begin(),scale.end(),[&](const int & scaleNote4){
                   for_each(scale.begin(),scale.end(),[&](const int & scaleNote5){
                       for_each(scale.begin(),scale.end(),[&](const int & scaleNote6){
                           for_each(triad.begin(),triad.end(),[&](const int & triadNote){
                               chords.push_back({scaleNote1,scaleNote2,scaleNote3,scaleNote4,scaleNote5,scaleNote6,triadNote});
                           });
                       });
                   });
               });
           });
       });
    });

    return chords;
}


#endif //_TINTINTABULATION_H