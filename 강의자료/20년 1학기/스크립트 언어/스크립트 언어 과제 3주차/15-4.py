def main():
    for i in range(1,11):
        print(i,m(i))

def m(i):
    if i ==1:
        return 1
    else:
        return m(i-1) + 1/i

main()
