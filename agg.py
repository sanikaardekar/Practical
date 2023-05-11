def aggregate(n):
    size=1
    dcost=0
    icost=0
    total_cost=0
    total=0

    print('Element\tDoubling Copying cost\tInsertion cost\Total cost')

    for i in range(1, n + 1):
        icost=1
        if i > size:
            size *= 2
            dcost = i - 1
        total_cost = dcost + icost
        total = total + total_cost

        print(i,"\t",dcost,"\t\t\t",icost,"\t\t",total_cost)
        dcost = 0
        icost = 0

    amortized_cost = total / n
    return amortized_cost

n = int(input("Enter no of elements: "))
am = aggregate(n)
print("Amortized cost: ",am)