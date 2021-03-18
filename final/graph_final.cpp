#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <bits/stdc++.h>
//Ian Delgado
//Joseph Jess
//CS260
//March 10th 2021

//Graph program that will do some functions like add vertices, add edges with weights, find the shortest path from source vertex,
//and minimize the weights of the edge


/*
Tests:

vector<vector<pair<int,int>>> graph(number, vector<pair<int,int>>(number));

add_edge(graph, source, other vertex, weight);
add_edge(graph, source, other vertex, weight);
add_edge(graph, source, other vertex, weight);
add_edge(graph, source, other vertex, weight);
add_edge(graph, source, other vertex, weight);
add_edge(graph, source, other vertex, weight);
add_edge(graph, source, other vertex, weight);
add_edge(graph, source, other vertex, weight);
add_edge(graph, source, other vertex, weight);

vector<int> dist = dijkstra(graph, source vertex);


expected output:

source vertex -> connected vertex with weight -> connnected vertex with weight
source vertex -> connected vertex with weight -> connnected vertex with weight
source vertex -> connected vertex with weight -> connnected vertex with weight
source vertex -> connected vertex with weight -> connnected vertex with weight
source vertex -> connected vertex with weight -> connnected vertex with weight
source vertex -> connected vertex with weight -> connnected vertex with weight

Vertex      Distance from source vertex
num of vertex     num of distance from source
num of vertex     num of distance from source
num of vertex     num of distance from source
num of vertex     num of distance from source
num of vertex     num of distance from source
num of vertex     num of distance from source


Minimum Spanning Tree:

vertex-other_vertex, min weight
vertex-other_vertex, min weight
vertex-other_vertex, min weight
vertex-other_vertex, min weight
vertex-other_vertex, min weight
vertex-other_vertex, min weight
vertex-other_vertex, min weight
*/

using namespace std;
//class of our graph
class Graph {
    public:
        //function for finding the shortest path using dijkstra's algo
        vector<int> dijkstra(vector<vector<pair<int,int>>> graph, int start) {
            
            vector<int> dist(graph.size(), INT_MAX);

            
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> priority_queue;

            // add first number to priority queue which is 
            priority_queue.push(make_pair(0, start));
            dist[start] = 0;
            //while priority queue is not empty
            while(!priority_queue.empty()){
                // Get min distance vertex from priority_queue
                int u = priority_queue.top().second;
                priority_queue.pop();
                //for loop to add vertex and weight
                for(int i = 0; i < graph[u].size(); i++)
                {
                    int v = graph[u][i].first;
                    int weight = graph[u][i].second;

                    // If the distance to v is shorter by going through u
                    if (dist[v] > dist[u] + weight)
                    {
                        dist[v] = dist[u] + weight;
                        priority_queue.push(make_pair(dist[v], v));
                    }
                }
            }
            return dist;
        }
        //method for minimum spanning tree
        vector<tuple<int,int,int>> min_span_tree(vector<vector<pair<int,int>>>& graph, int start) {
        
            vector<int> parent(graph.size(), -1);
            vector<int> key(graph.size(), INT_MAX);
            vector<bool> in_min_span_tree(graph.size(), false);
            key[start] = 0;

            // <key, vertex> pair. First element of priority queue will be the minimum
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> priority_queue;
            priority_queue.push(make_pair(0, start));
            
            vector<tuple<int,int,int>> result;
            while (!priority_queue.empty()) {
                // Get min distance vertex from priority_queue
                int v = priority_queue.top().second;
                priority_queue.pop();
                //check to see if parent array is not empty and if vertex is not in minimum_span_tree
                if (parent[v] != -1 && in_min_span_tree[v] == false)
                    result.emplace_back(make_tuple(parent[v], v, key[v]));

                in_min_span_tree[v] = true;
                cout << v <<endl;
                for(auto x : graph[v])
                {
                    int av = x.first;
                    int weight = x.second;
                    if (in_min_span_tree[av] == false && key[av] > weight)
                    {
                        parent[av] = v;
                        key[av] = weight;
                        priority_queue.push(make_pair(key[av],av));
                    }
                }
            
            
            }
            return result;
        }
        
        //function to add edge
        void add_edge(vector<vector<pair<int,int>>>& graph, int u, int v, int w)
        {
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }

        //function to print adjacency list
        void print_adj_list(vector<vector<pair<int,int>>>& graph){
        //iterate over all verticies
            cout << "Adjacency List:" << endl;
            for (int i=0; i < 10; i++)
            {
                cout << i;
                for (int j=0; j < graph[i].size(); j++)
                    cout << " -> " << graph[i][j].first << "," << graph[i][j].second;
                cout << endl;
            }
        }

        
};


int main()
{
    Graph g;
    // pair of node, weight
    vector<vector<pair<int,int>>> graph(10, vector<pair<int,int>>(10));

    g.add_edge(graph, 0, 1, 9);
    g.add_edge(graph, 0, 7, 14);
    g.add_edge(graph, 1, 2, 84);
    g.add_edge(graph, 1, 7, 6);
    g.add_edge(graph, 2, 3, 82);
    g.add_edge(graph, 2, 8, 41);
    g.add_edge(graph, 2, 5, 45);
    g.add_edge(graph, 3, 4, 72);
    g.add_edge(graph, 3, 5, 24);
    g.add_edge(graph, 4, 5, 21);
    g.add_edge(graph, 5, 6, 26);
    g.add_edge(graph, 6, 7, 18);
    g.add_edge(graph, 6, 8, 63);
    g.add_edge(graph, 7, 8, 264);
    
    g.print_adj_list(graph);

    vector<int> dist = g.dijkstra(graph, 5);
    // Print shortest distances stored in dist[]
    
    cout << "Vertex      Distance from 5" << endl;
    for(int i = 0; i < 10; ++i){
        cout << i << "\t\t" << dist[i] << endl;
    }   

    vector<tuple<int,int,int>> res = g.min_span_tree(graph, 0);
    cout << "Minimum Spanning Tree: " << endl;
    for (tuple<int,int,int> t : res){
        cout << get<0>(t) << "-" << get<1>(t) << "," << get<2>(t) << endl;
    }
    
    return 0;
}

/* Time Complexity:

Our adding vertex functions seems to be O(1) because we are creating all the 
vertexes at one execution

I believe adding edges is O(n) time because to add an edge, the program must traverse to the approprate spot in array to connect verticies

dijsktra's algorithm seems to be O(n) depending on the number of verticies in the graph

Similarly, minimum spanning tree seems to be O(n) time
(i'm horrible with time analysis as you can tell. I plan on studying run time analysis very intensly during the break,
I was caught up in a lot with my other classes that I didn't have enough time to study run time as I wanted to.:( )
*/

