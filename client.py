import numpy as np
import pygame
from pygame.locals import *
import sys
import os
import socket
import pickle
from Block import Block
from keyhandle import key_handle

server_ip = "127.0.0.1"
port = 5000

def Next_Ball(b_group,Stage):
    Stage.add(b_group.sprites()[0])
    b_group.remove(b_group.sprites())
    block = Block("test.png", 150, 0, Stage)
    b_group.add(block)
    return Stage, b_group, block

def Check_Stage(Stage):
    is_full = False
    lower_rows = [blocks for blocks in Stage.sprites() if blocks.rect.bottom == 400]
    if len(lower_rows) == 8:
        is_full = True
    return is_full, lower_rows

def clear_row(Stage, lower_rows):
    Stage.remove(lower_rows)
    for block in Stage:
        block.isdead = False
        block.move_down()
        print(block.rect.bottom)

if __name__ == "__main__":
    title = "TETRIS"
    pygame.init()
    SCREEN = Rect(0, 0, 400, 400)
    screen = pygame.display.set_mode(SCREEN.size)
    pygame.display.set_caption(title)

    Stage = pygame.sprite.RenderUpdates()

    block = Block("test.png", 150, 0, Stage)
    b_group = pygame.sprite.RenderUpdates()
    b_group.add(block)
    b_group.update()

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
                    key_handle(data, block, b_group)
                    if b_group.sprites()[0].isdead:
                        Stage, b_group,block = Next_Ball(b_group, Stage)
                        is_full, lower_rows = Check_Stage(Stage)
                        if is_full:
                            clear_row(Stage, lower_rows)

            screen.fill((255, 255, 255))
            b_group.draw(screen)
            Stage.draw(screen)
            pygame.display.update()
