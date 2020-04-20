#include<bits/stdc++.h> 
using namespace std; 
int value(char r){ 
    if (r == 'I') 
        return 1; 
    if (r == 'V') 
        return 5; 
    if (r == 'X') 
        return 10; 
    if (r == 'L') 
        return 50; 
    if (r == 'C') 
        return 100; 
    if (r == 'D') 
        return 500; 
    if (r == 'M') 
        return 1000; 
    return -1; 
} 

int romanToDecimal(string str){ 
    int res = 0;
    for (int i=0; i<str.length(); i++){
        int s1 = value(str[i]); 
        if (i+1 < str.length()){ 
            int s2 = value(str[i+1]); 
            if (s1 >= s2){ 
                res = res + s1; 
            } 
            else{ 
                res = res + s2 - s1; 
                i++;
            } 
        } 
        else{ 
            res = res + s1; 
        } 
    } 
    return res; 
}
int get_sum(int number){ 
	int sum = 0;
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int i=12;     
    while(number>0){ 
      int div = number/num[i]; 
      number = number%num[i]; 
      while(div--){ 
        sum += sym[i].length(); 
      } 
      i--; 
    }
    return sum;
} 
  
int main(){
    int ans = 0, ans2 = 0;;
    string s;
    for(int i=1;i<=1000;i++){
    	cin>>s;
    	ans2 += s.length();
    	ans+= get_sum(romanToDecimal(s));
    }
    cout<<ans2 - ans<<endl;
    return 0; 
}
