# include <cstdio>
# include <iostream>
# include <string>
# include <cstring>
# include <algorithm>
# include <istream>
# include <vector>
using namespace std;
# define MAX 11234
int b[MAX];
int vis[MAX];
int n,m;
vector<int>mat[MAX];
int dfs ( int i, int c ) 
{
	if ( vis[i] ) {
		return b[i]==c;
	}
	else {
		vis[i] = 1;
		b[i] = c;
		for ( int k = 0;k < mat[i].size();k++ ) {
			if ( !dfs(mat[i][k],!c) ) {
				return 0;
			}
		}
		return 1;
	}
} 
int main(void)
{
	int t; scanf("%d",&t);
	while ( t-- ) {
		scanf("%d%d",&n,&m);
		for ( int i = 0;i < n;i++ ) {
			mat[i].clear();
		}
		while ( m-- ) {
			int u,v; scanf("%d%d",&u,&v);
			u--;
			v--;
			mat[u].push_back(v);
			mat[v].push_back(u);
		}
		memset(vis,0,sizeof(vis));
		int flag = 1;
		for ( int i = 0;i < n;i++ ) {
			if ( !vis[i] ) {
				flag&=dfs(i,0);
			}
		}
		if ( flag ) {
			puts("Correct");
		}
		else {
			puts("Wrong");
		}
	}
	return 0;
}
