import numpy as np

shape = [
    np.array([[1, 0], [0, 1]]),
    np.array([[1, 1], [1, 0]])
    ]

class Block():
    def __init__(self, Stage):
        self.Sstage = Stage
        self.shape = shape[np.random.choice(len(shape))]
        self.row = 0
        self.col = 0
        self.Dstage = np.zeros_like(Stage)
        self.Dstage[self.row: self.row + 2, self.col: self.col + 2] = self.shape.copy()
        self.isdead = False
        self.isGO = False
        if self.Sstage[0][0] == 1:
            self.isGO = True

    def rotate(self):
        def rot_arr(arr, col, row):
            tmp = arr.copy()
            arr[0, 0] = arr[1, 0]
            arr[1, 0] = arr[1, 1]
            arr[1, 1] = arr[0, 1]
            arr[0, 1] = tmp[0, 0]
            nextblk = np.zeros_like(self.Dstage)
            nextblk[row: row + 2, col: col + 2] = arr
            return nextblk
        nextblk = rot_arr(self.shape, self.col, self.row)
        if np.any(nextblk + self.Sstage == 2):
            return self.Sstage, self.Dstage
        else:
            self.Dstage = nextblk
            return self.Sstage, self.Dstage

    def move_left(self):
        nextblk = np.roll(self.Dstage, -1, axis=1)
        # Game over
        if self.Sstage[0][0] == 1:
            return np.zeros_like(self.Sstage), np.zeros_like(self.Sstage)
        # check wall
        elif self.col == 0:
            if np.any(self.Dstage[self.row: self.row+2, self.col]):
                return self.Sstage, self.Dstage
            else:
                self.Dstage = nextblk
                return self.Sstage, self.Dstage
        # check current block
        elif np.any(nextblk + self.Sstage == 2):
            return self.Sstage, self.Dstage
        # can move
        else:
            self.Dstage = nextblk
            self.col = self.col - 1;
            return self.Sstage, self.Dstage

    def move_right(self):
        nextblk = np.roll(self.Dstage, 1, axis=1)
        # Game over
        if self.Sstage[0][0] == 1:
            return np.zeros_like(self.Sstage), np.zeros_like(self.Sstage)
        # check wall
        elif self.col == 6:
            if np.any(self.Dstage[self.row: self.row + 2, self.col + 1]):
                return self.Sstage, self.Dstage
            else:
                self.Dstage = nextblk
                return self.Sstage, self.Dstage
        # check current block
        elif np.any(nextblk + self.Sstage == 2):
            return self.Sstage, self.Dstage
        # can move
        else:
            self.Dstage = nextblk
            self.col = self.col + 1
            return self.Sstage, self.Dstage

    def move_down(self):
        nextblk = np.roll(self.Dstage, 1, axis=0)
        if np.where(nextblk == 1)[0][0] == 0:
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
            self.row = self.row + 1
            return self.Sstage, self.Dstage

    def move_dfast(self):
        while(self.isdead == False):
          self.move_down()
        return self.Sstage, np.zeros_like(self.Sstage)
