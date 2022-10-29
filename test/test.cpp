#include "teamdata.h"

// TODO: Use pointers to read data
//       write cleaner code + reorganize
//       take expansion into account

int main()
{
    const string FILENAME = "../data/NFL_Information.csv";
    
    vector<NFLData::TeamData> teamData;


    readData(teamData, FILENAME);

    for (int i = 0; i < teamData.size(); i++)
    {
        teamData[i].print();
        cout << endl << endl;
    }


    return 0;
}