import random
def main():
    #카드 52장 모양3, 숫자 13
    num = random.randint(0,51)
    result = ""
    if num // 13 == 0:
        result = "크로바"
    elif num // 13 == 1:
        result = "다이아몬드"
    elif num // 13 ==2:
        result = "하트"
    else:
        result = "스페이드"
    if num % 13 == 0:
        result += "A"
    elif num % 13 == 10:
        result += "J"
    elif num % 13 == 11:
        result += "Q"
    elif num % 13 == 12:
        result += "K"
    else:
        result += str(num%13)
    print ("당신이 뽑은 카드는 ", result)

main()
