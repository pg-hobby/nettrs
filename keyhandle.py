from pygame.locals import * 

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

