
#include<iostream>
#include<vector>
#include <list>
#include <fstream>
#include <map>
#include <set>
#include <vector>
using namespace std;

template <typename T>
class Graph
{
	int V; 
	map<T, set<T>> adj;
public:
	Graph(int V);
	void addEdge(T v, T w);
	vector<T> BFS(char s);
};

template <typename T>
Graph<T>::Graph(int V)
{
	this->V = V;
}

template <typename T>
void Graph<T>::addEdge(T v, T w)
{
	adj[v].insert(w);
}

template <typename T>
vector<T> Graph<T>::BFS(char s)
{
	vector<T> result;
	map<char, bool> visited;

	list<char> queue;

	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty())
	{
		s = queue.front();
		result.push_back(s);
		queue.pop_front();

		for (auto adjecent : adj[s])
		{
			if (!visited[adjecent])
			{
				visited[adjecent] = true;
				queue.push_back(adjecent);
			}
		}
	}
	return result;
}
