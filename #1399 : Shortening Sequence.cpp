# include <cstdio>
# include <iostream>
# include <algorithm>
# include <cmath>
using namespace std;
# define MAX 1123456
int a[MAX];
int main(void)
{
	int n; scanf("%d",&n);
	for ( int i = 0;i < n;i++ ) {
		scanf("%d",&a[i]);
	}
	int res1 = 0, res2 = 0;
	for ( int i = 0;i < n;i++ ) {
		if ( a[i]&1 ) res1++;
		else res2++;
	}
	printf("%d\n",abs(res1-res2));


	return 0;
}
