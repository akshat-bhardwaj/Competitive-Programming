#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll toint(string s){
	ll mul = 1,ans=0;
	int l = s.length();
	for(int i=0;i<l;i++){
		ans += mul * (ll)(s[l-i-1]-'0');
		mul *= 10;
	}
	return ans;
}
int main() {
	ll x[10] = {1,2,3,4,5,6,7,8,9,10};
	int N = 10*9*8*7*6*5*4*3*2*1;
	ll chk;
	string ans="";
	string tmp;
	for(int i=1;i<=N;i++){
		if(x[4]==10 || x[5]==10 || x[6]==10 || x[7]==10 || x[8]==10) {
			next_permutation(x,x+10);
			continue;
		}
		if(x[9]>x[0] || x[9]>x[1] || x[9]>x[2] || x[9]>x[3]) {
			next_permutation(x,x+10);
			continue;
		}
		chk = x[9] + x[4] + x[5];
		if(chk == x[0]+x[5]+x[6] && chk == x[1]+x[6]+x[7] && chk == x[2]+x[7]+x[8] && chk==x[3]+x[8]+x[4] ){
			tmp = to_string(x[9])+to_string(x[4])+to_string(x[5])+to_string(x[0])+to_string(x[5])+to_string(x[6])+to_string(x[1])+to_string(x[6])+to_string(x[7])+to_string(x[2])+to_string(x[7])+
			to_string(x[8])+to_string(x[3])+to_string(x[8])+to_string(x[4]);
			if(ans.compare(tmp)<0) ans = tmp;
		}
		next_permutation(x,x+10);
	}
	cout<<ans<<endl;
	return 0;
}
