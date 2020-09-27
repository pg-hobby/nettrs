import numpy as np

class Block():
    def __init__(self, Stage):
        self.Sstage = Stage
        self.Dstage = np.zeros_like(Stage)
        self.Dstage[0, 0] = 1
        self.isdead = False

    def move_left(self):
        nextblk = np.roll(self.Dstage, -1, axis=1)
        # Game over
        if self.Sstage[0][0] == 1:
            return np.zeros_like(self.Sstage), np.zeros_like(self.Sstage)
        # check wall
        elif np.where(nextblk == 1)[1][0] == 7:
            return self.Sstage, self.Dstage
        # check current block
        elif np.any(nextblk + self.Sstage == 2):
            return self.Sstage, self.Dstage
        # can move
        else:
            self.Dstage = nextblk
            return self.Sstage, self.Dstage

    def move_right(self):
        nextblk = np.roll(self.Dstage, 1, axis=1)
        # Game over
        if self.Sstage[0][0] == 1:
            return np.zeros_like(self.Sstage), np.zeros_like(self.Sstage)
        # check wall
        elif np.where(nextblk == 1)[1][0] == 0:
            return self.Sstage, self.Dstage
        # check current block
        elif np.any(nextblk + self.Sstage == 2):
            return self.Sstage, self.Dstage
        # can move
        else:
            self.Dstage = nextblk
            return self.Sstage, self.Dstage

    def move_down(self):
        nextblk = np.roll(self.Dstage, 1, axis=0)
        # Game over
        if self.Sstage[0][0] == 1:
            return np.zeros_like(self.Sstage), np.zeros_like(self.Sstage)
        # check wall
        elif np.where(nextblk == 1)[0][0] == 0:
            self.isdead = True
            self.Sstage += self.Dstage
            return self.Sstage, np.zeros_like(self.Sstage)
        # check current block
        elif np.any(nextblk + self.Sstage == 2):
            self.isdead = True
            self.Sstage += self.Dstage
            return self.Sstage, np.zeros_like(self.Sstage)
        # can move
        else:
            self.Dstage = nextblk
            return self.Sstage, self.Dstage

    def move_dfast(self):
        while(self.isdead == False):
          self.move_down()
        return self.Sstage, np.zeros_like(self.Sstage)
