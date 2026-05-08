#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int>& arr){
    int n = arr.size();
    int low = 0 , mid = 0 , high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++,low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    vector<int> arr = {0,1,2,0,1,2};
    sortArray(arr);
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}