# include <cstdio>
# include <iostream>
using namespace std;
# define MAX 1234
int a[MAX];
int main(void)
{
	int n; scanf("%d",&n);
	for ( int i = 0;i < n;i++ ) {
		scanf("%d",&a[i]);
	}
	int pos = 0;
	for ( int i = n-2;i >= 0 ;i-- ) {
		if ( a[i] >= a[i+1] ) {
			pos = i;
			break;
		}
	}
	//cout<<pos<<endl;
	for ( int i = 0;i <= pos;i++ ) {
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}
