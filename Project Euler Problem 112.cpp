#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define vec vector<int> 
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt")  
bool f(int i){
	int k = i%10,flag = 0,j=i;
	i/=10;
	while(i>0){
		if(i%10 > k){
			flag++;
			break;
		}
		k=i%10;
		i/=10;
	}
	i=j;
	k = i%10;
	i/=10;
	while(i>0){
		if(i%10 < k){
			flag++;
			break;
		}
		k=i%10;
		i/=10;
	}
	if(flag>1)return 0;
	return 1;
}
int main(){
	clock_t cc;
	cc=clock();
	foutput;
	int i=1,b=0,t=0;
	while(true){
		if(!f(i))b++;
		t++;
		//cout<<b<<" "<<t<<endl;
		if(100*b >= 99*t){
			cout<<t<<endl;
			break;
		}
		i++;
	}
	cc=clock()-cc;
	cout<<float(cc)/CLOCKS_PER_SEC<<endl;
	return 0;
}
