// UVa156 Ananagrams
// Rujia Liu
// 题意：输入一些单词，找出所有满足如下条件的单词：该单词不能通过字母重排得到输入文本中的另外一个单词
// 算法：把每个单词“标准化”，即全部转化为小写字母然后排序，然后放到map中进行统计
#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

map<string,int> cnt;
vector<string> words;

// 将单词s进行“标准化”
string repr(string s) {
  string ans = s;
  for(int i = 0; i < ans.length(); i++)
    ans[i] = tolower(ans[i]);
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  int n = 0;
  string s;
  while(cin >> s) {
    if(s[0] == '#') break; //每输入一个字符串就存起来,到s
    words.push_back(s);  //存入words数组中.
    string r = repr(s);
    if(!cnt.count(r)) cnt[r] = 0; // 如果cnt中找这个字符串没有的话.count=0的话,那么我们
    // 就写入map 中.
    cnt[r]++;  //再+1
  }
  vector<string> ans;// 创建答案,
  for(int i = 0; i < words.size(); i++)
    if(cnt[repr(words[i])] == 1) ans.push_back(words[i]); //如果只有一个,就记录下来.
  sort(ans.begin(), ans.end()); //排序
    for(int i = 0; i < ans.size(); i++) //打印即可.
    cout << ans[i] << "\n";
  return 0;
}
