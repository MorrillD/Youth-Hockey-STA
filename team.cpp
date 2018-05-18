/*
  Dylan Morrill
  Team Class implementation
*/

/*basic constructor, default name to unknown*/
Team::Team(string teamName) {
  name = teamName;
}

/*destructor, empty roster*/
Team::~Team() {
  roster.clear();
}

/*add player to the roster(map), default stats to 0*/
void Team::addPlayer(string name) {
  stats temp;
  temp.goals = 0;
  temp.assists = 0;
  temp.points = 0;
  temp.pim = 0;
  temp.ppg = 0;
  temp.ppa = 0;
  temp.shg = 0;
  temp.sha = 0;

  roster.insert(pair<string, stats>(name, temp));
}

/*remove player, reducing size of the roster*/
bool Team::removePlayer(string name) {
  map<string, stats>::iterator itr;

  itr = roster.find(name);
  if(itr == roster.end()) {
    return false;
  }

  roster.erase(name);
  return true;
}

/*update all stats, add each stats from previous "game"*/
bool Team::updateStats(string name, int g, int a, int pim, int ppg, int ppa, int shg, int sha) {
  map<string, stats>::iterator itr;

  itr = roster.find(name);
  if(itr == roster.end()) {
    return false;
  }

  roster[name].goals += g;
  roster[name].assists += a;
  roster[name].points += (g + a);
  roster[name].pim += pim;
  roster[name].ppg += ppg;
  roster[name].ppa += ppa;
  roster[name].shg += shg;
  roster[name].sha += sha;
  return true;
}

/*search through map for player, print name and stats*/
bool Team::findPlayer(string name) {
  map<string, stats>::iterator itr;

  itr = roster.find(name);
  if(itr == roster.end()) {
    return false;
  }

  printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", name.c_str(), roster[name].goals, roster[name].assists, roster[name].points, roster[name].pim, roster[name].ppg, roster[name].ppa, roster[name].shg, roster[name].sha);
  return true;
}

/*print team name,each player on the team, and their stats*/
void Team::dumpRoster() {
  for(map<string, stats>::iterator itr = roster.begin(); itr != roster.end(); ++itr) {
    printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", itr->first.c_str(), itr->second.goals, itr->second.assists, itr->second.points, itr->second.pim, itr->second.ppg, itr->second.ppa, itr->second.shg, itr->second.sha);
  }
}