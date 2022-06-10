# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
def compare(root1, root2):
    if((root1 is None and root2 is not None) or (root2 is None and root1 is not None) ):
        return False
        
    if root1:
        if(not (root1.value == root2.value) ):
            return False
            
        return compare(root1.left, root2.left) and compare(root1.right, root2.right)

    else:
        return True
        
def swap_children(root):
    if root:
        swap_children(root.left)
        swap_children(root.right)
        temp = root.left
        root.left = root.right
        root.right = temp

def isTreeSymmetric(t):
    if(t == None):
        return True

    swap_children(t.right)
    
    return compare(t.left, t.right)