// UVa679 Dropping Balls
// Rujia Liu
#include<cstdio>
int main() {
  int T, D, I;
  scanf("%d", &T);// 直接模拟最后一个小球的路线.  T表示一共有多少组数据



  while(T--) {
    scanf("%d%d", &D, &I);// 读取2个数 D是深度, I是小球的数量.
    int k = 1;  //每一个小球, 他是奇数 那么他就往根的左边走, 偶数就往右边走
    /// 第三个球,是往做再往左. 等价于编号1了, 对于第二次判断.
    // 第四个球,往右再往左. 所以规律就是判断奇偶数,然后奇数就/2 ,偶数就
    for(int i = 0; i < D-1; i++) //一层一层的走, i表示当前层数. I表示第几个.
      if(I%2) { k = k*2; I = (I+1)/2; }// 偶数就向右走, I表示剩余的.
      else { k = k*2+1; I /= 2; }
    printf("%d\n", k);
  }
  return 0;
}
