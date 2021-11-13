#include <iostream>
#include <algorithm>

using namespace std;

/*
3 3
1 2 1
2 3 2
3 1 3

 5 8
1 2 3
1 3 7
2 3 10
2 4 4
2 5 8
3 4 6
3 5 2
4 5 17
 */
/*
 前期变量准备：
    一个结构体数组：因为涉及到边val排序，需要存储关系
    parent数组：存储根节点
 */
int n,m;
int parent[110];

struct Edge{
    int from;
    int to;
    int val;
};
Edge edge[110 * 110];

bool cmp(Edge node1 , Edge node2){
    return node1.val < node2.val ;
}

int findRoot(int x){
    if(parent[x] == x){
        return x;
    }else{
        return parent[x] = findRoot(parent[x]);
    }
}

bool unionNode(int node1 , int node2){
    int root1 = findRoot(node1);
    int root2 = findRoot(node2);
    if(root1 != root2){
        parent[root1] = root2;
        return true;
    }
    return false;
}

void init(){
    for(int i = 0; i <= n; i ++){
        parent[i] = i;
    }
}

int Kruskal(){
    sort(edge , edge + m , cmp);
    int cnt = 0;
    int sum = 0;
    init();
    for(int i = 0; i < m; i ++){
        if(unionNode(edge[i].from ,edge[i].to)){
            sum += edge[i].val ;
            cnt ++;
        }
        if(cnt == n-1){
            break;
        }
    }
    return sum;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        cin >> edge[i].from >> edge[i].to >> edge[i].val;
    }
    int minLen = Kruskal();
    cout << minLen << endl;
    return 0;
}

