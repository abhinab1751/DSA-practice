#include <iostream>
#include <vector>
using namespace std;

void print1(){
    for(int i = 0; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            cout << " * ";
        }
        cout << endl;
    }
}

void print2(){
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j <= i; j++){
            cout << " * ";
        }
        cout << endl;
    }
}

void print3(){
    for(int i = 1; i < 7 ; i++){
        for(int j = 1; j < i; j++){
            cout << j << " ";
        } cout << endl;
    }
}

int main(){                         

    print3();
    return 0;
}

//1 
//1 2 
//1 2 3 
//1 2 3 4 
//1 2 3 4 5 