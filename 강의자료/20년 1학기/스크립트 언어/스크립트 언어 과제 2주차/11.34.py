def ex():
    points = eval(input("6개의 점을 입력하세요 : "))
    print(getRightmostLowestPoint(points))

def getRightmostLowestPoint(points):
    max=0
    index=0
    for i in range(0,11,2):
        if max < points[i]:
            max = points[i]
            index = i
        if max == points[i]:
            if points[index+1] > points[i+1]: #새로 발견된 우측의 점이 원래 우측의 점보다 아래에 있으면
                index = i #가장 우측 아래있는 점은 새로 발견된 점이다.
        
    l = points[index], points[index+1]
    return l

ex()
