#include <iostream>
#include <list>
#include <vector>
using namespace std;

void explainlist(){
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(4);

    ls.push_front(5);
    ls.emplace_front(); {2,4};

    //rest functions same as vector
    //begin, end, rbegin, rend, clear , insert , size , swap.
}