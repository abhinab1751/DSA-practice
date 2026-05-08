#include <iostream>
#include <vector>
using namespace std;

int mergeSortedArr(vector<int>& arr1, vector<int>& arr2, int m, int n){
    int idx = m+n-1, i = m-1, j = n-1;
    while(i >= 0 && j >= 0){
        if(arr1[i] > arr2[j]){
            arr1[idx] = arr1[i];
            idx--, i--;
        }
        else{
            arr1[idx] = arr2[j];
            idx--, j--;
        }
    }
}

int main(){
    vector<int> arr1 = {1,2,3,0,0,0};
    vector<int> arr2 = {2,5,6};
    int m = 3, n = 3;
    mergeSortedArr(arr1, arr2, m, n);
    for(int i = 0; i < arr1.size(); i++){
        cout << arr1[i] << " ";
    }
    cout << endl;
    return 0;
}