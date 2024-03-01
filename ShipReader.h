#pragma once
#include <fstream>
#include <map>
#include <string>
#include <vector>

class ShipReader {
private:
  std::ifstream file;
  unsigned int numOfShips;
  std::vector<std::string> shipNames;
  std::vector<std::string> shipClasses;
  std::vector<int> shipLength;
  std::vector<int> shipShieldCapacity;
  std::vector<double> shipWarpSpeed;
  std::map<std::string, std::pair<int, float>> shipWeapons;

public:
  ShipReader();
  ShipReader(std::string _file);
};
