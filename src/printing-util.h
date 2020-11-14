#pragma once
#include "chord-names.h"
#include "parsing-util.h"

namespace HarmonyTools::Printing{
    using namespace std;
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
            noteNamesToBold.insert(ChordNames::NOTES_TO_NAME[note%12]);
        });

        vector<string> chunks = Parsing::split(outputToFormat);

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


}
