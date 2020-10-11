#!/usr/bin/env python3
import numpy as np
import os
import socket
import pickle
from _thread import *
from Block import Block
from keyhandle import key_handle

ip_address = "127.0.0.1"
port = 5000
sstage = np.zeros(128).astype("int").reshape([8, 16])

def Check_Stage(sstagep):
    is_full = False
    if np.all(sstagep[7] == 1):
        is_full = True
    return is_full

def threaded_client(conn, player):
    global sstage
    sstagep = np.zeros(64).astype("int").reshape([8, 8])
    dstage = np.zeros(64).astype("int").reshape([8, 8])
    with conn:
        conn.sendall(pickle.dumps(player))
        blk = Block(sstagep)
        while True:
            raw = conn.recv(2024)
            if not raw:
                break
            data = pickle.loads(raw)
            sstagep,dstage = key_handle(data, blk)
            #print(sstagep + dstage)
            if blk.isdead == True:
                del blk
                blk = Block(sstagep)
            if Check_Stage(sstagep):
                for i in reversed(range(sstagep.shape[0] - 1)):
                    sstagep[i + 1] = sstagep[i]
                sstagep[0] = np.zeros(8)
            sstage[:, 8 * player: (8 * player) + 8] = sstagep
            print(sstage)
            conn.sendall(pickle.dumps([sstage, dstage]))

if __name__ == "__main__":
    player = 0
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((ip_address,port))
        s.listen(2) ## connection
        while True:
            conn,addr = s.accept()
            print('Connected to: ' + addr[0] + ':' + str(addr[1]))
            start_new_thread(threaded_client, (conn, player))
            player += 1
