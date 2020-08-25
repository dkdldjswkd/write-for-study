def main():
    number = eval(input("숫자 입력 : "))
    #if isPalindrome(number):
    #    print(number, "는 Palindrome이다")
    #else:
    #    print(number, "는 Palindrome이 아니다")
    print("역수는 ",reverse(number))

def isPalindrome(number):
    if number == reverse(number):
        return True
    else:
        return False

def reverse(number):
    result = 0
    while number:
        result = result*10 + number%10
        number = number // 10
    return result

main()

