#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kadanesAlgo(int arr[], int n){
    int currSum = 0, maxSum = INT_MIN;
    for(int i = 0; i<n;i++){
        currSum = currSum + arr[i];
        if(currSum < 0){
            currSum = 0;
        }
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}

int main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << kadanesAlgo(arr, n) << endl;
    return 0;
}