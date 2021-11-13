#### 树

##### 1.性质

​	1.只有一个根节点；

​	2.除了根节点，所有节点都有且只有一个父节点；

​	3.无环。将任意一个节点作为起始节点，都不存在任何回到该起始节点的路径。（正是前两个性质保证了无环的成立。）

##### 2.名词

- **根（Root）**：树中最顶端的节点，根没有父节点。

- **子节点（Child）**：节点所拥有子树的根节点称为该节点的子节点。
- **父节点（Parent）**：如果节点拥有子节点，则该节点为子节点的父节点。
- **兄弟节点（Sibling）**：与节点拥有相同父节点的节点。
- **子孙节点（Descendant）**：节点向下路径上可达的节点。
- **叶节点（Leaf）**：没有子节点的节点。
- **内节点（Internal Node）**：至少有一个子节点的节点。
- **度（Degree）**：节点拥有子树的数量。
- **边（Edge）**：两个节点中间的链接。
- **路径（Path）**：从节点到子孙节点过程中的边和节点所组成的序列。
- **层级（Level）**：根为 Level 0 层，根的子节点为 Level 1 层，以此类推。
- **高度（Height）/深度（Depth）**：树中层的数量。比如只有 Level 0,Level 1,Level 2 则高度为 3。

#### 树的三种遍历形式

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211013194509197.png" alt="image-20211013194509197" style="zoom:40%;" />

##### 1.前序遍历

​	**根->左子树->右子树**

​	上图二叉树的前序遍历：**ABCDEFGHK**

```c++
void preOrder(Tree * bt){
      if(bt!=NULL){
           visit(bt->data);
           preOrder(bt->lChild);
           preOrder(bt->rChild);
    }       
}
```

##### 2.中序遍历

​	**左子树->根->右子树**

​	上图二叉树的中序遍历：**BDCAEHGKF**

```c++
void inOrder(Tree * bt){
      if(bt!=NULL){
           inOrder(bt->lChild);
           visit(bt->data);
           inOrder(bt->rChild);
    }       
}
```

##### 3.后序遍历

​	**左子树->右子树->根**

​	上图二叉树的后序遍历：DCBHKGFEA

```c++
void postOrder(Tree * bt){
      if(bt!=NULL){
           postOrder(bt->lChild);
           postOrder(bt->rChild);
           visit(bt->data);
    }       
}
```

#### 二叉树（Binary Tree）

##### 1.二叉树

​	**二叉树（Binary Tree）是一种特殊的树类型，其每个节点最多只能有两个子节点。**这两个子节点分别称为当前节点的左孩子（left child）和右孩子（right child）。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211014085229995.png" alt="image-20211014085229995" style="zoom:50%;" />

##### 2.完全二叉树和满二叉树

​	**完全二叉树（Complete Binary Tree）**：深度为 h，有 n 个节点的二叉树，当且仅当其每一个节点都与深度为 h 的满二叉树中，序号为 1 至 n 的节点对应时，称之为完全二叉树。

​	**满二叉树（Full Binary Tree）**：一棵深度为 h，且有 2h - 1 个节点称之为满二叉树。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211014085503545.png" alt="image-20211014085503545" style="zoom:50%;" />

#### 二叉查找树

##### 1.性质

​	二叉查找树（BST：Binary Search Tree）是一种特殊的二叉树，它改善了二叉树节点查找的效率。二叉查找树有以下性质：

​	对于任意一个节点 n，

- 其左子树（left subtree）下的每个后代节点（descendant node）的值都小于节点 n 的值；

- 其右子树（right subtree）下的每个后代节点的值都大于节点 n 的值。

  <img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211014085854538.png" alt="image-20211014085854538" style="zoom:50%;" />

##### 2.节点操作

```c++
//二叉树结构体定义
typedef struct node{
	int value;
	char key;
	int Index;
	struct node *left;
	struct node *right;
}BSTNode,*PBSTNode;
```

**查询节点：**

​	假设要查找节点 n，从 BST 的根节点开始。算法不断地比较节点值的大小直到找到该节点，或者判定不存在。每一步都要处理两个节点：树中的一个节点，称为节点 c，和要查找的节点 n，然后并比较 c 和 n 的值。开始时，节点 c 为 BST 的根节点。然后执行以下步骤：

1. 如果 c 值为空，则 n 不在 BST 中；
2. 比较 c 和 n 的值；
3. 如果值相同，则找到了指定节点 n；
4. 如果 n 的值小于 c，那么如果 n 存在，必然在 c 的左子树中。回到第 1 步，将 c 的左孩子作为 c；
5. 如果 n 的值大于 c，那么如果 n 存在，必然在 c 的右子树中。回到第 1 步，将 c 的右孩子作为 c；

