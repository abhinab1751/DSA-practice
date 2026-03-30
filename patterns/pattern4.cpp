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

void print4(){
    for(int i = 0; i < 7 ; i++){
        for(int j = 0; j < i; j++){
            cout << i << " ";
        } cout << endl;
    }
}

int main(){                         

    print4();
    return 0;
}

//1 
//2 2 
//3 3 3 
//4 4 4 4 
//5 5 5 5 5 
//6 6 6 6 6 6 