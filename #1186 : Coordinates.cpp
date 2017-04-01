#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<map>
using namespace std;

int a[10005],b[10005];
int main()
{
    int p,q;
    while(~scanf("%d%d",&p,&q))
    {
        int sum1=0,sum2=0;
        for(int i=1;i*i<p;i++)
        {
            if(p%i==0)
            {
                a[sum1++]=i;
                a[sum1++]=p/i;
            }
        }
        if((int)sqrt(p)*(int)sqrt(p)==p)
        {
            a[sum1++]=(int)sqrt(p);
        }
        for(int i=1;i*i<q;i++)
        {
            if(q%i==0)
            {
                b[sum2++]=i;
                b[sum2++]=q/i;
            }
        }
        if((int)sqrt(q)*(int)sqrt(q)==q)
        {
            b[sum2++]=(int)sqrt(q);
        }
        sort(a,a+sum1);
        sort(b,b+sum2);
        a[sum1]=0;
        b[sum2]=0;
        for(int i=0;i<sum1;i++)
        {
            if(a[i]!=a[i+1])
            {
                for(int j=0;j<sum2;j++)
                {
                    if(b[j]!=b[j+1])
                    {
                        printf("%d %d\n",a[i],b[j]);
                    }
                }
            }
        }
    }
    return 0;
}
