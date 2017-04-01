# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;
# define MAX 1234
double a[MAX];
void init()
{
	double temp = 0.5;
	for ( int i = 0;i < 1024;i++ ) {
		a[i] = 0.5-temp;
		temp *= 0.5;
	} 
}
int main(void)
{
	init();
	//for ( int i = 0;i < 10;i++ ) cout<<a[i]<<endl; 
	int t; scanf("%d",&t);
	while ( t-- ) {
		double k; scanf("%lf",&k);
		int pos = lower_bound(a,a+505,k)-a;
		if ( a[pos]==k ) {
			puts("-1");
		}
		else {
			printf("%d\n",pos*4);
		}
	}
	return 0;
}
