
class Node:
    def __init__(self, name=None, isLeaf=None, wordNum=0, leafs=None):
        self.name = name
        self.isLeaf = isLeaf
        self.wordNum = wordNum
        self.leafs = leafs

    def __str__(self):
        return self.leafs

class Tire:
    def __init__(self):
        self.root = Node("root", False, 0, {})

    def create_trie(self):
        position = self.root
        file = open("./test_data.txt", 'r')
        for line in file:
            words = line.split(" ")
            for word in words:
                for c in word:
                    if c == '\n':break
                    if c not in position.leafs:
                        position.leafs[c] = Node(c, False, 1, {})
                    else:
                        position.leafs[c].wordNum += 1
                    position = position.leafs[c]
                position.isLeaf = True
                position = self.root

if __name__ == '__main__':
    trie = Tire()
    trie.create_trie()

