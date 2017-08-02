//Implementation of BFS
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> graph[], int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
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

void bfs(vector<int> graph[], int n, int start)
{
	deque<int> queue;
	vector<int> visited(n, 0);
	queue.push_back(start);
	while(!queue.empty())
	{
		int currentV = queue.front();
		queue.pop_front();
		visited[currentV] = 1;
		cout << currentV << " ";
		for(int i = 0; i < graph[currentV].size(); i++)
		{
			int temp = graph[currentV][i];
			if(visited[temp] == 0)
			{
				queue.push_back(temp);
				visited[temp] = 1;
			}
		}
	}
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
	cout << "BFS:\n";
	bfs(graph, n, 0);
}	