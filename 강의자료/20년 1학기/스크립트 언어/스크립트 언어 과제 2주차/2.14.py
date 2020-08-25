Python 3.8.2 (tags/v3.8.2:7b3ab59, Feb 25 2020, 22:45:29) [MSC v.1916 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> x1, y1, x2, y2, x3, y3 = eval(input("삼각형 3 꼭지점"))
삼각형 3 꼭지점1.5,-3.4,4.6,5,9.5,-3.4
>>> s1=((x2-x1)**2+(y2-y1)**2)**0.5
>>> s2=((x3-x1)**2+(y3-y1)**2)**0.5
>>> s3=((x3-x2)**2+(y3-y2)**2)**0.5
>>> s=(s1+s2+s3)/2
>>> area=(s*(s-s1)*(s-s2)*(s-s3))**0.5
>>> print("삼각형 넓이는 ", area)
삼각형 넓이는  33.600000000000016
>>> 