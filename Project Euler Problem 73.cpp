//Project Euler Problem 53.cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define pp pair<int,int>
#define ppl pair<long long int,long long int>
#define vec vector<int> 
#define finput ifstream cin;cin.open("input.txt")
#define foutput ofstream cout;cout.open("output.txt") 

int main(){
		//Farey sequence properties
		int n=12000,a=1,b=3,c=4000,d=11999,ans=0,x,y;
		while ( c != 1 && d != 2 ) {
		    ans++;
		    x = ((n+b)/d)*c - a;
		    y = ((n+b)/d)*d - b;
		    a=c;b=d;
		    c=x;d=y;
		}
		cout<<ans;
}
