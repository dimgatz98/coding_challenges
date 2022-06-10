# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
def hasPathWithGivenSum(t, s):
    if t is None:
        return False
    
    # Create a queue for BFS
    queue = []

    # Mark the source node as
    # visited and enqueue it
    queue.append((t, t.value))
    
    while queue:
        # Dequeue a vertex from
        # queue and print it
        n = queue.pop(0)
        if n[1] == s and n[0].left is None and n[0].right is None:
                return True
                
        # Get all adjacent vertices of the
        # dequeued vertex s. If a adjacent
        # has not been visited, then mark it
        # visited and enqueue it
        if n[0].left:
            queue.append((n[0].left, n[1] + n[0].left.value))
            
        if n[0].right:                
            queue.append((n[0].right, n[1] + n[0].right.value))
            
    return False