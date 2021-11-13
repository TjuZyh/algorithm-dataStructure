#include <iostream>
#include <string.h>
using namespace std;

/*
 HuffmanTree编码应用
 首先对字符串进行预处理，统计字符出现的个数，排序，构造huffmanTree，对出现次数多的字符先进行编码
 */

/*
Input
AAAAABCD
THE_CAT_IN_THE_HAT
END
 */

typedef struct{
    int weight;
    int parent;
    int left;
    int right;
}Node;

Node node[60];

int main(){
    char ch[100000];
    //存储字符出现个数，index为字符序号
    int hash[35];
    int i,j,k;
    int len;
    while(cin>>ch , strcmp(ch,"END")!=0){
        memset(hash,0,sizeof(hash));
        len = strlen(ch);
        for(i=0 ; i<len ; i++){
            hash[ch[i]-64]++;
        }
        //初始化
        for(i=1,j=1;i<35;i++)
        {
            if(hash[i]!=0)
            {
                node[j].weight=hash[i];
                node[j].parent=node[j].left=node[j].right=0;
                j++;
            }
        }
        j--;

        for(i=j+1;i<j*2;i++)
            node[i].parent=node[i].left=node[i].right=0;

        for(i=j+1;i<j*2;i++){
            int m1,m2;
            m1=m2=999999;
            int x1,x2;
            for(k=1;k<i;k++){
                if(node[k].weight<m1&&node[k].parent==0){
                    m2=m1;
                    x2=x1;
                    m1=node[k].weight;
                    x1=k;
                }else if(node[k].weight<m2&&node[k].parent==0){
                    m2=node[k].weight;
                    x2=k;
                }
            }
            node[i].weight = m1+m2;
            node[i].right = x1;
            node[i].left = x2;
            node[x1].parent = i;
            node[x2].parent = i;
        }

        int sum=0;
        int cnt;
        for(i=1 ; i<j+1 ; i++){
            k=i;
            cnt=0;
            while(node[k].parent!=0){
                k=node[k].parent;
                cnt++;
            }
            sum+=cnt*node[i].weight;
        }
        if(j==1)
            sum=len;
        float ratio;
        ratio=float(len*8)/sum;
        printf("%d %d %.1f\n",len*8,sum,ratio);
    }
    return 0;
}

