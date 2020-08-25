def main():
    decimal = eval(input("10진수 입력 : "))
    print(decimal, "의 이진수:", decimalToBinary(decimal))

def decimalToBinary(value):
    if value ==0:
        return ""
    else:
        return decimalToBinary(value//2)+str(value%2)
main()
