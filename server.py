import math
from pygase import Gamestate, Backend
from keyhandle import key_handle
from Block import Block


Stage = pygame.sprite.RenderUpdates()
block = Block("test.png",150,0,Stage)
b_group = pygame.sprite.RenderUpdates()
b_group.add(block)
b_group.update()
initial_game_state = GameState(Stage=Stage,b_group=b_group ,block = block)

def time_step(game_state,dt):
    ## update gamestatus by time
    pass

def key_space():
    print("space")

def key_down():
    print("down")

def key_left():
    print("left")

def key_right():
    print("right")

def key_quit():
    print("quit")


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
