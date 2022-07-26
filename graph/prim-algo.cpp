// Prim's algorithm (also known as Jarník's algorithm) is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized.
#include <bits/stdc++.h>
using namespace std;

int main()
{
     int N, m;
     cin >> N >> m;
     vector<pair<int, int>> adj[N];

     int a, b, wt;
     for (int i = 0; i < m; i++)
     {
          cin >> a >> b >> wt;
          adj[a].push_back(make_pair(b, wt));
          adj[b].push_back(make_pair(a, wt));
     }

     int parent[N];
     // Create a vector for keys and initialize all
    // keys as infinite (INF)
     int key[N];
      // To keep track of vertices included in MST
     bool mstSet[N];

     for (int i = 0; i < N; i++)
          key[i] = INT_MAX, mstSet[i] = false;

     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

     key[0] = 0;
     parent[0] = -1;
     pq.push({0, 0});
     // Run the loop till all the nodes have been visited
     // because in the brute code we checked for mstSet[node] == false while computing the minimum
     // but here we simply take the minimal from the priority queue, so a lot of times a node might be taken twice
     // hence its better to keep running till all the nodes have been taken.
     // try the following case:
     // Credits: Srejan Bera
     // 6 7
     // 0 1 5
     // 0 2 10
     // 0 3 100
     // 1 3 50
     // 1 4 200
     // 3 4 250
     // 4 5 50
     while (!pq.empty())
     {  
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
          int u = pq.top().second;
          pq.pop();

          mstSet[u] = true;

          for (auto it : adj[u])
          {
               int v = it.first;
               int weight = it.second;
               if (mstSet[v] == false && weight < key[v])
               {
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
               }
          }
     }

     for (int i = 1; i < N; i++)
          cout << parent[i] << " - " << i << " \n";// these are the edges
     return 0;
}