def main():
    decimal = eval(input("10진수 입력 : "))
    print(decimal, "의 16진수:", decimalToHex(decimal))

def decimalToHex(value):
    if value ==0:
        return ""
    else:
        if value % 16 == 10:
            r = 'A'
        elif value % 16 == 11:
            r ='B'
        elif value % 16 == 12:
            r= 'C'
        elif value % 16 == 13:
            r= 'D'
        elif value % 16 == 14:
            r= 'E'
        elif value % 16 == 15:
            r = 'F'
        else:
            r = str(value%16)
        return decimalToHex(value//16) +r
main()
