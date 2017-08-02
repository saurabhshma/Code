//http://practice.geeksforgeeks.org/problems/x-total-shapes/0
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

int bfs(vector<int> graph[], int n)
{
	deque<int> queue;
	vector<int> visited(n, 0);
	int count = 0;
	for(int j = 0; j < n; j++)
	{
		if(visited[j] == 0)
		{
			queue.push_back(j);
			while(!queue.empty())
			{
				int currentV = queue.front();
				queue.pop_front();
				visited[currentV] = 1;
				//cout << currentV << " ";
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
			count++;
		}
	}
	return count;
}

int main()
{
	int t, n, m, count;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		count = 0;
		cin >> n >> m;
		string input[n];
		for(int j = 0; j < n; j++)
			cin >> input[j];
		map<int, int> mappings;
		int count = 0;
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				if(input[j][k] == 'X')
				{
					mappings[j * m + k] = count;
					count++;
				}
			}
		}
		
		vector<int> graph[count];
		
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < m; k++)
			{
				if(j == 0)
				{
					if(input[j][k] == 'X')
					{
						if(k != 0)
						{
							if(input[j][k - 1] == 'X')
							{
								addEdge(graph, mappings[j * m + k], mappings[j * m + k - 1]);
							}
						}
					}
				}
				else
				{
					if(input[j][k] == 'X')
					{
						if(k != 0)
						{
							if(input[j][k - 1] == 'X')
							{
								addEdge(graph, mappings[j * m + k], mappings[j * m + k - 1]);
							}
							if(input[j - 1][k] == 'X')
							{
								addEdge(graph, mappings[j * m + k], mappings[(j - 1) * m + k]);
							}
						}
						else
						{
							if(input[j - 1][k] == 'X')
							{
								addEdge(graph, mappings[j * m + k], mappings[(j - 1) * m + k]);
							}	
						}
					}
				}
			}
		}
		int result = bfs(graph, count);
		cout << result << "\n";
	}
}	