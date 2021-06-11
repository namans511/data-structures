class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def printList(head):
    ptr = head
    while ptr is not None:
        print(ptr.data, end=" ")
        ptr = ptr.next
    print()

def getLength(node):
        c=0
        while node:
            c+=1
            node=node.next
        return c

def putZeroes(first, second):
    l1 = getLength(first)
    l2 = getLength(second)
    if l1 == l2:
        return first, second
    small = first if l1<l2 else second
    large = second if l1<l2 else first

    n = abs(l1-l2)
    prev=Node(0)
    head = prev
    while n-1 > 0:
        node = Node(0)
        prev.next = node
        prev = node
        n -= 1
    prev.next = small
    return head, large


























