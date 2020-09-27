import numpy as np

class Block():
    def __init__(self, Stage):
        self.Sstage = Stage
        self.Dstage = np.zeros_like(Stage)
        self.Dstage[0, 0] = 1
        self.isdead = False

    def move_left(self):
        if np.where(self.Dstage == 1)[1][0] == 0:
            return
        self.Dstage = np.roll(self.Dstage, -1, axis=1)
        print(self.Dstage)

    def move_right(self):
        if np.where(self.Dstage == 1)[1][0] == 7:
            return
        self.Dstage = np.roll(self.Dstage, 1, axis=1)
        print(self.Dstage)

    def move_down(self):
            return
        if np.where(self.Dstage == 1)[0][0] == 7:
        self.Dstage = np.roll(self.Dstage, 1, axis=0)
        print(self.Dstage)
