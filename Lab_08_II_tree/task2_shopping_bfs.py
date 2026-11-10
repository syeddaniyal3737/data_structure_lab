from collections import deque


class Node:
    def __init__(self, category):
        self.category = category
        self.left = None
        self.right = None


def bfs(root):
    if root is None:
        return []

    categories = []
    queue = deque([root])

    while queue:
        current = queue.popleft()
        categories.append(current.category)

        if current.left:
            queue.append(current.left)
        if current.right:
            queue.append(current.right)

    return categories


shopping_root = Node("Electronics")
shopping_root.left = Node("Clothing")
shopping_root.right = Node("Mobiles")
shopping_root.left.left = Node("Men")
shopping_root.left.right = Node("Women")
shopping_root.right.left = Node("Laptops")
shopping_root.right.right = Node("Accessories")

print("TASK 2: ONLINE SHOPPING CATEGORIES - BFS")
print("BFS Order:", " -> ".join(bfs(shopping_root)))
