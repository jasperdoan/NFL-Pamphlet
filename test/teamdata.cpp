#include "teamdata.h"


NFLData::TeamData::TeamData(string teamName, string stadiumName, int capacity, string location, Conference conference, Division division, string surfaceType, RoofType roofType, int yearOpened)
                 : teamName(teamName), stadiumName(stadiumName), capacity(capacity), location(location), conference(conference), division(division), surfaceType(surfaceType), roofType(roofType), yearOpened(yearOpened) { }



void NFLData::TeamData::print()
{
    cout << left;
    cout << setw(W) << "Team Name: "    << teamName     << endl;
    cout << setw(W) << "Stadium Name: " << stadiumName  << endl;
    cout << setw(W) << "Capacity: "     << capacity     << endl;
    cout << setw(W) << "Location: "     << location     << endl;
    cout << setw(W) << "Conference: "   << (const string[]){"NFC", "AFC"}[conference]                   << endl;
    cout << setw(W) << "Division: "     << (const string[]){"NORTH", "SOUTH", "EAST", "WEST"}[division] << endl;
    cout << setw(W) << "Surface Type: " << surfaceType  << endl;
    cout << setw(W) << "Roof Type: "    << (const string[]){"OPEN", "RETRACTABLE", "FIXED"}[roofType]   << endl;
    cout << setw(W) << "Year Opened: "  << yearOpened   << endl;
}


///-/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// READ DATA FUNC [namespace NDLData]
///
void NFLData::readData(vector<TeamData> &teams, const string FILENAME)
{
    ifstream file(FILENAME);                                // Open file
    
    string teamName, stadiumName, location, surfaceType;    // Variables to hold data
    int capacity, yearOpened;
    NFLData::Conference conference;
    NFLData::Division division;
    NFLData::RoofType roofType;

    string line, strEnum;
    int pos, nextPos;


    // Generic lambda expression to find each col(s) of data
    //      Looks for a starting pos, and next pos based on ','
    //      Returns a string
    auto findStringData = [&]()
    {
        string tempStr;

        nextPos = line.find(',', pos);
        tempStr = line.substr(pos, nextPos - pos);
        pos = nextPos + 1;

        return tempStr;
    };



    try
    {
        if (!file) { throw 20; }            // If file could not be opened, throw error 20
        while (getline(file, line))         // While is still able to get new line (!eof)
        {
            pos = 0;                        // Set current pos
            nextPos = 0;                    // Set next pos

            // Team name
            teamName = findStringData();

            // Stadium name
            stadiumName = findStringData();

            // Capacity
            capacity = stoi(findStringData());
            
            // Location
            nextPos = line.find(',', line.find(',', pos) + 1);
            location = line.substr(pos, nextPos - pos);
            pos = nextPos + 1;

            // Conference
            strEnum = findStringData();
            switch (strEnum[0])
            {
                case 'N': conference = NFLData::NFC; break;
                case 'A': conference = NFLData::AFC; break;
            }

            // Divison
            strEnum = findStringData();
            switch (strEnum[0])
            {
                case 'N': division = NFLData::NORTH; break;
                case 'S': division = NFLData::SOUTH; break;
                case 'E': division = NFLData::EAST; break;
                case 'W': division = NFLData::WEST; break;
            }

            // Surface type
            surfaceType = findStringData();

            // Roof type
            strEnum = findStringData();
            switch (strEnum[0])
            {
                case 'O': roofType = NFLData::OPEN; break;
                case 'R': roofType = NFLData::RETRACTABLE; break;
                case 'F': roofType = NFLData::FIXED; break;
            }

            // Year opened
            yearOpened = stoi(findStringData());
            
            
            teams.push_back(NFLData::TeamData(teamName, stadiumName, capacity, location, conference, division, surfaceType, roofType, yearOpened));
        }
    }
    catch (int e)
    {
        cout << "Error occurred | Unexpected results: " << e << endl;
    }


    file.close();
}