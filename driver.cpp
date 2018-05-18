#include <iostream>
#include <string>
#include "team.h"

using namespace std;

int main() {
  string nameHolder;

  cout << "Enter team name: ";
  cin >> nameHolder;

  Team newTeam(nameHolder);
}