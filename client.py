import numpy as np
import pygame
from pygame.locals import *
import sys
import os
import socket
import pickle

server_ip = "127.0.0.1"
port = 5000

if __name__ == "__main__":
    title = "TETRIS"
    pygame.init()
    SCREEN = Rect(0, 0, 400, 400)
    screen = pygame.display.set_mode(SCREEN.size)
    pygame.display.set_caption(title)

    clock = pygame.time.Clock()
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((server_ip, port))
        while (1):
            clock.tick(30)
            # イベント処理
            for event in pygame.event.get():
                if event.type == QUIT:  # 閉じるボタンが押されたら終了
                    pygame.quit()       # Pygameの終了(画面閉じられる)
                    sys.exit()
                elif event.type == KEYDOWN:
                    s.sendall(pickle.dumps(event.key))
                    raw = s.recv(1024)
                    if not raw:
                        break
                    data = pickle.loads(raw)
