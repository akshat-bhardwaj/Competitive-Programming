from decimal import * 
import math
def func(a):
	getcontext().prec = 102
	root = (Decimal(a).sqrt())
	sumdigits=0
	if (root == math.floor(root)): 
		return 0
	sumdigits += sum(int(x) for x in str(root)[0:101] if x.isdigit())
	return sumdigits

ans = 0
for i in range(101):
	ans+=func(i)
print(ans)
