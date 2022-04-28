#include <iostream>
#include <list>
#include <stack>
using namespace std;
class graph_for_topologicalsort
 {
	int total_Vertices;
	list<int>* adjency_list;


	void topolo_gical_Sort_Util(int x, bool visited_vertex[], stack<int>& Stack)
	{
        visited_vertex[x] = true;
        list<int>::iterator y;
        for (y = adjency_list[x].begin(); y != adjency_list[x].end(); ++y)
            if (!visited_vertex[*y])
                topolo_gical_Sort_Util(*y, visited_vertex, Stack);
        Stack.push(x);
	}


public:
	graph_for_topologicalsort(int total_Vertices)
	{
        this->total_Vertices =total_Vertices;
        adjency_list = new list<int>[total_Vertices];
    }


	void add_new_edge(int source, int destination)
	{
	    adjency_list[source].push_back(destination);
    }


	void function_of_topolo_gical_Sort()
	{
        stack<int> Stack;
        bool* visited_vertex = new bool[total_Vertices];
        for (int x = 0; x< total_Vertices; x++)
            visited_vertex[x] = false;
        for (int x = 0; x < total_Vertices; x++)
            if (visited_vertex[x] == false)
                topolo_gical_Sort_Util(x, visited_vertex, Stack);
        while (Stack.empty() == false)
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
	}
};
int main()
{
    graph_for_topologicalsort ob(6);
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
	cout << "Topological Sort: ";
	ob.function_of_topolo_gical_Sort();

	return 0;
}
