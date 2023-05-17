def gcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a
def encryption(pk,pt):
    e, n = pk
    return pow(pt,e,n)

def decryption(pk,ct):
    d,n = pk
    return pow(ct,d,n)
p=int(input("enter large prime"))
q=int(input("enter large prime"))

n=p*q
phi=(p-1)*(q-1)

e=2
while(gcd(e,phi))!=1:
    e+=1

d=pow(e,-1,phi)

publickey=(e,n)
privatekey=(d,n)

plaintext=int(input("enter number"))

ct=encryption(publickey, plaintext)
print(ct)
dt=decryption(privatekey, ct)
print(dt)