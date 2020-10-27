#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int OCTAVE = 12;

enum IntervalType {
    UNISON,
    MINOR_SECOND,
    MAJOR_SECOND,
    MINOR_THIRD,
    MAJOR_THIRD,
    PERFECT_FOURTH,
    DIMINISHED_FIFTH,
    PERFECT_FIFTH,
    MINOR_SIXTH,
    MAJOR_SIXTH,
    MINOR_SEVENTH,
    MAJOR_SEVENTH
};

map<int, string> NOTES = {
    {0, "C"},
    {1, "Db"},
    {2, "D"},
    {3, "Eb"},
    {4, "E"},
    {5, "F"},
    {6, "Gb"},
    {7, "G"},
    {8, "Ab"},
    {9, "A"},
    {10, "Bb"},
    {11, "B"}
};

map<int, IntervalType> INTERVALS = {
    {0, UNISON},
    {1, MINOR_SECOND},
    {2, MAJOR_SECOND},
    {3, MINOR_THIRD},
    {4, MAJOR_THIRD},
    {5, PERFECT_FOURTH},
    {6, DIMINISHED_FIFTH},
    {7, PERFECT_FIFTH},
    {8, MINOR_SIXTH},
    {9, MAJOR_SIXTH},
    {10, MINOR_SEVENTH},
    {11, MAJOR_SEVENTH},
};

map<set<int>,string> CHORD_NAMES = {
    {{0,2,7},"sus2"},
    {{0,2,7,5},"add4sus2"},
    {{0,2,7,9},"6sus2"},
    {{0,2,7,10},"7sus2"},
    {{0,2,7,10,5},"11sus2"},
    {{0,2,7,10,9},"13sus2"},
    {{0,2,7,10,9,5},"13sus2"},
    {{0,2,7,8},"b13sus2"},
    {{0,2,7,10,8},"b13sus2"},
    {{0,2,7,10,8,5},"b13sus2"},
    {{0,2,7,11},"maj7sus2"},
    {{0,2,7,11,5},"maj7add11sus2"},
    {{0,2,7,11,9},"maj7add13sus2"},

    {{0,4,7},""},
    {{0,4,7,2},"9"},
    {{0,4,7,5},"add4"},
    {{0,4,7,9},"6"},
    {{0,4,7,9,2},"69"},
    {{0,4,7,10},"7"},
    {{0,4,7,10,5},"11"},
    {{0,4,7,10,5,2},"11"},
    {{0,4,7,10,9},"13"},
    {{0,4,7,10,9,5},"13"},
    {{0,4,7,8}," b13"},
    {{0,4,7,10,8}," b13"},
    {{0,4,7,10,8,5}," b13"},
    {{0,4,7,11},"maj7"},
    {{0,4,7,11,2},"maj7add9"},
    {{0,4,7,11,5},"maj7add11"},
    {{0,4,7,11,9},"maj7add13"},

    {{0,5,7},"sus4"},
    {{0,5,7,2},"9sus4"},
    {{0,5,7,9},"6sus4"},
    {{0,5,7,10},"7sus4"},
    {{0,5,7,10,9},"13sus4"},
    {{0,5,7,11},"maj7sus4"},
    {{0,5,7,11,2},"maj7add9sus4"},
    {{0,5,7,11,9},"maj7add13sus4"},

    {{0,3,7},"m"},
    {{0,3,7,2},"m9"},
    {{0,3,7,5},"m11"},
    {{0,3,7,2,5},"m11"},
    {{0,3,7,10,5},"m11"},
    {{0,3,7,2,10,5},"m11"},
    {{0,3,7,9},"m6"},
    {{0,3,7,10},"m7"},
    {{0,3,7,10,2},"m7add9"},
    {{0,3,7,10,9},"m13"},
    {{0,3,7,11},"min/maj7"},

    {{0,3,6},"dim"},
    {{0,3,6,9},"dim7"},
    {{0,3,6,10},"m7b5"},

    {{0,4,8},"aug"},
};


vector<int> reduceChord(vector<int> chord){
    vector<int> reduced = vector<int>();
    for (size_t i = 0; i < chord.size(); i++)
    {
        int note = chord[i]%12;
        if(find(reduced.begin(),reduced.end(),note)==reduced.end()){
            reduced.push_back(note);
        }
    }

    return reduced;
    
}

set<int> normalizeChord(vector<int> chord)
{   
    vector<int> reduced = reduceChord(chord);
    set<int> normalized = set<int>();
    if(chord.size()>1){
        int root = chord[0];
        for (size_t i = 0; i < reduced.size(); i++)
        {
            normalized.insert((reduced[i]+OCTAVE-root)%OCTAVE);
        }
        
    } 

    return normalized;
}

vector<int> chordToIntervals(vector<int> chord){
    vector<int> intervals = vector<int>();
    if(chord.size()>1){
        int lastNote=chord[0];
        for(int i=0;i<chord.size()-1;i++){
            int severalOctaves =OCTAVE*4;
            int interval = (chord[i+1]+severalOctaves-chord[i])%12;
            intervals.push_back(interval);
        }
    }else{
        intervals = {0};
    }

    return intervals;
}

string nameChord(const vector<int> chord){
    string name = "?";
    vector<int> reducedChord = reduceChord(chord); 
    vector<int> intervals = chordToIntervals(reducedChord);
    set<int> normalizedChord = normalizeChord(chord);

    if(CHORD_NAMES.find(normalizedChord)!=CHORD_NAMES.end()){
        
        int root = reducedChord[0]%OCTAVE;
        string rootName = NOTES[root];
        string valenceAndTensions = CHORD_NAMES[normalizedChord];
        name = rootName+valenceAndTensions;
        
    } 
    return name;
}

vector<string> findPossibleChordNames(vector<int> chord){
    vector<string> chordNames;
    for (size_t i = 0; i < chord.size(); i++)
    {
        vector<int> inversion;
        vector<int> left(chord.begin(),chord.begin()+i);
        vector<int> right(chord.begin()+i,chord.end());
        inversion = right;
        inversion.insert( inversion.end(), left.begin(), left.end() );

        chordNames.push_back(nameChord(inversion));
        
    }

    return chordNames;
    
}

vector<string> findAllChordNamesInVectorOfChords(vector<vector<int>> chordList){
    vector<string> names=vector<string>();
    for_each(chordList.begin(),chordList.end(),[&](const vector<int> & chord){
        vector<string> possibleNames = findPossibleChordNames(chord);
        for_each(possibleNames.begin(),possibleNames.end(),[&](const string & name){
            names.push_back(name);
        });
    });

    return names;

}

set<string> filterToUniqueNames(vector<string> chordList){
    set<string> names=set<string>();
    for_each(chordList.begin(),chordList.end(),[&](const string & name){
        names.insert(name);
    });

    return names;

}







