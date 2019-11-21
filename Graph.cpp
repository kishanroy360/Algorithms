#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
   map<T,list<T> >adjList;
public:
	Graph(){

	}
	void addEdge(T x,T y,bool bidir=true){
	    adjList[x].push_back(y);
		if(bidir) adjList[y].push_back(x);
	}
    void printAdj(){
    	for(auto it: adjList){
    		cout<<it.first<<"->";
    		for(auto vertex: it.second){
    			cout<<vertex<<",";
    		}
    		cout<<endl;
    	}
    }
    void bfs(T src){
    	map<T,bool>visited;
    	queue<T>q;
    	q.push(src);
    	visited[src]=true;
    	while(!q.empty()){
           T node=q.front();
           q.pop();
           cout<<node<<",";
           for(auto neighbour: adjList[node]){
           	if(!visited[neighbour]) {
           		q.push(neighbour);
           		visited[neighbour]=true;}
           }
    	}
    }
    void SSSP(T src){
    	map<T,int>dist;
    	for(auto it: adjList) dist[it.first]=INT_MAX;
    	dist[src]=0;
        map<T,T> parent;
        parent[src]=src;
    	queue<T>q;
    	q.push(src);
    	while(!q.empty()){
           T node=q.front();
           q.pop();
           cout<<node<<",";
           for(auto neighbour: adjList[node]){
           	if(dist[neighbour]==INT_MAX) {
           		q.push(neighbour);
           		dist[neighbour]=dist[node]+1;
           		parent[neighbour]=node;
           	}
           }
    	}
    	for(auto it:adjList){
    		cout<<it.first<<"->"<<dist[it.first]<<endl;
    	}
    }
};
int main(){
	Graph<int> g;
	g.addEdge(0,4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(4,3);
    g.addEdge(4,2);
    g.addEdge(3,2);
    g.addEdge(3,5);
    g.SSSP(0);
    return 0;
}
