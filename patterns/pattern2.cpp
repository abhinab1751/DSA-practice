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

int main(){                         

    print2();
    return 0;
}