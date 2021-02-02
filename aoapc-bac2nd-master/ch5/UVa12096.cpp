// UVa12096 The SetStack Computer
// Rujia Liu
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set,int> IDcache; // 把集合映射成ID
vector<Set> Setcache; // 根据ID取集合

// 查找给定集合x的ID。如果找不到，分配一个新ID
int ID (Set x) {
  if (IDcache.count(x)) return IDcache[x];
  Setcache.push_back(x); // 添加新集合  注意取id的时候, 就已经存在 setcache里面了.
  return IDcache[x] = Setcache.size() - 1;
}

int main () {
  int T;
  cin >> T;  //一共有多少个操作.
  while(T--) {
    stack<int> s; // 题目中的栈
    int n;
    cin >> n; //一个栈有n个操作.
    for(int i = 0; i < n; i++) {
      string op;
      cin >> op; //读入一个操作.
      if (op[0] == 'P') s.push(ID(Set()));  //直接压入, 需要id操作.
      else if (op[0] == 'D') s.push(s.top());// 栈顶复制
      else {
        Set x1 = Setcache[s.top()]; s.pop(); // 找到栈顶所表示的set, 然后栈poop
        Set x2 = Setcache[s.top()]; s.pop(); //再做一次. 得到另一个set x2
        Set x;   //建立一个新的set来存.
        if (op[0] == 'U') set_union (ALL(x1), ALL(x2), INS(x));// set_union 输入 first的起止坐标,
//并操作.
        if (op[0] == 'I') set_intersection (ALL(x1), ALL(x2), INS(x)); //交操作
        if (op[0] == 'A') { x = x2; x.insert(ID(x1)); }  // 插入操作. 把x1插入到x2中.
        s.push(ID(x)); //新的栈压回去.
      }      
      cout << Setcache[s.top()].size() << endl;
    }
    cout << "***" << endl;
  }
  return 0;  
}
