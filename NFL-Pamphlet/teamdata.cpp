#include "teamdata.h"


NFLData::TeamData::TeamData(string teamName, string stadiumName, int capacity, string location, Conference conference, Division division, string surfaceType, RoofType roofType, int yearOpened)
                 : teamName(teamName), stadiumName(stadiumName), capacity(capacity), location(location), conference(conference), division(division), surfaceType(surfaceType), roofType(roofType), yearOpened(yearOpened) { }


NFLData::TeamData::~TeamData() { }

string NFLData::TeamData::getTeamName() { return teamName; }
string NFLData::TeamData::getStadiumName() { return stadiumName; }
int NFLData::TeamData::getCapacity() { return capacity; }
string NFLData::TeamData::getLocation() { return location; }
string NFLData::TeamData::getConference() { return (const string[]){"National Football Conference", "American Football Conference"}[conference]; }
string NFLData::TeamData::getDivision() { return (const string[]){"North", "South", "East", "West"}[division]; }
string NFLData::TeamData::getSurfaceType() { return surfaceType; }
string NFLData::TeamData::getRoofType() { return (const string[]){"Open", "Retractable", "Fixed"}[roofType]; }
int NFLData::TeamData::getYearOpened() { return yearOpened; }
