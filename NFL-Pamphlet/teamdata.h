#ifndef TEAM_DATA_H
#define TEAM_DATA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

namespace NFLData
{
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
            ~TeamData();

            string getTeamName();
            string getStadiumName();
            int getCapacity();
            string getLocation();
            string getConference();
            string getDivision();
            string getSurfaceType();
            string getRoofType();
            int getYearOpened();
    };

    void readData(vector<TeamData> &, const string );
};

#endif