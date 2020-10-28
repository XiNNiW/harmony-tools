#include "src/tintintabulation.h"
#include "src/chord-names.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

vector<string> split(const std::string& str)
{   
    vector<string> chunks = vector<string>();
    istringstream stringStream(str);
    copy(istream_iterator<string>(stringStream),
         istream_iterator<string>(),
         back_inserter(chunks));

    return chunks;
}

vector<int> convertStringOfIntsToVector(const string intsAsString){
    vector<int> ints = vector<int>();
    vector<string> chunks = split(intsAsString);

    std::for_each(chunks.begin(),chunks.end(),[&](string & chunk){
        ints.push_back(stoi(chunk));
    });

    return ints;
}

string makeNSpaces(int n){
    string output = "";
    if(n>0){
        for (size_t i = 0; i < n; i++)
        {
            output+=" ";
        }
    }
    return output;
}

string boldSpecificNotes(const string outputToFormat, const vector<int> notesToBold){
    set<string> noteNamesToBold = set<string>();
    std::for_each(notesToBold.begin(),notesToBold.end(),[&noteNamesToBold](const int & note){
        noteNamesToBold.insert(NOTES_TO_NAME[note%12]);
    });

    vector<string> chunks = split(outputToFormat);

    string formattedChunks = "";

    std::for_each(chunks.begin(),chunks.end(),[&formattedChunks,noteNamesToBold](const string & word){
        string formatted = word;
        if(noteNamesToBold.end()!=find(noteNamesToBold.begin(),noteNamesToBold.end(),word)){
            formatted = "\e[1m" + word + "\e[0m";
        }
        formattedChunks+=formatted+" ";
    });

    return formattedChunks;

}

int main(int argc, char* argv[], char* envp[]){

    if(argc>2){
        vector<int> scale = convertStringOfIntsToVector(argv[1]);
        vector<int> triad = convertStringOfIntsToVector(argv[2]);

        vector<vector<int>> chords = findPossibleTintintabulationHarmony_4NoteChords(scale, triad);
        vector<pair<string,string>> allNames = findAllChordNamesInVectorOfChords(chords);
        vector<pair<string,string>> names = sortNames(filterToUniqueNames(allNames));

        std::cout << "\a";
        std::cout << "---------------------------------------\n";
        std::cout << "scale: " << spellNotes<vector<int>>(scale)<< "\n" << "chord: " << spellNotes<vector<int>>(triad) << "\n";

        std::cout << "---------------------------------------\n";
        std::cout << "found " << names.size() << " chords: \n";
        std::cout << "---------------------------------------\n";
        
        auto printIfKnown = [=](const pair<string,string> & name)
        {
            if(name.first!="?"){
                std::cout << name.first << name.second << makeNSpaces(12-(name.first+name.second).size()) << "-\t" << boldSpecificNotes(spellChordByName(name),triad);
                std::cout << "\n";
            }
        };

        std::for_each(names.begin(), names.end(), printIfKnown);
        std::cout << "...\n";
        std::cout << (allNames.size()-names.size()) << " could not be named or were redundant...\n";
        std::cout << "...\n";

    } else {
        std::cout << "tintintabulation chord combination helper";
        std::cout << "\n";
        std::cout << "call with a scale and a chord to generate a list of chords from the scale containing at least one note from the chord";
        std::cout << "\n";
        std::cout << "EX) chord-pallet \"0 2 4 5 7 9 11\" \"1 4 8\"";
    }

    std::cout << "\n";

    return 0;
}

