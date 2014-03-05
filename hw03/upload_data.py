import pymongo
from pymongo import MongoClient

"""
Takes a
"""
def make_collection(datab, t):

    posts = datab.posts

    for doc in t:
        post_id = post.insert(doc)

    return datab

doc =  {'name': 'Kevin Bacon',
               'movies': ['Animal House', 'Apollo 13']}

client = MongoClient
db = client.test_database
collection = db.test_collection
post_id = post.insert(doc)

# def main():
#     example_doc =  {'name': 'Kevin Bacon',
#                     'movies': ['Animal House', 'Apollo 13']}

#     doc2 = {'name': 'Jeremy Sumpter',
#             'movies': 'Peter Pan'}

#     t = []
#     t.append(example_doc)
#     t.append(doc2)

#     client = MongoClient
#     db = client.test_database
#     collection = db.test_collection

#     newdb = make_collection(t)
#     print db.collection_names()

if __name__ == '__main__':
    main()

# print(posts.find_one({'movies': 'Animal House'}))
