//马拉车算法 O(n)

# include <cstdio>
# include <iostream>
# include <string>
# include <cmath>
using namespace std;
# define MAX 1234567
int p[2*MAX];
int main(void)
{
    int tt; cin>>tt;
    while ( tt-- ){
    string str; cin>>str;
    int n = str.size();
    string str2;
    str2 += "$#";
    for ( int i = 0;i < n;i++ ){
        str2+=str[i];
        str2+='#';
    }
    int mx = 0, id = 0;
    n = str2.size();
    for ( int i = 1;i <= n;i++ ){
        if ( mx > i ){
            p[i] = min(p[2*id-i],mx-i);
        }
        else{
            p[i] = 1;
        }
        while ( str2[i+p[i]]==str2[i-p[i]] ) p[i]++;
        if ( p[i]+i > mx ){
            mx = p[i]+i;
            id = i;
        }
    }
    int res = -1;
    for ( int i = 1;i < n;i++ ) res = max(res,p[i]);
    res--;
    cout<<res<<endl;
    }
    return 0;
}
