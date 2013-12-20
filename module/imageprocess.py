from __future__ import print_function
import Image

def cluster(r, g, b):
    if r in range(70, 160) and g in range(0, 50): return 0 # red
    elif r in range(70, 160) and g in range(50, 120): return 1 # yellow
    elif g in range(170, 230) and b in range(0, 100): return 2 # green
    elif r in range(0, 70) and b in range(60, 256) and g in range(60, 256): return 3 # blue
    elif r in range(200, 256) and b in range(100, 200): return 4 # heart
    else: return 5 # purple


def get_color_map():
    offsetx = (1108-698)/12
    offsety = (668-326)/10

    first_pointx = 698 + offsetx
    first_pointy = 326 + offsety

    offsetx *= 2
    offsety *= 2
    
    result = []
    
    for row in range(5):
        puzzle_map = [(first_pointx, first_pointy+row*offsety)]
        for num in xrange(5):
            puzzle_map.append((puzzle_map[num][0]+offsetx, puzzle_map[num][1]))

        puzzle_map_color_point = [(x-698, y-326) for (x, y) in puzzle_map]

        im = Image.open("puzzle.png")
        pix = im.load()
    
        puzzle_map_color = []
        for (x, y) in puzzle_map_color_point:
            puzzle_map_color.append(pix[x, y]) 
    
        for (r, g, b) in puzzle_map_color:
            result.append(cluster(r, g, b))
            
    return ' '.join([str(x) for x in result])

if __name__ in '__main__':
    print(get_color_map(), end='')