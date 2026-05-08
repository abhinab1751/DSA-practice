#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool isAlphaNum(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
        return true;
    }
}


bool validPalindrome(string str){
    int n = str.size();
    int st = 0 , end = n-1;
    while(st < end){
        if(!isAlphaNum(str[st])){
            st++;
            continue;
        }
        if(!isAlphaNum(str[end])){
            end--;
            continue;
        }

        if(str[st] != str[end]){
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main(){
    string str = "A man, a plan, a canal: Panama";
    cout << validPalindrome(str) << endl;   
    return 0;
}