import re
# name = line[0].strip().split('|')
# name2 = name[0].split(',')
# first = name2[1].strip()
# last = name2[0].strip()
# title = name[1].strip()

def something(filename):
    f = open(filename, 'r')
    for line in f.readlines():
        d = {}
        items = line.split('|')
        print items
        
        # Get Names
        names = items[0].split(',')
        last = re.sub(r'\(.*?\)', '', names[0]).strip()
        if len(names) > 1:
            first = re.sub(r'\(.*?\)', '', names[1]).strip()
            name = first + ' ' + last
        else:
            name = last
        d['name'] = name




something('actresses.txt') 
