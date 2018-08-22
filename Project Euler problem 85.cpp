#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define pp pair<int,int>
#define ppl pair<long long int,long long int>
#define vec vector<int> 
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt") 

int main(){
   // finput;foutput;
    ll int ans,ab=1000000,j;
    for(ll int i=1;i*i<=8000000;i++){
    	j=(ll int)(sqrt(8000000/(i*(i+1))));
    	if( abs( j*(j+1)*i*(i+1) - 8000000) < ab ){
    		ab = abs( j*(j+1)*i*(i+1) - 8000000);
    		ans = i*j;
    	}
    	j++;
    	if( abs( j*(j+1)*i*(i+1) - 8000000) < ab ){
    		ab = abs( j*(j+1)*i*(i+1) - 8000000);
    		ans = i*j;
    	}
    }
    cout<<ans<<endl;
}
