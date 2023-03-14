#include <iostream>
using namespace std;

int main() {
   int n;
   cout << "Please enter a number: ";
   cin >> n;
   while (n < 3 || n > 9) {
      cout << "Invalid input. Please enter a number between 3 and 9 (inclusive): ";
      cin >> n;
   }
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
         cout << "*";
      }
      cout << endl;
   }
   for (int i = n - 1; i >= 1; i--) {
      for (int j = 1; j <= i; j++) {
         cout << "*";
      }
      cout << endl;
   }
   return 0;
}
