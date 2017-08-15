#include <bits/stdc++.h>
using namespace std;
bool check(int a,int b){
    int a1[10]={0},a2[10]={0};
    while(a>0){
        a1[a%10]++;
        a/=10;
    }
    while(b>0){
        a2[b%10]++;
        b/=10;
    }
    for(int i=0;i<10;i++){
        if(a1[i]!=a2[i]) return 0;
    }
    return 1;
}
bool f(int i){
    if(check(i,2*i) && check(i,3*i) && check(i,4*i) && check(i,5*i) && check(i,6*i)) return 1;
    return 0;
}
int main(){
    for(int i=101;i<=1000000;i++){
        if(f(i)){
            cout<<i<<endl;
        }
    }
}
