#include <iostream>
#include <vector>
#include <map>
using namespace std;


void map(){
    map<int , int> mp;                               //stores in key and value pair
                                                     //{key,value}
    map<int , pair<int , int>> mp;                   //key is unique 
                                                     //and in sorted order
    map<pair<int, int>, int> mp;

    mp[1] = 2; // {1,2}
    mp.emplace({3,1}); // ({1,2},{3,1})

    mp.insert({2,4});  // ({1,2}, {1,3}, {2,4})

    mp({2,3}) = 10;   // ({1,2}, {1,3}, {2,4} , {{2,3},10})

    for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }

    cout << mp[1]; // 2
    cout << mp[5]; // 0

    auto it = mp.find(3);
    cout << *(it).second;  //1

    auto it = mp.find(5);  //.end()

    //this is the syntax

    auto it = mp.lower_bound(2);

    auto it = mp.upper_bound(3);

    //erase , swap , size , empty , are same as above;


}