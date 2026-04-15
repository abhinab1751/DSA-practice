#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int original = n;
    int count = 0;

    int temp = n;
    while (temp > 0) {
        count++;
        temp = temp / 10;
    }

    int sum = 0;
    temp = n;

    while (temp > 0) {
        int digit = temp % 10;   
        sum += pow(digit, count);
        temp = temp / 10;        
    }

    if (sum == original) {
        cout << "Armstrong Number";
    } else {
        cout << "Not an Armstrong Number";
    }

    return 0;
}