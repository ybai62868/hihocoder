# include <iostream>
# include <string>
# include <vector>
# include <string>
# include <cstring>
using namespace std;
# define MAX 112345
struct node 
{
	int to;
	int next;
}edge[MAX<<1];
int head[MAX];
int book[MAX];
int dis[MAX];
int cnt;
void addedge(int u,int v)
{
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
	cnt++;
}
void dfs( int u,int d ) 
{
	book[u] = 1;
	dis[u] = d;
	for ( int i = head[u];i;i = edge[i].next ) {
		int v = edge[i].to;
		if ( !book[v] ) {
			dfs(v,d+1);
		}
	} 
}
int main(void)
{
	int n, a, b; cin>>n;
	cnt = 1;
	for ( int i = 1;i < n;i++ ) {
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	}
	dfs(1,0);
	int ans = 0;
	int pos = -1;
	for ( int i = 1;i <= n;i++ ) {
		if ( ans < dis[i] ) {
			pos = i;
			ans = dis[i];
		}
	} 
 	memset(book,0,sizeof(book));
 	dfs(pos,0);
 	for ( int i = 1;i <= n;i++ ) {
 		ans = max(ans,dis[i]);
 	}
 	cout<<ans<<endl;
	return 0;
}
