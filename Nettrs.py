import numpy as np
import pygame
from pygame.locals import * 
import sys

def Next_Ball(b_group,Stage):
    Stage.add(b_group.sprites()[0])
    b_group.remove(b_group.sprites())  
    block = Block("test.png",150,0,Stage)
    b_group.add(block)
    return Stage,b_group,block

def key_handle(key,block,group):
    if key==K_SPACE:
        block.move_dfast()
    elif key==K_LEFT:
        block.move_left()
    elif key==K_RIGHT:
        block.move_right()
    elif key==K_DOWN:
        block.move_down()
    else:
        print("ERROR")

def Check_Stage(Stage):
    is_full = False
    lower_rows = [blocks for blocks in Stage.sprites() if blocks.rect.bottom==400]
    if len(lower_rows) == 8:
        is_full = True
    return is_full,lower_rows

def clear_row(Stage,lower_rows):
    Stage.remove(lower_rows)
    for block in Stage:
        block.isdead=False
        block.move_down()
        print(block.rect.bottom)

class Block(pygame.sprite.Sprite):
    def __init__(self,filename,x,y,Stage):
        pygame.sprite.Sprite.__init__(self)
        self.image = pygame.image.load(filename).convert_alpha()
        self.image = pygame.transform.scale(self.image,(50,50))
        self.rect = self.image.get_rect()
        self.rect.center = (x+25,y+25)
        self.stage = Stage
        self.isdead = False
        
    def move_left(self):
        if self.rect.left  >= 50:
            self.rect.move_ip(-50,0)
    def move_right(self):
        if self.rect.right <= 350:
            self.rect.move_ip(50,0)
    def move_down(self):
        for sblock in self.stage.sprites():
            if (self.rect.right == sblock.rect.right) and (self.rect.bottom == sblock.rect.top):
                self.isdead = True
        if (self.rect.bottom > 350):
            self.isdead = True
        if self.isdead == False:
            self.rect.move_ip(0,50)
    def move_dfast(self):
        while(self.isdead==False):
            self.move_down()

title = "TETRIS"
pygame.init()
SCREEN = Rect(0, 0, 400, 400)
screen = pygame.display.set_mode(SCREEN.size)
pygame.display.set_caption(title)

Stage = pygame.sprite.RenderUpdates()

block = Block("test.png",150,0,Stage)
b_group = pygame.sprite.RenderUpdates()
b_group.add(block)
b_group.update()

clock = pygame.time.Clock()
while (1):
    clock.tick(30)
    # イベント処理
    for event in pygame.event.get():
        if event.type == QUIT:  # 閉じるボタンが押されたら終了
            pygame.quit()       # Pygameの終了(画面閉じられる)
            sys.exit()
        elif event.type == KEYDOWN:
            key_handle(event.key,block,b_group)
            if b_group.sprites()[0].isdead:
                Stage,b_group,block = Next_Ball(b_group,Stage)
                is_full,lower_rows = Check_Stage(Stage)
                if is_full:
                    clear_row(Stage,lower_rows)

    screen.fill((255,255,255))
    b_group.draw(screen)
    Stage.draw(screen)
    pygame.display.update()
