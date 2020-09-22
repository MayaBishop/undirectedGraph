//
//  UndirectedGraph.cpp
//  undirectedGraph
//
//  Created by Maya Bishop on 2020-04-15.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#include "UndirectedGraph.h"

//removes the trailing zeros from the end of a string that was created from a double

//constructor/destructor
UndirectedGraph::UndirectedGraph(){
    vertexes = {};
    num_edges = 0;
    num_vertexes = 0;
}

UndirectedGraph::~UndirectedGraph(){
    clear();
}

//
string UndirectedGraph::insertVertex(string name){
    if(searchVertex(name)!=-1){
        return "failure";
    }
    vertexes.push_back(new Vertex(name));
    num_vertexes++;
    return "success";
}

string UndirectedGraph::insertEdge(string name1, string name2, double weight){
    if((weight <= 0) || (name1 == name2)){
        return "failure";
    }
    int vertex1 = searchVertex(name1);
    if(vertex1 == -1){
        return "failure";
    }
    int vertex2 = searchVertex(name2);
    if(vertex2 == -1){
        return "failure";
    }
    bool previousEdge = false;
    vector<Edge*> vertex_adj = vertexes[vertex1]->getAdjancencies();
    for(int i = 0; i < vertex_adj.size(); i++){//O(Ajacencies for name1 node)
        if(vertex_adj[i]->getU() == vertex2){
            vertex_adj.erase(vertex_adj.begin()+i);
            vertexes[vertex1]->setAdjancencies(vertex_adj);
            previousEdge = true;
            break;
        }
    }
    if(previousEdge){
        vector<Edge*> vertex_adj = vertexes[vertex2]->getAdjancencies();
        for(int i = 0; i < vertex_adj.size(); i++){//O(Ajacencies for name2 node)
            if(vertex_adj[i]->getU() == vertex1){
                vertex_adj.erase(vertex_adj.begin()+i);
                vertexes[vertex2]->setAdjancencies(vertex_adj);
                break;
            }
        }
    }else{
        num_edges++;
    }
    vertexes[vertex1]->addEdge(new Edge(weight, vertex2));
    vertexes[vertex2]->addEdge(new Edge(weight, vertex1));
    return "success";
}

int UndirectedGraph::searchVertex(string name){
    for (int i = 0; i< vertexes.size(); i++) {
        if(vertexes[i]->getName() == name){
            return i;
        }
    }
    return -1;
}

string UndirectedGraph::degree(string name){
    int i = searchVertex(name);
    if(i==-1){
        return "failure";
    }
    string adj_size = to_string(vertexes[i]->getAdjancencies().size());
    return "degree of "+name+" "+adj_size;
}

string UndirectedGraph::vertexCount(){
    return "number of nodes " + to_string(num_vertexes);
}

string UndirectedGraph::edgeCount(){
    return "number of edges " + to_string(num_edges);
}

string UndirectedGraph::weight(string name1, string name2){
    if(name1==name2){
        return "failure";
    }
    int vertex1 = searchVertex(name1);
    if(vertex1 == -1){
        return "failure";
    }
    int vertex2 = searchVertex(name2);
    if(vertex2 == -1){
        return "failure";
    }
    double w = weight(vertex1, vertex2);
    if(w == 0.0){
        return "failure";
    }
    return "direct distance "+name1+" to "+name2+" "+removeZeros(w);
}




string UndirectedGraph::smallestWeight(string name1, string name2){
    if(name1==name2){
        return "failure";
    }
    int vertex1 = searchVertex(name1);
    if(vertex1 == -1){
        return "failure";
    }
    int vertex2 = searchVertex(name2);
    if(vertex2 == -1){
        return "failure";
    }
    double w = smallestWeight(vertex1, vertex2);
    if(w == 0.0||w == INFINITY){
        return "failure";
    }
    return "shortest distance "+name1+" to "+name2+" "+removeZeros(w);
}

string UndirectedGraph::printPath(string name1, string name2){
    if(name1==name2){
        return "failure";
    }
    int vertex1 = searchVertex(name1);
    if(vertex1 == -1){
        return "failure";
    }
    int vertex2 = searchVertex(name2);
    if(vertex2 == -1){
        return "failure";
    }
    double w = smallestWeight(vertex1, vertex2);
    if(w == 0.0||w == INFINITY){
        return "failure";
    }
    Vertex* u = vertexes[vertex2];
    string output = "";
    while(u->getParentIndex()!=-1){
        output = " "+u->getName()+output;
        u = vertexes[u->getParentIndex()];
    }
    output = u->getName()+output;
    return output;
}

string UndirectedGraph::clear(){
    for(int i = num_vertexes-1; i>=0; i--){
        delete vertexes[i];
        vertexes[i] = nullptr;
        vertexes.pop_back();
        num_vertexes--;
    }
    num_edges = 0;
    return "success";
}

//helper functions
double UndirectedGraph::weight(int name1, int name2){
    vector<Edge*> vertex_adj = vertexes[name1]->getAdjancencies();
    for(int i = 0; i < vertex_adj.size(); i++){//O(Ajacencies for name1 node)
        if(vertex_adj[i]->getU() == name2){
            return vertex_adj[i]->getDistance();
        }
    }
    return 0.0;
}

double UndirectedGraph::smallestWeight(int name1, int name2){
    for(int i = 0; i < num_vertexes; i++){//O(|N|)
        vertexes[i]->setKey(INFINITY);
        vertexes[i]->setParentIndex(-1);
        vertexes[i]->setHeapIndex(i);
    }
    vertexes[name1]->setKey(0.0);
    PriorityQueue p_q = PriorityQueue(vertexes);//O(|N|)
    Vertex* u = nullptr;
    Vertex* v = vertexes[name2];
    while ((p_q.getHeapSize()>0)&&u!=v) {
        u = p_q.extractMin();//O(|N|lg|N|)
        for(int i = 0; i < u->getAdjancencies().size();i++){//O(|E|(lg|N|))
            //REMOVE ALL VISITED STUFF CAUSE 2E simplifies to E
            relax(searchVertex(u->getName()), u->getAdjancencies()[i]->getU(),u->getAdjancencies()[i]->getDistance());//O(1)
            p_q.modifyKey(vertexes[u->getAdjancencies()[i]->getU()]->getHeapIndex());//This should be the index in the priority queue not in the graph//O(lg|N|)
             
        }
    }
    if(p_q.getHeapSize()<=0 && u!=v){
        return 0.0;
    }
    return v->getKey();
}

void UndirectedGraph::relax(int u, int v, double weight){
    if(vertexes[v]->getKey()>vertexes[u]->getKey()+weight){
        vertexes[v]->setKey(vertexes[u]->getKey()+weight);
        vertexes[v]->setParentIndex(u);
    }
}

string UndirectedGraph::removeZeros(double s){
    if((s-int(s)) == 0){
        return to_string(int(s));
    }
    string new_string = to_string(s);
    int divider = new_string.find(".");
    for(int i = new_string.length()-1; i > divider; i--){
        if(new_string[i] == '0'){
            new_string.erase(new_string.begin()+i);
        }else{
            break;
        }
    }
    return new_string;
}
