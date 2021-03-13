#include <iostream>
#include <string>

using namespace std;

class Room
{

public:
  int roomNumber;
  float roomCost, night, calculatedRoomCost;
  bool status;

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

  string _Surname;
  float totalBill = 0;
public:
  string surname;
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
int opt, i, c=-1, selection;

// Arrays Dynamic for Guest, Auto for Room the Data is a 2-dimensional array to store room number and cost

Guest *guests[10];
Room roomNumbers[10];
float data[][2] = {{1,100},{2,90},{3,85.5},{4,80},{5,80},{6,50},{7,50},{8,45.5},{9,45.5},{10,40}};

// This for loop assigns the data array values into roomNumbers

for (i = 0; i < 10; i++)
{
  roomNumbers[i].setRoomNumber(data [i] [0]);
  roomNumbers[i].setRoomCost(data [i] [1]);
  roomNumbers[i].status = false; // This boolean value assigns a false value to a room that has not been allocated at the start all rooms will be false
}

do
{
  system("cls");
  cout<<"######## Hotel Management #########\n";
  cout<<"\n1. Check-In Room";
  cout<<"\n2. Check-Out Room";
  cout<<"\n3. Available Rooms";
  cout<<"\n4. Exit";
  cout<<"\n\nEnter Option: ";
  cin>>opt;
  switch(opt)
  {
    case 1: // assigning the room

    for (c = 0; c < 10; c++)
    {
     if (roomNumbers[c].status == false) // If the room is unoccupied
      {
        // This assigns the guest name and allocates the first available room

        roomNumbers[c].setRoomNumber(data [c] [0]);
        roomNumbers[c].setRoomCost(data [c] [1]);
        guests[c] = new Guest;
        guests[c] -> arrival();

        // Display allocated rooms

        cout << endl << endl;
        guests[c] -> display();
        cout << " has been allocated to room " << roomNumbers[c].getRoomNumber() << endl << endl;
        cout << "The cost of this room will be \x9c" << roomNumbers[c].getRoomCost() << " per night" << endl;
        roomNumbers[c].status = true; // Once a room is occupied assign the boolean value to true
        cout << endl << endl;
        break;
     }
    }
    cout << "Press any key to return to the main menu" << endl;
      getchar();
      getchar();
      break;

    case 2: // checks out room

      cout << "Please enter the room that the guest is checking out from: ";
      cin >> selection;

        if (selection >= 0)
        {
          selection = selection - 1;
          roomNumbers[selection].setOvernight();

          // calculate final bill

          guests[selection] -> charges();

          cout << endl << "The bill for room " << roomNumbers[selection].getRoomNumber() << " has been updated";

          calculatedRoomCost = roomNumbers[selection].getRoomCost() * roomNumbers[selection].noNights();
          finalBill = calculatedRoomCost + guests[selection]->getBill();
          roomNumbers[selection].status = false; // reassigns room to false now the guest as checked out

          cout << endl << endl << endl << "Room Charge: \x9c" << roomNumbers[selection].getRoomCost() << endl << "Nights stayed: " << roomNumbers[selection].noNights() << endl << "Extra Charges: " << guests[selection]->getBill() << endl << "Final bill: " << finalBill << endl;
          delete guests[selection];
          guests[selection] = NULL;
        }
        else
        {
          cout << "There are no guests left in the hotel" << endl;
          cout << endl << "try again";
        }

      cout << "Press any key to return to the main menu" << endl;
      getchar();
      getchar();
      break;

    case 3: // Displays the rooms available

    for (i = 0; i < 10; i++)
    {
      if (roomNumbers[i].status == true)
      {
        cout << "Guest Name: " << guests[i]->surname << " Room No: " << roomNumbers[i].getRoomNumber() << " cost: \x9c" << roomNumbers[i].getRoomCost() << endl;
        cout << endl;
      }
      else
      {
        cout << "Room number " << roomNumbers[i].getRoomNumber() << " is un-occupied" << endl;
      }
    }

    cout << "Press any key to return to the main menu" << endl;
    getchar();
    getchar();
    break;

    case 4:

    cout<<"\nTHANK YOU! FOR USING SOFTWARE";
    break;

    default:

    cout<<"\nPlease Enter correct option";
    break;
  }
}while(opt!=4);

return 0;
};
