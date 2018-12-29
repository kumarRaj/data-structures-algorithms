# See if a path exists between 2 nodes in a graph
import Queue

class Node(object):
	def __init__(self, data, edges = []):
		super(Node, self).__init__()
		self.data = data
		self.edges = list(edges)
		self.visited = False

	def addEdge(self, *args):
		# print(self)
		self.edges.extend(args)
		# print(self.edges)

	def __str__(self):
		return "[" + str(self.data) + str([ str(node.data) for node in self.edges]) + "]"




class Graph(object):
	"""docstring for main"""
	def __init__(self):
		one = Node(1)#, [Node(2)]), 
		two = Node(2)#, [Node(3),Node(5)]), 
		three = Node(3)#, [Node(4),Node(5)]), 
		four = Node(4)#, [Node(6)]), 
		five = Node(5)#, []), 
		six = Node(6)#, [Node(1)])
		one.addEdge(two)
		two.addEdge(three, five)
		three.addEdge(four, five)
		four.addEdge(six)
		six.addEdge(one)
		self.nodes = [one, two, three, four, five, six]

	def __str__(self):
		return str([str(node) for node in self.nodes])


	def isPathPresent(self, node1, node2):
		if node1 == node2:
			return True

		q = Queue.Queue()
		q.put(node1)
		while not q.empty():
			tempNode = q.get()
			for child in tempNode.edges:
				if child == node2:
					return True
				if child.visited != True:
					q.put(child)
			# visitedNode = q.pop()
			tempNode.visited = True
		return False


if __name__ == '__main__':
	graph = Graph()
	print("Path from 1 to 4 " + str(graph.isPathPresent(graph.nodes[0], graph.nodes[3])))
	graph = Graph()
	print("Path from 1 to 6 " + str(graph.isPathPresent(graph.nodes[0], graph.nodes[5])))
	graph = Graph()
	print("Path from 6 to 5 " + str(graph.isPathPresent(graph.nodes[5], graph.nodes[4])))
	graph = Graph()
	print("Path from 5 to 4 " + str(graph.isPathPresent(graph.nodes[4], graph.nodes[3])))
