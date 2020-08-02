import math
from pygase import Gamestate, Backend
from Block import Block
from pygame.locals import * 
import pygame

Stage = pygame.sprite.RenderUpdates()
block = Block("test.png",150,0,Stage)
b_group = pygame.sprite.RenderUpdates()
b_group.add(block)
b_group.update()
initial_game_state = GameState(Stage=Stage,b_group=b_group ,block = block)

def time_step(game_state,dt):
    ## update gamestatus by time
    pass

def key_space(game_state):
    game_state.block.move_dfast()
    print("space")

def key_down(game_state):
    game_state.block.move_down()
    print("down")

def key_left(game_state):
    game_state.block.move_left()
    print("left")

def key_right(game_state):
    game_state.block.move_right()
    print("right")

def key_quit(game_state):
    print("quit")
    pass

backend = Backend(
        initial_game_state,
        time_step,
        event_handlers={"K_SPACE":key_space,
                        "K_DOWN":key_down,
                        "K_RIGHT":key_right,
                        "K_LEFT":key_left,
                        "K_QUIT":key_quit
                        }
       )

if __name__ == "__main__":
    backend.run('localhost', 8080)
