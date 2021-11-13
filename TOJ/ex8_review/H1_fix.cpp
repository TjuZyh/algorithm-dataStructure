#include <iostream>
#include <algorithm>

using namespace std;

/*
4
100 200
200 1300
1000 1250
2000 3200
 */

struct Bul{
    int time;
    int timeL;
};
Bul bul[150010];

bool cmp(Bul bul1 , Bul bul2){
    return bul1.time < bul2.time;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> bul[i].time >> bul[i].timeL;
    }
    sort(bul , bul + n , cmp);
    int cnt = 0;
    int totalTime = 0;
    for(int i = 0 ; i < n ; i++){
        totalTime += bul[i].time;
        if(bul[i].time < totalTime){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

