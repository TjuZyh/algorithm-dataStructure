#include <iostream>

using namespace std;

/*
0051231232050775
1525354
15253545
 */

int main(){
    string str;
    int number[110];
    while(cin >> str){
        int j = 0;
        memset(number , 0 ,sizeof(number));
        int flag = 0;
        //针对于某些字符串某位没有5，则需要在某位加上5，实现遍历停止的条件
        str[str.length()] = '5';
        for(int i = 0 ; i < str.length()+1 ; ){
            while(str[i] == '5'){
                flag = 0;
                i++;
            }
            //如果不在字符串末尾加5，会出现字符串越界
            while(str[i] != '5'){
                number[j] = number[j] * 10 + str[i] - '0';
                i++;
                flag = 1;
            }
            if(flag){
                j++;
            }
            if(i == str.length()){
                break;
            }
        }
        if(str[str.length()-1] == '5'){
            sort(number , number + j - 1);
            for(int i = 0 ; i < j-1 ; i++){
                cout << number[i] << " "  ;
            }
            cout << endl;
        }else{
            sort(number , number + j);
            for(int i = 0 ; i < j ; i++){
                cout << number[i] << " "  ;
            }
            cout << endl;
        }

    }

    return 0;
}

