def ex():
    matrix = []
    for i in range(3):
        s = input("3x3행렬의 행 {0} 번 원소 입력:".format(i))
        I = [eval(i) for i in s.split()]
        matrix.append(I)
    sortColumns(matrix)
    print(matrix[0])
    print(matrix[1])
    print(matrix[2])

def sortColumns(m):
    for j in range(3):
        for i in range(2):
            for i in range(2):
                if m[i][j] > m[i+1][j]:
                    m[i][j],m[i+1][j] = m[i+1][j],m[i][j]

ex()
