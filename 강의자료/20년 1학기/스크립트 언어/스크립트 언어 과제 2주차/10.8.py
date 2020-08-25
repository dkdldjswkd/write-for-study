def ex10_8():
	sList = input("정수 리스트 입력 : "). split()
	intList = [eval(s) for s in sList]
	print("가장 작은 정수의 인덱스 : ", indexOfSmallestElement(intList))

def indexOfSmallestElement(lst):
    min = lst[0]
    index = 0
    for i in range(1, len(lst)):
        if min > lst[i]:
            min = lst[i]
            index = i
    return index
ex10_8()
