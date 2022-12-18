from BTrees.IIBTree import IIBTree
import time

t = IIBTree()
insertion_start_time = time.time()
for i in range(1000):
    t.update({i: 2*i})
insertion_end_time = time.time()
print("Insertion time:", format(
    (insertion_end_time-insertion_start_time)*1000, ".3f"),  "milliseconds")
key = int(input("enter key: "))
search_start_time = time.time()
if t.has_key(key):
    print(t[key])
search_end_time = time.time()
print("Search time:", format(
    (search_end_time-search_start_time)*1000, ".3f"), "milliseconds")
