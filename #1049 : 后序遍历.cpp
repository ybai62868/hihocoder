# include <cstdio>
# include <iostream>
# include <string>
using namespace std;
string getPost( string pre, string in ) 
{
	int len =  pre.size();
	if ( len <= 1 ) return pre;
	int i = in.find(pre[0]);
	string res = getPost(pre.substr(1,i),in.substr(0,i));
	res += getPost(pre.substr(i+1,len-1-i),in.substr(i+1,len-1-i));
	res += pre[0];
	return res;
}
int main(void)
{
	string str1, str2;
	cin>>str1>>str2;
	cout<<getPost(str1,str2)<<endl;
	return 0;
}
