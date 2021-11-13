#include<iostream>
#include<cstring>
using namespace std;

int x,y ;
int f[100010];
//因为数组不是按顺序排列的，需要用一个数组来存储已访问的节点
int vis[100010];//访问数组，用于判定最后有几个连通分量，
int degree[100010];//入度存储数组
int testTime = 1;

//查询根节点
int findRoot(int x)
{
    if(f[x] == x){
        return x;
    }
    return f[x] = findRoot(f[x]);
}
//合并两个子集
void Union(int u,int v)
{
    int t1=findRoot(u);
    int t2=findRoot(v);
    if(t1!=t2)
        f[t2]=t1;
}
void Init()
{
    memset(vis,0,sizeof(vis));//将vis数组全部赋值为0
    memset(degree,0 ,sizeof(vis));
    for(int i=1; i<=100000; i++)
        f[i]=i;
}
int main()
{
    //最外层循环，用于程序-1退出以及只有00的情况
    while(cin >> x >> y)
    {
        if(x + y == -2)
            break;
        if(x+y==0)//若当前行输入只有0 0 ，也判定为yes
        {
            cout << "Case " << testTime << " is a tree." << endl;
            testTime++;
            continue;
        }
        Init();
        vis[x] = vis[y] = 1;
        int flag=1; //标志位flag=1代表yes无环；flag=0代表no有环
        Union(x,y);
        degree[y]++;
        while(cin>>x>>y)//对于后续数据进行循环，从第二个数据开始
        {
            if(x+y==0)
                break;
            if(findRoot(x)==findRoot(y)) //并入子集时发现根节点相同，则证明有环，标志位改为0
                flag=0;
            else
            {
                Union(x,y);
                vis[x]=vis[y]=1;//记录已访问的节点，用于判断连通分量
                degree[y]++;
            }
        }
        int sum=0;
        for(int i=1; i<=100000; i++)
        {
            if(vis[i])
            {
                if(f[i]==i)//本身为根节点的即自成一个连通分量，即为一个子集
                    sum++;
                if(degree[i] > 1){
                    flag = 0;
                }
            }

        }
        if(sum > 1)//若有两个连通分量，不满足迷宫要求(有且仅有一条通路可以相通)
            flag=0;

        if(flag==1)
            cout << "Case " << testTime << " is a tree." << endl;
        else
            cout << "Case " << testTime << " is not a tree." << endl;

        testTime++;

    }
    return 0;
}

