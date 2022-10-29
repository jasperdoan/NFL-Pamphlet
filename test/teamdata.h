#ifndef TEAM_DATA_H
#define TEAM_DATA_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

namespace NFLData
{
    const int W = 15;

    enum Conference {NFC, AFC};
    enum Division {NORTH, SOUTH, EAST, WEST};
    enum RoofType {OPEN, RETRACTABLE, FIXED};

    class TeamData
    {
        private:
            string teamName;
            string stadiumName;
            int capacity;
            string location;
            Conference conference;
            Division division;
            string surfaceType;
            RoofType roofType;
            int yearOpened;
        
        public:
            TeamData(string, string , int, string, Conference, Division, string, RoofType, int);
            void print();
    };

    void readData(vector<TeamData> &, const string );
};

#endif