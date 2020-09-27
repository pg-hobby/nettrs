import numpy as np
import pygame
from pygame.locals import *
import sys
import os
import socket
import pickle

server_ip = "127.0.0.1"
port = 5000

# Block colors     [empty],         [dynamic],     [static]
colors = np.array([[255, 255, 255], [0, 255, 255], [255, 0, 0]])
stage = np.zeros(64).astype("int").reshape([8,8])
sstage = np.zeros(64).astype("int").reshape([8,8])
dstage = np.zeros(64).astype("int").reshape([8,8])

if __name__ == "__main__":
    title = "TETRIS"
    pygame.init()
    SCREEN = Rect(0, 0, 400, 400)
    screen = pygame.display.set_mode(SCREEN.size)
    pygame.display.set_caption(title)
    surface = pygame.surfarray.make_surface(colors[stage.T])
    surface = pygame.transform.scale(surface, (400, 400))

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
                    raw = s.recv(2048)
                    if not raw:
                        break
                    sstage,dstage = pickle.loads(raw)
                    stage = dstage + np.multiply(sstage, 2)
                    print(stage)
                    surface = pygame.surfarray.make_surface(colors[stage.T])
                    surface = pygame.transform.scale(surface, (400, 400))

            screen.fill((30, 30, 30))
            screen.blit(surface, (0, 0))
            pygame.display.update()

