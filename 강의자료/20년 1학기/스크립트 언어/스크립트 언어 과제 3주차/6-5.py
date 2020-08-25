def main():
    n1, n2, n3 = eval(input("3개 숫자 입력 : "))
    displaySortedNumbers(n1,n2,n3)
    
def displaySortedNumbers(n1,n2,n3):
    if n1 > n2 :
        n1, n2 = n2, n1
    if n2 > n3 :
        n2, n3 = n3, n2
    if n1 > n2 :
        n1, n2 = n2, n1
    print("정렬된 숫자는",n1,n2,n3)

main()
