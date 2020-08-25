def ex10_15():
    sList = input("정수 리스트 입력 : ").split()
    intList = [eval(s) for s in sList]
    if isSorted(intList):
        print("리스트는 정렬되어 있습니다.")
    else:
        print("리스트는 정렬되어 있지 않습니다.")

def isSorted(lst):
    for i in range(len(lst)-1):
        if lst[i] > lst[i+1]:
            return False
    return True

ex10_15()
