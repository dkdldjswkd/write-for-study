Python 3.8.2 (tags/v3.8.2:7b3ab59, Feb 25 2020, 22:45:29) [MSC v.1916 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> x1, y1, x2, y2, x3, y3, x4, y4 = eval(input("서울, 강릉, 광주, 부산의 좌표를 순서대로 입력하세요 : "))
서울, 강릉, 광주, 부산의 좌표를 순서대로 입력하세요 : 37.565289,126.8491259,37.7637326,128.8824475,35.1768201,126.7735892,35.1645701,129.0015892
>>> s1=((x2-x1)**2+(y2-y1)**2)**0.5
>>> s2=((x3-x1)**2+(y3-y1)**2)**0.5
>>> s3=((x3-x2)**2+(y3-y2)**2)**0.5
>>> a1=(s1+s2+s3)/2
>>> area1=(a1*(a1-s1)*(a1-s2)*(a1-s3))**0.5
>>> s4 = ((x4-x2)**2+(y4-y2)**2)**0.5
>>> s5 = ((x4-x3)**2+(y4-y3)**2)**0.5
>>> a2 = (s3+s4+s5)/2
>>> area2=(a2*(a2-s3)*(a2-s4)*(a2-s5))**0.5
>>> SumArea = area1+area2
>>> sumArea
Traceback (most recent call last):
  File "<pyshell#14>", line 1, in <module>
    sumArea
NameError: name 'sumArea' is not defined
>>> SumArea
5.315505097396578
>>> area1
2.4207678153090693
>>> area2
2.8947372820875086
>>> 