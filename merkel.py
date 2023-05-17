import hashlib
def increase(data):
    n=0
    while 2**n<len(data):
        n+=1
    newlen=2**n
    if newlen==len(data): 
        return data
    else:
        last=data[-1]
        data.extend([last]*(newlen-len(data)))
        return data
def merkle(transaction):
    if len(transaction) == 1:
        return transaction[0]
    hasheddata=list(map(lambda x: hashlib.sha1(x.encode()).hexdigest(),transaction))
    print(len(transaction))
    mergedlist=[hasheddata[i]+hasheddata[i+1] for i in range(0, len(transaction),2)]
    return merkle(mergedlist)

if __name__=="__main__":
    transaction = ["t1","t2","t3","t4"]
    transaction=increase(transaction)
    print(transaction)
    print(merkle(transaction))