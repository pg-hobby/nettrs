import numpy as np
import os
import socket
import pickle
from Block import Block
from keyhandle import key_handle

ip_address = "127.0.0.1"
port = 5000
sstage = np.zeros(64).reshape([8, 8])
dstage = np.zeros(64).reshape([8, 8])

if __name__ == "__main__":
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((ip_address,port))
        s.listen(1) ## connection
        while True:
            conn,addr = s.accept()

            with conn:
                blk = Block(sstage)
                while True:
                    raw = conn.recv(2024)
                    if not raw:
                        break
                    data = pickle.loads(raw)
                    sstage,dstage = key_handle(data, blk)
                    print(sstage + dstage)
                    if blk.isdead == True:
                        del blk
                        blk = Block(sstage)
                    conn.sendall(pickle.dumps([sstage, dstage]))
