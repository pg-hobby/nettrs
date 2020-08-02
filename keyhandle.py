from pygame.locals import * 
from pygase import Client

def key_handle(key):
    if key==K_SPACE:
        client.dispatch_event("K_SPACE")
    elif key==K_LEFT:
        client.dispatch_event("K_LEFT")
    elif key==K_RIGHT:
        client.dispatch_event("K_RIGHT")
    elif key==K_DOWN:
        client.dispatch_event("K_DOWN")
    else:
        print("ERROR")

