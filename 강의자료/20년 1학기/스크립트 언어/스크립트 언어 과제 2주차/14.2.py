def ex():
    s = input("정수 리스트 입력: ")
    intList = [eval(i) for i in s.split()]
    d = {}
    for n in intList:
        if n in d:
            d[n] += 1
        else:
            d[n] = 1
    maxCount = max(d.values())
    for k, v in d.items():
        if v == maxCount:
             print(k, end = " ")
    print()

ex()
