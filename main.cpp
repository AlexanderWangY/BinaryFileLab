#include "ShipReader.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;
int main() {

  ShipReader ships;

  cout << "Which file(s) to open?\n";
  cout << "1. friendlyships.shp" << endl;
  cout << "2. enemyships.shp" << endl;
  cout << "3. Both files" << endl;
  int option;
  cin >> option;

  if (option == 1) {
    ships.loadFile("friendlyships.shp");
    ships.loadShips();
  } else if (option == 2) {
    ships.loadFile("enemyships.shp");
    ships.loadShips();
  } else if (option == 3) {
    ships.loadFile("friendlyships.shp");
    ships.loadShips();
    ships.loadFile("enemyships.shp");
    ships.loadShips();
  } else {
    cout << "Not a valid selection! \n";
  }

  cout << "1. Print all ships" << endl;
  cout << "2. Starship with the strongest weapon" << endl;
  cout << "3. Strongest starship overall" << endl;
  cout << "4. Weakest ship (ignoring unarmed)" << endl;
  cout << "5. Unarmed ships" << endl;

  cin >> option;

  if (option == 1) {
    ships.displayShips();
  } else if (option == 2) {
    ships.displayStrongestWeapon();
  } else if (option == 3) {
    ships.displayStrongest();
  } else if (option == 4) {
    ships.displayWeakest();
  } else if (option == 5) {
    ships.displayUnarmed();
  }

  // Work your magic here
  return 0;
}
