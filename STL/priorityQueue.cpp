#include <iostream>
#include <vector>
#include <vector>
using namespace std;

void priorityQueue(){
    priority_queue<int> pq;
    pq.push(5);  // {5}
    pq.push(2);  // {5,2}
    pq.push(8);  // {8,5,2}                                 // Max Heap
    pq.emplace(10);  //{10,8,5,2}                           //push - log(n)
                                                            //pop - log(n)
    cout << pq.top();  // 10                                //top - O(1)

    pq.pop(); // {8,5,2}

    cout << pq.top(); //8


    //Min Heap
    priority_queue<int , vector<int>,greater<int>> pq;
    pq.push(5); //{5}
    pq.push(2); //{2,5}
    pq.push(8); //{2,5,8}
    pq.emplace(10); // {2,5,8,10}

    cout << pq.top();  //2
}