def check(a,b):
	n1=0;
	while(a>0):
		a=a//10
		n1=n1+1
	n2=0;
	while(b>0):
		b=b//10
		n2=n2+1
	if n1>n2 :
		return 1
	return 0


n=3
d=2
ans=0
for i in range(2,1001):
	d=n+d;
	n=(d-n)*2+n
	if(check(n,d)):
		ans=ans+1
print(ans)
