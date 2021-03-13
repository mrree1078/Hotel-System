#include <iostream>
#include <string>
#include "Room.h"

#ifndef Guest_H // include guard
#define Guest_H

using namespace std;

class Guest
{
private:
  string Surname;
  float totalBill;

public:
  // Constructor
  Guest ();
  Guest (const string _Surname) : Surname(_Surname) {
    // Initialising the bill to zero
    totalBill = 0;
  }

  // Destructor
  ~Guest(){
    cout << Surname << " has now checked out of the hotel with a final bill of \x9c" << totalBill<< endl;
  }

  // Functions
  void GuestCheckin();

  string getName() {
    return Surname;
  }

  void Charges()
  {

    bool done = false;
    string query;
    float outstandingCharge;

    while (!done)
    {
      cout << "Does the guest have any outstanding charges?" << endl;
      cin >> query;
      if (query == "Yes" || query == "Y" || query == "y")
      {
        cout << "Please enter the outstanding charge: " << endl;
        cin >> outstandingCharge;

        totalBill = totalBill + outstandingCharge;
      }
      else
      {
        done = true;
      }
    }
  }

  float getBill() {
    return totalBill;
  }
};

void Room::GuestCheckin ()
{
  cout << "What is the guests name?" << endl;
  cin >> _Surname;
}

#endif
