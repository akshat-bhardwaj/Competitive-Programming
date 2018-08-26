#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define vec vector<int> 
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt")  

multiset<int> a,b,temp;
int x,tot4[100]={0},tot6[100]={0};
void fill6(int x){
	temp.clear();
	if(x==0){
		a.insert(1);a.insert(2);a.insert(3);a.insert(4);a.insert(5);a.insert(6);
	}
	x++;
	for(multiset<int>::iterator it=a.begin();it!=a.end();it++){
		for(int i=1;i<=6;i++){
			temp.insert(*(it)+i);
		}
	}
	a.clear();
	for(multiset<int>::iterator it=temp.begin();it!=temp.end();it++){
		a.insert(*(it));
	}
	if(x==5) return;
	fill6(x);
}

void fill4(int x){
	temp.clear();
	if(x==0){
		b.insert(1);b.insert(2);b.insert(3);b.insert(4);
	}
	x++;
	for(multiset<int>::iterator it=b.begin();it!=b.end();it++){
		for(int i=1;i<=4;i++){
			temp.insert(*(it)+i);
			//cout<<(*it+i)<<" "; 
		}
	}
	b.clear();
	for(multiset<int>::iterator it=temp.begin();it!=temp.end();it++){
		b.insert(*(it));
	}
	if(x==8) return;
	fill4(x);
}

int main(){
	//foutput;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill6(0);
	fill4(0);
	for(multiset<int>::iterator it=a.begin();it!=a.end();it++){
		tot6[*(it)]++;
	}
	for(multiset<int>::iterator it=b.begin();it!=b.end();it++){
		tot4[*(it)]++;
	}
	double ans = 0;
	ll int total=0,val=0;
	total = 4LL*4LL*4LL*4LL*4LL*4LL*4LL*4LL*4LL*6LL*6LL*6LL*6LL*6LL*6LL;
	for(int i=10;i<=40;i++){
		val = 0;
		for(int j=6;j<i;j++){
			val+=tot4[i]*tot6[j];
		}
		ans+=(double)val/(double)total;
	}
	cout<<setprecision(7)<<ans<<endl;
}
