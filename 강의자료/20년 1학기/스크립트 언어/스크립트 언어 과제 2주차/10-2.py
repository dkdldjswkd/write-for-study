Python 3.8.2 (tags/v3.8.2:7b3ab59, Feb 25 2020, 22:45:29) [MSC v.1916 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> s=input("
	
SyntaxError: EOL while scanning string literal
>>> s=input("정수 리스트 입력:")
정수 리스트 입력:10 20 30 40 50
>>> s
'10 20 30 40 50'
>>> s.split()
['10', '20', '30', '40', '50']
>>> items = s.split()
>>> items
['10', '20', '30', '40', '50']
>>> numbers = [eval(x) for x in items]
>>> numbers
[10, 20, 30, 40, 50]
>>> numbers.reverse()
>>> print(numbers)
[50, 40, 30, 20, 10]
>>> for x in numvers:
	print(x)

	
Traceback (most recent call last):
  File "<pyshell#12>", line 1, in <module>
    for x in numvers:
NameError: name 'numvers' is not defined
>>> for x in numbers:
	print(x)

	
50
40
30
20
10
>>> 