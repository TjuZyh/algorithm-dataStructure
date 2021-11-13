#include <iostream>

using namespace std;

/*
riemann
marjorie
clinton
homer
marjorie
riemann
 */
int main(){
    string str1 , str2;

    while(cin >> str1 >> str2){
        int flag = 0;
        int len1 = str1.length();
        int len2 = str2.length();
        for(int i = 1 ; i < min(len1 , len2) ; i++){
            if(str1.substr(0 , i) == str2.substr(len2-i , len2)){
                flag = 1;
                cout << str1.substr(0 , i) << " " << i << endl;
            }
        }
        if(!flag){
            cout << "0" << endl;
        }
    }

    return 0;
}

