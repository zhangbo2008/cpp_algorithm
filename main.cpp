// UVa548 Tree
// Rujia Liu
// 题意：给一棵点带权（权各不相同，都是正整数）二叉树的中序和后序遍历，找一个叶子使得它到根的路径上的权和最小。如果有多解，该叶子本身的权应尽量小
// 算法：递归建树，然后DFS。注意，直接递归求结果也可以，但是先建树的方法不仅直观，而且更好调试
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

// 因为各个结点的权值各不相同且都是正整数，直接用权值作为结点编号
const int maxv = 10000 + 10;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n;

bool read_list(int* a) { // 传入的是int数组.
    string line;
    if(!getline(cin, line)) return false;  //从标准输入读取一行到line这个变量.
    stringstream ss(line);// 变成stringstream
    n = 0;
    int x;
    while(ss >> x) a[n++] = x;// n表示节点的数量.
    return n > 0;
}

// 把in_order[L1..R1]和post_order[L2..R2]建成一棵二叉树，返回树根
int build(int L1, int R1, int L2, int R2) {
    if(L1 > R1) return 0; // 空树
    int root = post_order[R2];
    int p = L1;
    while(in_order[p] != root) p++;
    int cnt = p-L1; // 左子树的结点个数  , p位置是root,
    lch[root] = build(L1, p-1, L2, L2+cnt-1);
    rch[root] = build(p+1, R1, L2+cnt, R2-1);
    return root;
}

int best, best_sum; // 目前为止的最优解和对应的权和, best用来存解的叶子值.

void dfs(int u, int sum) { // u是根节点的val
    sum += u;
    if(!lch[u] && !rch[u]) { // 叶子
        if(sum < best_sum || (sum == best_sum && u < best)) { best = u; best_sum = sum; }
    }
    if(lch[u]) dfs(lch[u], sum);//如果有做节点, 那么我们就递归跑子问题.
    if(rch[u]) dfs(rch[u], sum);
}

int main() {
    while(read_list(in_order)) {
        read_list(post_order);//读入2个顺序表.
        build(0, n-1, 0, n-1);
        best_sum = 1000000000;
        dfs(post_order[n-1], 0);
        cout << best << "\n";
    }
    return 0;
}
