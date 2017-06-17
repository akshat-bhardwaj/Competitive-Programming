#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define pp pair<int,int>
#define ppl pair<long long int,long long int>
#define vec vector<int> 
/**
int bins(int a[],int lo,int hi){
	//finds the last false
	// F F F "F" T T T T T
	int mid;
	while(lo < hi){
		mid = lo + (hi-lo+1)/2;
		if(a[mid]==TRUE)
	 		hi = mid-1;
		else
	        lo = mid;
    }
    if(a[lo]==TRUE){
    	return -1;
    	//All are true
    }
    return lo;
}
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
bool check(ll int a,ll int b){
	ll int v1=1+24*(a+b),v2=1+24*(b-a);
	ll int s1=(int)sqrt(v1),s2=(int)sqrt(v2);
	if(s1*s1==v1 && (s1+1)%6==0 && s2*s2==v2 && (s2+1)%6==0) return 1;
	return 0;
}
int main(){
	ll int a[10001];
	for(int i=1;i<=10000;i++){
		a[i]=(i*(3*i-1))/2;
	}
	for(int i=1;i<=10000;i++){
		for(int j=i+1;j<=10000;j++){
			if(check(a[i],a[j])){
				cout<<a[j]-a[i]<<endl;
			}
		}
	}
}
