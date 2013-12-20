import os, sys, time
lib_path = os.path.abspath('./module')
sys.path.append(lib_path)
from pymousewrapper import *
from shell import *
from screencapture import *

def run():
    time.sleep(1)
    mouseClick(847.2890625, 382.8671875)
    time.sleep(1)
    mouseDrag(847.2890625, 382.8671875,847.2890625, 449.59765625)
    #mouseDrag(847.2890625, 449.59765625,770.55078125, 449.59765625)
    #mouseDrag(770.55078125, 449.59765625,771.59375, 376.55859375)
    #mouseDrag(770.55078125, 449.59765625,847.2890625, 382.8671875)

if __name__ == '__main__':   
    shot()
    out = shell_command(['/opt/local/bin/python2.7', './module/imageprocess.py'])
    print out
    out = shell_command(['puzzle'])
    output = [x for x in out.split(' ')]
    output.pop()
    print output
    print len(output)