import os
import socket
import pickle

ip_address = "127.0.0.1"
port = 5000

if __name__ == "__main__":
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((ip_address,port))
        s.listen(1) ## connection
        while True:
            conn,addr = s.accept()

            with conn:
                while True:
                    raw = conn.recv(1024)
                    if not raw:
                        break
                    data = pickle.loads(raw)
                    print(data)
                    conn.sendall(pickle.dumps(key))
