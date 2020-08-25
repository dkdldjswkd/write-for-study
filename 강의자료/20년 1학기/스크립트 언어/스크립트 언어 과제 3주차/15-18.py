count = 0
def main():
    n = eval(input("디스크 개수 입력 : "))
    print("옮기는 순서는 다음과 같다.")
    moveDisks(n, 'A', 'B', 'C')
    print("옮긴 횟수 : ",count)

def moveDisks(n, fromTower, toTower, auxTower):
    global count
    if n==1:
        count +=1
    else:
        moveDisks(n-1, fromTower, auxTower, toTower)
        count +=1
        moveDisks(n-1, auxTower, toTower, fromTower)

main()
