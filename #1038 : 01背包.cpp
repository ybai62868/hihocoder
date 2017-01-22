# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 123456
int need[MAX],value[MAX];
int dp[MAX];
int main(void)
{
	int n,m; scanf("%d%d",&n,&m);
	for ( int i = 0;i < n;i++ ) {
		scanf("%d%d",&need[i],&value[i]);
	}
	for ( int i = 0;i < n;i++ ) {
		for ( int j = m;j >= need[i];j-- ) {
			dp[j] = max(dp[j],dp[j-need[i]]+value[i]);
		}
	}
 	printf("%d\n",dp[m]);
	return 0;
}
