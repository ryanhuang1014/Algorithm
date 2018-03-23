'''
可以通过在函数内部使用global关键字的方式
在函数内部改变外部全局变量的数值
否则就算与外部变量同名，也无法改变外部变量数值
'''
outside = 1
# def changeGlobal():
	# global outside
	# outside = 100
# print(outside)

'''
递归关键在于不改变内部处理逻辑的前提下，不断缩小处理的规模
缩小的规模主要通过函数后面传入的参数体现

递归有两个要点：1、必须要一个base case，便于在问题达到最小规模时候返回。
2、通过函数后面不断变小的传入规模，来实现递归
'''


def isPlalinDrome(strr):
	'''
判断是否是回文，其实就是先比较一个字符串的头尾是否相同，
然后不断缩减字符串的长度，再比较头尾是否相同，直到字符串长度变为1
	'''
	if len(strr)==1:    #tip1: 基本情况  base case
		return True
	elif len(strr)==2:
		if strr[0]==strr[1]:
			return True
		else:
			return False
	else:
		if strr[0]==strr[-1]:
			return isPlalinDrome(strr[1:-1])  #tip2: 缩减规模
		else:
			return False
# print(isPlalinDrome('abcdcba2'))

def Fibonacci(n):
	if n==1 or n==2:
		return 1
	else:
		return Fibonacci(n-1)+Fibonacci(n-2)

# print(Fibonacci(7))

def squareRootBi(num,left,right):
	episilon=0.01   #求平方根的误差值
	expect = (left+right)/2
	if abs(expect**2-num)<episilon:
		return expect
	elif expect**2<num:
		return squareRootBi(num,expect,right)
	else:
		return squareRootBi(num,left,expect)

# print(squareRootBi(9,0,9))

def squareRootBiLoop(num):
	assert isinstance(num,int),'the number is not a integer'
	left=0
	right=num
	expect = (left+right)/2
	episilon=0.1
	while abs(expect**2-num)>episilon: #和上面求平方根的方法一样，一定用abs()，不然出错
		if expect**2<num:
			left=expect
		else:
			right=expect
		expect=(left+right)/2
	return expect
# print(squareRootBiLoop(9))

def squareRootNR(n,guess):  #Newton and Rapson method
	epsilon=0.01
	if abs(guess**2-n)<epsilon:
		return guess
	else:
		y=guess**2-n
		guess=-y/(2*guess)+guess
		return squareRootNR(n,guess)
# print(squareRootNR(4,3))

def Hanoi(n,fromStack,spareStack,toStack):
	if n==1:
		print(fromStack,' =====> ',toStack)
	else:
		Hanoi(n-1,fromStack,toStack,spareStack)
		Hanoi(1,fromStack,spareStack,toStack)
		Hanoi(n-1,spareStack,spareStack,toStack)
# Hanoi(3,'a','b','c')


#对已经有序的数组进行查找的操作
li=list(range(5))
def searchBi(li,target,left,right):
	if right-left<=1:
		if li[left]==target or li[right]==target:
			return target
		else:
			return False 
	mid=(left+right)//2
	if li[mid]==target:
		return target
	else:
		if li[mid]<target:
			return searchBi(li,target,mid,right)
		else:
			return searchBi(li,target,left,mid)
# print(searchBi(li,6,0,4))
	
'''
dynamic programming动态编程的重点在于，对于已经计算好的结果进行及时的保存
避免相同的结果在不同的分支进行重复的计算，利用空间换时间
'''
mem={1:1,2:1}
def fastFib(n):
	global mem
	if n in mem:
		return mem[n]
	else:
		mem[n]=fastFib(n-1)+fastFib(n-2)
		return mem[n]
# print(fastFib(6))






'''
关于python拷贝复制的问题
到底是拷贝了地址还是拷贝了数值
'''
#赋址
a=[1,2,3]
b=a
a.reverse()
# print(b)

#赋值
#赋值必须使用整体
b=a[:]
a.reverse()
# print(b)