**BST 算法查找时间依赖于树的拓扑结构。最佳情况是 O(log­2n)，而最坏情况是 O(n)。**

```c++
//查找
//找到指定的键值
PBSTNode  Get(PBSTNode root,char Key)
{
	if(!root)
		return NULL;
	if(Key == root->key)
		return root;
	else if(Key < root->key)
		return Get(root->left,Key);
	else
		return Get(root->right,Key);
}
```

**插入节点：**

​	当向树中插入一个新的节点时，该节点将总是作为叶子节点。所以，最困难的地方就是如何找到该节点的父节点。类似于查找算法中的描述，我们将这个新的节点称为节点 n，而遍历的当前节点称为节点 c。开始时，节点 c 为 BST 的根节点。则定位节点 n 父节点的步骤如下：

1. 如果节点 c 为空，则节点 c 的父节点将作为节点 n 的父节点。如果节点 n 的值小于该父节点的值，则节点 n 将作为该父节点的左孩子；否则节点 n 将作为该父节点的右孩子。
2. 比较节点 c 与节点 n 的值。
3. 如果节点 c 的值与节点 n 的值相等，则说明用户在试图插入一个重复的节点。解决办法可以是直接丢弃节点 n，或者可以抛出异常。
4. 如果节点 n 的值小于节点 c 的值，则说明节点 n 一定是在节点 c 的左子树中。则将父节点设置为节点 c，并将节点 c 设置为节点 c 的左孩子，然后返回至第 1 步。
5. 如果节点 n 的值大于节点 c 的值，则说明节点 n 一定是在节点 c 的右子树中。则将父节点设置为节点 c，并将节点 c 设置为节点 c 的右孩子，然后返回至第 1 步。

```c++
//插入操作
//------1.BSTree为空-------------------------
//------2.BSTree已经有该键，那么只需要更新
//------3.正常操作---------------------------
void BSTInsert(PBSTNode *root,char Key,int Value)
{
	//树开始是空值
	if(!(*root))
	{
		(*root) = (PBSTNode)malloc(sizeof(BSTNode));
		(*root)->Index = 0;
		(*root)->key = Key;
		(*root)->value = Value;
		(*root)->left = (*root)->right = NULL;
		return;
	}
	PBSTNode Temp = (PBSTNode)malloc(sizeof(BSTNode));
	PBSTNode des = Get((*root),Key);
	//已经存在更新键值
	if(des != NULL)
	{
		des->value = Value;
		return;
	}
	//正常的情况下：
	PBSTNode Go = (*root);
	while(Go)
	{
		if(Go->key > Key)
		{
			if(!Go->left)
			{
				Temp->key = Key;
				Temp->value = Value;
				Temp->left = Temp->right = NULL;
				Go->left = Temp;
                //序号没有实现更新。
				return;
			}
			else
				Go = Go->left;
		}//end of > situation
		else
		{
			if(!Go->right)
			{
				Temp->key = Key;
				Temp->value = Value;
				Temp->left = Temp->right = NULL;
				Go->right = Temp;
				return;
			}
			else
				Go = Go->right;
		}
	}
}
```

```c++
//利用插入函数来创建BSTree
PBSTNode CreateBSTree(char *data,int n)
{
	PBSTNode Root = NULL;
	if(n == 0)
		Root =  NULL;
	else
	{
		for(int i = 0;i < n;i++)
			BSTInsert(&Root,data[i],i);
	}
	return Root;
}
```

**删除节点：**

​	删除节点算法的第一步是定位要被删除的节点，这可以使用前面介绍的查找算法，因此运行时间为 O(log­2n)。接着应该选择合适的节点来代替删除节点的位置，它共有三种情况需要考虑。

- **情况 1：**如果删除的节点没有右孩子，那么就选择它的左孩子来代替原来的节点。二叉查找树的性质保证了被删除节点的左子树必然符合二叉查找树的性质。因此左子树的值要么都大于，要么都小于被删除节点的父节点的值，这取决于被删除节点是左孩子还是右孩子。因此用被删除节点的左子树来替代被删除节点，是完全符合二叉搜索树的性质的。
- **情况 2：**如果被删除节点的右孩子没有左孩子，那么这个右孩子被用来替换被删除节点。因为被删除节点的右孩子都大于被删除节点左子树的所有节点，同时也大于或小于被删除节点的父节点，这同样取决于被删除节点是左孩子还是右孩子。因此，用右孩子来替换被删除节点，符合二叉查找树的性质。
- **情况 3：**如果被删除节点的右孩子有左孩子，就需要用被删除节点右孩子的左子树中的最下面的节点来替换它，就是说，我们用被删除节点的右子树中最小值的节点来替换。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211014091808631.png" alt="image-20211014091808631" style="zoom:50%;" />

