import numpy as np
import pygame
from pygame.locals import * 
from pygase import Client
import sys
from keyhandle import key_handle

if __name__ == "__main__":
    title = "TETRIS"
    pygame.init()
    SCREEN = Rect(0, 0, 400, 400)
    screen = pygame.display.set_mode(SCREEN.size)
    pygame.display.set_caption(title)
    
    client = Client()
    client.connect_in_thread(port=8080)

    clock = pygame.time.Clock()
    while (1):
        clock.tick(30)
        # イベント処理
        for event in pygame.event.get():
            if event.type == QUIT:  # 閉じるボタンが押されたら終了
                client.disconnect(shutdown_server=True)
                pygame.quit()       # Pygameの終了(画面閉じられる)
                sys.exit()
            elif event.type == KEYDOWN:
                key_handle(event.key)
        with client.access_game_state() as game_state:

            screen.fill((255,255,255))
            game_state.b_group.draw(screen)
            game_state.Stage.draw(screen)
        pygame.display.update()
