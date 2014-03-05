filename = 'actresses.txt'

f = open(filename, 'r')

line = f.readlines()

name = line[0].strip().split('|')
name2 = name[0].split(',')
first = name2[1].strip()
last = name2[0].strip()
title = name[1].strip()
print first, last, title
