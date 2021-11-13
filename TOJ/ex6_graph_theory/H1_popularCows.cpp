#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

/*
3 3
1 2
2 1
2 3
 */

/*
 * 对于一个有向无环图来说，其中有且仅有一个点出度为零，那么这个特殊的点，可以由其他任何点到达。
 * 那么接下来我们直接对所给的图进行强连通分量划分，然后把每个强连通分量看做一个点，判定出度为零的点有几个，
 * 如果有一个就输出这个点对应的强连通分量含有的节点个数，否则为零。
 */

const int maxn = 10005;
struct node{
    int to, next;
} edge[maxn*5];

int head[maxn], id[maxn], tot, cnt, times, top;
int dfn[maxn], low[maxn], vis[maxn], stack[maxn], inStack[maxn];

void init(){
    tot = top = 0;//top指向栈顶
    cnt = 0;//强连通分量
    times = 1;//时间戳
    memset (id, 0, sizeof(id));//i所属的连通分量
    memset (stack, 0, sizeof(stack));//dfs到的元素进栈
    memset (inStack, 0, sizeof(inStack));//i是否在栈中
    memset (head, -1, sizeof(head));
    memset (dfn, 0, sizeof(dfn));//进栈时间
    memset (low, 0, sizeof(low));//i能到达的最早进栈的节点的进栈时间
    memset (vis, 0, sizeof(vis));//强连通分量是否有出度
}

void Add (int from, int to){
    edge[tot].to = to;
    edge[tot].next = head[from];
    head[from] = tot++;
}
void Tarjan (int u){
    dfn[u] = low[u] = times ++;
    inStack[u] = 1;
    stack[top++] = u;
    for (int i=head[u]; i!=-1; i=edge[i].next){
        int v = edge[i].to;
        if (!dfn[v])//v没有dfs到过
            Tarjan(v);
        if (inStack[v])//v在栈中
            low[u] = min (low[v], low[u]);
    }
    if (low[u] == dfn[u])
    {//找到一个强连通分量
        cnt ++;
        while (1)
        {//在栈中弹出强连通分量
            int v = stack[--top];
            inStack[v] = 0;
            id[v] = cnt;
            if (v == u)
                break;
        }
    }
}

int main (){
    int n, m;
    while (scanf ("%d %d", &n, &m) != EOF){
        init ();
        while (m --){
            int from, to;
            cin >> from >> to;
            Add (from, to);
        }
        for (int i=1; i<=n; i++)
            if (!dfn[i])//i点没进过栈，i点进栈继续dfs
                Tarjan(i);
        int sum = 0, x;
        for (int i=1; i<=n; i++)
            for (int j = head[i]; j != -1; j = edge[j].next)
                if (id[i] != id[edge[j].to])//id[i] 到 id[edge[j].to这条边不在强连通分量中，记录id[i]分量有出度
                    vis[id[i]] ++;
        for (int i=1; i<=cnt; i++)
            if (!vis[i]){
                sum ++;
                x = i;
            }

        if (sum == 1){
            sum = 0;
            for (int i=1; i<=n; i++){
                if (id[i] == x){
                    sum ++;
                }
            }
            cout << sum << endl;
        }else{
            cout << "0" << endl;
        }
    }
    return 0;
}

