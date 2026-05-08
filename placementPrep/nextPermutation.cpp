#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int nextPermutation(vector<int>& arr){
    int n = arr.size();
    int piv = -1;
    for(int i =n-2; i>= 0; i--){
        if(arr[i] < arr[i+1]){
            piv = i;
            break;
        }
    }
    if(piv == -1){
            reverse(arr.begin(), arr.end());
            return 0;
        }
    for(int i = n -1; i > piv ; i--){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[piv]);
            break;
        }
    }
    reverse(arr.begin() + piv + 1, arr.end());
    return 1;
}

int main(){
    vector<int> arr = {1,2,3};
    nextPermutation(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}