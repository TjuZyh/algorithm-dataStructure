#include <iostream>
#include <algorithm>

using namespace std;

/*
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
 */


int n , m;

struct StrRank{
    string str;
    int T;
};

StrRank strRank[110];


int countWord(string str){
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ;j++){
            if(str[i] > str[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

bool cmp(string str1 , string str2){
    return countWord(str1) < countWord(str2);
}


int main(){
    cin >> n >> m;
    string str[11];
    for(int i = 0 ; i < m ; i++){
        cin >> str[i];
    }
    sort(str , str + m , cmp);
    for(int i = 0 ; i < m ; i++){
        cout << str[i] << endl;
    }
    return 0;
}

