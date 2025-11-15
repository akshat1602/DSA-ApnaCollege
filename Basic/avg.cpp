#include <iostream>
using namespace std;

int main() {
   float maths;
   float physics;
   float chemistry;

   cout << "Enter marks for Maths: ";
   cin >> maths;
   cout << "Enter marks for Physics: ";
   cin >> physics;
   cout << "Enter marks for Chemistry: ";
   cin >> chemistry;

   float average = (maths + physics + chemistry) / 3;

   cout << "The average is: " << average << endl;

    return 0;
}