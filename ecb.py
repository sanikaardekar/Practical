def lhs(para,shift):
    temp=[]
    for i in range(len(para)-shift):
        temp.append(para[i+shift])
    temp.extend(para[0:shift])
    print(temp)
    ct.extend(temp)
def rhs(para, shift):
    temp=[]
    for i in range(len(para)):
        temp.append(para[i-shift])
    print(temp)
    pt.extend(temp)
def encrypt(para, shift):
    paraa=''
    parab=''
    for word in para:
        paraa=paraa+str(ord(word))
    print("ascii")
    print(paraa)
    parai=int(paraa)
    parab=bin(parai)
    parab=parab[2:]
    print("binary val: ")
    print(parab)
    print("encrypted: ")
    block=[]
    pos=0
    while parab and pos<len(parab):
        while pos<len(parab):
            block.append(parab[pos])
            pos=pos+1
            if pos%128==0:
                lhs(block,shift)
                block=[]
                continue
    lhs(block,shift)
def decrypt(ct, shift):
    block=[]
    pos=0
    while ct and pos<len(ct):
        while pos<len(ct):
            block.append(ct[pos])
            pos=pos+1
            if pos%128==0:
                lhs(block,shift)
                block=[]
                continue
    rhs(block, shift)

    text=''
    for i in pt:
        text=text+i
    paraa=str(int(text,2))
    j=0
    ans=''
    while j<len(paraa):
        ans=ans+chr(int(paraa[j]+paraa[j+1]))
        j=j+2
    print("decrypted:"+ans)

if __name__=="__main__":
    pt=[]
    ct=[]
    para=input("enter text")
    para=para.upper()
    shift=int(input("enter shift"))
    encrypt(para,shift)
    decrypt(ct,shift)

    

