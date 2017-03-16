# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 123
int a[MAX],b[MAX];
int main(void)
{
	int t; scanf("%d",&t);
	while ( t-- ) {
		int n; scanf("%d",&n);
		for ( int i = 0;i < n;i++ ) {
			int temp2; 
			double temp1;
			scanf("%lf%d",&temp1,&temp2);
			a[i] = temp1*10;
			b[i] = temp2;
		}
		int res = -1;
		for ( int i = 0;i < n;i++ ) {
			if ( a[i]%50==0 ) {
				res = max(res,b[i]);
			}
		}
		for ( int i = 0;i < n;i++ ) {
			for ( int j = i+1;j < n;j++ ) {
				if ( (a[i]+a[j])%50==0 ) {
					res = max(res,b[i]+b[j]);
				}
			}
		}
		for ( int i = 0;i < n;i++ ) {
			for ( int j = i+1;j < n;j++ ) {
				for ( int k = j+1;k < n;k++ ) {
					if ((a[i]+a[j]+a[k])%50==0) {
						res = max(res,b[i]+b[j]+b[k]);
					}
				}
			}
		}

		printf("%d\n",res);
	}

	return 0;
}
