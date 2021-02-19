// UVa122 Trees on the level
// Rujia Liu
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 256 + 10;

struct Node{
    bool have_value;
    int v;
    Node* left, *right;
    Node():have_value(false),left(NULL),right(NULL){}
};

Node* root;

Node* newnode() { return new Node(); }

bool failed;
void addnode(int v, char* s) {
    int n = strlen(s);
    Node* u = root; //从root 出发.
    for(int i = 0; i < n; i++)
        if(s[i] == 'L') {
            if(u->left == NULL) u->left = newnode();
            u = u->left;
        } else if(s[i] == 'R') {
            if(u->right == NULL) u->right = newnode();
            u = u->right;
        }
    if(u->have_value) failed = true;
    u->v = v;
    u->have_value = true;
}

void remove_tree(Node* u) {
    if(u == NULL) return;
    remove_tree(u->left);  //递归析构每一个节点.
    remove_tree(u->right);
    delete u;  //然后再析构自己.
}

char s[maxn]; //字符串处理用这个char数组, 不用char * . 那个不好用.因为char * 定义底层是char const , 不容易修改.  这个字符串的用法是 s[index] 表示取索引位置.  &s[index]表示取index开始到结尾的子串.
bool read_input() {
    failed = false; //初始化设置当前全局变量.
    remove_tree(root);
    root = newnode();
    for(;;) {  //死循环的写法.
        if(scanf("%s", s) != 1) return false;
        if(!strcmp(s, "()")) break;
        int v;
        sscanf(&s[1], "%d", &v); //把子串给v, 字符串就是地址. 下面用v表示这个字符串 里面的数值. 就是抽取前面这个子串里面的数字部分. 把他抽取出来给v. 达到正则的目的.
        addnode(v, strchr(s, ',')+1);
    }
    return true;
}

bool bfs(vector<int>& ans) {
    queue<Node*> q;  //用广度遍历, 逐行打印.  每一次扔进去left,right就等价于走了一行.
    ans.clear();
    q.push(root);     // 队列中,一直扔节点.然后取一个仍如left,right
    while(!q.empty()) {
        Node* u = q.front(); q.pop();
        if(!u->have_value) return false;
        ans.push_back(u->v);
        if(u->left != NULL) q.push(u->left);
        if(u->right != NULL) q.push(u->right);
    }
    return true;
}

int main() {
    vector<int> ans;
    while(read_input()) {//每次读一行
        if(!bfs(ans)) failed = 1;
        if(failed) printf("not complete\n");
        else {
            for(int i = 0; i < ans.size(); i++) {
                if(i != 0) printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
