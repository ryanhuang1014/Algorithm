ranList=[4,2,6,8,2,0,3,9,8,14,12,2,3]
'''
注意bubble中[]中可能越界的问题
以及使用了j-1后，可能出现的负数索引的问题
'''
def bubbleSort(li):
	length=len(li)
	for i in range(length):
		for j in range(1,length-i):  
			if li[j-1]>li[j]:
				temp=li[j-1]
				li[j-1]=li[j]
				li[j]=temp
	return li
# print(bubbleSort(ranList))

def selectiveSort(li):
	pivot=0
	maxx=li[0]
	length=len(li)
	for i in range(length):
		for j in range(length-i):
			if li[j]>maxx:
				maxx=li[j]
				pivot=j
		temp=li[length-i-1]
		li[length-i-1]=li[pivot]
		li[pivot]=temp
		pivot=0
		maxx=li[0]
	return li

# print(selectiveSort(ranList))

def merge(left,right):
	i,j=0,0
	result=[]
	while i<len(left) and j<len(right):
		if left[i]<right[j]:
			result.append(left[i])
			i+=1
		else:
			result.append(right[j])
			j+=1
	while i<len(left):
		result.append(left[i])
		i+=1
	while j<len(right):
		result.append(right[j])
		j+=1
	return result
def mergeSort(li):
	if len(li)==1:
		return li
	else:
		mid=len(li)//2
		left=mergeSort(li[:mid])
		right=mergeSort(li[mid:])
		together=merge(left,right)
		return together
# print(mergeSort(ranList))
'''
partition 目的是以key为界限
使得原来的数组小于key的部分都放到key左边，大于key的部分都放到key右边
最后返回key的坐标，用来递归
'''
def partition(li,low,high):
	key=li[low]
	while low<high:
		while low<high and li[high]>=key:
			high-=1
		while low<high and li[high]<key:
			li[low]=li[high]
			low+=1
			li[high]=li[low]
	li[low]=key
	return low

def quickSort(li,low,high):
	if low>=high:
		return 
	else:
		pivot=partition(li,low,high)
		quickSort(li,low,pivot)
		quickSort(li,pivot+1,high)
# quickSort(ranList,0,len(ranList)-1)
# print(ranList)			

'''
桶排序和哈希表的特点相似，都是利用空间换时间
分为几个桶，并没有定论，看心情吧。
桶越多，时间越短，空间开销越大
比较适合数值有很多一样的排序，比如全校学生成绩排序
'''
def bucketSort(li):
	result=[]
	length=len(li)
	numBucket=5
	buckets=[[] for i in range(length)]
	for i in range(numBucket):
		n=li[i]//numBucket
		buckets[n].append(li[i])
	for i in range(numBucket):
		quickSort(buckets[i],0,len(buckets[i])-1)
		result.extend(buckets[i])
	return result
print(bucketSort(ranList))

