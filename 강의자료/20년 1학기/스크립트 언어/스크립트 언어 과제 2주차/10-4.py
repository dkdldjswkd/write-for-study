s=input("지정되지 않은 개수 정수 입력 : ")
items = s.split() #문자열 리스트로 변환
numbers = [eval(x) for x in items] #정수형 리스트로 변환
average = sum(numbers) / len(numbers)
numOfAbove = 0
for n in numbers:
    if n >= average:
        numOfAbove += 1
print("평균 : ", average)
print("평균보다 크거나 같은 원소의 개수 : ", numOfAbove)
print("평균보다 작은 원소의 개수 : ",len(numbers)-numOfAbove)
