import random
def ex():
    Nball = eval(input("떨어뜨릴 공의 개수 입력 : "))
    Nslots = eval(input("콩기계 슬롯의 개수 입력 : "))
    slots = [0]*Nslots
    for i in range(Nball):
        slots[path(Nslots)] +=1
    maxHeight = max(slots)
    for h in range(maxHeight, 0, -1): #maxHeight = 3, 2, 1
        for i in range(len(slots)):
            if slots[i] < h:
                print(" ", end="")
            else:
                print("0", end="")
        print()

#슬롯의 위치 인덱스를 반환
def path(Nslots):
    index = 0
    for i in range(Nslots-1):
        if random.random() < 0.5:
            print("L", end="")
        else:
            print("R", end="")
            index +=1
    print()
    return index

ex()
