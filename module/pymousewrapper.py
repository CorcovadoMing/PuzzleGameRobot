from Quartz.CoreGraphics import CGEventCreateMouseEvent
from Quartz.CoreGraphics import kCGMouseButtonLeft
from Quartz.CoreGraphics import kCGHIDEventTap
from Quartz.CoreGraphics import kCGEventMouseMoved
from Quartz.CoreGraphics import kCGEventLeftMouseDown
from Quartz.CoreGraphics import kCGEventLeftMouseUp
from Quartz.CoreGraphics import CGEventCreate
from Quartz.CoreGraphics import CGEventGetLocation
from Quartz.CoreGraphics import CGEventPost
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
    