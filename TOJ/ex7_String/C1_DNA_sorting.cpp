#include <iostream>

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



int countWord(char str[]){
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

void BubbleSort(StrRank strRank[] , int len){
    for(int i = 0 ; i < len ; i++){
        for(int j = 0 ; j < len - i - 1 ; j++){
            if(strRank[j].T > strRank[j+1].T){
                StrRank temp;
                temp = strRank[j+1];
                strRank[j+1] = strRank[j];
                strRank[j] = temp;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    char str[n];
    for(int i = 0 ; i < m ; i++){
        cin >> str;
        strRank[i].str = str;
        strRank[i].T = countWord(str);
    }

    BubbleSort(strRank , m);
    for(int i = 0 ; i < m ; i++){
        cout << strRank[i].str <<endl;
    }
    return 0;
}

