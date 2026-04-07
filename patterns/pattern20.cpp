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

void print15(){
    for(int i = 0; i <= 6; i++){
        for(char j = 'A'; j <= 'A' + (6-i-1); j++){
            cout << j;
        }
        cout << endl;
    }
}

void print16(){
    for(int i = 0; i<= 6; i++){
        char ch = 'A' + i;
        for(int j = 0 ; j <= i;j++){
            cout << ch << " ";
        }
        cout << endl;
    }
}

void print17(){
    for(int i = 0 ; i < 6 ; i++){
        for(int j = 0; j <= 6-i-1; j++){
            cout << " ";
        }
        char ch = 'A';
        char breakpoint = (2*i + 1)/2;
        for(int j = 0; j < (2*i + 1); j++){
            cout << ch;
            if(j <= breakpoint) ch++;
            else ch--;
        }
        for(int j = 0; j <=  6-i-1; j++){
            cout << " ";
        }
        cout << endl;
    }
}

void print18(){
    for(int i = 0; i <= 4; i++){
        for(char j = 'E' - i ; j <= 'E'; j++){
            cout << j;
        }
        cout << endl;
    }
}

void print19(){
    int n = 6;
    int iniS = 0;

    
    for(int i = 0; i < n ; i++){
        for(int j = 1; j <= n - i; j++){
            cout << "*";
        }
        for(int j = 0; j < iniS ; j++){
            cout << " ";
        }
        for(int j = 1; j <= n - i; j++){
            cout << "*";
        }
        iniS += 2;
        cout << endl;
    }

    
    iniS = 2*n - 2;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        for(int j = 0; j < iniS ; j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        iniS -= 2;
        cout << endl;
    }
}

void print20(){
    int n = 4;
    int space = 2*n - 2;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        for(int j = 0; j <= space; j++){
            cout << " ";
        }
        for(int j = 1; j <= i; j++){
            cout << "*";
        }
        space -= 2;
        cout << endl;
    }
    space = 2;
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= n-i-1; j++){
            cout << "*";
        }
        for(int j = 0; j <= space; j++){
            cout << " ";
        }
        for(int j = 1 ; j <= n-i-1; j++){
            cout << "*";
        }
        space += 2;
        cout << endl;
    }
}

int main(){                         
    print20();
    return 0;
}


//*       *
//**     **
//***   ***
//**** ****
//***   ***
//**     **
//*       *









