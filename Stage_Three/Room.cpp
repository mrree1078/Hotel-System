#include <iostream>
#include <string>

using namespace std;

class Room
{

public:
  int roomNumber;
  float roomCost;
  float night;
  float calculatedRoomCost;

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

  int getRoomNumber();
  float getRoomCost();
  float noNights();
  void setOvernight();
};

// Room Functions

float Room::noNights()
{
  return night;
}

void Room::setOvernight()
{
  cout << "how many nights has the guest stayed in the room?" << endl;
  cin >> night;
}

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

class Guest
{
  string surname;
  string _Surname;
  float totalBill = 0;
public:
  Guest ();
  ~Guest()
  {
    cout << endl << endl << surname << " has now checked out of the hotel" << endl;
  }

  // Functions

  void charges();
  string getName();
  float getBill();
  void arrival();
  void display();
};

// Guest Functions

string Guest::getName()
{
  return surname;
}

float Guest::getBill()
{
  return totalBill;
}

void Guest::charges()
{
  string query;
  float outstandingCharge;

  cout << "Does the guest have any outstanding charges?" << endl;
  cin >> query;
  if (query == "Yes" || query == "Y" || query == "y")
  {
    cout << "Please enter the outstanding charge: " << endl;
    cin >> outstandingCharge;

    totalBill = totalBill + outstandingCharge;
  }
  else
    totalBill = totalBill;
}

void Guest::arrival()
{
  cout << endl << endl << "Enter the guests name: ";
  cin >> surname;
}

void Guest::display()
{
  cout << surname;
}

Guest::Guest()
{
	cout << endl << endl << "A guest has arrived " << endl;
}

// Main Program

int main() {

float finalBill;
float calculatedRoomCost;

Guest *guests[10];
Room roomNumbers[10];
float data[][2] = {{1,100},{2,90},{3,85.5},{4,80},{5,80},{6,50},{7,50},{8,45.5},{9,45.5},{10,40}};

int i, checkIn, c=-1;

for (i = 0; i < 10; i++)
{
  roomNumbers[i].setRoomNumber(data [i] [0]);
  roomNumbers[i].setRoomCost(data [i] [1]);
}

cout << endl << endl << " Enter 1 for Check-ins, 2 for Check-outs, 0 to quit simulation ";
cin >> checkIn;
while (checkIn != 0)
{
if (checkIn == 1)
  if (c < 10)
  {
    c++;

    roomNumbers[c].setRoomNumber(data [c] [0]);
    roomNumbers[c].setRoomCost(data [c] [1]);
    guests[c] = new Guest;
    guests[c] -> arrival();

    // Display allocated rooms
    cout << endl << endl;
    guests[c] -> display();
    cout << " has been allocated to room " << roomNumbers[c].getRoomNumber();
    cout << endl << endl;

    roomNumbers[c].setOvernight();

    // calculate final bill
    guests[c] -> charges();

    cout << "The bill for room " << roomNumbers[c].getRoomNumber() << " has been updated";
  }
  else
    cout << "no rooms available" << endl;
else if (checkIn == 2)
  if (c >= 0)
  {
    calculatedRoomCost = roomNumbers[c].getRoomCost() * roomNumbers[c].noNights();
    finalBill = calculatedRoomCost + guests[c]->getBill();

    cout << endl << "Room Charge: " << calculatedRoomCost << endl << "Extra Charges: " << guests[c]->getBill() << endl << "Final bill: " << finalBill;
    delete guests[c];
    guests[c] = NULL;
    c--;
  }
  else
    cout << "There are no guests left in the hotel" << endl;
  else
  cout << endl << "try again";
  cout << endl << endl << " Enter 1 for Check-ins, 2 for Check-outs, 0 to quit simulation ";
  cin >> checkIn;
}


return 0;
};
