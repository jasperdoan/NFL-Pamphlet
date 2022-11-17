#ifndef DISPLAYDATA_H
#define DISPLAYDATA_H

#include "teamdata.h"

using namespace NFLData;

class DisplayData
{
    protected:
        // TODO: Change to a map (hash tables) instead of using vectors
        //     Time complexity of map is O(1) while vector is O(n)
        //     Space complexity of map is O(n) while vector is O(n)
        // Map is a better choice for this application
        //    Map is a hash table, which is a data structure that stores data in an array format
        //    The key value could be the the sum of the team name's ascii values modded by the size of the array 
        static vector<TeamData> teamData;
        static vector<TeamData> filteredData;
        static vector<TeamData> currentData;
    
    public:
        void readData(vector<TeamData> &, const string );
};

#endif