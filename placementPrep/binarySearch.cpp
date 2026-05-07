#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target){
    int st = 0 , end = arr.size();
    for(int i = 0; i < arr.size(); i++){
        int mid = st + (end - st)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            st = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    int target = 9;
    cout << binarySearch(arr,target) << endl;
    return 0;
}