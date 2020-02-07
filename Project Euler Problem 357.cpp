#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

#define ll long long
#define N 100000000

using namespace std;
vector<ll int> p;
ll int prime[N+1]={0};

void primes(){
    for(ll int i=2;i*i<=N;i++){
        if(prime[i]==0){
            for(ll int j=2*i;j<=N;j+=i){
                prime[j]=1;
            }
        }
    }
    for(ll int i=2;i<=N;i++){
        if(prime[i]==0){
            p.push_back(i);
        }
    }
}

bool checkIfPrimeGenerating(ll potential){
    for(ll iter = 2; iter*iter <= potential; iter++){
        if(potential%iter!=0) continue;
        if(prime[potential/iter + iter] == 1) {
            return 0;
        }
    }
    return 1;
}
int main() {
    primes();
    long long int ans=0;
    ll int n = p.size();
    for(ll i=0;i<n;i++){
        if((p[i]-1)%4==0) continue;
        ll potential = p[i]-1;
        if(checkIfPrimeGenerating(potential)) {
            ans += potential;
        }
    }
    cout<<ans<<endl;
}
