import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import bisect
from math import *
from numpy import *
#plotting the graph of function f(x)=0
def f(x):
    return (x**3-2*x-5)
roots = bisect(f,a=2,b=3)
print(roots)

x = np.linspace(-3,3,400)
y = f(x)

plt.plot(x,y,label="f(x)")
plt.axhline(0,color="black",linestyle='--',linewidth=0.8,label='x-axis')
plt.plot(roots,0,'ro',markersize=8,label=f'curve intersect at x-axis({roots: 3f}0)')
plt.title("Intersection of f(x) with x-axis")
plt.xlabel("x-axis")
plt.ylabel("y-axis")
plt.legend()
plt.show()

#bisection method
def f(x):
    return (x-np.tan(x))
a = eval(input("Enter the value of a="))
b = eval(input("Enter the value of b="))
n = eval(input("Enter the value of n="))

for i in range(1,n+1):
    c = (a+b)/2
    print(c)
    if f(a)*f(c)<0:
        b=c
    elif f(c)*f(b)<0:
        a = c
    c1 = (a+b)/2
    if abs(c1-c)<0.001:
        print("Accurate root is ",c)
        break
roots = c
#regula falsi method
def f(x):
    return(x**3-5*x-1)
a =eval(input("Enter the value of a:"))
b =eval(input("Enter the value of b:"))
n =eval(input("Enter the value of n:"))

for i in range(1,n+1):
    c = (a*f(b)-b*f(a))/(f(b)-f(a))
    print([i,c])
    if f(a)*f(c)<0:
        b=c
    elif f(c)*f(b)<0:
        a=c
    c1 = (a*f(b)-b*f(a))/(f(b)-f(a))

    if abs(c1-c)<0.0001:
        print("Accurate root is :",c)
        break
#Newton raphson method
def f(x):
    return(x**2-20)
def g(x):
    return(2*x)
a=eval(input("Enter the value of a="))
b=eval(input("Enter the value of b="))
n=eval(input("Enter the value of n="))

x0=(a+b)/2
for i in range(1,n+1):
    print([1,x0])
    x1=x0-(f(x0)/g(x0))
    if abs(x1-x0)<0.0001:
        print("Accurate root is:",x0)
        break
    x0=x1
#forward difference table
x=eval(input("Enter the value of x = "))
y=eval(input("Enter the value of y = "))
n=eval(input("Enter the value of n = "))
D = zeros((n,n+1))
for i in range (0,n):
    D[i,0] = x[i]
    D[i,1] = y[i]
for j in range (2,n+1):
    for i in range (0, n-j+1):
        D[i,j] = D[i+1,j-1]-D[i,j-1]
print("Forward difference table is : ")
print(D)
#backward difference table
x=eval(input("Enter the value of x = "))
y=eval(input("Enter the value of y = "))
n=eval(input("Enter the value of n = "))
D = zeros((n,n+1))
for i in range (0,n):
    D[i,0] = x[i]
    D[i,1] = y[i]
for j in range (2,n+1):
    for i in range (n-1, j-2,-1):
        D[i,j] = D[i,j-1]-D[i-1,j-1]
print("Backward difference table is : ")
print(D)
#divided difference table
from math import *
from numpy import *

n=eval(input("Enter the length of x as n="))
x=eval(input("Enter the values of x="))
y=eval(input("Enter the values of y="))
D=zeros((n,n+1))

for i in range(0,n):
       D[i,0]=x[i]
       D[i,1]=y[i]
for j in range(2,n+1):
       for i in range(0,n-j+1):
           D[i,j]=(D[i+1,j-1]-D[i,j-1])/(x[i+j-1]-x[i])
print("Divided difference table is as follows:")
print(D)
# Forward interpolation

from math import *
from numpy import *

x=eval(input("Enter the value of x = "))
y=eval(input("Enter the value of y = "))
n=eval(input("Enter the value of n = "))
xg=eval(input("Enter the values of x, Where interpolation is carried out as xg"))
D = zeros((n,n+1))
for i in range (0,n):
    D[i,0] = x[i]
    D[i,1] = y[i]
for j in range (2,n+1):
    for i in range (0, n-j+1):
        D[i,j] = D[i+1,j-1]-D[i,j-1]
print("Forward difference table is : ")
print(D)

h=x[1]-x[0]
u=(xg-x[0])/h
sum1=0
pp=1
for i in range(1,n):
    sum1=sum1+(pp*D[0,i])
    pp = pp*(u-(i-1))/(i)
print(sum1)


# Backward interpolation

x=eval(input("Enter the value of x = "))
y=eval(input("Enter the value of y = "))
n=eval(input("Enter the value of n = "))
xg=eval(input("Enter the values of x, Where interpolation is carried out as xg"))

D = zeros((n,n+1))
for i in range (0,n):
    D[i,0] = x[i]
    D[i,1] = y[i]
for j in range (2,n+1):
    for i in range (n-1, j-2,-1):
        D[i,j] = D[i,j-1]-D[i-1,j-1]
