#include <iostream>

/*
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0
 */

using namespace std;

int n ;
int parent[110];

struct Edge{
    int node1 , node2 , val;
}edge[110];

bool cmp(Edge edge1 , Edge edge2){
    return edge1.val < edge2.val;
}

int findRoot(int x){
    /*x == parent[x] ? x : findRoot(parent[x]);*/
    if(x == parent[x]){
        return x;
    }else{
        return findRoot(parent[x]);
    }
}

void init(){
    for(int i = 1 ; i <= n ; i++){
        parent[i] = i;
    }
}


int main(){
    cin >> n;
    int cnt = 1;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j<= n ; j++){
                cin >> edge[cnt].val;
                edge[cnt].node1 = i;
                edge[cnt].node2 = j;
                cnt++;
        }
    }
    init();
    sort(edge , edge + cnt , cmp);
    int minLen = 0;
    int num = n;
    for(int i = 1 ; i <= cnt && num > 1 ; i++){
        int a = edge[i].node1;
        int b = edge[i].node2;
        int aRoot = findRoot(a);
        int bRoot = findRoot(b);
        if(aRoot != bRoot){
            parent[aRoot] = bRoot;
            minLen += edge[i].val;
            num--;
        }
    }
    cout << minLen <<endl;
    return 0;
}

