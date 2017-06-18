mod=10000000000
def modexp(x,b):
    res=1
    while b>0:
        if b%2==1:
            res=(res*x) % mod
        x=(x*x)%mod
        b=b//2
    return res

ans=0
for i in range(1,1001):
    ans=ans+modexp(i,i)
    ans=ans%mod
print(ans)
