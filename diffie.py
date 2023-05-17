Q=int(input("enter value of Q"))
P=int(input("enter value of P"))
a=int(input("enter value of a"))
b=int(input("enter value of b"))

x=int(pow(Q,a,P))
y=int(pow(Q,b,P))

ka=int(pow(y,a,P))
kb=int(pow(x,b,P))

if ka==kb:
    print("done")
else:
    print("failed")

print(f"secret key for p1: {ka}")
print(f"secret key for p2: {kb}")