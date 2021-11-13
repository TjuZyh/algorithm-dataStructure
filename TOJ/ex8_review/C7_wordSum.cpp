#include <iostream>
#include <algorithm>

using namespace std;

/*
To
to be or not to be is a question to

to
Did the Ottoman Empire lose its power at that time

I


I
heloo oa isd s d   ii Is io i ioi iioi ooooi
hello oa isd s d   ii Is io i ioi iioi ooooi

i
i iii
 */

/*
T 84 t 116

大写字母 65-90
小写字母 97-122
 */

string word;
string line;

int main(){
    while(cin >> word){
        getchar();
        int lenWord = word.length();
        getline(cin , line);
        int cnt = 0;
        int space = 0;
        int t = 0;
        //预处理字符串,转换为小写
        transform(word.begin(),word.end(),word.begin(),::tolower);
        transform(line.begin(),line.end(),line.begin(),::tolower);
        for(int  i = 0 ; i < line.length() ; i++){
            if(line[i] == 32 && line[i+1] != 32){
                space++;
            }
            if(word[0] == line[i]){
                if(line.substr(i , lenWord) == word && (line[i + lenWord] == 32 || (i + lenWord) == line.length()) ){
                    cnt++;
                    if(cnt == 1 && word[0] == line[0]){
                        t = i;
                    }else if(cnt == 1){
                        t = i;
                    }
                }
            }
        }
        if(cnt == 0){
            cout << "-1" << endl;
        }else{
            cout << cnt << " " << t << endl;
        }
        cout << endl;
    }
}

