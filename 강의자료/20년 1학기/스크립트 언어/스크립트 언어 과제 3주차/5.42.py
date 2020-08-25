import random
def main():
    count  = 0;
    for i in range(1000000):
        x = random.random()*2 -1
        y = random.random()*2 -1
        if x<0:
            count +=1
        elif 0<=x<=1 and 0<=y<=1:
            y1 = y+x # y절편
            if y1 <= 1:
                count +=1
    print ("1,3번 영역에 포함될 확률 : ", count/1000000)

main()
