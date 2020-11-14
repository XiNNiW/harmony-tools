#include "src/tintintabulation.h"
#include "src/chord-names.h"
#include "src/parsing-util.h"
#include "src/printing-util.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace HarmonyTools::Parsing;
using namespace HarmonyTools::Tintintabulation;
using namespace HarmonyTools::ChordNames;
using namespace HarmonyTools::Printing;
using namespace std;


int main(int argc, char* argv[], char* envp[]){

    if(argc>2){
       
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
        std::cout << "EX) ./chord-pallet \"D E F G A Bb C\" \"D F# A\"";
    }

    std::cout << "\n";

    return 0;
}

