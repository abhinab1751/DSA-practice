#include <iostream>
#include <vector>
#include <set>
using namespace std;

void setS(){
    set<int> st;

    st.insert(1);  // {1}                            // Sorted and unique
    st.emplace(2); // {1,2} 
    st.insert(2);  // {1,2}
    st.insert(4);  //{1,2,4}
    st.insert(3);  //{1,2,3,4}


    //{1,2,3,4,5}
    auto it = st.find(3);

    //{1,2,3,4,5}
    auto it = st.find(6);

    //{1,4,5}
    st.erase(5);  // earses 5 // takes logarithmic time

    int cnt = st.count(1);  //1

    auto it = st.find(3);
    st.erase(it);   // it takes constant time

    //{1,2,3,4,5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2); // {1,4,5}               //erase(start, end) removes elements in [start, end)
                                                //(includes start, excludes end)

}