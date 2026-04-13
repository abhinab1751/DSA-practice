#include <iostream>
#include <vector>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    //they are same
    if(p1.first >p2.first) return true;
    return false;
}

void Sort(){


    sort(a, a+n);
    sort(v.begin(), v.end());

    sort(a+2, a+4);

    pair<int, int> a[] = {{1,2} , {2,1} , {4,1} };


    //sort it according to second element    //{{2,1},{4,1},{1,2}}
    //if second element is same then sort 
    //it according to first element but in descending   //{{4,1},{2,1},{1,2}}

    sort(a, a+n , comp);

    int num = 7;
    int cnt = __builtin_popcount();            //bits mai like 7 is 111  so it will give the number of 1 are there so here it will be 3

    long long num = 1736472984818938;
    int cnt = __builtin_popcountll();  

    string s = "123";
    sort(s.begin(),s.end());

    do{
        cout << s << endl;
    } while(next_permutation(s.begin(),s.end()));

    int maxi = *max_element(a,a+n);
}