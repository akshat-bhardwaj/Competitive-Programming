#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define pp pair<int,int>
#define ppl pair<long long int,long long int>
//#define vec vector<int> 
/**
int bins2(int a[],int lo,int hi){
	//finds the first true
	// F F F F "T" T T T T
	int mid;
	while(lo < hi){
		mid = lo + (hi-lo)/2;
		if(a[mid]==TRUE)
	 		hi = mid;
		else
	        lo = mid+1;
    }
    if(a[lo]==FALSE){
    	return -1;
    	//All are false
    }
    return lo;
}
ll int mod(ll int a){
	if(a<0) return -a;
	return a;
}
int prime[1000001]={0},vector <int> p;
void sieve(){
	for(int i=2;i*i<=1000000;i++){
		if(prime[i]==0){
			for(int j=2*i;j<=1000000;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(prime[i]==0){
			p.push_back(i);
		}
	}
}
*/
vector<int> p;
int main(){
	int prime[1000001]={0};
	for(int i=2;i*i<=1000000;i++){
		if(prime[i]==0){
			for(int j=2*i;j<=1000000;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(prime[i]==0){
			p.push_back(i);
		}
	}
	vector <int> vec[1000001];
	for(int i=0;i<p.size();i++){
		for(int j=p[i];j<=1000000;j+=p[i]){
			int count=0,temp=j;
			while(temp%p[i]==0){
				temp/=p[i];
				count++;
			}
			if(count)
				vec[j].push_back(count);
		}
	}
	for(int i=600;i<=999998;i++){
		if(vec[i].size()==4 && vec[i+1].size()==4 && vec[i+2].size()==4 && vec[i+3].size()==4){
			cout<<i<<endl;
			break;
		}
	}
}
