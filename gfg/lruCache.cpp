//http://practice.geeksforgeeks.org/problems/lru-cache/1
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */
int size;
map<int, pair<int, list::iterator it> > mappings;
list<int> lruList;

LRUCache::LRUCache(int N)
{
    size = N;
     //Your code here
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
     //Your code here
     if(mappings.find(x) == mappings.end())
     {
         lruList.push_front(x);
         mappings[x] = make_pair(y, lruList.begin());
     }
     else
     {
        pair<int, list::iterator it> tempPair = mappings[x];
        list::iterator tempIt = tempPair.second;
        lruList.erase(tempIt);
        lruList.push_front(x);
        tempIt = lruList.begin();
        mappings[x] = make_pair(y, tempIt);
     }
}
/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    //Your code here
    if(mappings.find(x) == mappings.end())
        return -1;
    else
    {
        pair<int, list::iterator it> tempPair = mappings[x];
        int value = tempPair.first;
        list::iterator tempIt = tempPair.second;
        lruList.erase(tempIt);
        lruList.push_front(x);
        tempIt = lruList.begin();
        mappings[x] = make_pair(value, tempIt);
        return (value);
    }
}