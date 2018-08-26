#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define vec vector<int> 
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt")  

bool f(int x1,int y1,int x2,int y2,int x3,int y3){
	ll int c1 =y3*(x2-x1)+x3*(y1-y2)+x1*y2 - y1*x2;
	ll int c2 =x1*y2 - y1*x2;
	if(c1*c2>0) return 1;
	return 0;
}
int main(){
	finput;foutput;
	int x1,x2,x3,y1,y2,y3,t=1000,count=0;
	int i=1;
	while(t--){
		cin>>x1;cin.ignore();
		cin>>y1;cin.ignore();
		cin>>x2;cin.ignore();
		cin>>y2;cin.ignore();
		cin>>x3;cin.ignore();
		cin>>y3;
		if( f(x1,y1,x2,y2,x3,y3) && 
			f(x2,y2,x3,y3,x1,y1) && 
			f(x1,y1,x3,y3,x2,y2) ){ 
			count++;
		}
		i++;
	}
	cout<<count;		
}
