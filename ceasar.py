def get_num(n):
    return ord(n.lower())-97
def get_char(c):
    return chr(c+97)
def encryption(string, key):
    ct=""
    for i in string:
        ct+=get_char((get_num(i)+key)%26)
    return ct
def decryption(string, key):
    dt=""
    for i in string:
        dt+=get_char((get_num(i)-key)%26)
    return dt
if __name__ == "__main__":
    text=input("Enter text")
    key=int(input("Enter key"))
    ct=encryption(text, key)
    dt=decryption(ct,key)
    print(f"encrypted text: {ct}")
    print()
    print(f"decrypted text :{dt}")