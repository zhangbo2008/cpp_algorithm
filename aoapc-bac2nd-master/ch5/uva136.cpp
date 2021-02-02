// UVa136 Ugly Numbers
// Rujia Liu
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
const int coeff[3] = {2, 3, 5};

int main() {
  priority_queue<LL, vector<LL>, greater<LL> > pq;  // 建立一个有限队列. 第一个是类型,第二个底层结构.第三个是< 函数.
  //所以这里面数越小优先级越大.
  set<LL> s;
  pq.push(1);
  s.insert(1); //首先仍如第一个丑数 1.
  for(int i = 1; ; i++) {
    LL x = pq.top(); pq.pop();  //然后每一次,我们读取最小的数出来, 用pop即可.然后
    if(i == 1500) {
      cout << "The 1500'th ugly number is " << x << ".\n";
      break;
    }
    for(int j = 0; j < 3; j++) {//放入3个
      LL x2 = x * coeff[j];
      if(!s.count(x2)) { s.insert(x2); pq.push(x2); }//如果s中不存在,才进行push.
    }



  }
  return 0;
}
