/*
  Dylan Morrill
  Team Class defenitions
*/

#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct stats {
  int goals;
  int assists;
  int points;   //goals + assists
  int pim;    //penalty minutes
  int ppg;    //power play goals
  int ppa;    //power play assists
  int shg;    //short hand goals
  int sha;    //short hand assists
};

class Team {
  private:
    map<string, stats> roster;
    string name;

  public:
    /*basic constructor, default name to unknown*/
    Team(string teamName = "UNKNOWN");

    /*destructor*/
    ~Team();

    /*add player to the roster(map), default stats to 0*/
    void addPlayer(string name);

    /*remove player, reducing size of the roster*/
    bool removePlayer(string name);

    /*update all stats, add each stats from previous "game"*/
    bool updateStats(string name, int g, int a, int pim, int ppg, int ppa, int shg, int sha);

    /*search through map for player, print name and stats*/
    bool findPlayer(string name);

    /*print team name,each player on the team, and their stats*/
    void dumpRoster();
};

#include "team.cpp"
#endif