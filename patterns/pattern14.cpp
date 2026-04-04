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
        for(int j = 0; j <= i; j++){
            cout << i << " ";
        } cout << endl;
    }
}

void print5(){
    for(int i = 0; i < 5 ; i++){
        for(int j = 0; j < 5-i; j++){
            cout << " * ";
        } 
        cout << endl;
    }
}

void print6(){
    for(int i = 1; i < 7 ; i++){
        for(int j = 1; j < 7 - i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void print7(){
    for(int i = 0; i < 9; i++){
        for(int j = 0 ; j < 9-i-1; j++){
            cout << " ";
        }
        for(int j = 0; j < 2*i+1; j++){
            cout << "*";
        }
        for(int j = 0; j < 9-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void print8(){
    for(int i = 0; i < 9; i++){
        for(int j = 0 ; j < i; j++){
            cout << " ";
        }
        for(int j = 0; j < (2*9) - (2*i+1); j++){
            cout << "*";
        }
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        cout << endl;
    }
}

//void print10(){
//    for(int i = 1; i < 2*8-1; i++){
//        int stars = i;
//        if(i > 8) stars = 2*8 - i;
//        for(int j = 1; j<=2*8 - i){
//            cout << " * ";
//        }
//        cout << endl;
//    }
//}

void print11(){
    int start = 1;
    for(int i = 0; i < 8; i++){
        if(i % 2 == 0) start = 1;
        else start = 0;
        for(int j = 0; j <= i; j++){
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}


void print12(){
    int space = 2* (5-1);
    for(int i = 1 ; i <= 5; i++){
        for(int j = 1; j <= i; j++){
            cout << j;
        }
        for(int j = 1; j <= space; j++){
            cout << " ";
        }
        for(int j = i; j >= 1; j--){
            cout << j;
        }
        cout << endl;
        space-=2;
    }
}

void print13(){
    int num = 1;
    for(int i = 1; i<=6; i++){
        for(int j = 1; j <= i; j++){
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}

void print14(){
    for(int i = 0; i < 5; i++){
        for(char j = 'A'; j <= 'A' + i ; j++){
            cout << j;
        }
        cout << endl;
    }
}

int main(){                         
    print14();
    return 0;
}


//A
//AB
//ABC
//ABCD
//ABCDE




