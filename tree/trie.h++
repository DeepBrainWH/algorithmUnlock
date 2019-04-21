//
// Created by wangheng on 3/21/19.
//

#ifndef ALGORITHMUNLOCK_TRIE_H
#define ALGORITHMUNLOCK_TRIE_H

#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode(char, int, bool);

    ~TrieNode() = default;

    char name;
    int countNum;
    bool isLeaf;
    TrieNode *map = new TrieNode[26];
};

TrieNode::TrieNode(char name, int countNum, bool isLeaf) {
    this->name = name;
    this->countNum = countNum;
    this->isLeaf = isLeaf;
}

class Trie {
public:
    Trie() = default;

    ~Trie() = default;

    TrieNode *root = new TrieNode(NULL, 0, false);
};


#endif //ALGORITHMUNLOCK_TRIE_H
