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
    time.sleep(0.09)
    mouseEvent(kCGEventMouseMoved, posx, posy);

def mouseClickDown(posx, posy):
    mouseEvent(kCGEventLeftMouseDown, posx,posy);

def mouseClickUp(posx, posy):
    mouseEvent(kCGEventLeftMouseUp, posx,posy);

def mouseClick(posx, posy):
    mouseClickDown(posx, posy)
    mouseClickUp(posx, posy)

def getLocation():
    ourEvent = CGEventCreate(None)
    currentpos = CGEventGetLocation(ourEvent)
    return currentpos.x, currentpos.y
    