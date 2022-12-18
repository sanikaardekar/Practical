from bplustree import BPlusTree
import time

tree = BPlusTree('.\Tmp\\bplustree.db', order=1000)
insertion_start_time= time.time()
for i in range(1000):
    data=(2*i).to_bytes(10,'big')
    tree[i]=data
insertion_end_time=time.time()
print("Insertion time:", format((insertion_end_time-insertion_start_time)*1000, ".3f"),  "ms")
while True:
    data=int(input("Enter key : "))
    if data<0 or data>999:
        break
    start_time=time.time()
    byte_data=tree.get(data)
    end_time=time.time()
    int_data=int.from_bytes(byte_data, 'big')
    print("Value : ",int_data)
    print("Time taken : ",(end_time-start_time)*1000," ms")

tree.close()