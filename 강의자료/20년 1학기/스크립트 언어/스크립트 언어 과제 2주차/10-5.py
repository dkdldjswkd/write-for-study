s=input("10개 개수 정수 입력 : ")
items = s.split() #문자열 리스트로 변환
numbers = [eval(x) for x in items] #정수형 리스트로 변환
list2 = []
for number in numbers:
    if not number in list2:
        list2.append(number)
print("중복을 제거한 고유한 숫자 : ", list2)
