#f = open("out.txt", "w")
def sum(n):
   r = 0
   while n:
       r, n = r + n % 10, n // 10
   return r

a=[2,1,2,1,1,4]
for i in range(94):
	if i%3 == 0 or i%3 == 1:
		a.append(1)
	else:
		a.append(6+2*(i/3))
den=a[99]
nem=1
#print(a)
for i in range(100):
	j=100-i-1
	nem=a[j-1]*den+nem
	den,nem = nem,den
#print(nem)
print(sum(nem))

