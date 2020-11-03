#include "src/tintintabulation.h"
#include "src/chord-names.h"
#include <iostream>
#include <iomanip>
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
            formatted = "\e[33m" + word + "\e[37m";
        } else {
            formatted = "\e[34m" + word + "\e[37m";
        }
        formattedChunks+=" "+formatted;
    });

    return formattedChunks;

}

int main(int argc, char* argv[], char* envp[]){

    if(argc>2){
        // vector<int> scale = convertStringOfIntsToVector(argv[1]);
        // vector<int> triad = convertStringOfIntsToVector(argv[2]);        
        vector<int> scale = noteNamesToNoteNumbers(split(argv[1]));
        vector<int> triad = noteNamesToNoteNumbers(split(argv[2]));

        set<set<int>> chords = findPossibleTintintabulationHarmony(scale, triad);
        map<int,vector<vector<int>>> mapOfChordsByNumberOfNotes = groupChordsByNumberOfNotes(chords);
        int countOfFoundChords=0;
        std::cout << "\a";
        std::cout << "---------------------------------------"<< "\n";
        std::cout << "scale: " << boldSpecificNotes(spellNotes<vector<int>>(scale),triad) << "\n" << "chord: " 
                << boldSpecificNotes(spellNotes<vector<int>>(triad),triad) <<  "\n";

        
        for (std::pair<int, vector<vector<int>>> pairOfNumberOfNotesToChords : mapOfChordsByNumberOfNotes) {
            map<string,vector<string>> uniqueChordsByRoot = 
                groupChordNamesByRoot(
                    sortNames(
                        filterToUniqueNames(
                            findAllChordNamesInVectorOfChords(pairOfNumberOfNotesToChords.second)
                        )   
                    )
                );

            if(uniqueChordsByRoot.size()>0){
                
                std::cout   << "---------------------------------------" <<"\n"
                            << pairOfNumberOfNotesToChords.first <<" note chords: "<<"\n"
                            << "---------------------------------------"<<"\n";

                
                for(pair<string,vector<string>> chordFamily:uniqueChordsByRoot){

                    string rootName = chordFamily.first;
                    vector<string> chordTypes = chordFamily.second;
                    countOfFoundChords+=chordTypes.size();

                    auto printRow = [](string chordName, string chordSpelling){
                        std::cout  << std::left << setw(18) << chordName << setw(18) << chordSpelling << std::right   << "\n";
                    };


                    auto printChord = [&countOfFoundChords,rootName,printRow,triad](const string & chordTypeName)
                    {
                        printRow( rootName + chordTypeName , boldSpecificNotes(spellChordByName(pair<string,string>{rootName,chordTypeName}),triad));
                        
                    };



                    for_each(chordTypes.begin(), chordTypes.end(),printChord);
                    std::cout << "\n";


                }
                
                // std::for_each(uniqueChordsByRoot.begin(), uniqueChordsByRoot.end(), printChord);
            
            }
            
            
        }
        std::cout << "...\n";
        std::cout << (chords.size()-countOfFoundChords) << " could not be named...\n";
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

