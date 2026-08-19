#include <iostream>
#include <string>
#include <stack>
//题目：处理含有+和*的运算式
//例如：1+1*3+4 对应的输出为 8 
using namespace std;
int main()
{
  string s;
  stack<long long> st;
  cin >> s;
  s += '+';
  int n = s.size();
  char lastop='+';
  long long num=0;
  // 处理逻辑是对于任何一个 num ,如果它的左侧符号是
  // '+'号则直接入栈
  // '*'号则弹栈与当前数字相乘然后再入栈
  for (int i=0;i<n;i++){
    if ('0'<=s[i] && s[i]<='9'){
      num = num*10+(s[i]-'0');
    }
    else {
      if (lastop=='+')st.push(num);
      else {
        num *= st.top();
        st.pop();
        st.push(num);
      }
      num = 0;
      lastop = s[i]; 
    }
  }
  long long ans=0;
  while (!st.empty()){
    ans+=st.top();
    st.pop();
  }
  cout << ans%10000;
}
