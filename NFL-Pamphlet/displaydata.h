#ifndef DISPLAYDATA_H
#define DISPLAYDATA_H

#include "teamdata.h"

using namespace NFLData;

class DisplayData
{
    protected:
        static vector<TeamData> teamData;
        static vector<TeamData> originalData;
        static vector<TeamData> filteredData;
    
    public:
        void readData(vector<TeamData> &, const string );
};

#endif