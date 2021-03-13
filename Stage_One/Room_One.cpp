#include <iostream>
#include <string>

using namespace std;

class Room
{
  int roomNumber;
  float roomCost;

public:

  Room (int roomNo, float cost)
  {
    roomNumber = roomNo;
    roomCost = cost;
  };

  int getRoomNumber();
  float getRoomCost();
};

// Functions

int Room::getRoomNumber()
{
  return roomNumber;
}

float Room::getRoomCost()
{
  return roomCost;
}

int main() {

  Room room1 (1, 55.5);

  cout << "The room number is: " << room1.getRoomNumber() << endl;
  cout << "The room cost is \x9c" << room1.getRoomCost() << endl;

  return 0;
};
