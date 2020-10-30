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

map<int, string> NOTES_TO_NAME = {
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

map<string,int> NAME_TO_NOTE = {
    {"C",0},
    {"Db",1},
    {"D",2},
    {"Eb",3},
    {"E",4},
    {"F",5},
    {"Gb",6},
    {"G",7},
    {"Ab",8},
    {"A",9},
    { "Bb",10},
    { "B",11}
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
    // 2 NOTE CHORDS
    {{0,7},"5"},

    // 3 NOTE CHORDS
    //minor
    {{0,3,7},"m"},
    //major
    {{0,4,7},""},
    //dim
    {{0,3,6},"dim"},
    //aug
    {{0,4,8},"aug"},
    //sus 2
    {{0,2,7},"sus2"},
    //sus 4
    {{0,5,7},"sus4"},

    
    // 4 NOTE CHORDS
    //minor
    {{0,3,7,1},"maddb9"},
    {{0,3,7,2},"madd9"},
    {{0,3,7,5},"madd11"},
    {{0,3,7,6},"madd#11"},
    {{0,3,7,8},"maddb13"},
    {{0,3,7,9},"m6"},
    {{0,3,7,10},"m7"},
    {{0,3,7,11},"min/maj7"},
    //major
    {{0,4,7,1},"addb9"},
    {{0,4,7,2},"add9"},
    {{0,4,7,5},"add11"},
    {{0,4,7,6},"add#11"},
    {{0,4,7,8},"addb13"},
    {{0,4,7,9},"6"},
    {{0,4,7,10},"7"},
    {{0,4,7,11},"maj7"},
    //dim
    {{0,3,6,9},"dim7"},
    {{0,3,6,10},"m7b5"},
    //sus 2
    {{0,2,7,1},"sus2addb9"},
    {{0,2,7,2},"sus2add9"},
    {{0,2,7,5},"sus2add11"},
    {{0,2,7,6},"sus2add#11"},
    {{0,2,7,8},"sus2addb13"},
    {{0,2,7,9},"6sus2"},
    {{0,2,7,10},"7sus2"},
    {{0,2,7,11},"maj7sus2"},
    //sus 4
    {{0,5,7,1},"sus4addb9"},
    {{0,5,7,2},"sus4add9"},
    // {{0,5,7,5},"sus4add11"},
    // {{0,5,7,6},"sus4add#11"},
    {{0,5,7,8},"sus4addb13"},
    {{0,5,7,9},"6sus4"},
    {{0,5,7,10},"7sus4"},
    {{0,5,7,11},"maj7sus4"},

    // 5 NOTE CHORDS
    // minor
    // {{0,3,7,1,2},"pooop"},
    {{0,3,7,1,5},"maddb9add11"},
    {{0,3,7,1,6},"maddb9add#11"},
    {{0,3,7,1,8},"maddb9addb13"},
    {{0,3,7,1,9},"m6addb9"},
    {{0,3,7,1,10},"mb9"},
    {{0,3,7,1,11},"min/maj7b9"},
    //
    {{0,3,7,2,5},"madd9add11"},
    {{0,3,7,2,6},"madd9add#11"},
    {{0,3,7,2,8},"madd9addb13"},
    {{0,3,7,2,9},"6add9"},
    {{0,3,7,2,10},"m9"},
    {{0,3,7,2,11},"min/maj79"},
    //
    // {{0,3,7,5,6},"pooop"},
    {{0,3,7,5,8},"madd11addb13"},
    {{0,3,7,5,9},"m6add11"},
    {{0,3,7,5,10},"m7add11"},
    {{0,3,7,5,11},"min/maj7add11"},
    //
    {{0,3,7,6,8},"madd#11addb13"},
    {{0,3,7,6,9},"m6add#11"},
    {{0,3,7,6,10},"m7add#11"},
    {{0,3,7,6,11},"min/maj7add#11"},
    //
    // {{0,3,7,8,9},"7add13"}, too odd
    {{0,3,7,8,10},"m7addb13"},
    {{0,3,7,8,11},"min/maj7addb13"},
    //
    {{0,3,7,9,10},"m7add13"},
    {{0,3,7,9,11},"min/maj7add13"},

    // major
    // {{0,4,7,1,2},"pooop"},
    {{0,4,7,1,5},"addb9add11"},
    {{0,4,7,1,6},"addb9add#11"},
    {{0,4,7,1,8},"addb9addb13"},
    {{0,4,7,1,9},"6addb9"},
    {{0,4,7,1,10},"b9"},
    {{0,4,7,1,11},"maj7b9"},
    //
    {{0,4,7,2,5},"add9add11"},
    {{0,4,7,2,6},"add9add#11"},
    {{0,4,7,2,8},"add9addb13"},
    {{0,4,7,2,9},"6add9"},
    {{0,4,7,2,10},"9"},
    {{0,4,7,2,11},"maj79"},
    //
    // {{0,4,7,5,6},"pooop"},
    {{0,4,7,5,8},"add11addb13"},
    {{0,4,7,5,9},"6add11"},
    {{0,4,7,5,10},"7add11"},
    {{0,4,7,5,11},"maj7add11"},
    //
    {{0,4,7,6,8},"add#11addb13"},
    {{0,4,7,6,9},"6add#11"},
    {{0,4,7,6,10},"7add#11"},
    {{0,4,7,6,11},"maj7add#11"},
    //
    // {{0,4,7,8,9},"7add13"}, too odd
    {{0,4,7,8,10},"7addb13"},
    {{0,4,7,8,11},"maj7addb13"},
    //
    {{0,4,7,9,10},"7add13"},
    {{0,4,7,9,11},"maj7add13"},
    //sus 2
    {{0,2,7,5,9},"6add4sus2"},
    {{0,2,7,10,5},"7add11sus2"},
    {{0,2,7,10,9},"7add13sus2"},
    {{0,2,7,10,8},"7addb13sus2"},
    {{0,2,7,11,5},"maj7add11sus2"},
    {{0,2,7,11,9},"maj7add13sus2"},
    //#9
    {{0,4,7,10,3},"7#9"},

    // 6 NOTE CHORDS
    //minor
    // {{0,3,7,1,2,5},"poopp"},  
    // {{0,3,7,1,2,6},"poopp"},  
    // {{0,3,7,1,2,8},"poopp"},  
    // {{0,3,7,1,2,9},"poopp"},  
    // {{0,3,7,1,2,10},"poopp"},  
    // {{0,3,7,1,2,11},"poopp"},  
    // {{0,3,7,1,5,6},"poopp"},  
    {{0,3,7,1,5,8},"maddb9add11addb13"}, 
    {{0,3,7,1,5,9},"maddb9add11add13"},  
    {{0,3,7,1,5,10},"m11(b9)"},  
    // {{0,3,7,1,5,11},"min/maj11(b9)"},  
    {{0,3,7,1,6,8},"maddb9add#11addb13"},  
    {{0,3,7,1,6,9},"maddb9add#11add13"},  
    {{0,3,7,1,6,10},"m#11(b9)"},  
    // {{0,3,7,1,6,11},"min/maj#11(b9)"}, 
    // {{0,3,7,1,8,9},"pooop"},  
    {{0,3,7,1,8,10},"mb9addb13"},  
    // {{0,3,7,1,8,11},"min/maj7addb9addb13"}, 
    {{0,3,7,1,9,10},"b9add13"},  
    // {{0,3,7,1,9,11},"min/maj7addb9add13"}, 
    //
    // {{0,3,7,2,5,6},"poop"}, 
    {{0,3,7,2,5,8},"madd9add11addb13"},
    {{0,3,7,2,5,9},"madd9add11add13"},  
    {{0,3,7,2,5,10},"m11"},  
    // {{0,3,7,2,5,11},"min/maj11"},  
    {{0,3,7,2,6,8},"madd9add#11addb13"},  
    {{0,3,7,2,6,9},"madd9add#11add13"},  
    {{0,3,7,2,6,10},"m#11"},  
    // {{0,3,7,2,6,11},"min/maj#11"},  
    // {{0,3,7,2,8,9},"pooop"},  
    {{0,3,7,2,8,10},"m9addb13"},  
    // {{0,3,7,2,8,11},"min/maj9addb13"},  
    {{0,3,7,2,9,10},"m9addb13"},  
    // {{0,3,7,2,9,11},"min/maj9addb13"}, 
    //
    //
    // {{0,3,7,5,6,8},"poop"}, 
    // {{0,3,7,5,8,9},"poop"},
    {{0,3,7,5,8,10},"m7add11addb13"},
    // {{0,3,7,5,8,11},"min/maj7add11addb13"},
    {{0,3,7,5,9,10},"m7add11add13"},
    // {{0,3,7,5,9,11},"min/maj7add11add13"},
    //
    {{0,3,7,6,8,10},"m7#11b13"},
    // {{0,3,7,6,8,11},"min/maj7#11b13"},
    {{0,3,7,6,9,10},"m7#11add13"},
    // {{0,3,7,6,9,11},"min/maj7#11add13"},
    //
    // {{0,4,7,8,9,10},"poop"},
    // {{0,4,7,8,10,11},"pooop"},
    // {{0,4,7,9,10,11},"pooop"},
     //major
    // {{0,4,7,1,2,5},"poopp"},  
    // {{0,4,7,1,2,6},"poopp"},  
    // {{0,4,7,1,2,8},"poopp"},  
    // {{0,4,7,1,2,9},"poopp"},  
    // {{0,4,7,1,2,10},"poopp"},  
    // {{0,4,7,1,2,11},"poopp"},  
    // {{0,4,7,1,5,6},"poopp"},  
    {{0,4,7,1,5,8},"addb9add11addb13"}, 
    {{0,4,7,1,5,9},"addb9add11add13"},  
    {{0,4,7,1,5,10},"11(b9)"},  
    {{0,4,7,1,5,11},"maj11(b9)"},  
    {{0,4,7,1,6,8},"addb9add#11addb13"},  
    {{0,4,7,1,6,9},"addb9add#11add13"},  
    {{0,4,7,1,6,10},"#11(b9)"},  
    {{0,4,7,1,6,11},"maj#11(b9)"}, 
    // {{0,4,7,1,8,9},"pooop"},  
    {{0,4,7,1,8,10},"b9addb13"},  
    {{0,4,7,1,8,11},"maj7addb9addb13"}, 
    {{0,4,7,1,9,10},"b9add13"},  
    {{0,4,7,1,9,11},"maj7addb9add13"}, 
    //
    // {{0,4,7,2,5,6},"poop"}, 
    {{0,4,7,2,5,8},"add9add11addb13"},
    {{0,4,7,2,5,9},"add9add11add13"},  
    {{0,4,7,2,5,10},"11"},  
    {{0,4,7,2,5,11},"maj11"},  
    {{0,4,7,2,6,8},"add9add#11addb13"},  
    {{0,4,7,2,6,9},"add9add#11add13"},  
    {{0,4,7,2,6,10},"#11"},  
    {{0,4,7,2,6,11},"maj#11"},  
    // {{0,4,7,2,8,9},"pooop"},  
    {{0,4,7,2,8,10},"9addb13"},  
    {{0,4,7,2,8,11},"maj9addb13"},  
    {{0,4,7,2,9,10},"9addb13"},  
    {{0,4,7,2,9,11},"maj9addb13"}, 
    //
    //
    // {{0,4,7,5,6,8},"poop"}, 
    // {{0,4,7,5,8,9},"poop"},
    {{0,4,7,5,8,10},"7add11addb13"},
    {{0,4,7,5,8,11},"maj7add11addb13"},
    {{0,4,7,5,9,10},"7add11add13"},
    {{0,4,7,5,9,11},"maj7add11add13"},
    //
    {{0,4,7,6,8,10},"7#11b13"},
    {{0,4,7,6,8,11},"maj7#11b13"},
    {{0,4,7,6,9,10},"7#11add13"},
    {{0,4,7,6,9,11},"maj7#11add13"},
    //
    // {{0,4,7,8,9,10},"poop"},
    // {{0,4,7,8,10,11},"pooop"},
    // {{0,4,7,9,10,11},"pooop"},
    //sus 2
    {{0,2,7,10,8,5},"b13sus2"},
    {{0,2,7,10,9,5},"13sus2"},

    //7 NOTE CHORDS
    //major
    {{0,4,7,10,1,5,8},"b13(b9)"},  
    {{0,4,7,10,1,6,8},"b13(b9#11)"},
    {{0,4,7,10,2,5,8},"b13"},  
    {{0,4,7,10,2,6,8},"b13(#11)"},  
    {{0,4,7,10,1,5,9},"13(b9)"},  
    {{0,4,7,10,1,6,9},"13(b9#11)"},  
    {{0,4,7,10,2,5,9},"13"},  
    {{0,4,7,10,2,6,9},"13(#11)"},  
    {{0,4,7,11,1,5,9},"maj13(b9)"},  
    {{0,4,7,11,1,6,9},"maj13(b9#11)"},  
    {{0,4,7,11,2,5,9},"maj13"},  
    {{0,4,7,11,2,6,9},"maj13(#11)"},  
    //minor
    {{0,3,7,10,1,5,8},"mb13(b9)"},  
    {{0,3,7,10,1,6,8},"mb13(b9#11)"},
    {{0,3,7,10,2,5,8},"mb13"},  
    {{0,3,7,10,2,6,8},"mb13(#11)"},  
    {{0,3,7,10,1,5,9},"m13(b9)"},  
    {{0,3,7,10,1,6,9},"m13(b9#11)"},  
    {{0,3,7,10,2,5,9},"m13"},  
    {{0,3,7,10,2,6,9},"m13(#11)"},  
    // {{0,3,7,11,1,5,9},"min/maj13(b9)"},  
    // {{0,3,7,11,1,6,9},"min/maj13(b9#11)"},  
    // {{0,3,7,11,2,5,9},"min/maj13"},  
    // {{0,3,7,11,2,6,9},"min/maj13(#11)"},  

};

template<typename Collection>
string spellNotes(const Collection notes){
    string spelling = "";
    auto spell = [&](const int & note){
        spelling += NOTES_TO_NAME[note%OCTAVE];
        spelling += " ";
    };
    for_each(notes.begin(),notes.end(),spell);
    return spelling;
}

string spellChordByName(const pair<string,string> name){
    string spelling = "?";
    set<int> notesInSpelling = set<int>();
    for(auto iterator = CHORD_NAMES.begin(); iterator!=CHORD_NAMES.end(); ++iterator){
        if(iterator->second==name.second){
            if(iterator->first.size()>notesInSpelling.size()){
                notesInSpelling = set<int>();
                
                for_each(iterator->first.begin(),iterator->first.end(),[&](const int & note){
                    if(NAME_TO_NOTE.find(name.first)!=NAME_TO_NOTE.end())
                        notesInSpelling.insert(note+NAME_TO_NOTE[name.first]);
                });
                spelling = spellNotes(notesInSpelling);
            }
        }
    }

    return spelling;
}

vector<string> spellChordsByNotes(const vector<vector<int>> chords){
    vector<string> spellings = vector<string>();
    for_each(chords.begin(),chords.end(),[&](const vector<int> & chord){
        spellings.push_back(spellNotes(chord));
    });
    return spellings;
}


vector<int> reduceChord(const vector<int> chord){
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

set<int> normalizeChord(const vector<int> chord)
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

map<int, vector<vector<int>>> groupChordsByNumberOfNotes(const vector<vector<int>> chords){
     map<int,vector<vector<int>>> chordsByNumberOfNotes = map<int,vector<vector<int>>>();
     
     for_each(chords.begin(),chords.end(),[&chordsByNumberOfNotes](vector<int> chord){
        vector<int> withoutDuplicateNotes = reduceChord(chord);
        int chordSize = withoutDuplicateNotes.size();
        if(chordSize>0&&chordSize<=7){
            if(chordsByNumberOfNotes.find(chordSize)==chordsByNumberOfNotes.end())
                chordsByNumberOfNotes[chordSize] = vector<vector<int>>();
            chordsByNumberOfNotes[chordSize].push_back(withoutDuplicateNotes);
        }
     });

     return chordsByNumberOfNotes;
}

vector<int> chordToIntervals(const vector<int> chord){
    vector<int> intervals = vector<int>();
    if(chord.size()>1){
        int lastNote=chord[0];
        for(int i=0; i<chord.size()-1; i++){
            int severalOctaves =OCTAVE*4;
            int interval = (chord[i+1]+severalOctaves-chord[i])%12;
            intervals.push_back(interval);
        }
    } else {
        intervals = {0};
    }

    return intervals;
}

pair<string, string> nameChord(const vector<int> chord){
    pair<string,string> name = pair<string,string>({"?","?"});
    vector<int> reducedChord = reduceChord(chord); 
    vector<int> intervals = chordToIntervals(reducedChord);
    set<int> normalizedChord = normalizeChord(chord);

    if(CHORD_NAMES.find(normalizedChord)!=CHORD_NAMES.end()){
        
        int root = reducedChord[0]%OCTAVE;
        string rootName = NOTES_TO_NAME[root];
        string valenceAndTensions = CHORD_NAMES[normalizedChord];
        name = pair<string,string>({rootName, valenceAndTensions});
        
    } 

    return name;
}

vector<pair<string,string>> findPossibleChordNames(const vector<int> chord){
    vector<pair<string,string>> chordNames;
    for (size_t i = 0; i < chord.size(); i++)
    {
        vector<int> inversion;
        vector<int> left(chord.begin(),chord.begin()+i);
        vector<int> right(chord.begin()+i,chord.end());
        inversion = right;
        inversion.insert( inversion.end(), left.begin(), left.end() );

        pair<string,string> name = nameChord(inversion);
        
        chordNames.push_back(name);
        
    }

    return chordNames;
}

vector<pair<string,string>> findAllChordNamesInVectorOfChords(const vector<vector<int>> chordList){
    vector<pair<string,string>> names=vector<pair<string,string>>();
    for_each(chordList.begin(),chordList.end(),[&](const vector<int> & chord){
        vector<pair<string,string>> possibleNames = findPossibleChordNames(chord);
        for_each(possibleNames.begin(),possibleNames.end(),[&](const pair<string,string> & name){
            if(name.first!="?")
                names.push_back(name);
        });
    });

    return names;
}

vector<pair<string,string>> filterToUniqueNames(const vector<pair<string,string>> chordList){
    vector<pair<string,string>> uniqueNames = vector<pair<string,string>>();
    for_each(chordList.begin(),chordList.end(),[&uniqueNames](const pair<string,string> & name){
        if(uniqueNames.end()==find_if(uniqueNames.begin(),uniqueNames.end(),[=](const pair<string,string> & uniqueName){
            return uniqueName.first == name.first && uniqueName.second == name.second;
        })){
            uniqueNames.push_back(name);
        }
        
    });

    return uniqueNames;
}

vector<pair<string,string>> sortNames(const vector<pair<string,string>> chords){
    vector<pair<string,string>> sortedChords = vector<pair<string,string>>(chords);
    std::sort(sortedChords.begin(),sortedChords.end(),[](const pair<string,string> & left, const pair<string,string> & right){
        return (left.first + left.second) <(right.first + right.second);
    });
    return sortedChords;
}

map<string,vector<pair<string,string>>> groupNames(vector<pair<string,string>> names){
    map<string,vector<pair<string,string>>> groupedNames = map<string,vector<pair<string,string>>>();
    for_each(names.begin(),names.end(),[&groupedNames](const pair<string,string> & name){
        if(groupedNames.find(name.first)==groupedNames.end())
                groupedNames[name.first] = vector<pair<string,string>>();
        groupedNames[name.first].push_back(name);
    });
    return groupedNames;
}

map<string, vector<string>> groupChordNamesByRoot(vector<pair<string,string>> names){
    map<string,vector<string>> rootsToChords = map<string,vector<string>>();

    for (auto nameIterator = names.begin(); nameIterator != names.end(); ++nameIterator)
    {
        if(rootsToChords.find(nameIterator->first)==rootsToChords.end()){
            rootsToChords[nameIterator->first] = vector<string>();
        }
        rootsToChords[nameIterator->first].push_back(nameIterator->second);
    }

    return rootsToChords;
    
}








