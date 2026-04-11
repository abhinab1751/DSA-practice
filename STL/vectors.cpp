#include <iostream>
#include <vector>
using namspace std;

void vectors(){
    vector<int> v;

    v.push_back(1);      //[1]
    v.emplace__back(2);    // [1,2]    dynamiclly increase

    vector<pair<int , int>> vec;

    v.push_back({1,2});    // in push_back we have to provide the {}.
    v.emplace_back(1,2);   // here we dont need to use {}.


    vector<int> v(5,100);    //{100,100,100,100,100}


    vector<int> v(5);

    vector<int> v1(5,20);     //{20,20,20,20,20}
    vector<int> v2(v1);


}