import subprocess

def shell_command(data): # data is an array
    p = subprocess.Popen(data, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    out, err = p.communicate()
    return out

if __name__ == '__main__':
    data = ['a']
    dataclone = [str(x) for x in xrange(4)]
    for d in dataclone:
        data.append(d)
    print data

    out = shell_command(data)

    output = [x for x in out.split('\n')]
    print output