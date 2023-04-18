#include <iostream>
#include <cmath>

using namespace std;

double sum_calculator(int n, int k = 1) {
    if (k > n) {
        return 0;
    }
    return (pow(-1, k + 1) / k) + sum_calculator(n, k + 1);
}

int main() {
    int n;
    cout << "Enter the value for n: ";
    cin >> n;

    if (n > 0) {
        double result = sum_calculator(n);
        cout << "The result is: " << result << endl;
    } else {
        cout << "Please enter a positive number!" << endl;
    }

    return 0;
}