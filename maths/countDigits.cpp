#include <iostream>
using namespace std;

int countDigits(int n){
    int cnt = 0;
    while(n > 0){
        int lastDigit = n % 10;
        cnt = cnt + 1;
        n = n / 10;
    }
    return cnt;
}

int main(){
    int result = countDigits(455);
    cout << result;
}



//for extracting a single digit just use % with 10 it will give you the last digit 
//such as n = 5455 then do n % 10 it will give you the last digit which is 5 and then 
//for next element use / by 10 and keep the count of the digits


//another way we can do it by log base 10 where for example n = 7754 so log base 10 of 7754 will give some 3.82 and if we add + 1
//it be 4 so on adding + 1 we get the number of digits


//int count(int n){
//    int cnt = (int)(log10(n) + 1); 
//    return cnt; 
//}