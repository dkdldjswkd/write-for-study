def main():
    a,b,c = eval(input("a, b, c 입력 : "))
    D= b**2 - 4*a*c
    if D < 0:
        print("이 방정식은 실근이 존재하지 않습니다.")
    elif D==0:
        r1 = -b/(2*a)
        print("실근은 ", r1, "입니다.")
    else:
        r1 = (-b+D**0.5)/(2*a)
        r2 = (-b-D**0.5)/(2*a)
        print("실근은 {0}과 {1}".format(r1,r2))
main()
