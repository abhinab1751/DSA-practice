#include <iostream>
using namespace std;

int peakIndex(int arr[], int n){
    int st = 0;
    int end = n - 1;

    while(st < end){
        int mid = st + (end - st) / 2;

        if(arr[mid] < arr[mid + 1]){
            st = mid + 1;
        }
        else{
            end = mid;
        }
    }

    return st;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << peakIndex(arr, n) << endl;

    return 0;
}