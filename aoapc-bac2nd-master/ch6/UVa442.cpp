// UVa442 Matrix Chain Multiplication
// Rujia Liu
// 题意：输入n个矩阵的维度和一些矩阵链乘表达式，输出乘法的次数。假定A和m*n的，B是n*p的，那么AB是m*p的，乘法次数为m*n*p
// 算法：用一个栈。遇到字母时入栈，右括号时出栈并计算，然后结果入栈。因为输入保证合法，括号无序入栈
#include<cstdio>
#include<stack>
#include<iostream>
#include<string>
using namespace std;

struct Matrix {
  int a, b;        //矩阵需要维护他的横纵大小. a,b即可.
  Matrix(int a=0, int b=0):a(a),b(b) {}  //构造函数, 默认都取0,
} m[26];     //26个矩阵.

stack<Matrix> s;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string name;  //至多26个矩阵,
    cin >> name;// 先读取一个字符串,
    int k = name[0] - 'A';  //然后用一个int来 表示,
    cin >> m[k].a >> m[k].b;// 之后读取2个int,
  }
  string expr;
  while(cin >> expr) {// 下面读入表达式.
    int len = expr.length();
    bool error = false;
    int ans = 0;
    for(int i = 0; i < len; i++) {// 根据括号匹配栈.
      if(isalpha(expr[i])) s.push(m[expr[i] - 'A']);  //是字母就亚茹栈.
      else if(expr[i] == ')') {     // ( 不用管,  )匹配就行.
        Matrix m2 = s.top(); s.pop();           //匹配到了就找到m2
        Matrix m1 = s.top(); s.pop();          //再找到m1
        if(m1.b != m2.a) { error = true; break; }
        ans += m1.a * m1.b * m2.b;         //匹配到的就计算复杂度即可.
        s.push(Matrix(m1.a, m2.b));          //把结果压入站. 重新简历一个新矩阵.是一个新矩阵.
      }
    }
    if(error) printf("error\n"); else printf("%d\n", ans);
  }

  return 0;
}
