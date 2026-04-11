#include <iostream>
#include <vector>
#include <stack>
using namespace std;


void stack(){
    stack<int> st;
    st.push(1);  // {1}
    st.push(2);  // {2,1}
    st.push(3);  //{3,2,1}
    st.push(4);  // {4,3,2,1}
    st.emplace(5); // {5,4,3,2,1}


    cout << st.top(); // 5                      //all operations are done in O(1) push ,pop , top

    st.pop();  // {4,3,2,1}

    cout << st.top();  //4

    cout << st.size(); //4

    cout << st.empty(); // false

    stack<int>st1, st2;
    st1.swap(st2);
}