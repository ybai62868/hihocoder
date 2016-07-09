# include <cstdio>
# include <iostream>
# include <vector>
# include <algorithm>
# include <cmath>
# include <cstring>
# include <list>
# include <set>
using namespace std;
# define MAX 5555
# define inf 99999999
struct point{
	int x,y;
	bool operator < ( const point & p2) const{
		if ( x<p2.x||(x==p2.x&&y<p2.y) ) return true;
		return false;
	}
	bool operator == ( const point & p2 ) const{
		return (x==p2.x&&y==p2.y);
	}
};
struct line{
	point p1, p2;
};
int judgePoint( line * l ){
	set<point>s;
	for ( int i = 0;i < 4;i++ ){
		s.insert(l[i].p1);
		s.insert(l[i].p2);
	}
	if( s.size() == 4 ) return true;
	else return false;
}
int judgeRect( line * l ){
	for(int i=1; i<4; ++i){    
        if((l[0].p1.y-l[0].p2.y)*(l[i].p1.y-l[i].p2.y)==-(l[0].p1.x-l[0].p2.x)*(l[i].p1.x-l[i].p2.x)) continue;     
        if((l[0].p1.y-l[0].p2.y)*(l[i].p1.x-l[i].p2.x)==(l[0].p1.x-l[0].p2.x)*(l[i].p1.y-l[i].p2.y)) continue;    
        return false;    
    }    
    return true;    
}
int main(void)
{
	int t; cin>>t;
	line l[4];
	while ( t-- ){
		for ( int i = 0;i < 4;i++ ){
			cin>>l[i].p1.x>>l[i].p1.y>>l[i].p2.x>>l[i].p2.y;
		}
		int flag = 0;
		if ( judgePoint(l)&&judgeRect(l) ) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}


	return 0;
}
