#!/usr/bin/env python3
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
ostage = np.zeros(64).astype("int").reshape([8,8])
stage = np.zeros(64).astype("int").reshape([8,8])
sstage = np.zeros(64).astype("int").reshape([8,8])
dstage = np.zeros(64).astype("int").reshape([8,8])

if __name__ == "__main__":
    title = "TETRIS"
    pygame.init()
    SCREEN = Rect(0, 0, 800, 400)
    screen = pygame.display.set_mode(SCREEN.size)
    pygame.display.set_caption(title)
    surface = pygame.surfarray.make_surface(colors[stage.T])
    surface = pygame.transform.scale(surface, (400, 400))
    surface2 = pygame.surfarray.make_surface(colors[ostage.T])
    surface2 = pygame.transform.scale(surface2, (400, 400))

    clock = pygame.time.Clock()
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((server_ip, port))
        player = pickle.loads(s.recv(256))
        while (1):
            clock.tick(30)
            s.sendall(pickle.dumps(-1))
            raw = s.recv(2048)
            if not raw:
                break
            sstage,dstage = pickle.loads(raw)
            sstage = np.multiply(sstage, 2)
            ostage = sstage[:, 8 * ((player + 1) % 2): (8 * ((player + 1) % 2)) + 8]
            # print(sstage[:, 8 * ((player + 1) % 2): (8 * ((player + 1) % 2)) + 8])
            stage = dstage + sstage[:, 8 * player: (8 * player) + 8]
            surface = pygame.surfarray.make_surface(colors[stage.T])
            surface = pygame.transform.scale(surface, (400, 400))
            surface2 = pygame.surfarray.make_surface(colors[ostage.T])
            surface2 = pygame.transform.scale(surface2, (400, 400))

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
                    sstage = np.multiply(sstage, 2)
                    stage = dstage + sstage[:, 8 * player: (8 * player) + 8]
                    ostage = sstage[:, 8 * ((player + 1) % 2): (8 * ((player + 1) % 2)) + 8]
                    # print(sstage[:, 8 * ((player + 1) % 2): (8 * ((player + 1) % 2)) + 8])
                    surface = pygame.surfarray.make_surface(colors[stage.T])
                    surface = pygame.transform.scale(surface, (400, 400))
                    surface2 = pygame.surfarray.make_surface(colors[ostage.T])
                    surface2 = pygame.transform.scale(surface2, (400, 400))

            screen.fill((30, 30, 30))
            screen.blit(surface, (0, 0))
            screen.blit(surface2, (400, 0))
            pygame.draw.line(screen, (0, 95, 0), (400, 0), (400, 400), 1)
            pygame.display.update()

