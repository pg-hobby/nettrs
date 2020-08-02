import pygame

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


