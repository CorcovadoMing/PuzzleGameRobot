from Quartz.CoreGraphics import *
import time 

def mouseEvent(type, posx, posy):
    theEvent = CGEventCreateMouseEvent(
                None,
                type,
                (posx, posy),
                kCGMouseButtonLeft)
    CGEventPost(kCGHIDEventTap, theEvent)

def mouseMove(posx, posy):
    mouseEvent(kCGEventMouseMoved, posx, posy);

def mouseClick(posx, posy):
    mouseEvent(kCGEventLeftMouseDown, posx,posy);
    mouseEvent(kCGEventLeftMouseUp, posx,posy);

def mouseDrag(start_posx, start_posy, end_posx, end_posy):
    time.sleep(.1)
    mouseEvent(kCGEventLeftMouseDown, start_posx, start_posy)
    time.sleep(.5)
    mouseMove(end_posx, end_posy)
    time.sleep(.5)
    mouseEvent(kCGEventLeftMouseUp, end_posx, end_posy)
    
def getLocation():
    ourEvent = CGEventCreate(None)
    currentpos = CGEventGetLocation(ourEvent)
    return currentpos.x, currentpos.y
    