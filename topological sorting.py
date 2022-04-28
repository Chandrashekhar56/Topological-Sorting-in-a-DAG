from collections import defaultdict
class graph_for_topologicalsort:
	def __init__(self,total_vertices):
		self.Graph = defaultdict(list)
		self.Vertices = total_vertices
		
	def add_new_edge(self,source_vertex,destination_vertex):
		self.Graph[source_vertex].append(destination_vertex)

	def topolo_gical_Sort_Util(self,x,visited_vertex,stack_for_topologicalsort):
            
		visited_vertex[x] = True
		
		for y in self.Graph[x]:
			if visited_vertex[y] == False:
				self.topolo_gical_Sort_Util(y,visited_vertex,stack_for_topologicalsort)
		stack_for_topologicalsort.insert(0,x)
	def function_of_topolo_gical_Sort(self):
		visited_vertex= [False]*self.Vertices
		stack_for_topologicalsort =[]
		for x in range(self.Vertices):
			if visited_vertex[x] == False:
				self.topolo_gical_Sort_Util(x,visited_vertex,stack_for_topologicalsort)
		print (stack_for_topologicalsort)

ob= graph_for_topologicalsort(6)
ob.add_new_edge(5, 3);
ob.add_new_edge(5, 0);
ob.add_new_edge(5, 2);
ob.add_new_edge(5, 1);
ob.add_new_edge(2, 3);
ob.add_new_edge(2, 1);
ob.add_new_edge(2, 4);
ob.add_new_edge(2, 0);
ob.add_new_edge(3, 1);
ob.add_new_edge(3, 4);
ob.add_new_edge(3, 5);
ob.add_new_edge(4, 0);
ob.add_new_edge(4, 3);
ob.add_new_edge(4, 1);
ob.add_new_edge(1, 4);
ob.add_new_edge(1, 0);
ob.add_new_edge(1, 3);
ob.add_new_edge(0, 1);
ob.add_new_edge(0, 4);
ob.add_new_edge(0, 2);
ob.add_new_edge(0, 5);
print ("Topological Sort: ")
ob.function_of_topolo_gical_Sort()
