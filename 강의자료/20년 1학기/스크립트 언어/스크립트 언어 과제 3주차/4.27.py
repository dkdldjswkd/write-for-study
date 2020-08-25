def main():
    x, y = eval(input("x, y 입력 : ")) # (0, 100), (200, 0)
    if x>200 or x<0 or y>100 or y<0:
        print("삼각형 외부")
    else:
        slope = (0-100)/(200-0)
        y1 = -x*slope+y
        if y1 <= 100:
            print("삼각형 내부")
        else:
            print("삼각형 외부")

main()
