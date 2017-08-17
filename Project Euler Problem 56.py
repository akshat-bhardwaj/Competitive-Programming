# your code goes here
ma=0
for i in range(101):
	for j in range(101):
		if ma<sum(map(int, list(str(i**j)))):
			ma=sum(map(int, list(str(i**j))))
print(ma)
