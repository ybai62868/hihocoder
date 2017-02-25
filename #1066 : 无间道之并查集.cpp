# include <cstdio>
# include <iostream>
# include <string>
# include <map>
using namespace std;
# define MAX 112345
int father[MAX];
map<string,int>MAP;
void init()
{
	for ( int i = 1;i < MAX;i++ ) father[i] = i;
}
int getf( int x ) 
{
	if ( x==father[x] ) return x;
	else {
		father[x] = getf(father[x]);
		return father[x];
	}
}
void merge(int x,int y)
{
	int t1 = getf(x);
	int t2 = getf(y);
	if ( t1!=t2 ) {
		father[t2] = t1;
	}
}
int main(void)
{
	int n; scanf("%d",&n);
	init();
	int cnt = 1;
	for ( int i = 0;i < n;i++ ) {
		int index; scanf("%d",&index);
		string str1,str2; cin>>str1>>str2;
		if ( MAP[str1]==0 ) MAP[str1] = cnt++;
		if ( MAP[str2]==0 ) MAP[str2] = cnt++;
		if ( index==0 ) {
			merge(MAP[str1],MAP[str2]);
		}
		else{
			if ( getf(MAP[str1])==getf(MAP[str2]) ) {
				puts("yes");
			} 
			else puts("no");
		}
	}


	return 0;
}
