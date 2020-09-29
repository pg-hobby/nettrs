from pygame.locals import * 

def key_handle(key, block):
    if key == K_SPACE:
        return block.move_dfast()
    elif key == K_LEFT:
        return block.move_left()
    elif key == K_RIGHT:
        return block.move_right()
    elif key == K_DOWN:
        return block.move_down()
    elif key == -1:
	    return block.Sstage, block.Dstage
    else:
        print("Invalid key")
        return block.Sstage, block.Dstage
