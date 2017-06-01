#!/usr/bin/python

import re

def find_all_vocab(file_name):
    with open(file_name) as f:
        lines = [line for line in f]
    # print lines

    p = re.compile("([\w]+)")
    vocab = {}
    for line in lines:
        for key in  p.findall(line):
            vocab[key.lower()]=1
    
    ls_vocab = []
    for key in vocab:
        ls_vocab.append(key.lower())
    
    ls_vocab.sort()
    print len(ls_vocab)

    for key in ls_vocab:
        print key
    

find_all_vocab("/home/spider/Documents/search_string.txt")
