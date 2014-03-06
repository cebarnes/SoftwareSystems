import re

def create_docs(filename):
    f = open(filename, 'r')
    name_to_mov = {}
    mov_to_name = {}

    for line in f.readlines():
        try:
            line.decode('utf-8').encode('utf-8')
        except UnicodeDecodeError:
            # print "Could not decode line %s" % line
            continue
        items = line.split('|')

        # Get Names
        names = items[0].split(',')
        last = re.sub(r'\(.*?\)', '', names[0]).strip()
        if len(names) > 1:
            first = re.sub(r'\(.*?\)', '', names[1]).strip()
            name = first + ' ' + last
        else:
            name = last

        # Get Movie
        movie = items[1].strip()

        # # Get Year
        year = int(items[2].replace('(', '').replace(')', ''))

        # # Get Role
        role = items[3].replace('[', '').replace(']','').strip()

        # Add/Update dictionary name --> movies
        if name in name_to_mov.keys():
            name_to_mov[name] += [movie]
        else:
            name_to_mov[name] = [movie] 

        # Add/Update dictionary movie --> names
        if movie in mov_to_name.keys():
            mov_to_name[movie] += [name]
        else:
            mov_to_name[movie] = [name]

    return name_to_mov, mov_to_name

def separate_docs(d , s1, s2):
    list_of_dicts = []
    for key in d:
        list_of_dicts.append({s1:key, s2: d[key]})
    return list_of_dicts

if __name__ == '__main__':
    a,b = create_docs('actresses.txt') 
    print separate_docs(a, 'movies')
