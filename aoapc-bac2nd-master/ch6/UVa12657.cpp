// UVa12657 Boxes in a Line
// Rujia Liu
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100000 + 5;  //为什么加5.
int n, left[maxn], right[maxn];  /// right表示下一个节点的index      //left表示上一个节点.

inline void link(int L, int R) {
  right[L] = R; left[R] = L;
}

int main() {
  int m, kase = 0;
  while(scanf("%d%d", &n, &m) == 2) { //每次读2个数据,就处理开始.

      //初始化链表.  0还是头指针.
    for(int i = 1; i <= n; i++) {
      left[i] = i-1;
      right[i] = (i+1) % (n+1);//最后节点连接到头结点. 当i取n时候, 连接到head节点.
    }


    right[0] = 1; left[0] = n; //初始化.
    int op, X, Y, inv = 0;




    while(m--) {//读取m个操作.
      scanf("%d", &op);   //每一个操作是一个数组. 读一个数字
      if(op == 4) inv = !inv;  //进行翻转.
      else {


        scanf("%d%d", &X, &Y);
        if(op == 3 && right[Y] == X) swap(X, Y); //交换引用. 因为就是下一个,所以整个链表结构不变, 只改变数据即可. swap就够了.
        if(op != 3 && inv) op = 3 - op; //因为之前有4操作互换.
        if(op == 1 && X == left[Y]) continue;
        if(op == 2 && X == right[Y]) continue;

        int LX = left[X], RX = right[X], LY = left[Y], RY = right[Y];
        if(op == 1) { // 如果是op1那么就
          link(LX, RX); link(LY, X); link(X, Y);
        }
        else if(op == 2) {
          link(LX, RX); link(Y, X); link(X, RY);
        }
        else if(op == 3) {//如果是交换, 如果x本身就在y的左边.
          if(right[X] == Y) { link(LX, Y); link(Y, X); link(X, RY); }
          else { link(LX, Y); link(Y, RX); link(LY, X); link(X, RY); }
        }



      }
    }








//下面是打印结果.
    int b = 0; //指针变量.
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
      b = right[b];
      if(i % 2 == 1) ans += b;
    }//奇数的都加上.

    if(inv && n % 2 == 0) ans = (long long)n*(n+1)/2 - ans;// 如果做了inv总共偶数个,那么就是全部其他值.
    printf("Case %d: %lld\n", ++kase, ans);







  }
  return 0;
}
