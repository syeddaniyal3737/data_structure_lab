class Node:
    def __init__(self, token):
        self.token = token
        self.left = None
        self.right = None
        self.height = 1


def height(node):
    return node.height if node else 0


def balance_factor(node):
    return height(node.left) - height(node.right) if node else 0


def update_height(node):
    node.height = 1 + max(height(node.left), height(node.right))


def right_rotate(unbalanced):
    new_root = unbalanced.left
    transferred_subtree = new_root.right

    new_root.right = unbalanced
    unbalanced.left = transferred_subtree

    update_height(unbalanced)
    update_height(new_root)
    return new_root


def left_rotate(unbalanced):
    new_root = unbalanced.right
    transferred_subtree = new_root.left

    new_root.left = unbalanced
    unbalanced.right = transferred_subtree

    update_height(unbalanced)
    update_height(new_root)
    return new_root


def insert(root, token):
    if root is None:
        return Node(token)

    if token < root.token:
        root.left = insert(root.left, token)
    elif token > root.token:
        root.right = insert(root.right, token)
    else:
        return root

    update_height(root)
    balance = balance_factor(root)

    # LL case
    if balance > 1 and token < root.left.token:
        return right_rotate(root)

    # RR case
    if balance < -1 and token > root.right.token:
        return left_rotate(root)

    # LR case
    if balance > 1 and token > root.left.token:
        root.left = left_rotate(root.left)
        return right_rotate(root)

    # RL case
    if balance < -1 and token < root.right.token:
        root.right = right_rotate(root.right)
        return left_rotate(root)

    return root


def inorder(root, result):
    if root:
        inorder(root.left, result)
        result.append(root.token)
        inorder(root.right, result)


def display_tree(root, level=0, position="Root"):
    if root is None:
        return

    print(
        "    " * level
        + f"{position}: {root.token} "
        + f"(Height={root.height}, Balance Factor={balance_factor(root)})"
    )
    display_tree(root.left, level + 1, "Left")
    display_tree(root.right, level + 1, "Right")


tokens = [15, 25, 35, 45, 55, 65, 75]
avl_root = None

for token in tokens:
    avl_root = insert(avl_root, token)

inorder_result = []
inorder(avl_root, inorder_result)

print("TASK 4: HOSPITAL APPOINTMENT SYSTEM - AVL TREE")
print("In-order Traversal:", " -> ".join(map(str, inorder_result)))
print("\nFinal Balanced AVL Tree:")
display_tree(avl_root)
