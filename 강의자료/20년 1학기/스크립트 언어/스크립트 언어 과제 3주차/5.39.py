def main():
    sales =1 #1원 부터 시작해서 늘려나가 본다.
    commission = 0 #25000000
    goal = 25000000
    while commission < goal:
        sales  += 1
        print("sales", sales, "commission", commission)
        if sales > 10000000:
            commission = 5000000*0.08 + 5000000*0.1 + (sales-10000000)*0.12
        elif sales > 5000000:
            commission = 5000000*0.08 + (sales-5000000)*0.1
        else :
            commission = sales*0.08
    print("연봉 3천만원이 되기 위한 최소 매출액 :", sales)
main()
