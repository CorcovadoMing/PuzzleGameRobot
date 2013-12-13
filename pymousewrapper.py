from Quartz.CoreGraphics import *

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
    mouseEvent(kCGEventLeftMouseDown, start_posx, start_posy)
    mouseMove(end_posx, end_posy)
    mouseEvent(kCGEventLeftMouseUp, end_posx, end_posy)
    
def getLocation():
    ourEvent = CGEventCreate(None)
    currentpos = CGEventGetLocation(ourEvent)
    return currentpos.x, currentpos.y
    