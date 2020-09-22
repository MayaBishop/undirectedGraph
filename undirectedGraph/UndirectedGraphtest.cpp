//
//  undirectedGraphtest.cpp
//  undirectedGraph
//
//  Created by Maya Bishop on 2020-04-15.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#include <iostream>
#include <string>
#include "UndirectedGraph.h"
using namespace std;

int main(int argc, const char * argv[]) {
        //initialize variables used for parsing commands
    UndirectedGraph graph;
    string line;
    string command;
    int param;
    string parameters;
    int divider;
    while(!cin.eof()){
        //get the line from the file and find the divider
        getline(cin, line);
        divider = line.find(" ");
        command = line.substr(0,divider);
        //check the command entered and call the correct method from deque in response
        if(command == "i"){
            parameters = line.substr(divider+1);
            cout << graph.insertVertex(parameters) << endl;
            
        }else if(command == "setd"){
            parameters = line.substr(divider+1);
            divider = parameters.find(";");
            string u = parameters.substr(0,divider);
            parameters = parameters.substr(divider+1);
            divider = parameters.find(";");
            string v = parameters.substr(0,divider);
            double w = stod(parameters.substr(divider+1));
            cout << graph.insertEdge(u,v, w) << endl;
        }else if(command == "s"){
            parameters = line.substr(divider+1);
            int result = graph.searchVertex(parameters);
            if(result == -1){
                cout << "not found" << endl;
            }else{
                cout << "found "+parameters << endl;
            }
            
        }else if(command == "degree"){
            string param = line.substr(divider+1);
            cout << graph.degree(param) << endl;
            
        }else if(command == "graph_nodes"){
            cout << graph.vertexCount() << endl;
            
        }else if(command == "graph_edges"){
            cout << graph.edgeCount() << endl;
            
        }else if(command == "d"){
            parameters = line.substr(divider+1);
            divider = parameters.find(";");
            string u = parameters.substr(0,divider);
            string v = parameters.substr(divider+1);
            cout << graph.weight(u,v) << endl;
            
        }else if(command == "shortest_d"){
            parameters = line.substr(divider+1);
            divider = parameters.find(";");
            string u = parameters.substr(0,divider);
            string v = parameters.substr(divider+1);
            cout << graph.smallestWeight(u,v) << endl;
            
        }else if(command == "print_path"){
            parameters = line.substr(divider+1);
            divider = parameters.find(";");
            string u = parameters.substr(0,divider);
            string v = parameters.substr(divider+1);
            cout << graph.printPath(u,v) << endl;
            
        }else if(command == "clear"){
            cout << graph.clear() << endl;
            
        }
        
        
    }
    
    return 0;
}
