#include <iostream>
using namespace std;


void explainPairs(){
    pair<int, int> p = {1,3};

    cout << p.first << " " << p.second;

    pair<int,pair<int,int>> p = {1, {1,2}};

    cout << p.first << " " << p.second.second << " " << p.second.first;

    pair<int,int> arr[] = { {1,2} , {2,3}, {3,4} };

    cout << arr[1].second;
}