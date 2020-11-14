#pragma once

#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

namespace HarmonyTools::Parsing{
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
}
