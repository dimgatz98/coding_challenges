from typing import Generic, Iterable, List, TypeVar

T = TypeVar("T")


class Node(Generic[T]):
    pass


class Node:
    def __init__(self, val: int, neighbours: Iterable[Node]) -> None:
        self.value = val
        self.neighbours = list(neighbours)

    def append(self, neighbour: Node) -> None:
        self.neighbours.append(neighbour)

    def getNeighbours(self) -> List[Node]:
        return self.neighbours

    def getValue(self) -> int:
        return self.value

    def __str__(self) -> str:
        return str(self.value)

    @staticmethod
    def printList(nodes: List[Node]):
        visited = set()
        done = set()

        def printDFS(node: Node):
            for n in node.getNeighbours():
                if n not in visited:
                    visited.add(n)
                    printDFS(n)
            if node not in done:
                done.add(node)
                print(node.getValue())

        for node in nodes:
            if node not in visited:
                visited.add(node)
                printDFS(node)

    @staticmethod
    def reverseEdges(nodes):
        newNodes = []
        for i in range(1, len(nodes) + 1):
            newNodes.append(Node(i, []))

        newRoot = newNodes[4]

        visited = set()

        def recursion(node: Node):
            for n in node.getNeighbours():
                newNodes[n.getValue() - 1].append(newNodes[node.getValue() - 1])
                if n not in visited:
                    visited.add(n)
                    recursion(n)

        for node in nodes:
            if node not in visited:
                visited.add(node)
                recursion(node)

        return newRoot, newNodes

    @staticmethod
    def kosaraju(nodes: List[Node]):
        visited = set()
        done = set()
        stack = []

        def dfs(node: Node, cout: bool = False):
            for n in node.getNeighbours():
                if n not in visited:
                    visited.add(n)
                    dfs(n, cout)
            if cout:
                print(node.getValue(), end=" ")

            if (not cout) and (node not in done):
                done.add(node)
                stack.append(node.getValue())

        for node in nodes:
            if node not in visited:
                visited.add(node)
                dfs(node)

        _, reversedNodes = Node.reverseEdges(nodes)

        visited.clear()
        while len(stack) > 0:
            curr = stack[-1]
            del stack[-1]
            if reversedNodes[curr - 1] not in visited:
                visited.add(reversedNodes[curr - 1])
                dfs(reversedNodes[curr - 1], cout=True)
                print()


def creatTestTree():
    nodes = []
    root = Node(1, [])
    nodes.append(root)
    root.append(Node(2, []))
    node2 = root.getNeighbours()[0]
    nodes.append(node2)
    node2.append(Node(3, []))
    node2.append(Node(4, []))
    node3, node4 = node2.getNeighbours()
    nodes.extend([node3, node4])
    node3.append(root)
    node4.append(Node(5, []))
    nodes.append(node4.getNeighbours()[0])

    return root, nodes


if __name__ == "__main__":
    root, nodes = creatTestTree()
    Node.kosaraju(nodes)
