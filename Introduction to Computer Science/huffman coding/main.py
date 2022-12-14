import heapq
import string

# 3 points

# example messages from class:
# ToXToooTTXXooooX
# .....@@@@@@@$$.$.$.$$........@
# ABCDEFGHIJKLMNOPRSTUWVXYZ
# 112210101211013101110213331001203100100123300

ALPHABET = string.printable
message = input("type in your message: ")
value_table = []


class Node:
    def __init__(self, frequency, symbol, left=None, right=None):
        self.freq = frequency
        self.symbol = symbol
        self.left = left
        self.right = right

        # tree direction (0/1)
        self.direction = ''

    def __lt__(self, nxt):
        return self.freq < nxt.freq


def printNodes(node, val=''):
    # huffman code for current node
    new_value = val + str(node.direction)
    # if not an edge node, traverse inside it
    if node.left:
        printNodes(node.left, new_value)
    if node.right:
        printNodes(node.right, new_value)

    # display the code for an edge node
    if not node.left and not node.right:
        print(f"{node.symbol} -> {new_value}")
        value_table.append(new_value)


letterCount = {}
for i in range(len(ALPHABET)):
    x = message.count(ALPHABET[i])
    if x:
        letterCount.update({ALPHABET[i]: x})

sortedCount = sorted(letterCount.items(), key=lambda z: z[1])

print("number of recurring characters: " + str(sortedCount))
chars = []
freq = []

for i in range(len(sortedCount)):
    chars.append(sortedCount[i][0])
    freq.append(sortedCount[i][1])

# list containing unused nodes
nodes = []

# converting characters and frequencies
# into huffman tree nodes
for x in range(len(chars)):
    heapq.heappush(nodes, Node(freq[x], chars[x]))

while len(nodes) > 1:
    # sort all the nodes in ascending order
    # based on their frequency
    leftBranch = heapq.heappop(nodes)
    rightBranch = heapq.heappop(nodes)

    # assign directional value to these nodes
    leftBranch.direction = 0
    rightBranch.direction = 1

    # combine the 2 smallest nodes to create
    # new node as their parent
    newNode = Node(leftBranch.freq + rightBranch.freq, leftBranch.symbol + rightBranch.symbol, leftBranch, rightBranch)

    heapq.heappush(nodes, newNode)

printNodes(nodes[0])

dic = {}

for i in range(len(nodes[0].symbol)):
    dic[nodes[0].symbol[i]] = value_table[i]

table = message.maketrans(dic)
print("coded message: " + '\033[94m' + message.translate(table) + '\033[0m')
