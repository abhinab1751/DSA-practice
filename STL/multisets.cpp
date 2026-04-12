#include <iostream>
#include <vector>
#include <set>
using namespace std;

void multiset(){
    //everything same as set
    //only stores duplictes elements also

    multiset<int> ms;
    ms.insert(1);   //{1}
    ms.insert(1);   //{1,1}
    ms.insert(1);   //{1,1,1}

    ms.erase(1);   // all 1's erased
  
   int cnt = ms.count(1);  

    ms.erase(ms.find(1)); // only one 1 is erased

    ms.erase(ms.find(1),ms.find(1)+2);    

    //rest all are same
}