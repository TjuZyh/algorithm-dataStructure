#### 排序

##### 1.经典排序算法讲解

https://www.cnblogs.com/skywang12345/p/3596746.html

###### 1) 冒泡排序

​	**思想：**比较两个相邻的元素，将值大的元素交换到右边，每一次循环都将最大的数移动到数组最右侧。

​	**算法的时间复杂度为O(n^2）**

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20210927195709520.png" alt="image-20210927195709520" style="zoom:50%;" />

​	**实现：**

```c++
void bubbleSort(int arr[], int length){
	for (int i = 0; i < length; i++){
    //冒泡交换到最后一位，最后一位确定后，只需要冒泡交换到当前位置的前一位
		for (int j = 0; j < length -  i - 1; j++){
			if (arr[j] > arr[j + 1]){
				int temp;
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
```

###### 2) 选择排序

​	**思想：**每一趟在n-i+1(i=1,2,...,n-1)个记录中选取关键字最小的记录作为有序序列中第i个记录。具体来说，假设长度为n的数组arr，要按照从小到大排序，那么先从n个数字中找到最小值min1，如果最小值min1的位置不在数组的最左端(也就是min1不等于arr[0])，则将最小值min1和arr[0]交换，接着在剩下的n-1个数字中找到最小值min2，如果最小值min2不等于arr[1]，则交换这两个数字，依次类推，直到数组arr有序排列。

​	**算法的时间复杂度为O(n^2）**

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20210927200544534.png" alt="image-20210927200544534" style="zoom:50%;" />

​	**实现：**	

```c++
void SelectionSort(int arr[], int length){
	for (int i = 0; i < length; i++){
    //定义一个标志位用于标志当前遍历到了最小值的数组索引
		int index = i;
    //遍历寻找当前最小值的数组索引
		for (int j = i+1; j < length; j++){
			if (arr[j] < arr[index]){
				index = j;
			}
		}
    //若标志位就是i，则不需要交换，减少一次交换，稍微节省了一点时间
		if (index == i)
			continue;
		else
		{
			int temp;
			temp = arr[index];
			arr[index] = arr[i];
			arr[i] = temp;
		}
	}
}
```

###### 3) 插入排序

​	**思想：**每一步将一个待排序的数据插入到前面已经排好序的有序序列中，直到插完所有元素为止。

​	直接插入排序是将无序序列中的数据插入到有序的序列中，在遍历无序序列时，首先拿无序序列中的首元素去与有序序列中的每一个元素比较并插入到合适的位置，一直到无序序列中的所有元素插完为止。

​	**算法的时间复杂度为O(n^2）**

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20210927214258577.png" alt="image-20210927214258577" style="zoom:50%;" />

```c++
void insertSort(int *arr , int len){
  	//暂存当前遍历到的值，准备插入有序序列中
  	int temp;
  	//arr[0]当做有序序列，从arr[i]开始遍历
  	for(int i = 1 ; i < len ; i++){
    		temp = arr[i];
      	for(int j = i -1 ; j >= 0 && arr[j] > temp ; j--){
          	//将大于当前插入值的元素后移
          	arr[j + 1] = arr[j];
        }
      	arr[j + 1] = temp;
  	}
}
```

###### 4) 希尔排序

​	**思想：**先将待排记录序列分割成为若干子序列分别进行插入排序，待整个序列中的记录"基本有序"时，再对全体记录进行一次直接插入排序。

​	<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20210927220743393.png" alt="image-20210927220743393" style="zoom:50%;" />

​	**实现：**

```c++
// 插入排序
void shellSort(int arr[], int length){
	int increasement = length;
	int i, j, k;
	do{
		// 确定分组的增量
		increasement = increasement / 3 + 1;
		for (i = 0; i < increasement; i++){
			for (j = i + increasement; j < length; j += increasement){
				if (arr[j] < arr[j - increasement]){
					int temp = arr[j];
					for (k = j - increasement; k >= 0 && temp < arr[k]; k -= increasement){
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}
	} while (increasement > 1);
}
```

###### 5) 快速排序

​	**基本思想：**选择一个基准数，通过一趟排序将要排序的数据分割成独立的两部分；其中一部分的所有数据都比另外一部分的所有数据都要小。然后，再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列

​	**具体过程：**从待排序列中任意选取一个记录(通常选取第一个记录)作为基准值；将记录中关键字比它小的记录都安置在它的位置之前，将记录中关键字比它大的记录都安置在它的位置之后。这样，以该基准值为分界线，将待排序列分成的两个子序列；递归地把"基准值前面的子数列"和"基准值后面的子数列"进行排序

​	**快速排序的时间复杂度在最坏情况下是O(N^2)，平均的时间复杂度是O(N*lgN)**

​	**快速排序是稳定的**	

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20210928111234534.png" alt="image-20210928111234534" style="zoom:50%;" />

​	**实现：**

```c++
void quickSort(int arr[], int low, int high){
    if (low >= high){
        return;
    }
    int i = low;
    int j = high;
    //基准数，一般初始化为第一个记录
    int baseVal = arr[low];
    //当i >= j 时结束本次遍历交换
    while (i < j){
        //从右向左找比基准数小的数
        while (i < j && arr[j] >= baseVal){
            j--;
        }
        if (i < j){
            arr[i] = arr[j];
            i++;
        }
        // 从左向右找比基准数大的数
        while (i < j && arr[i] < baseVal){
            i++;
        }
        if (i < j){
            arr[j] = arr[i];
            j--;
        }
    }
    //把基准数放到i的位置
    arr[i] = baseVal;
    //递归剩余的序列
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}
```

###### 6) 归并排序

​	**算法思想：**分治思想，“归并”的含义是将两个或两个以上的有序序列组合成一个新的有序表。假设初始序列含有n个记录，则可以看成是n个有序的子序列，每个子序列的长度为1，然后两两归并，得到![img](https://img-blog.csdn.net/20180610100804187)（![img](https://img-blog.csdn.net/20180610100859572)表示不小于x的最小整数）个长度为2(或者是1)的有序子序列，再两两归并。如此重复，直到得到一个长度为n的有序序列为止。

​	<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20210928114512224.png" alt="image-20210928114512224" style="zoom:50%;" />

​	**实现：**

```c++
//将有二个有序数列a[first...mid]和a[mid+1...last]合并。
void mergeOrderArray(int a[], int first, int mid, int last, int temp[]){
    //在形参中定义了一个暂存数组temp[]
    int i = first, j = mid + 1;
    int m = mid,   n = last;
    int k = 0;
    //同时遍历两个数组中的记录，将小的记录赋值给temp[]
    while (i <= m && j <= n){
        if (a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    }
    //如果其中一个数组遍历结束，则将剩余记录赋值给temp[]
    while (i <= m){
        temp[k++] = a[i++];
    }
    while (j <= n){
        temp[k++] = a[j++];
    }
    //将temp[]复制给a[]
    for (i = 0; i < k; i++){
        a[first + i] = temp[i];
    }
}
//递归将序列划分为只有一个元素的子序列, 然后逐次对子序列进行合并
void merge_sort(int a[], int first, int last, int temp[]){
    if (first < last){
        int mid = (first + last) / 2;
        merge_sort(a, first, mid, temp);    //左边有序
        merge_sort(a, mid + 1, last, temp); //右边有序
        mergeOrderArray(a, first, mid, last, temp); //再将二个有序数列合并
    }
}
//再封装一层函数(用户友好度)
void mergeSort(int a[], int n){
    //动态数组，申请n个大小为int的内存
    int *p = new int[n];
    merge_sort(a, 0, n - 1, p);
}
```

###### 7) 堆排序

​	**堆：**n个元素的序列{k1, k2, ... , kn}当且仅当满足一下条件时，称之为堆；可以将堆看做是一个完全二叉树。并且，每个结点的值都大于等于其左右孩子结点的值，称为大顶堆；或者每个结点的值都小于等于其左右孩子结点的值，称为小顶堆

​	<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20210928120120164.png" alt="image-20210928120120164" style="zoom:50%;" />

​	**堆排序思想：**将待排序列构造成一个大顶堆(或小顶堆)，整个序列的最大值(或最小值)就是堆顶的根结点，将根节点的值和堆数组的末尾元素交换，此时末尾元素就是最大值(或最小值)，然后将剩余的n-1个序列重新构造成一个堆，这样就会得到n个元素中的次大值(或次小值)，如此反复执行，最终得到一个有序序列

​	<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20210928120321297.png" alt="image-20210928120321297" style="zoom:50%;" />

​	**将二叉树调整为堆：**从二叉树最后一个非叶子结点开始，将结点上的值依次和左右子树中的值作比较，若子树上的值大于结点值，则将其交换。对二叉树上所有的非叶子结点执行上述操作，最终将二叉树调整为一个大顶堆。

​	**实现：**

```c++
/*
	arr 待调整的数组
	i 待调整的结点的下标
	length 数组的长度
*/
void HeapAdjust(int arr[], int i, int length)
{
	// 调整i位置的结点
	// 先保存当前结点的下标
	int max = i;
	// 当前结点左右孩子结点的下标
	int lchild = i * 2 + 1;
	int rchild = i * 2 + 2;
	if (lchild < length && arr[lchild] > arr[max])
	{
		max = lchild;
	}
	if (rchild < length && arr[rchild] > arr[max])
	{
		max = rchild;
	}
	// 若i处的值比其左右孩子结点的值小，就将其和最大值进行交换
	if (max != i)
	{
		int temp;
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
		// 递归
		HeapAdjust(arr, max, length);
	}
}
 
// 堆排序
void HeapSort(int arr[], int length)
{
	// 初始化堆
	// length / 2 - 1是二叉树中最后一个非叶子结点的序号
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(arr, i, length);
	}
	// 交换堆顶元素和最后一个元素
	for (int i = length - 1; i >= 0; i--)
	{
		int temp;
		temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		HeapAdjust(arr, 0, i);
	}
}
```

##### 2.利用sort函数

需要引入<algorithm>头文件

默认从小到大排序，但是可以通过cmp函数制定排序规则，实现自定义排序

```c++
//排序长度为n的arr数组
sort(num , num + n);

//按需求自定义cmp
struct Stu{
	int stuId , score;
}stu[11]

//按分数降序排序，若分数相同则按学号升序排序
bool cmp(Stu stu1 , Stu stu2){
	if(stu1.score != stu2.score){
		return stu1.score > stu2.score;
	}else{
		return stu1.stuId < stu2.stuId;
	}
}

sort(stu , stu + n , cmp)
```

