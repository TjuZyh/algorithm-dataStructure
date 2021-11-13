#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

/*
2
3 3
1 2 1
2 3 2
3 1 3
4 4
1 2 2
2 3 2
3 4 2
4 1 2
 */

/*去掉已生成最小生成树的一条边后，继续求最小生成树，若最小生成树的长度不变，则不唯一*/

#define inf 0x3f3f3f3f

int n,m;
int parent[110];
int map[110][110];

struct Edge{
    int from;
    int to;
    int val;
};
Edge edge[110 * 110];

bool cmp(const Edge node1 , const Edge node2){
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

/*
去掉其中一条边时有两种情况：
    1.没有最小生成树
    2.最小生成树长度变化
 */
int KruskalByCut(int x,int y){
    int cnt = 0;
    int sum = 0;
    init();
    for(int i = 0; i < m; i ++){
        //去掉生成树的当前边
        if(edge[i].from == x && edge[i].to == y){
            continue;
        }
        if(unionNode(edge[i].from ,edge[i].to)){
            sum += edge[i].val ;
            cnt ++;
        }
        if(cnt == n-1)
            break;
    }
    if(cnt == n-1)//去掉该边以后必须保证能够生成最小生成树才返回权值
        return sum;
    return inf;
}
int main(){
    int cases;
    cin >> cases;
    while(cases--){
        cin >> n >> m;
        for(int i = 0; i < m; i ++){
            cin >> edge[i].from >> edge[i].to >> edge[i].val;
        }
        init();
        memset(map,0,sizeof(map));

        //kruskal算法求最小生成树的值
        sort(edge , edge + m , cmp);
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < m; i ++){
            if(unionNode(edge[i].from ,edge[i].to)){
                sum += edge[i].val ;
                cnt ++;
                //将加入最小生成树的点标记为1
                map[edge[i].from][edge[i].to] = 1;
            }
            //当选取的边的数量相比与顶点的数量-1时，说明最小生成树已经生成
            if(cnt == n-1){
                break;
            }
        }

        //求出最小值为sum
        bool flag = false;
        int sum2;
        for(int i = 0;  i < m; i ++){
            //如果该边属于最小生成树
            if(map[edge[i].from][edge[i].to]){
                sum2 = KruskalByCut(edge[i].from , edge[i].to );
                if(sum2 == sum){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            cout << "Not Unique!" << endl;
        }else{
            cout << sum << endl;
        }
    }
    return 0;
}

