#include <iostream>

int a[500001], b[500001],i;
long long num;

/*
设两个有序的子文件放在同一向量中相邻的位置上：R[low..m]，R[m+1..high]，
先将它们合并到一个局部的暂存向量R1中，待合并完成后将R1复制回R[low..high]中。

合并过程中，设置i，j和p三个指针，其初值分别指向这三个记录区的起始位置。
合并时依次比较R[i]和R[j]的关键字，取关键字较小的记录复制到R1[p]中，然后将被复制记录的指针i或j加1，以及指向复制位置的指针p加1。

重复这一过程直至两个输入的子文件有一个已全部复制完毕(不妨称其为空)，此时将另一非空的子文件中剩余记录依次复制到R1中即可。
 * */
void merge(int l,int m,int r)//归并
{
    int  p=0 , i=l , j=m+1;//p指向输出，i,j指向输入
    while(i<=m && j<=r)//两个输入空间不为0
    {
        if(a[i] > a[j])//取最小值转入输出空间
        {
            b[p++] = a[j++];
            num += m-i + 1;//a[i]后数值相对于a[i]为逆序
        }
        else
            b[p++] = a[i++];
    }
    while(i<=m) b[p++] = a[i++];//非空输入空间转入输出空间
    for(i = 0; i < p; ++i)//归并结束，结果复制到原输入数组
        a[l+i] = b[i];
}

void Mergesort(int l2,int r2)//归并排序
{
    if(l2<r2)
    {
        int m2=(l2+r2)/2;//将长为n的序列分为两部分
        Mergesort(l2,m2);//对子序列排序
        Mergesort(m2+1,r2);
        merge(l2,m2,r2);//合并子序列
    }
}
int main(  )
{
    int N;
    while(scanf("%d",&N)&&N)
    {
        num=0;
        for(i=0;i<N;i++)
            scanf("%d",&a[i]);
        Mergesort(0,N-1);
        printf("%lld\n",num);
    }
    return 0;
}
