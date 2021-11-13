#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

/*
3 3
1 2
2 3
3 1
3 3
1 2
2 3
3 2
0 0
 */

const int MAX=10000+10;
vector<int> map[MAX];//构建邻接表
stack<int> s;//将更新到的点入栈
int dfs[MAX];//访问的节点次序,即u或u的子树能够追溯到的最早的栈中节点的序号(时间戳)
int Low[MAX];//父节点最早出现的时间戳//节点u搜索的序号(时间戳)
bool isStack[MAX];//是否在栈中
int used[MAX];//标记该点输入哪个联通分量
int top;//时间戳
int newFlag;//联通分量

void initAll(){
    memset(dfs,0,sizeof(dfs));
    memset(Low,0,sizeof(Low));
    memset(isStack,false,sizeof(isStack));
    memset(used,0,sizeof(used));
    for(int i = 0 ; i  < MAX ; i++){
        map[i].clear();
    }
    while(!s.empty()){
        s.pop();
    }
    newFlag = 0;
    top=0;
}

//tarjan算法
void tarjan(int u){
    dfs[u]=Low[u]=++top;//时间戳
    isStack[u]=true;//存在栈中
    s.push(u);
    for(int i = 0 ; i < map[u].size() ; i++){
        int v=map[u][i];
        //判断是否更新过
        if(!dfs[v]){
            //递归，继续更新
            tarjan(v);
            //若存在子节点能找到比父节点更早节点，即有环
            if(Low[v]<Low[u]){
                Low[u]=Low[v];
            }
        }
        else if(isStack[v]&&dfs[v]<Low[u]){
            Low[u]=dfs[v];
        }
    }
    //找不到邻接点了，即找到联通分量的结束条件
    if(dfs[u]==Low[u]){
        newFlag++;
        int x;
        do{
            x=s.top();
            isStack[x]=false;
            used[x]=newFlag;
            s.pop();
        }while(x!=u);//输出联通分量
    }
    return;
}
int main(){
    int N,M;
    cin >> N >> M;
    while(N != 0 && M != 0){
        initAll();
        for(int i=0;i<M;i++){
            int room1,room2;
            cin >> room1 >> room2;
            map[room1].push_back(room2);
        }
        for(int i = 1 ; i <= N ; i++){
            if(!dfs[i]){
                tarjan(i);
            }
        }
        if(newFlag == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        cin >> N >> M;
    }
    return 0;
}