print("Backward difference table is : ")
print(D)

h=x[1]-x[0]
u=(xg-x[-1])/h
sum2=0
pp=1
for i in range(1,n):
    sum2=sum2+(pp*D[-1,i])
    pp=pp*(u+(i-1))/(i)
print(sum2)

#divided diffrence interpolation
from math import*
from numpy import*
n=eval(input("Enter the value of n="))
x=eval(input("Enter the value of x="))
y=eval(input("Enter the value of y="))
xg=eval(input("Enter the value of xg="))
d=zeros((n,n+1))
for i in range (0,n):
     d[i,0]=x[i]
     d[i,1]=y[i]
     for j in range (2,n+1):
          for i in range (0,n-j+1):
               d[i,j]=(d[i+1,j-1]-d[i,j-1])/(x[i+j-1]-x[i])
print("divided difference table as follows:")
print(d)
sum3=0
pp=1
for i in range (0,n):
     sum3=sum3+(pp*d[0,i+1])
     pp=pp*(xg-x[i])
print("value of function at xg is=",sum3)

#lagrange's interpolation
from math import*
from numpy import*
n=eval(input("Enter the value of n="))
x=eval(input("Enter the value of x="))
y=eval(input("Enter the value of y="))
xg=eval(input("Enter the value of xg="))
y_val=0
for i in range (n):
     l=1
     for j in range (n):
          if j!=1:
               l=l*(xg-x[j])/(x[i]-x[j])
     y_val=y_val+y[i]*l
print("value of function at xg is=",y_val)

#trapozidal
def f(x):
     y=(1)/(1+x)
     return(y)
a=eval(input("Enter the value of a="))
b=eval(input("Enter the value of b="))
n=eval(input("Enter the value of n="))
h=(b-a)/(n)
add1=0
add2=0
for i in range (0,n+1):
     x=a+i*h
     y=f(x)
     print([x,y])
     if i==0 or i==n:
          add1=add1+y
     else:
          add2=add2+y
          I=(h/2)*(add1+2*add2)
print("Value of definite integration I=",I)

#symphsons 1/3rd
def f(x):
     y=(1)/(1+x)
     return(y)
a=eval(input("Enter the value of a="))
b=eval(input("Enter the value of b="))
n=eval(input("Enter the value of n="))
h=(b-a)/(n)
sum1=0
sum2=0
sum3=0
for i in range(0,n+1):
     x=a+i*h
     y=f(x)
     print([x,f(x)])
     if i==0 or i==n:
          sum1=sum1+y
     elif i%2==0:
          sum2=sum2+y
     else:
          sum3=sum3+y
          I=(h/3)*(sum1+2*sum2+4*sum3)
print("Value of definite integration =",I)

#symphsons 3/8
def f(x):
     y=(1)/(1+x)
     return(y)
a=eval(input("Enter the value of a="))
b=eval(input("Enter the value of b="))
n=eval(input("Enter the value of n="))
h=(b-a)/(n)
sum1=0
sum2=0
sum3=0
for i in range(0,n+1):
     x=a+i*h
     y=f(x)
     print([x,f(x)])
     if i==0 or i==n:
          sum1=sum1+y
     elif i%3==0:
          sum2=sum2+y
     else:
          sum3=sum3+y
          I=3*(h/8)*(sum1+2*sum2+3*sum3)
print("value of definite integration=",I)

#euler method
def f(x,y):
     z=1+x
     return(z)
x0=0
y0=1
h=0.1
n=3
for i in range (1,n+1):
     x1=x0+h
     y1=y0+h*f(x0,y0)
     print([i,x1,y1])
     x0=x1
     y0=y1
     
# euler's modified method
def f(x,y):
     z=1+x
     return(z)
x0=0
y0=1
h=0.1
n=10
for i in range (1,n+1):
     x1=x0+h
     y_predic=y0+h*f(x0,y0)
     y_correct=y0+(h/2)*(f(x0,y0)+f(x0+h,y_predic))
     print([i,x1,y_correct])
     x0=x1
     y0=y_correct

# runge kutta 4th 
def f(x,y):
     z=1+y
     return(z)
x0=0
y0=1
h=0.1
n=3
for i in range (1,n+1):
     k1=h*f(x0,y0)
     k2=h*f(x0+h/2,y0+k1/2)
     k3=h*f(x0+h/2,y0+k2/2)
     k4=h*f(x0+h,y0+k3)
     x1=x0+h
     y1=y0+(1/6)*(k1+2*k2+2*k3+k4)
     print([i,x1,y1])
     x0=x1
     y0=y1

#runge kutta 2nd
def f(x,y):
     z=1+y
     return(z)
x0=0
y0=1
h=0.1
n=3
for i in range (1,n+1):
     k1=h*f(x0,y0)
     k2=h*f(x0+h,y0+k1)
     x1=x0+h
     y1=y0+(1/2)*(k1+k2)
     print([i,x1,y1])
     x0=x1
     y0=y1
