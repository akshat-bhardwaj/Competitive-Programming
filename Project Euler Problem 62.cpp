#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt") 
map <string, pair <int,int> > mm;
string convert(int n){
	int a[100];
	int siz,i=0;
	ll int k = n;
	k=k*k*k;
	//cout<<k<<" ";
	while(k>0){
		a[i]=k%10;
		k/=10;
		i++;
	}
	siz=i;
	sort(a,a+siz);
	char ans[siz];
	for(int j=0;j<siz;j++){
		ans[j] = a[j]-'0';
	}
	return ans;
}
int main(){
	int i = 1;
	foutput;
	string temp;
	while(i++){
		temp = convert(i);
		if( mm[temp].first == 0 ){
			mm[temp].first = i;
			mm[temp].second++;
		}
		else{
			mm[temp].second++;
			if(mm[temp].second == 5){
				cout<<(ll)mm[temp].first*(ll)mm[temp].first*(ll)mm[temp].first;
				return 0;
			}
		}
	}
}
