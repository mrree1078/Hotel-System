#include <iostream>
#include <string>

using namespace std;

class Guest
{
private:
  string Surname;
  float totalBill;

public:
  // Constructor
  Guest (const string _Surname) : Surname(_Surname)
  {
    // Initialising the bill to zero
    totalBill = 0;
    cout << "What is the guests room bill?" << endl;
    cin >> totalBill;
    cout << "The guest " << Surname << "'s bill is \x9c" << totalBill << endl << endl;
  }

  // Destructor
  ~Guest()
  {
    cout << Surname << " has now checked out of the hotel with a final bill of \x9c" << totalBill<< endl;
  }

  // Functions

  string getName()
  {
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

  float getBill()
  {
    return totalBill;
  }
};

int main() {

  string _Surname;

  cout << "What is the guests name?" << endl;
  cin >> _Surname;

  Guest FirstGuest (_Surname);

  FirstGuest.Charges();

  cout << "\nThe Guests name is " << FirstGuest.getName() << endl;
  cout << "The Guests total bill is \x9c" << FirstGuest.getBill() << endl << endl;

  return 0;
};
