#!/usr/bin/env python3
import numpy as np
import os
import time
import socket
import pickle
from _thread import *
from Block import Block
from keyhandle import key_handle

ip_address = "127.0.0.1"
port = 5000
sstage = np.zeros(128).astype("int").reshape([8, 16])
wait_flag = True

def Check_Stage(sstagep, full_array, n):
    if np.all(sstagep[n] == 1):
        full_array.append(n)
    if (n > 0):
        Check_Stage(sstagep, full_array, n - 1)
    return full_array

def threaded_client(conn, player):
    global wait_flag
    global sstage
    sstagep = np.zeros(64).astype("int").reshape([8, 8])
    dstage = np.zeros(64).astype("int").reshape([8, 8])
    while wait_flag:
        time.sleep(1)
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
            if blk.isGO == True:
                sstagep = np.ones_like(sstagep)
                dstage = np.zeros(64).astype("int").reshape([8, 8])
            else:
                full_array = []
                full_array = Check_Stage(sstagep, full_array, sstagep.shape[1] - 1)
                if blk.isdead == True:
                    # Gameover
                    del blk
                    blk = Block(sstagep)
                if len(full_array):
                    for i in reversed(full_array):
                        for j in reversed(range(i)):
                            sstagep[j + 1] = sstagep[j]
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
            if player == 2:
                wait_flag = False
