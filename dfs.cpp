//Implementation of DFS using STL
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
	graph[u].push_back(v);
	//graph[v].push_back(u); add this line for undirected graph
}

void display(vector<int> graph[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << i << ": ";
		for(int j = 0; j < graph[i].size(); j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}

void dfsUtil(vector<int> graph[], int n, int start, vector<bool>& visited)
{
	visited[start] = true;
	cout << start << " ";
	for(int i = 0; i < graph[start].size(); i++)
	{
		if(!visited[graph[start][i]])
			dfsUtil(graph, n, graph[start][i], visited);
	}
}

void dfs(vector<int> graph[], int n, int start)
{
	vector<bool> visited(n);
	for(int i = 0; i < n; i++)
	{
		visited[i] = false;
	}
	dfsUtil(graph, n, start, visited);
	cout << "\n";
}

int main()
{
	int n, u, v;
	cout << "Enter number of vertices\n";
	cin >> n;
	vector<int> graph[n];
	while(1)
	{
		cout << "Enter edge u v (-1 -1 to exit)\n";
		cin >> u >> v;
		if(u == -1 && v == -1)
			break;
		else
			addEdge(graph, u, v);
	}
	display(graph, n);
	cout << "DFS:\n";
	dfs(graph, n, 2);
}	