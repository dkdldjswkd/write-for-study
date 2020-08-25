Python 3.8.2 (tags/v3.8.2:7b3ab59, Feb 25 2020, 22:45:29) [MSC v.1916 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> import math
>>> x1, y1 = eval(input("첫번째 점 위도 경도 60분법:"))
첫번째 점 위도 경도 60분법:39.55,-116.25
>>> x2, y2 = eval(input("두번째 점 위도 경도 60분법:"))
두번째 점 위도 경도 60분법:41.5,87.37
>>> d=6370.01*math.acos(math.sin(math.radians(x1))*math.sin(math.radians(x2))+math.cos(math.radians(x1))*math.cos(math.radians(x2))*math.cos(math.radians(y1)-math.radians(y2)))
>>> d
10690.113638146982
>>> 