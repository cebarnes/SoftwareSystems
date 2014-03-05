import pymongo
from pymongo import MongoClient


client = MongoClient()
db = client.text_database
collection = db.test_collection
posts = db.posts

def main():
    doc =  {'name': 'Kevin Bacon',
            'movies': ['Animal House', 'Apollo 13']}
    t = []
    t.append(doc)

    upload_data(posts, t)
    print db.collection_names()

def upload_data(docs, t):
    for doc in t:
        post_id = docs.insert(doc)
    return docs


if __name__ == '__main__':
    main()