#include <iostream>
#include <algorithm>

using namespace std;

/*
4 5 25
10 10 12 13 15
CS004 3 5 1 3
CS003 5 2 4 1 3 5
CS002 2 1 2
CS001 3 2 3 5
1 2 40
10 30
CS001 1 2
2 3 20
10 10 10
CS000000000000000001 0
CS000000000000000002 2 1 2
0
 */

int N , M , G;
int score;
int scores[11];
string stuId;
int AcNum , Ac;

struct Stu{
    string stuId;
    int ACNum;
    int AC[11];
    int totalScore;
};

Stu stu[1010];

int cmp(const Stu &stu1 ,const Stu &stu2){
    if(stu1.totalScore != stu2.totalScore){
        return stu1.totalScore > stu2.totalScore;
    }else{
        return stu1.stuId < stu2.stuId;
    }
}

int main(){
    while(cin >> N){
        if(N == 0){
            break;
        }
        cin >> M >> G;
        for(int i = 1 ; i <= M ; i++){
            cin >> score;
            scores[i] = score;
        }
        int cnt = 0;
        int tempArr[11];
        for(int i = 1 ; i <= N ; i++){
            int totalScore = 0;
            cin >> stuId >> AcNum;
            for(int j = 1 ; j <= AcNum ; j++){
                cin >> Ac;
                tempArr[j] = Ac;
                totalScore += scores[Ac];
            }
            if(totalScore >= G){
                cnt++;
                stu[cnt].stuId = stuId;
                stu[cnt].ACNum = AcNum;
                stu[cnt].totalScore = totalScore;
                for(int j = 1 ; j <= AcNum ; j++){
                    stu[cnt].AC[j] = tempArr[j];
                }
            }
        }
        sort(stu+1 , stu+cnt+1 , cmp);

        //print
        cout << cnt << endl;
        for(int i = 1 ; i <= cnt ; i++){
            cout << stu[i].stuId << " " <<  stu[i].totalScore << endl;
        }

    }
    return 0;
}

