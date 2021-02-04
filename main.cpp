// UVa11988 Broken Keyboard
// Rujia Liu
#include<cstdio>
#include<cstring>
const int maxn = 100000 + 5;
int last, cur, next[maxn]; // 光标位于cur号字符之后面//  next数组来实现的链表.// 实际上是用next数组来 存光标跳转.
char s[maxn];

int main() {
    while(scanf("%s", s+1) == 1) {//存入数组中. 地址便宜一个.// 读入一个数据就存下来, 一个数据不超过100000+5个字符.
        // 表示每次处理一个字符串, 空格作为结束符.   \000  在Windows系统中，正斜杠/表示除法， 除法是正统的运算, 用正斜杠表示--------用来进行整除运算；反斜杠\用来表示目录 反斜杠,反过来,所以是左撇子从左开始写.

        int n = strlen(s+1); // 输入保存在s[1], s[2]...中
        last = cur = 0;
        next[0] = 0;

        for(int i = 1; i <= n; i++) {
            char ch = s[i];
            if(ch == '[') cur = 0;  //cur表示走完当前字符后, 光标所在的位置.
            else if(ch == ']') cur = last; // cur表示下个节点插入的位置.
            else {
                next[i] = next[cur];  //遇到其他字符就正常跳转.----------这段逻辑等价于链表中的添加节点的操作. 这一行等价于 在 i-1节点和 i节点之间加入current. 也就是把i节点加入 i-1和current之间!!!!!!!!!!!!!!!!.    所以这个步奏是 把i的next指针指向cur
                next[cur] = i;            // 表示current结点跳跃后的索引是i.
                if(cur == last) last = i; // 更新“最后一个字符”编号,  用于更新上吗的else if 判断.
                cur = i; // 移动光标   //current走到i结点. 做下次链接.
            }
        }


        for(int i = next[0]; i != 0; i = next[i])// next找到下一个索引 ,  0是头结点.
            printf("%c", s[i]);

        printf("\n");
    }
    return 0;
}
