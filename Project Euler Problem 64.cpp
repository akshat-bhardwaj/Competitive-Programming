#include <bits/stdc++.h>
using namespace std;
//https://imgur.com/a/SFfwvlv 
int main() {
	int a0,m0,d0,a,m,d;
	int ans=0,cnt,sq,lim;
	for(int i=1;i<=10000;i++){
		lim = sqrt(i);
		sq = (int)lim;
		if(sq*sq == i) continue;
		cnt=0;
		a0 = sq;
		d0 = 1;
		m0 = -1*sq;
		m = m0;
		d = d0;
		a = a0;
		//cout<<a<<" "<<d<<" "<<m<<endl;
		cnt++;
		while(true){
			d = (i - m*m) / d;
			a = (int) ( (lim - (double)m) / (double)d );
			m = -1*( m + d * a );
			//cout<<a<<" "<<d<<" "<<m<<endl;
			if(2*a0 == a) break;
			cnt++;
		}
		//cout<<cnt<<endl;
		if(cnt%2==1) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
