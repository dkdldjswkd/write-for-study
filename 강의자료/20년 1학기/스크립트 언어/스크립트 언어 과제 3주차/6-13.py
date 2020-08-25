def main():
    print("\ti\t\tm(i)")
    for i in range(1,21):
        print("\t{}\t\t{}".format(i,m(i)))

def m(n):
    sum = 0
    for i in range(1,n+1):
        sum += i/(i+1)
    return sum

main()
