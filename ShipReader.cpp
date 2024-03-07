#include "ShipReader.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

ShipReader::ShipReader() { numOfShips = 0; }

ShipReader::ShipReader(std::string _file) {
  file.open(_file, std::ios::binary);
  numOfShips = 0;
  std::cout << _file << " has been loaded!\n";
}

ShipReader::~ShipReader() {
  if (file.is_open()) {
    file.close();
  }
}

void ShipReader::loadFile(std::string _file) {
  if (file.is_open()) {
    file.close();
  }

  file.open(_file, std::ios::binary);
}

void ShipReader::loadShips() {
  file.read(reinterpret_cast<char *>(&numOfShips), sizeof(int));

  for (int i = 0; i < numOfShips; i++) {
    int lenOfName;
    file.read(reinterpret_cast<char *>(&lenOfName), sizeof(int));

    char *buffer = new char[lenOfName];
    file.read(buffer, lenOfName);

    std::string shipName(buffer, lenOfName - 1);
    delete[] buffer;

    int lenOfClass;
    file.read(reinterpret_cast<char *>(&lenOfClass), sizeof(int));

    buffer = new char[lenOfClass];
    file.read(buffer, lenOfClass);

    std::string shipClass(buffer, lenOfClass - 1);

    delete[] buffer;

    short int shipLength;

    file.read(reinterpret_cast<char *>(&shipLength), sizeof(short int));

    int shipShield;

    file.read(reinterpret_cast<char *>(&shipShield), sizeof(int));

    float shipWarp;

    file.read(reinterpret_cast<char *>(&shipWarp), sizeof(float));

    Ship newShip;
    newShip.name = shipName;
    newShip.shipClass = shipClass;
    newShip.length = shipLength;
    newShip.shieldCapacity = shipShield;
    newShip.warpSpeed = shipWarp;
    int numOfWeapons;

    file.read(reinterpret_cast<char *>(&numOfWeapons), sizeof(int));

    for (int x = 0; x < numOfWeapons; x++) {
      this->loadWeapons(newShip);
    }

    ships.push_back(newShip);
  }
}

void ShipReader::loadWeapons(Ship &newShip) {
  Weapon weapon;
  char *buffer;
  int nameLength;

  file.read(reinterpret_cast<char *>(&nameLength), sizeof(int));
  buffer = new char[nameLength];

  file.read(buffer, nameLength);

  std::string weaponName(buffer, nameLength - 1);

  delete[] buffer;
  weapon.name = weaponName;

  int weaponPower;

  file.read(reinterpret_cast<char *>(&weaponPower), sizeof(int));

  weapon.powerRating = weaponPower;

  float weaponPowerConsump;

  file.read(reinterpret_cast<char *>(&weaponPowerConsump), sizeof(float));

  weapon.powerConsump = weaponPowerConsump;

  newShip.weapons.push_back(weapon);
}

void ShipReader::displaySingleShip(Ship ship) {

  std::cout << "Name: " << ship.name << "\n";
  std::cout << "Class: " << ship.shipClass << "\n";

  if (ship.length > 0) {
    std::cout << "Length: " << ship.length << "\n";
  }
  std::cout << "Shield capacity: " << ship.shieldCapacity << "\n";
  std::cout << "Maximum Warp: " << ship.warpSpeed << "\n";
  std::cout << "Armaments: \n";

  if (ship.weapons.size() == 0) {
    std::cout << "Unarmed\n";
  } else {
    int totalPower = 0;
    for (Weapon w : ship.weapons) {
      std::cout << w.name << ", " << w.powerRating << ", " << w.powerConsump
                << "\n";
      totalPower += w.powerRating;
    }

    std::cout << "Total firepower: " << totalPower << "\n";
  }

  std::cout << "\n";
}

void ShipReader::displayShips() {
  for (Ship currShip : ships) {
    this->displaySingleShip(currShip);
  }
}

void ShipReader::displayStrongestWeapon() {
  Ship maxShip;
  Weapon maxWeapon;
  for (Ship currShip : ships) {
    for (Weapon w : currShip.weapons) {
      if (w.powerRating > maxWeapon.powerRating) {
        maxShip = currShip;
        maxWeapon = w;
      }
    }
  }

  this->displaySingleShip(maxShip);
}

void ShipReader::displayStrongest() {
  Ship maxShip;
  int maxPower = 0;

  for (Ship currShip : ships) {
    int power = 0;
    if (currShip.weapons.size() != 0) {
      for (Weapon w : currShip.weapons) {
        power += w.powerRating;
      }

      if (power > maxPower) {
        maxPower = power;
        maxShip = currShip;
      }
    }
  }

  this->displaySingleShip(maxShip);
}

void ShipReader::displayWeakest() {
  Ship minShip;
  int minPower = 0;

  for (Ship s : ships) {
    int power = 0;

    if (s.weapons.size() != 0) {
      for (Weapon w : s.weapons) {
        power += w.powerRating;
      }

      if (minPower == 0 || power < minPower) {
        minPower = power;
        minShip = s;
      }
    }
  }

  this->displaySingleShip(minShip);
}

void ShipReader::displayUnarmed() {
  for (Ship s : ships) {
    if (s.weapons.size() == 0) {
      this->displaySingleShip(s);
    }
  }
}
