# include <cstdio>
# include <iostream>
# include <string>
# include <cstring>
# include <map>
# include <vector>
using namespace std;
map<string,string>father;
map<string,int>book;
void work( string a,string b )
{
	string x;
	book.clear();
	x = a;
	while (!x.empty()) {
		book[x] = 1;
		x = father[x];
	}
	x = b;
	while ( !x.empty()&&!book[x] ) {
		// book[b] = 1;
		x = father[x];
	}
	if ( !x.empty() ) {
		cout<<x<<endl;
	}
	else{
		printf("-1\n");
	}
}
int main(void)
{
	father.clear();
	int n; scanf("%d",&n);
	while ( n-- ) {
		string a,b; cin>>a>>b;
		father[b] = a;
	}
	int m; scanf("%d",&m);
	while ( m-- ) {
		string a,b; cin>>a>>b;
		work(a,b);
	}
	
	return 0;
}
