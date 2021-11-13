#include <stdio.h>
#define N 10   //指定哈希表的长度
//自定义哈希函数
int hash(int value) {
    return value % 10;
}
//创建哈希表
void creatHash(int arr[5], int hashArr[N]) {
    int i,index;
    //将序列中每个元素存储到哈希表
    for (i = 0; i < 5; i++) {
        index = hash(arr[i]);
        while(hashArr[index % N] != 0) {
            index++;
        }
        hashArr[index] = arr[i];
    }
}

//实现哈希查找算法，hashArr 表示哈希表，value 为要查找的目标元素
int hash_search(int* hashArr, int value) {
    int hashAdd = hash(value);             //查找目标元素所在的索引
    while (hashArr[hashAdd] != value) {    // 如果索引位置不是目标元素，则发生了碰撞
        hashAdd = (hashAdd + 1) % N;       // 根据线性探测法，从索引位置依次向后探测
        //如果探测位置为空，或者重新回到了探测开始的位置（即探测了一圈），则查找失败
        if (hashArr[hashAdd] == 0 || hashAdd == hash(value)) {
            return -1;
        }
    }
    //返回目标元素所在的数组下标
    return  hashAdd;
}

int main()
{
    int hashAdd;
    int hashArr[N] = { 0 };
    int arr[5] = {  };
    creatHash(arr, hashArr);

    hashAdd = hash_search(hashArr, 50);
    //如果返回值为 -1，表明查找失败，反之则返回目标元素所在的位置
    if (hashAdd == -1) {
        printf("查找失败\n");
    }
    else {
        printf("查找成功，目标元素所在哈希表中的下标为：%d", hashAdd);
    }
    return 0;
}


