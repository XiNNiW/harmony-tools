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
    std::istringstream stringStream(str);
    std::copy(std::istream_iterator<std::string>(stringStream),
         std::istream_iterator<std::string>(),
         std::back_inserter(chunks));

    return chunks;
}

vector<int> convertStringOfIntsToVector(const string intsAsString){
    vector<int> ints = vector<int>();
    vector<string> chunks = split(intsAsString);
    
    for (size_t i = 0; i < chunks.size(); i++)
    {

        //if(isdigit(chunks[i])){
        ints.push_back(stoi(chunks[i]));
        //}
        
    }

    return ints;
    
}

int main(int argc, char* argv[], char* envp[]){

    if(argc>2){
        vector<int> scale = convertStringOfIntsToVector(argv[1]);
        vector<int> triad = convertStringOfIntsToVector(argv[2]);

        vector<vector<int>> chords = findPossibleTintintabulationHarmony_4NoteChords(scale, triad);
        set<string> names = findAllUniqueChordNamesInVectorOfChords(chords);

        std::for_each(names.begin(), names.end(), [](const std::string & name)
                                                {
                                                    if(name!="?"){
                                                        std::cout << name;
                                                        std::cout << "\n";
                                                    }
                                                });

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

