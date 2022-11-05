#include <stdio.h>
#include <string> 
#include <iostream>
using namespace std;

int ZeroToRemoveInString(string s){
    int length = s.length();
    int count = 0;
    for(int i = length-1; i >= 0; i--){
        if(s[i] == '0' || s[i] == '.')
            count ++;
        else
             break;
        
    }
    return count;
}

string suffixWithUnit(double number){
    int i = 0;
    for(i; i < 2 ; i++){
        if(number / 1000 >= 1){
            number /= 1000;
        }
        else break;
    }
    string s = to_string(number);
    int length = s.length();
    switch(i){
        case 0:
            s.erase(s.end()-ZeroToRemoveInString(s), s.end());
            break;
        case 1:
            s.erase(s.end()-ZeroToRemoveInString(s), s.end());
            s += " Kilo";
            break;
        case 2:
            s.erase(s.end()-ZeroToRemoveInString(s), s.end());
            s += " Mega";
            break;
    }
    return s;
}

int main()
{
    cout << suffixWithUnit(123);
    return 0;
}
