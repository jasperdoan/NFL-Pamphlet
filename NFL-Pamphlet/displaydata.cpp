#include "displaydata.h"

///-/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// READ DATA FUNC [namespace NFLData]
///
void DisplayData::readData(vector<TeamData> &teams, const string FILENAME)
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
            if (strEnum.find("North") != string::npos) { division = NFLData::NORTH; }
            else if (strEnum.find("South") != string::npos) { division = NFLData::SOUTH; }
            else if (strEnum.find("East") != string::npos) { division = NFLData::EAST; }
            else if (strEnum.find("West") != string::npos) { division = NFLData::WEST; }

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
///-/////////////////////////////////////////////////////////////////////////////////////////////////////////////