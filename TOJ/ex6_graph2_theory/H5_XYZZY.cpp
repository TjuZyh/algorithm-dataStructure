#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

/*
5
0 1 2
-60 1 3
-60 1 4
20 1 5
0 0
5
0 1 2
20 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
21 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
20 2 1 3
-60 1 4
-60 1 5
0 0
-1
 */

const int maxN = 110;

struct Room {
    int energy;
    int doorwaysNum;
    int doorways[maxN];
    int lastEnergy;
};

Room room[maxN];
int n;

bool is_visited[maxN];

bool CanArrive(int pos);
bool Search(int pos, int energy);

int main() {
    while (scanf("%d", &n), n != -1) {
        for (int i = 1; i <= n; i++) {
            cin >> room[i].energy >> room[i].doorwaysNum;
            for (int j = 0; j < room[i].doorwaysNum ; ++j) {
                cin >> room[i].doorways[j];
            }
            //该房间从未被访问，访问后将其置为当前能量
            room[i].lastEnergy = -1;
        }
        if(Search(1,100)){
            cout << "winnable" << endl;
        }else{
            cout << "hopeless" << endl;
        }
    }

    return 0;
}

bool Search(int pos, int energy) {
    //能量耗尽
    if (energy <= 0) {
        return false;
    }
    //到达最后一个房间
    if (pos == n) {
        return true;
    }
    if (room[pos].lastEnergy != -1) {
        if (energy > room[pos].lastEnergy) {
            memset(is_visited, false, sizeof(is_visited));
            if (CanArrive(pos)) {
                return true;
            }
        }
        return false;
    };
    room[pos].lastEnergy = energy;
    for (int i = 0 ; i < room[pos].doorwaysNum ; ++i) {
        int newRoomPos = room[pos].doorways[i];
        if (Search(newRoomPos, energy + room[newRoomPos].energy)) {
            return true;
        }
    }
    return false;
}


bool CanArrive(int pos) {
    if (is_visited[pos]) {
        return false;
    }
    if (pos == n) {
        return true;
    }
    is_visited[pos] = true;
    for (int i = 0; i < room[pos].doorwaysNum; ++i) {
        if (CanArrive(room[pos].doorways[i])) {
            return true;
        }
    }
    return false;
}