'''
实现了类似c++中的操作符重载的功能
使用dir(fuc)可以发现很多python自动为class加入的隐藏方法
其中很多都是和操作符绑定，例如：__eq__和==等价，
直接print某个对象，调用的是对象的__str__方法，
使用for循环使用的是__next__方法等
'''
# oo programming
import random
import math
import plot
import pylab


class cPoint(object):
    """docstring for cPoint
    first class for simple point
    """

    def __init__(self, x, y):
        super(cPoint, self).__init__()
        self.x = x
        self.y = y
        self.radium = math.sqrt(self.x ** 2 + self.y ** 2)
        self.angle = math.atan2(self.y, self.x)

    def cartesian(self):
        return (self.x, self.y)

    def polar(self):
        return (self.radium, self.angle)

    def __str__(self):
        return ('x is ' + str(self.x) + ' y is ' + str(self.y))

    def __ge__(self, other):
        return ((self.x >= other.x) and (self.y >= other.y))

    def __eq__(self, other):
        return (self.x == other.x) and (self.y == other.y)


p1 = cPoint(1, 1)
p2 = cPoint(1, 0.3)


# print(p1>=p2)

# 自己构建for 循环迭代器
class faculty(object):
    """docstring for faculty"""

    def __init__(self):
        super(faculty, self).__init__()
        self.place = None
        self.members = [1, 2, 4, 3, 1]

    def __iter__(self):
        self.place = -1
        return self

    def __next__(self):
        if self.place >= len(self.members) - 1:
            raise StopIteration
        else:
            self.place += 1
            return self.members[self.place]


f = faculty()
# for i in f:
# 	print(i)



'''
下面test中的count其实为类属性
但是实例可以通过self.count访问类的属性
但是一旦通过self改变count的数值以后，count属性就将变成实例的属性
直接通过类名改变类属性count的数值，不影响count的归属，是类属性仍然是类属性
'''


class test(object):
    """docstring for test"""
    count = 0

    def __init__(self):
        super(test, self).__init__()

    def __str__(self):
        return (str(self.count))


t1 = test()
t2 = test()
t3 = test()

# 类内存空间之中的变量直接改变之后，由于所有的实例中的count都指向同一个类的内存地址，所以实例的count都会发生改变
# test.count=233
# print(t1)
# print(t2)
# print(t3)

# 某一个实例直接修改了类属性之后，该类属性将变为实例属性，直接修改类属性不影响改该变量的值
# t1.count=444
# test.count=111111
# print(t1)
# print(t2)
# print(t3)


'''
关于类继承中属性访问权限的问题	
f3访问f1与f2的话，需要指明访问的范围。class.method()或者class.method(self)或者self.method()

self.blabla  中的blabla是self对象中的参数，所以在类中的命名空间中无法查询到，在对象实例的dir中可以查询到
实例的.运算符默认将把自己self参数作为第一个参数传入函数中。而类的.运算符则不会
instance.method()  等价于  class.method(instance)，前者在()中默默传入了self参数
'''


class newClass(object):
    x1 = 2

    def __init__(self, arg):
        super(newClass, self).__init__()
        self.arg = arg

    def f1(self):
        print('122')

    def f2():
        print('233')

    def f3(self):
        # newClass.f1(self)
        self.f1()
        newClass.f2()
        print(self.arg)


class nn(newClass):
    def __init__(self, arg):
        super(nn, self).__init__()
        self.arg = arg

    def f4():
        print('344')


# n1=newClass(23)
# newClass.f3(n1)


'''
可以在method之前加上__，来使得访问权限强制变为私有
'''
# class ezTes(object):
# 	"""docstring for ezTes"""
# 	def __init__(self, arg):
# 		super(ezTes, self).__init__()
# 		self.arg = arg
# 	def __isPrivate(self):
# 		print('566')
# 	def classMethod():
# 		print('677')
# ez=ezTes(3)
# ezTes.__isPrivate(ez)
# ezTes.classMethod()

'''
一些关于漫步的仿真程序
'''


