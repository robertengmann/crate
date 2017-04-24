# Dynamic programming fibonacci
def fib(n):
    if n in [0, 1]:
        return n
    
    mem = [0, 1]
    
    for i in xrange(2, n):
        mem.append(mem[i-1] + mem[i-2])
        
    return mem[n-1] + mem[n-2]

print fib(59)


# Binary search
def binary_search(a, x):
    low = 0
    high = len(a) - 1
    mid = -1
    
    while low <= high:
        mid = (low + high) / 2
        
        if a[mid] < x:
            low = mid + 1
        elif a[mid] > x:
            high = mid - 1
        else:
            return mid
        
    return -1

print binary_search([1, 2, 3], 1)


# LinkedList
class ListNode:
    
    def __init__(self, data=0, next_node=None):
        self.data = data
        self.next = next_node
    
    def __repr__(self):
        s = ''
        n = self
        
        while n.next != None:
            s += "%s;" % n.data
            n = n.next
        s += str(n.data)
        
        return s
        
    def search_list(self, key):
        n = self
        
        while n and n.data != key:
            n = n.next
            
        return n
    
    def append(self, data):
        n = self
        
        while n.next != None:
            n = n.next
        
        n.next = ListNode(data)
        
    def delete(self, data):
        n = self
        
        if n.data == data:
            return n.next
        
        while n.next != None:
            if n.next.data == data:
                n.next = n.next.next
                return self
            n = n.next
            
        return self
        
        
l = ListNode(14)
l.append(15)
l.append(16)
l.delete(15)

print l


# Stack
class EmptyStackException(Exception):
    pass

class StackNode:
    
    def __init__(self, item=None):
        self.data = item
        self.next = None
        self.top = None
        
    def pop(self):
        if self.top == None:
            raise EmptyStackException()
        
        item = self.top.data
        self.top = self.top.next
        
        return item
    
    def push(self, item):
        node = StackNode(item)
        node.next = self.top
        self.top = node
        
    def peek(self):
        if self.top == None:
            raise EmptyStackException()
            
        return self.top.data
    
    def is_empty(self):
        return self.top == None
    
    
s = StackNode()
s.push(12)
print s.peek()
s.push(111)
print s.peek()
print s.pop()
print s.pop()
print s.is_empty()


# Queue
class NoSuchElementException(Exception):
    pass

class QueueNode:
    
    def __init__(self, data=None):
        self.data = data
        self.next = None
        self.first = None
        self.last = None
        
    def add(self, item):
        node = QueueNode(item)
        
        if self.last != None:
            self.last.next = node
        
        self.last = node
        
        if self.first == None:
            self.first = self.last
            
    def remove(self):
        if self.first == None:
            raise NoSuchElementException()
        
        data = self.first.data
        self.first = self.first.next
        
        if self.first == None:
            self.last = None
            
        return data
    
    def peek(self):
        if self.first == None:
            raise NoSuchElementException()
        
        return self.first.data
    
    def is_empty(self):
        return self.first == None
    
    
q = QueueNode()
q.add(14)
q.add(15)
q.add(16)

print q.peek()
q.remove()
print q.peek()


# BinarySearchTree
class BinarySearchTreeNode:
    
    def __init__(self, data=None, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right
        
    def visit(self):
        print self.data
    
def insert(tree, item):
    if item < tree.data:
        if tree.left != None:
            insert(tree.left, item)
        else:
            tree.left = BinarySearchTreeNode(item)
    else:
        if (tree.right != None):
            insert(tree.right, item)
        else:
            tree.right = BinarySearchTreeNode(item)
    
    
def in_order_traversal(node):
    if node != None:
        in_order_traversal(node.left)
        node.visit()
        in_order_traversal(node.right)
    
    
def pre_order_traversal(node):
    if node != None:
        node.visit()
        pre_order_traversal(node.left)
        pre_order_traversal(node.right)

    
def post_order_traversal(node):
    if node != None:
        post_order_traversal(node.left)
        post_order_traversal(node.right)
        node.visit()

        
b = BinarySearchTreeNode(10)
insert(b, 29)
insert(b, 2)
in_order_traversal(b)
print "---"
pre_order_traversal(b)
print "---"
post_order_traversal(b)
