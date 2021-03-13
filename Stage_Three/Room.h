#include <iostream>
#include <string>
#include "Guest.h"

#ifndef Room_H // include guard
#define Room_H

using namespace std;

class Room
{

  int roomNumber;
  float roomCost;

public:

  // Constructor
  Room ()
  {
    roomNumber = 0;
    roomCost = 0;
  };

  Room (int roomNo, float cost)
  {
    roomNumber = roomNo;
    roomCost = cost;
  };

  // Functions
  void setRoomNumber(int roomNo);
  void setRoomCost(float cost);


  int status = 0;
  int count = 0;
  int findRooms;
  int getRoomNumber();
  float getRoomCost();

};

void Room::setRoomNumber (int roomNo)
{
  roomNumber = roomNo;
}

void Room::setRoomCost (float cost)
{
  roomCost = cost;
}

int Room::getRoomNumber ()
{
  return roomNumber;
}

float Room::getRoomCost ()
{
  return roomCost;
}



Guest* guests[10];
#endif
