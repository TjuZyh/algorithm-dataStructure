#include<iostream>
#include<algorithm>
using namespace std;
#define MaxInt  32767
#define MaxNum  6
int dist[MaxNum];
int preV[MaxNum];
int A[MaxNum][MaxNum] = {MaxInt};
void Dijkstra(int v0){
    bool S[MaxNum];
    int n = MaxNum;
    for (int i = 0 ; i < n ; ++i){
        dist[i] = A[v0][i];
        S[i] = false;
        if (dist[i] < MaxInt)
            preV[i] = v0;
        else
            preV[i] = -1;
    }
    dist[v0] = 0;
    S[v0] = true;
    for (int i = 1; i < n; ++i)
    {
        int mindist = MaxInt;
        int u = v0;
        for (int j = 0; j < n; ++j)
        {
            if ((!S[j]) && dist[j] < mindist)
            {
                u = j;
                mindist = dist[j];
            }

        }
        S[u] = true;

        for (int j = 0; j < n; ++j)
        {
            if ((!S[j]) && (A[u][j] < MaxInt))
            {
                if (dist[u] + A[u][j] < dist[j])
                {
                    dist[j] = dist[u] + A[u][j];
                    preV[j] = u;
                }
            }
        }
    }
}