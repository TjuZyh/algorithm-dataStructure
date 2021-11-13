#### 8_string

##### 1、trie（字典树）

###### 1.定义

​	字典树，顾名思义，是关于“字典”的一棵树。即：它是对于字典的一种存储方式（所以是一种数据结构而不是算法）。这个词典中的每个“单词”就是从根节点出发一直到某一个目标节点的路径，路径中每条边的字母连起来就是一个单词。

<img src="/Users/zyh/Library/Application Support/typora-user-images/image-20211107110420328.png" alt="image-20211107110420328" style="zoom:80%;" />

```
apple
dog
cat
```

trie树的核心思想是空间换时间，利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。

###### 2.Trie树的基本性质

- 根节点不包含字符，除根节点意外每个节点只包含一个字符。
- 从根节点到某一个节点，路径上经过的字符连接起来，为该节点对应的字符串。
-  每个节点的所有子节点包含的字符串不相同。
- 如果字符的种数为n，则每个结点的出度为n，这也是空间换时间的体现，浪费了很多的空间。
- 插入查找的复杂度为O(n)，n为字符串长度。

###### 3.基本思想

**1. 插入过程(insert)**

​	对于一个单词，从根开始，沿着单词的各个字母所对应的树中的节点分支向下走，直到单词遍历完，将最后的节点标记，表示该单词已插入Trie树。

**2.查询过程(search)**

​	从根开始按照单词的字母顺序向下遍历trie树，一旦发现某个节点标记不存在或者单词遍历完成而最后的节点未标记，则表示该单词不存在，若最后的节点已标记，表示该单词存在。

###### 4.数据结构

```c++
struct Trie {
    int tag, next[next_cnt];
    void init() {
        tag = 0;
        memset(next, -1, sizeof(next));
    }
}trie[maxn];
```

###### 5.Trie树的操作

**1. 插入**

假设存在字符串str，Trie树的根结点为root，root一开始为0，i一开始为0。

​	1) 取str[i]，判断trie[root].next[str[i]-97]是否为空。（**ASCII(a) == 97**）

​		**若为空 **: 则增加trie_node来分配新节点，记新节点的地址为next，把新节点的地址赋给trie[root].next[str[i]-97]，然后root = next；

​		**若非空 **: 则root=trie[root].next[str[i]-97]；
​	2)i++，继续取str[i]，重复1)中的操作，直到遇到结束符'\0'，返回当前节点的值。

```c++
void update(char *str) {
    int len = strlen(str), root = 0;
    for (int i = 0; i < len; i++) {
        int temp = str[i] - 'a';
        int next = trie[root].next[temp];
      	//若空
        if (next == -1) {
            next = ++trie_cnt;
            trie[next].init();
            trie[root].next[temp] = next;
        }
        root = next;
    }
    trie[root].tag = 1;
}
```

**2.查找**

假设要查找的字符串为str，Trie树的根结点为root，root=0，i=root

​	1)取str[i]，判断判断trie[root].next[str[i]-97]是否为空。

​		**若为空**，则返回false；

​		**若非空**，则root=trie[root].next[str[i]-97]，继续取字符。

​	2)重复1)中的操作直到遇到结束符'\0'，返回当前节点的值。

```c++
int query(char *str) {
    int len = strlen(str), root = 0;
    for (int i = 0; i < len; i++) {
        int temp = str[i] - 'a';
        int next = trie[root].next[temp];
        if (next == -1) {
            return 0;
        }
        root = next;
    }
    return trie[root].tag;
}
```

###### 6.例题

**1.hat's words**

**Problem descripation:**

A hat’s word is a word in the dictionary that is the concatenation of exactly two other words in the dictionary. You are to find all the hat’s words in a dictionary

**Input:**

Standard input consists of a number of lowercase words, one per line, in alphabetical order. There will be no more than 50,000 words. Only one case. 

```
a
ahat
hat
hatword
hziee
word
```

**output:**

Your output should contain all the hat’s words, one per line, in alphabetical order.

```
ahat
hatword
```

**思路：利用trie存储全部单词，后利用substr拆分单词后搜索trie，若均在trie中，则输出**

**实现：**

```c++
#include<iostream>
#include<algorithm>
using namespace std;

/*
a
ahat
hat
hatword
hziee
word
 */

/*利用substr分割成两块暴力查找*/
string word[50010] = {};
int n = 1, num = 1;
int tire[50000][30] = {};
int vis[500009] = {};
void insert(string str){
    int len = str.length();
    //初始化根节点
    int nd = 0;
    for(int i = 0; i < len; i++){
        int k = str[i] - 'a';
        //子节点为空
        if (!tire[nd][k]){
            tire[nd][k] = num;
            num++;
        }
        nd = tire[nd][k];
    }
    //结束标识
    vis[nd] = 1;
}
int search(string str){
    int len = str.length();
    int nd = 0;
    for(int i = 0; i < len; i++){
        int k = str[i] - 'a';
        if (!tire[nd][k]){
            return 0;
        }
        nd = tire[nd][k];
    }
    if (vis[nd] == 1){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    while(cin >> word[n]){
        //建立trie树
        insert(word[n]);
        n++;
    }
    for(int i = 1; i <= n; i++){
        for (int j = 1; j < word[i].length(); j++){
            string s1, s2;
            //将单词分割两部分，搜索trie树即可
            s1 = word[i].substr(0, j);
            s2 = word[i].substr(s1.length(), word[i].length()-s1.length());
            if (search(s1) && search(s2)){
                cout << word[i] << endl;
                break;
            }else{
                continue;
            }
        }
    }
    return 0;
}
```

