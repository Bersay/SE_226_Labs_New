#include <iostream>
#include <cmath>

using namespace std;

double sum_calculator(int n, int k) {
    if (k > n) {
        return 0;
    }
    return (pow(-1, k + 1) / k) + sum_calculator(n, k + 1);
}

double sum_calculator() {
    int n;
    cout << "Enter the value for n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number!" << endl;
        return -1;
    }

    return sum_calculator(n, 1);
}

int main() {
    double result = sum_calculator();
    if (result != -1) {
        cout << "The result is: " << result << endl;
    }
    return 0;
}