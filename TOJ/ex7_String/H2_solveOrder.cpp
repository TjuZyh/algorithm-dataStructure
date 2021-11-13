#include <iostream>
#include <algorithm>

using namespace std;

/*
3
3
red 1
green 2
yellow 3
1
blue 83
2red 2
white 1

 */

struct Bal{
    string color;
    int num;
}bal[11];

int cmp(Bal bal1 , Bal bal2){
    return bal1.num > bal2.num;
}

int main(){
    int T , num;
    cin >> T;
    while(T--){
        cin >> num;
        for(int i = 1 ; i <= num ; i++){
            cin >> bal[i].color >> bal[i].num;
        }
        sort(bal +1 , bal + num +1 , cmp);
        for(int i = 1 ; i <= num ; i++){
            cout << bal[i].color << " ";
        }
        cout << endl;
    }
    return 0;
}

