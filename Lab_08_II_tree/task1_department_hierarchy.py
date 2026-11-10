class Node:
    def __init__(self, name):
        self.name = name
        self.left = None
        self.right = None


def display_hierarchy(root):
    if root is None:
        return

    left_child = root.left.name if root.left else "None"
    right_child = root.right.name if root.right else "None"
    print(f"{root.name}: Left = {left_child}, Right = {right_child}")

    display_hierarchy(root.left)
    display_hierarchy(root.right)


department_root = Node("HOD Dr. Ahmed")
department_root.left = Node("Coordinator Dr. Fatima")
department_root.right = Node("Coordinator Dr. Bilal")
department_root.left.left = Node("Prof. Hassan")
department_root.left.right = Node("Prof. Ayesha")
department_root.right.left = Node("Prof. Usman")
department_root.right.right = Node("Prof. Sara")

print("TASK 1: UNIVERSITY DEPARTMENT HIERARCHY")
display_hierarchy(department_root)
