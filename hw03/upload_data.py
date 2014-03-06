import pymongo
from pymongo import MongoClient
import re
from parser2 import create_docs, separate_docs


client = MongoClient()
db = client.test_database
collection = db.test_collection
posts = db.posts


def upload_data(docs, t):
    for i in range(t):  
        # post_id = posts.insert(t[i])
        print t[i]


a,b = create_docs('actresses.txt')
name_to_mov = separate_docs(a, u'name', u'movies')
mov_to_name = separate_docs(b, u'movie', u'actors')

posts.insert(name_to_mov)
posts.insert(mov_to_name)

posts.find_one(name="Aaliyah")