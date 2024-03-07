#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
struct Weapon {
  std::string name;
  int powerRating;
  float powerConsump;
};

struct Ship {
  std::string name;
  std::string shipClass;
  short int length;
  int shieldCapacity;
  double warpSpeed;
  std::vector<Weapon> weapons;
};

class ShipReader {
private:
  std::ifstream file;
  int numOfShips;
  std::vector<Ship> ships;

public:
  ShipReader();
  ShipReader(std::string _file);
  ~ShipReader();

  void loadFile(std::string _file);
  void loadShips();
  void loadWeapons(Ship &newShip);
  void displayShips();
  void displaySingleShip(Ship ship);
  void displayStrongest();
  void displayStrongestWeapon();
  void displayWeakest();
  void displayUnarmed();
};
