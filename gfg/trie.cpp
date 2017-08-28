//http://practice.geeksforgeeks.org/problems/trie-insert-and-search/0
#include <bits/stdc++.h>

using namespace std;

struct trie
{
  struct trie *children[26];
  bool isLeaf;
};

void insert(string input, struct trie *t, int i)
{
//	cout << "i " << i << "\n";
//	cout << "input.size() " << input.size() << "\n";
    if(i == input.size() - 1)
    {
        struct trie *temp = new(struct trie);
        temp->isLeaf = true;
        for(int j = 0; j < 26; j++)
	    {
	        temp->children[j] = NULL;
	    }
        t->children[input[i] - 'a'] = temp;
    }
    else
    {
        if(t->children[input[i] - 'a'] == NULL)
        {
            struct trie *temp = new(struct trie);
            temp->isLeaf = false;
            for(int j = 0; j < 26; j++)
    	    {
    	        temp->children[j] = NULL;
    	    }
            t->children[input[i] - 'a'] = temp;
        }
        insert(input, t->children[input[i] - 'a'], i+1);
    }
}

bool search(struct trie *t, string query, int i)
{
	//cout << query[i] << "\n";
	if(i == query.size() - 1)
	{
		if(t->children[query[i] - 'a'] == NULL || (t->children[query[i] - 'a'])->isLeaf == false)
		{
			//cout << "false\n";
			return false;
		}
		else
		{
			//cout << "true\n";
			return true;
		}
	}
	else
	{
		if(t->children[query[i] - 'a'] == NULL)
			return false;
		else
			return(search(t->children[query[i] - 'a'], query, i + 1));
	}
}

int main()
 {
	//code
	int t, n;
	string input, query;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
	    cin >> n;
	    struct trie *tr = new(struct trie);
	    tr->isLeaf = false;
	    for(int j = 0; j < 26; j++)
	    {
	        tr->children[j] = NULL;
	    }
	    for(int j = 0; j < n; j++)
	    {
	        cin >> input;
	        insert(input, tr, 0);
	        input.clear();
	    }
	    cin >> query;
	    bool result = search(tr, query, 0);
	    if(result)
	    	cout << 1 << "\n";
	    else
	    	cout << 0 << "\n";
	    query.clear();
	    delete(tr);
	}
	return 0;
}