import numpy as np
import os
import socket
import pickle
from _thread import *
from Block import Block
from keyhandle import key_handle

ip_address = "127.0.0.1"
port = 5000
sstage = np.zeros(64).astype("int").reshape([8, 8])

def Check_Stage():
    global sstage
    is_full = False
    if np.all(sstage[7] == 1):
        is_full = True
    return is_full

def threaded_client(conn):
    global sstage
    dstage = np.zeros(64).astype("int").reshape([8, 8])
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
            if Check_Stage():
                for i in reversed(range(sstage.shape[0] - 1)):
                    sstage[i + 1] = sstage[i]
                sstage[0] = np.zeros(8)
            conn.sendall(pickle.dumps([sstage, dstage]))


if __name__ == "__main__":
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((ip_address,port))
        s.listen(2) ## connection
        while True:
            conn,addr = s.accept()
            print('Connected to: ' + addr[0] + ':' + str(addr[1]))
            start_new_thread(threaded_client, (conn, ))
