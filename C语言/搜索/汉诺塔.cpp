// 汉诺塔问题输入： n m
// 输出第一行 #No：a->c （No为第m步是第几个盘子） 
// 输出第二行 总步数 
#include <iostream>
using namespace std;
int cnt=0;
int m;

void hanoid(char a,char b, char c, int n)
{
  if(n==1){
  		cnt ++;
		if(cnt==m)cout <<"#"<<n<<": "<< a << "->" << c << endl;
		}
  else{
    hanoid(a,c,b,n-1);
    cnt++;
	if(cnt==m)cout <<"#"<<n<<": "<< a << "->" << c << endl;
    hanoid(b,a,c,n-1);
  }
}

int main()
{
  int n;
  cin >> n >> m;
  hanoid('A','B','C',n);
  cout << cnt;
  return 0;
}

