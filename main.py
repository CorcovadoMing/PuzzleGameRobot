import os, sys, time
lib_path = os.path.abspath('./module')
sys.path.append(lib_path)
from pymousewrapper import *
from shell import *
from screencapture import *
from imageprocess import *

offsetx = (1108-698)/12
offsety = (668-326)/10
first_pointx = 698 + offsetx
first_pointy = 326 + offsety
offsetx *= 2
offsety *= 2

def run(path):
    mouseClick(800, 30) # focus windows
    curx, cury = first_pointx, first_pointy
    mouseClickDown(curx, cury)
    time.sleep(0.8)
    for move in path:
        if move == '0':
            mouseMove(curx+offsetx, cury)
            curx, cury = curx+offsetx, cury
        elif move == '1':
            mouseMove(curx, cury+offsety)
            curx, cury = curx, cury+offsety
        elif move == '2':
            mouseMove(curx-offsetx, cury)
            curx, cury = curx-offsetx, cury
        elif move == '3':
            mouseMove(curx, cury-offsety)
            curx, cury = curx, cury-offsety
        else:
            print 'ERROR'
    mouseClickUp(curx, cury)

if __name__ == '__main__':   
    shot()
    color_map = get_color_map()
    command = ['puzzle']
    color = [x for x in color_map.split(' ')]
    for x in color:
        command.append(x)
    out, err = shell_command(command)
    output = [x for x in out.split(' ')]
    output.pop()
    run(output)