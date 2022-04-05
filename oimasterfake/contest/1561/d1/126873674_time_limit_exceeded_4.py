s=input().split()
d=[0 for i in range(200010)]
n=int(s[0])
p=int(s[1])
def lowbit(x):
	return x&(-x)
def add2(i,k):
	if i>n:
		return
	d[i]+=k
	add2(i+lowbit(i),k)
def add(i,j,k):
	add2(i,k)
	add2(j+1,-k)
def query(i):
	if i<=0:
		return 0
	return d[i]+query(i-lowbit(i))
add(n,n,1)
i=n
while i>=2:
	qq=query(i);
	add(1,i-1,qq)
	j=i
	while(j>=2):
		tmp=i//j
		add(tmp,tmp,qq)
		j-=1
	i-=1
print(query(1)%p)