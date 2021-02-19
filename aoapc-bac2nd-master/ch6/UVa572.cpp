// UVa572 Oil Deposits
// Rujia Liu
// 题意：输入一个字符矩阵，统计字符@组成多少个四连块
#include<cstdio>
#include<cstring>
const int maxn = 100 + 5;

char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

void dfs(int r, int c, int id) {
  if(r < 0 || r >= m || c < 0 || c >= n) return;   //先做边界判断.
  if(idx[r][c] > 0 || pic[r][c] != '@') return;  //如果已经走过或者走到的不是@, 也跳过
  idx[r][c] = id;  //下面的情况就都是可以做idx的了. 直接标记后. 继续找他周围的点dfs即可.
  for(int dr = -1; dr <= 1; dr++)//d表示差分.
    for(int dc = -1; dc <= 1; dc++)
      if(dr != 0 || dc != 0) dfs(r+dr, c+dc, id);  // if 去掉原地情况.
}

int main() {
  while(scanf("%d%d", &m, &n) == 2 && m && n) {
    for(int i = 0; i < m; i++) scanf("%s", pic[i]);
    memset(idx, 0, sizeof(idx));
    int cnt = 0;
    for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
        if(idx[i][j] == 0 && pic[i][j] == '@') dfs(i, j, ++cnt);//每碰到一个@,并且idex没有遍历过就开始遍历这个点.
    printf("%d\n", cnt);
  }
  return 0;
}
