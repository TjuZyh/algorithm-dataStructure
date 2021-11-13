#include <iostream>

using namespace std;

/*
a
ahat
hat
hatword
hziee
word


 */

/*用暴力即可，将字符串截取为两段，查询是否存在于数组中即可*/

string str[11];
int t;

bool find(string curStr){
    bool flag = false;
    for(int i = 0 ; i < t -1 ; i++){
        if(curStr == str[i]){
            flag = true;
        }
    }
    return flag;
}

int main(){

    while(getline(cin , str[t++])){
        if(!str[t-1].length()){
            break;
        }
    }

    for(int i = 0 ; i < t - 1 ; i++){
        for(int j = 1 ; j < str[i].length() ; j++){
            string str1 , str2;
            /*注意substr(i , j)函数的用法，是从i位置开始截取j位长度的字符串*/
            str1 = str[i].substr(0 , j);
            str2 = str[i].substr(j , str[i].length());
            //cout << str[i] << " " <<  str1 << " " << str2 << endl;
            if(find(str1) && find(str2)){
                cout << str[i] << endl;
                break;
            }
        }
    }

    return 0;
}
