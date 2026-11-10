class Node:
    def __init__(self, folder):
        self.folder = folder
        self.left = None
        self.right = None


def inorder(root, result):
    if root:
        inorder(root.left, result)
        result.append(root.folder)
        inorder(root.right, result)


def preorder(root, result):
    if root:
        result.append(root.folder)
        preorder(root.left, result)
        preorder(root.right, result)


def postorder(root, result):
    if root:
        postorder(root.left, result)
        postorder(root.right, result)
        result.append(root.folder)


file_root = Node("Computer")
file_root.left = Node("Documents")
file_root.right = Node("Downloads")
file_root.left.left = Node("Assignments")
file_root.left.right = Node("Projects")
file_root.right.left = Node("Images")
file_root.right.right = Node("Videos")

inorder_result = []
preorder_result = []
postorder_result = []
inorder(file_root, inorder_result)
preorder(file_root, preorder_result)
postorder(file_root, postorder_result)

print("TASK 3: COMPUTER FILE EXPLORER - DFS")
print("In-order   :", " -> ".join(inorder_result))
print("Pre-order  :", " -> ".join(preorder_result))
print("Post-order :", " -> ".join(postorder_result))
