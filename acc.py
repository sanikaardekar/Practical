def accounting(n):
    size = 1
    dcost = 0
    icost = 0
    total_cost = 0
    total = 0
    bank = 0

    print('Element\tDoubling Copying cost\tInsertion cost\Total cost\tBank')

    for i in range(1, n + 1):
        icost = 1

        if i > size:
            size *= 2
            dcost = i - 1

        total_cost = dcost + icost
        total = total + total_cost
        bank = bank + (3 - total_cost)

        print(i,"\t",dcost,"\t\t\t",icost,"\t\t",total_cost,"\t\t",bank)
        dcost = 0
        icost = 0

    amortized_cost = total / n
    return amortized_cost

n = int(input("Enter no of elements: "))
am = accounting(n)
print("Amortized cost: ",am)