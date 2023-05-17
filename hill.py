import numpy as np
def nomalise(x,n):
    newx=x
    p=len(x)%n
    for i in range(p):
        newx+="x"
    return newx
def encrypt(x,mat,n):
    if len(x)%n!=0:
        newx=nomalise(x,n)
    else:
        newx=x
    cipher=""
    for i in range(0,len(newx), n):
        temp=[]
        for j in range(n):
            temp.append(ord(newx[i+j])-ord('a'))
        sol=np.dot(mat,temp)
        for j in sol:
            cipher+=chr(j%26+ord('a'))
    return cipher
def decrypt(cipher, mat, n):
    text=""
    det=round(np.linalg.det(mat))
    newdet=pow(det,-1,26)
    adjoint=(np.linalg.inv(mat)*det)
    newadj=[]
    for i in range(len(adjoint)):
        temp=[]
        for j in range(len(adjoint[i])):
            if adjoint[i][j]<0:
                temp.append(round(adjoint[i][j]+26)*newdet)
            else:
                temp.append(round(adjoint[i][j])*newdet)
        newadj.append(temp)
    text=encrypt(cipher,newadj,n)
    return text
def main():
    x="sanikaardekar"
    n=2
    mat=[[2,3],[5,6]]
    print(mat)
    cipher=encrypt(x,mat,n)
    print(cipher)
    print()
    dt=decrypt(cipher, mat, n)
    print(dt)
main()