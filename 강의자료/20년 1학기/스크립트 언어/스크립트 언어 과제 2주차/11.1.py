def ex():
    matrix = []
    for i in range(3):
        s = input("3x4행렬의 행 {0} 번 원소 입력:".format(i))
        I = [eval(i) for i in s.split()]
        matrix.append(I)
    for j in range(4):
        print("열 {0}번 원소의 총합은 {1} 입니다".format(j, sumColumn(matrix,j)))

def sumColumn(m, columnIndex):
    sum = 0
    for i in range(len(m)):
        sum += m[i][columnIndex]
    return sum

ex()
