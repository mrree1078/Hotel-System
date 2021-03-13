#include <iostream>
#include <string>

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

  // Functions
  void setRoomNumber(int roomNo);
  void setRoomCost(float cost);

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

int main()
{

  Room roomNumbers[10];
  float data[10][2] = {{1,100},{2,90},{3,85.5},{4,80},{5,80},{6,50},{7,50},{8,45.5},{9,45.5},{10,40}};

  int i;

  for (i = 0; i < 10; i++)
  {
    roomNumbers[i].setRoomNumber(data [i] [0]); // accessing i as the object array and storing value
    roomNumbers[i].setRoomCost(data [i] [1]);
  }

  for (i = 0; i < 10; i++)
    cout << "Room number " << roomNumbers[i].getRoomNumber() << " cost: \x9c" << roomNumbers[i].getRoomCost() << endl;

return 0;

};
