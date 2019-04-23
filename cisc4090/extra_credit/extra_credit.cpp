/*
 * Ezriel Ciriaco
 * CISC 4090 L01
 * Due: 25 April 2019
 * EC2: Program that outputs the pairs of integers contained in the vector that add up to the specified value of SUM.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>

const int SIZE = 8; // Prevent users from entering an absurd value for DIST_INT for vector initialization.

using namespace std;

void user_input(int &a, int &b);
bool valid_input(int a);
void initialize_vector(vector<int> &v, int a);
void print_vector(vector<int> v, int a);

int main() {
  srand(time(NULL));
  vector<int> vector;
  int DIST_INT = 0;
  int SUM = 0;

  do {
    user_input(DIST_INT, SUM);
    if (!valid_input(DIST_INT))
      cout << "\nThese values are invalid!\n";
  } while (!valid_input(DIST_INT));

  initialize_vector(vector, DIST_INT);
  print_vector(vector, DIST_INT);

  return 0;
}

void user_input(int &a, int &b) {
  cout << "\nNumber of Distinct Integers (Must be <= 8): ";
  cin >> a;
  while (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "\nPlease enter an INTEGER for Distinct Integers: ";
    cin >> a;
  }
  cout << "\nValue for SUM: ";
  cin >> b;
  while (cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cout << "\nPlease enter an INTEGER for SUM: ";
    cin >> b;
  }
}

bool valid_input(int a) {
  if (a <= SIZE)
    return true;
  else
    return false;
}

void initialize_vector(vector<int> &v, int a) {
  int unique = 0;
  vector<int>::iterator it;
  for (int i = 0; i < a; i++) {
    while (it != v.end()) {
      unique = (double) 9 * rand() / RAND_MAX;
      it = find(v.begin(), v.end(), unique);
    }
      v.push_back(unique);
  }
}

void print_vector(vector<int> v, int a) {
  cout << "\nVector: ";
  for (int i = 0; i < v.size(); i++)
    cout << setw(2) << v[i];
  cout << endl;
}
