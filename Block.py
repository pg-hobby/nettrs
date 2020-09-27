import numpy as np

class Block():
    def __init__(self, Stage):
        self.Sstage = Stage
        self.Dstage = np.zeros_like(Stage)
        self.Dstage[0, 0] = 1
        self.isdead = False

    def move_left(self):
        if np.where(self.Dstage == 1)[1][0] == 0:
            return self.Sstage + self.Dstage
        self.Dstage = np.roll(self.Dstage, -1, axis=1)
        tmp = self.Sstage + self.Dstage
        if np.any(tmp == 2):
            self.Dstage = np.roll(self.Dstage, 1, axis=1)
        return self.Sstage + self.Dstage

    def move_right(self):
        if np.where(self.Dstage == 1)[1][0] == 7:
            return self.Sstage + self.Dstage
        self.Dstage = np.roll(self.Dstage, 1, axis=1)
        tmp = self.Sstage + self.Dstage
        if np.any(tmp == 2):
            self.Dstage = np.roll(self.Dstage, -1, axis=1)
        return self.Sstage + self.Dstage

    def move_down(self):
        if np.where(self.Dstage == 1)[0][0] == 7:
            self.isdead = True
            self.Sstage += self.Dstage
            return self.Sstage
        self.Dstage = np.roll(self.Dstage, 1, axis=0)
        tmp = self.Sstage + self.Dstage
        if np.any(tmp == 2):
            self.Dstage = np.roll(self.Dstage, -1, axis=0)
            self.isdead = True
            self.Sstage += self.Dstage
            return self.Sstage
        return self.Sstage + self.Dstage
