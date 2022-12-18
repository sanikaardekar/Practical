import socket
import sqlite3

def server_program():
    # get the hostname
    host = socket.gethostname()
    port = 9400  # initiate port no above 1024

    server_socket = socket.socket()  # get instance
    # look closely. The bind() function takes tuple as argument
    server_socket.bind((host, port))  # bind host address and port together

    # configure how many client the server can listen simultaneously
    server_socket.listen(2)
    conn, address = server_socket.accept()  # accept new connection
    print("Connection from: " + str(address))
    message ="1. Request to prepare for commit\n2. Enter query\n"  # take input
    conn.send(message.encode())
    while True:
        # receive data stream. it won't accept data packet greater than 1024 bytes
        data = conn.recv(1024).decode()
        #print(data=="1")
        if data=="1":
            dataconn = sqlite3.connect('test.db')
            message="Prepared to commit. Press 2 for query."
            conn.send(message.encode())
        elif data=="2":
            #print("hi")
            message="enter query"
            conn.send(message.encode())
            query = conn.recv(1024).decode()
            try:
                cur = dataconn.cursor()
                cur.execute(query)
                rows = cur.fetchall()
                for row in rows:
                    for c in row:
                        conn.send(str(c).encode())
                        conn.send(" ".encode())
                    conn.send("\n".encode())
                message="done"
                dataconn.commit()
            except Exception as e: 
                print(e)
                message="something wrong in the query"
            conn.send(message.encode())  # send data to the client

    conn.close()  # close the connection


if __name__ == '__main__':
    server_program()

