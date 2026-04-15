#include <iostream>
using namespace std;

void reverseNum() {
    int n;
    cin >> n;
    int revNum = 0;

    while (n > 0) {                           // just perform one thing which is reverseNUmber = (reverseNumber * 10) + lastDigit
        int ld = n % 10;                      //you will get the reverse number
        revNum = (revNum * 10) + ld;
        n = n / 10;
    }

    cout << revNum;
}

int main() {
    reverseNum();
    return 0;
}