class Location(object):
    """docstring for Location"""

    def __init__(self, x, y):
        super(Location, self).__init__()
        self.x = x
        self.y = y

    def getCord(self):
        return self.x, self.y

    def change(self, cx, cy):
        self.x += cx
        self.y += cy


class drunk(object):
    """docstring for drunk"""

    def __init__(self, *starter, name):
        super(drunk, self).__init__()
        self.name = name
        self.xStart = starter[0]
        self.yStart = starter[1]
        self.loc = Location(self.xStart, self.yStart)
        self.yell()

    def move(self, dire, dist):
        if dire == 'e' or dire == 'w':
            self.loc.change(dist, 0)
        elif dire == 'n' or dire == 's':
            self.loc.change(0, dist)
        else:
            raise ValueError("directions should be in e,w,s,b")

    def yell(self):
        print('my name is ', self.name)
        print('now my location is', self.loc.getCord())

    def dis(self):
        x, y = self.loc.getCord()
        return math.sqrt(x ** 2 + y ** 2)

    def reset(self):
        self.loc = Location(0, 0)


class field(object):
    """docstring for field"""

    def __init__(self, arg=0):
        super(field, self).__init__()
        self.arg = arg
        self.drunkList = []

    def indexByName(self, strr):
        for i in self.drunkList:
            if i.name == strr:
                return self.drunkList[strr]

    def addDrunk(self, drunky):
        self.drunkList.append(drunky)

    def numDrunk(self):
        return len(self.drunkList)


def performTrial(num):
    f1 = field()
    f1.addDrunk('Peng Li')
    x = []
    y = []
    for i in range(num):
        dirChoice = random.choice(['e', 'w', 's', 'n'])
        f1.indexByName('Peng Li').move(dirChoice, 1)
        x.append(f1.indexByName('Peng Li').loc.getCord[0])
        y.append(f1.indexByName('Peng Li').loc.getCord[1])


# dru = drunk(2,0,name='Peng Li')


# 股票市场仿真

class Stock(object):
    """docstring for Stock"""

    def __init__(self, price, distribution):
        super(Stock, self).__init__()
        self.price = price
        self.distribution = distribution
        self.lastChange = 0
        self.history = []

    def setPrice(self, price):
        self.price = price
        self.history.append(price)

    def getPrice(self):
        return self.price

    def makeMove(self, mktBias, mo):
        if self.price == 0:
            return
        oldPrice = self.price
        baseMove = self.distribution() + mktBias
        self.price = self.price * (1 + baseMove)
        if mo:
            self.price = self.price + random.gauss(-5, -5) * self.lastChange
        if self.price < 0.01:
            self.price = 0
        self.history.append(self.price)
        self.lastChange = oldPrice - self.price

    def showHistory(self, title):
        cur = plot.curve(yRange=self.history, label='price')
        return cur
        # cPlot=plot.curvePlot(xLim=[0,100],yLim=[0,200],title='2333')
        # cPlot.plotSingleCurve(cur)
        # cPlot.show()
        # print(self.history)
        # pylab.figure(title)
        # pylab.plot(self.history)
        # pylab.title('blabla..'+str(title))
        # pylab.xlabel('hello xlabel')
        # pylab.ylabel('hello ylabel')
        # pylab.show()


def unitTestStock():
    def runSim(stks, fig, mo):
        cPlot = plot.curvePlot(xLim=[0, 100], yLim=[0, 200], title='stock',isGrid=False)
        mean = 0
        for a in stks:
            for d in range(numDays):
                a.makeMove(bias, mo)
            cPlot.addCurve(a.showHistory(fig))
            mean += a.getPrice()
            cPlot.plotMultipleCurve()
            mean = mean / float(numStks)
        pylab.axhline(mean)
        cPlot.show()
    numStks = 20
    numDays = 100
    stks1 = []
    stks2 = []
    bias = 0
    mo = False
    for i in range(numStks):
        volatility = random.uniform(0, 1)
        d1 = lambda: random.uniform(-volatility, volatility)
        d2 = lambda: random.gauss(0, volatility / 2)
        stks1.append(Stock(100, d1))
        stks2.append(Stock(100, d2))
    runSim(stks1, 1, mo)
    runSim(stks2, 2, mo)


unitTestStock()
