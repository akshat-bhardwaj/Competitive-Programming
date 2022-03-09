#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
#define N 1001
int p[1001]={0};
vector<int> primes;
//sieve
void sieve(){
	p[2]=0;
	p[1]=0;
	for(int i=2;i<=N;i++){
		if(p[i]==1)
			continue;
		primes.pb(i);
		for(int j=i*2;j<=N;j+=i){
			p[j]=1;
		}
	}
}
int main() {
	// ifstream cin; 
 	// cin.open("input.txt");  
	sieve();
	int M = primes.size();
	int dp[N][M];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			dp[i][j]=0;
		}
	}
	dp[2][0]=1;

	for(int i=3;i<=100;i++){
		for(int j=0;j<M;j++){
			if(i<primes[j]) continue;
			if(i==primes[j]){
				dp[i][j]=1;
			}
			for(int k=j;k<M;k++){
				dp[i][j]+=dp[i-primes[j]][k];
			}
		}
		int temp=0;
		for(int j=0;j<M;j++){
			temp+=dp[i][j];
		}
		if(temp>5000)
			cout<<i<<" "<<temp<<endl;
	}
}
