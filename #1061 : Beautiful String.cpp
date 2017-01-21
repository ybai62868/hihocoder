# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cstring>
using namespace std;
char str[1<<24];
char c[1<<24];
int n[1<<24];
int main(void)
{
	int t; scanf("%d",&t);
	while ( t-- ) {
		int cnt = 0;
		int k; scanf("%d%*c",&k);
		gets(str);
		char pre = 0;
		for ( int i = 0;i < k;i++ ) {
			if ( str[i]!=pre ) {
				c[++cnt] = str[i];
				n[cnt] = 1;
				pre = str[i];
			}
			else {
				n[cnt]++;
			}
		}
		int flag = 0;
		for ( int i = 1;i <= cnt-2;i++ ) {
			if ( c[i]==c[i+1]-1&&c[i+1]==c[i+2]-1 ) {
				if ( n[i+1] <= n[i]&&n[i+1]<=n[i+2] )  {
					flag = 1;
					break;
				}
			}
		}
		if ( flag ) {
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
	return 0;
}
