// UVa11988 Broken Keyboard
// Rujia Liu
#include<cstdio>
#include<cstring>
const int maxn = 100000 + 5;
int last, cur, next[maxn]; // 光标位于cur号字符之后面//  next数组来实现的链表.
char s[maxn];   //char 所有位置.都会初始化为/0

int main() {
  while(scanf("%s", s+1) == 1) {//存入数组中. 地址便宜一个.// 读入一个数据就存下来, 一个数据不超过100000+5个字符.
      // 表示每次处理一个字符串, 空格作为结束符.

    int n = strlen(s+1); // 输入保存在s[1], s[2]...中
    last = cur = 0;
    next[0] = 0;

    for(int i = 1; i <= n; i++) {
      char ch = s[i];
      if(ch == '[') cur = 0;
      else if(ch == ']') cur = last;
      else {
        next[i] = next[cur];
        next[cur] = i;
        if(cur == last) last = i; // 更新“最后一个字符”编号
        cur = i; // 移动光标
      }
    }


    for(int i = next[0]; i != 0; i = next[i])
      printf("%c", s[i]);

    printf("\n");
  }
  return 0;
}
