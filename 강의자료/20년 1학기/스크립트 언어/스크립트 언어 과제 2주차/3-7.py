Python 3.8.2 (tags/v3.8.2:7b3ab59, Feb 25 2020, 22:45:29) [MSC v.1916 32 bit (Intel)] on win32
Type "help", "copyright", "credits" or "license()" for more information.
>>> import time
>>> time.time()
1586098577.1632025
>>> print(chr(ord('A')+int(time.time())%26))
Q
>>> print(chr(ord('A')+int(time.time())%26))
U
>>> 