```c++
//删除操作:
//-------1、未查找到----------------------------------------------------------------------
//-------2、删除的节点只有一个子节点，直接将其删除，并让其父节点指向其唯一的那个子节点即可
//-------3、删除的节点是叶子节点，直接删除就行
//-------4、删除的结点有两个子节点，则有两种方案可供选择：
//-------------------------------------------------------1)选取其右孩子的最小结点来顶替其位置
//-------------------------------------------------------2)选取其左孩子的最大节点来顶替其位置
//返回值-1表示删除非法。1代表成功。
int Delete(PBSTNode * Root,char key)
{
	//删除头结点
	if((*Root)->key == key)
	{
		if(!(*Root)->left && (*Root)->right)
		{
			(*Root) = (*Root)->right;
			free((*Root));
			return 1;
		}
		else if((*Root)->left && !(*Root)->right)
		{
			(*Root) = (*Root)->left;
			free((*Root));
			return 1;
		}
		PBSTNode Min = (PBSTNode)malloc(sizeof(BSTNode));
		Min = (*Root)->right;
		PBSTNode ParentMin = (PBSTNode)malloc(sizeof(BSTNode));
		ParentMin = (*Root);
		while(Min->left)
		{
			ParentMin = Min;
			Min = Min->left;
		}
		ParentMin->left = Min->right;
		Min->left = (*Root)->left;
		Min->right = (*Root)->right;
		(*Root) = Min;
		return 1;
	}
	//因为需要找到删除节点的父节点，所以不能调用Get函数
	PBSTNode Parent = (*Root);
	PBSTNode Go = (*Root);
	while(Go)
	{
		if(Go->key == key)
			break;
		else if(Go->key > key)
		{
			Parent = Go;
			Go = Go->left;
		}
		else
		{
			Parent = Go;
			Go = Go->right;
		}
	}
	//Situation 1
	if(!Go)
		return -1;
	//Situation 2
	if(!Go->left && Go->right)
	{
		if(Parent->left == Go)
			Parent->left = Go->right;
		else
			Parent->right = Go->right;
		free(Go);
		return 1;
	}
	else if(Go->left && !Go->right)
	{
		if(Parent->left == Go)
			Parent->left = Go->left;
		else
			Parent->right = Go->left;
		free(Go);
		return 1;
	}
    //Situation 3
	else if(!Go->left && !Go->right)
	{
		if(Parent->left == Go)
			Parent->left = NULL;
		else
			Parent->right = NULL;
		free(Go);
		return 1;
	}
	//Situation 4
	//Choose Solution 1: Min right son
	else
	{
		PBSTNode Min = (PBSTNode)malloc(sizeof(BSTNode));
		Min = Go->right;
		PBSTNode ParentMin = (PBSTNode)malloc(sizeof(BSTNode));
		ParentMin = Go;
		while(Min->left)
		{
			ParentMin = Min;
			Min = Min->left;
		}
		if(Parent->left == Go)
		{
			Parent->left = Min;
			ParentMin->left = Min->right;
			Min->left = Go->left;
			Min->right = Go->right;
		}
		else
		{
			Parent->right = Min;
			ParentMin->left = Min->right;
			Min->left = Go->left;
			Min->right = Go->right;
		}
	}//end of else
	return 1;
}
```

##### 3.例题实现

###### 1.complete BST

**Input：**

​	Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

```
10
1 2 3 4 5 6 7 8 9 0
```

**Output：**

```
6 3 8 1 5 7 9 0 2 4
```

**solve：**根据给定序列，建一棵完全二叉搜索树

```c++
//根据给定序列，建一棵完全二叉搜索树 
#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int data;
	int lchild;
	int rchild;
}Node[1010];
int n,len=1;
bool cmp(int a,int b){
	return a<b;
}
//构建CBST
void create(int data[],int index){
	if(index*2>n){
		Node[index].data=data[len];
		len++;
		return;
	}
	if(index*2<=n) create(data,index*2);
	Node[index].data=data[len];len++;
	if(index*2+1<=n) create(data,index*2+1);
}
int main(){
	int buf[1010];
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		scanf("%d",&buf[i]);
	}
	sort(buf+1,buf+n+1,cmp);
	create(buf,1);
	for(i=1;i<=n-1;i++){
		printf("%d ",Node[i].data);
	}
	printf("%d",Node[n].data);
	return 0;
} 
```

