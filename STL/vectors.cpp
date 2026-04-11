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

    // iterators
    vectors<int>::iterator it = v.begin();       //[2,6,8,4,1] will point to memory location of 2 

    it++;
    cout << *(it) << " ";      //now from address of 2 it will point to actual value which is 2 and then from it++ it will point to 6.
    
    it = it + 2; // here make it +2 from the begin then the answer will be 8
    cout << *(it) << " ";
    vector<int>:: iterators it = v.end();
    vector<int>:: iterators it = v.rend();
    vector<int>:: iterators it = v.rbegin();

    cout << v[0] << " " << v.at(0);
    cout << v.back() << " ";
    

    // For each Loop
    for(vector<int>:: iterator it = v.begin(); it != v.end(); it++){       // extended 
        cout << *(it) << " ";
    }
    for(auto it = v.begin(); it != v.end(); it++){ // use auto it directly get the variable used like int string and many more.
        cout << *(it) << " ";
    }
    for(auto it : v){
        cout << it << " ";  // for each loop
    }

    //erase
    v.erase(v.begin() + 1); //{10,20,12,23}


    //{10,20,12,23,35}
    v.erase(v.begin() + 2 , v.begin() + 4) //{10,20,35} {start,end}
    

    // insert function

    vector<int> v(2,100);  //{100,100}
    v.insert(v.begin(),300); // {300,100,100}.
    v.insert(v.begin() + 1, 2, 10);  // {300 , 10 ,10 , 100 ,100}.

    vector<int> copy(2,50); // {50,50}
    v.insert(v.begin() , copy.begin(), copy.end()); // {50, 50, 300 , 10 ,10 , 100, 100}
    
    //{10, 20}
    cout << v.size(); //2


    //{10,20}
    v.pop_back(); //{10}

    //v1 -> {10,20}
    //v2 -> {30,40}

    v1.swap(v2);  //v1 -> {30.40} , v2 -> {10,20}

}