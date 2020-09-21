import os
import socket

server_ip = "127.0.0.1"
port = 5000
if __name__ == "__main__":
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((server_ip,port))
        s.sendall(b"hello")
        data = s.recv(1024)

        print(repr(data))
