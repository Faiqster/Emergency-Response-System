#include <iostream>
#include <cmath>
using namespace std;
struct vertex{
	string label;
	int index;
};

const int rows = 30;
const int cols = 30;
int vertixcount=0;
vertex vertices[rows];
int parent[rows];
int graph[rows][cols];
float pCost;
string Hospital;


void add_vertex(string v) {
    vertices[vertixcount].label = v;
    vertices[vertixcount].index = vertixcount;
    vertixcount++;
}
int get_index(string c){
	for(int i=0;i<vertixcount;i++){
		if(vertices[i].label==c){
			return vertices[i].index; 
		}
	}
	return -1;
}
void add_edges(string v1, string v2, int cost) {
	int n1=get_index(v1);
	int n2=get_index(v2);
	graph[n1][n2]=cost;
	graph[n2][n1]=cost;
}
void traverse(int arr[rows][cols]){
	cout<<"Vertics";
	for(int i = 0; i < rows; i++){
           cout<<"\t | "<<vertices[i].label;
    }
    cout<<endl;
    cout<<"\n"<<endl;
	 for (int i = 0; i < rows; i++) {
	 	cout<<vertices[i].label<<"       ";
        for (int j = 0; j < cols; j++) {
           cout<<" | "<<arr[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<endl;
}
int min_vertix(int dist[], bool visited[]) {
    int min = INT_MAX;
    int min_index = -1;
    for (int v = 0; v < rows; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printpath(int parent[],  int g) { 
    if (parent[g] == -1)
        return;

    printpath(parent, parent[g]);

    cout <<"->"<< vertices[g].label;
}
void printreturnpath(int parent[]) { 
    for(int i=0;i<rows;i++){
    	cout<<"->"<<vertices[parent[i]].label;
	}
}
int dijkstra_algorithm(string source, string goal) {
    int dist[rows];
    bool visited[rows];
	int s=get_index(source);
	int g=get_index(goal);
    for (int i = 0; i < rows; i++) {
    	if(i==s){
    		dist[s] = 0;
		}
		else{
			dist[i] = INT_MAX;
		}
        parent[i] = -1;
        visited[i] = false;

}
    for (int i = 0; i < rows - 1; i++){
        int u = min_vertix(dist, visited);
        visited[u] = true;
        for (int v = 0; v < rows; v++) {
            if (!visited[v] && graph[u][v]!=0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    return dist[g];
}
string getSource(string g) {
    string src;
    int minPathCost = INT_MAX;
    string Hospitals[9][2] = {{"G-15", "Quaid-e-Azam International Hospital"},
    						  {"Blue Area", "Kalsum International Hospital"},
    						  {"Saddar", "Combined Military Hospital"},
    						  {"I-8", "Shifa International Hospital"},
    						  {"E-11", "Islamabad International Hospital"},
    						  {"F-10", "Maroof International Hospital"},
							  {"Saidpur Road","Holy Family Hospital"},
							  {"Murree Road","Benazir Bhutto Hospital"},
							  {"Satellite Town","Ahmed Medical Complex"}};						  
    for (int i=0;i<9;i++) {
    	string hosp=Hospitals[i][0];
    	if(g==Hospitals[i][0]){
            Hospital=Hospitals[i][1];
    		return hosp;
		}
        int pathCost = dijkstra_algorithm(g, hosp);
        if (pathCost < minPathCost){
            minPathCost = pathCost;
            src = hosp;
            Hospital=Hospitals[i][1];
        }
    }
    return src;
}


int main() {

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            graph[i][j] = 0;
        }
    }
    add_vertex("Alipur");add_vertex("Baharia Town");add_vertex("Bani Gala");
	add_vertex("BaraKahu");add_vertex("Blue Area");add_vertex("DHA");
	add_vertex("E-11");add_vertex("F-10");add_vertex("F-11");add_vertex("Faizabad");
	add_vertex("G-10");add_vertex("G-15");add_vertex("Gulberg Green");
	add_vertex("I-8");add_vertex("I-9");add_vertex("Margalla Town");
	add_vertex("Murree Road");add_vertex("Pakistan Town");add_vertex("Park View City");
	add_vertex("PWD");add_vertex("Rehmanabad");add_vertex("Saddar");
	add_vertex("Saidpur Road");add_vertex("Satellite Town");add_vertex("Shakarparian");
	add_vertex("Shamsabad");add_vertex("Shehzad Town");add_vertex("Soan Garden");
	add_vertex("Tramri");add_vertex("Westridge");

	add_edges("Alipur", "Bani Gala", 12);
	add_edges("Alipur", "Shehzad Town", 5.7);
	add_edges("Alipur", "Tramri", 2.7);
	add_edges("Baharia Town", "DHA", 10);
	add_edges("Bani Gala", "BaraKahu", 12);
	add_edges("Bani Gala", "F-10", 23);
	add_edges("Bani Gala", "F-11", 25);
	add_edges("Bani Gala", "G-10", 23);
	add_edges("Bani Gala", "G-15", 31);
	add_edges("Bani Gala", "I-8", 15);
	add_edges("Bani Gala", "I-9", 16);
	add_edges("Bani Gala", "Margalla Town", 13);
	add_edges("Bani Gala", "Park View City", 12);
	add_edges("Bani Gala", "Saidpur Road", 18);
	add_edges("Bani Gala", "Shakarparian", 15);
	add_edges("Bani Gala", "Shehzad Town", 6.9);
	add_edges("Bani Gala", "Tramri", 12);
	add_edges("BaraKahu", "Blue Area", 3.1);
	add_edges("BaraKahu", "F-10", 12);
	add_edges("BaraKahu", "F-11", 15);
	add_edges("BaraKahu", "G-10", 22);
	add_edges("BaraKahu", "G-15", 30);
	add_edges("BaraKahu", "I-9", 19);
	add_edges("BaraKahu", "Murree Road", 16);
	add_edges("BaraKahu", "Park View City", 24);
	add_edges("BaraKahu", "Saidpur Road", 17);
	add_edges("BaraKahu", "Shakarparian", 15);
	add_edges("Blue Area", "E-11", 12);
	add_edges("Blue Area", "F-10", 9);
	add_edges("Blue Area", "F-11", 9);
	add_edges("Blue Area", "G-10", 8.8);
	add_edges("Blue Area", "G-15", 21);
	add_edges("Blue Area", "Gulberg Green", 21.7);
	add_edges("Blue Area", "I-8", 9);
	add_edges("Blue Area", "I-9", 11);
	add_edges("Blue Area", "Murree Road", 10);
	add_edges("Blue Area", "Pakistan Town", 22);
	add_edges("Blue Area", "PWD", 19);
	add_edges("Blue Area", "Rehmanabad", 13.8);
	add_edges("Blue Area", "Saidpur Road", 16.5);
	add_edges("Blue Area", "Satellite Town", 13.2);
	add_edges("Blue Area", "Shakarparian", 5.1);
	add_edges("DHA", "G-15", 22);
	add_edges("DHA", "Gulberg Green", 20.3);
	add_edges("DHA", "Murree Road", 15.6);
	add_edges("DHA", "PWD", 10);
	add_edges("DHA", "Saddar", 8.7);
	add_edges("DHA", "Saidpur Road", 13);
	add_edges("E-11", "F-10", 6.7);
	add_edges("E-11", "F-11", 3.3);
	add_edges("E-11", "Faizabad", 17);
	add_edges("E-11", "G-10", 6.2);
	add_edges("E-11", "G-15", 16.9);
	add_edges("E-11", "Gulberg Green", 28.8);
	add_edges("E-11", "I-8", 13);
	add_edges("E-11", "I-9", 14.2);
	add_edges("E-11", "Margalla Town", 18.7);
	add_edges("E-11", "Murree Road", 17);
	add_edges("E-11", "Pakistan Town", 30);
	add_edges("E-11", "PWD", 29);
	add_edges("E-11", "Saddar", 20);
	add_edges("E-11", "Saidpur Road", 16);
	add_edges("E-11", "Satellite Town", 16.3);
	add_edges("F-10", "F-11", 1.8);
	add_edges("F-10", "G-10", 3.1);
	add_edges("F-10", "G-15", 13);
	add_edges("F-10", "Gulberg Green", 24.7);
	add_edges("F-10", "I-8", 10);
	add_edges("F-10", "I-9", 11);
	add_edges("F-10", "Margalla Town", 14.5);
	add_edges("F-10", "Murree Road", 12);
	add_edges("F-10", "Pakistan Town", 25.5);
	add_edges("F-10", "Park View City", 28);
	add_edges("F-10", "PWD", 25);
	add_edges("F-10", "Saddar", 19.1);
	add_edges("F-10", "Saidpur Road", 12.6);
	add_edges("F-10", "Satellite Town", 13);
	add_edges("F-10", "Shakarparian", 14.2);
	add_edges("F-10", "Westridge", 13.9);
	add_edges("F-11", "G-10", 3);
	add_edges("F-11", "G-15", 14);
	add_edges("F-11", "Gulberg Green", 26.6);
	add_edges("F-11", "I-8", 11);
	add_edges("F-11", "I-9", 11);
	add_edges("F-11", "Margalla Town", 16);
	add_edges("F-11", "Murree Road", 14);
	add_edges("F-11", "Pakistan Town", 27);
	add_edges("F-11", "PWD", 27);
	add_edges("F-11", "Saddar", 19);
	add_edges("F-11", "Saidpur Road", 13);
	add_edges("F-11", "Satellite Town", 13);
	add_edges("F-11", "Shakarparian", 15);
	add_edges("F-11", "Westridge", 18);
	add_edges("Faizabad", "G-10", 11);
	add_edges("Faizabad", "G-15", 18);
	add_edges("Faizabad", "Gulberg Green", 17);
	add_edges("Faizabad", "I-8", 4);
	add_edges("Faizabad", "I-9", 3.3);
	add_edges("Faizabad", "Murree Road", 3);
	add_edges("Faizabad", "Pakistan Town", 18);
	add_edges("Faizabad", "PWD", 18);
	add_edges("Faizabad", "Shakarparian", 8.6);
	add_edges("Faizabad", "Shamsabad", 4.7);
	add_edges("Faizabad", "Soan Garden", 15);
	add_edges("Faizabad", "Westridge", 16);
	add_edges("G-10", "G-15", 14);
	add_edges("G-10", "Gulberg Green", 25);
	add_edges("G-10", "I-8", 9);
	add_edges("G-10", "I-9", 10);
	add_edges("G-10", "Margalla Town", 14);
	add_edges("G-10", "PWD", 25);
	add_edges("G-10", "Saddar", 17);
	add_edges("G-10", "Saidpur Road", 15);
	add_edges("G-10", "Shakarparian", 14);
	add_edges("G-10", "Shamsabad", 13);
	add_edges("G-10", "Westridge", 16);
	add_edges("G-15", "Gulberg Green", 34);
	add_edges("G-15", "I-8", 18);
	add_edges("G-15", "I-9", 17);
	add_edges("G-15", "Margalla Town", 24);
	add_edges("G-15", "Murree Road", 23);
	add_edges("G-15", "Pakistan Town", 34.9);
	add_edges("G-15", "Park View City", 36);
	add_edges("G-15", "PWD", 34);
	add_edges("G-15", "Saidpur Road", 16);
	add_edges("G-15", "Saddar", 15);
	add_edges("G-15", "Shakarparian", 21);
	add_edges("G-15", "Shamsabad", 19);
	add_edges("G-15", "Westridge", 12);
	add_edges("Gulberg Green", "I-8", 17);
	add_edges("Gulberg Green", "Margalla Town", 14.6);
	add_edges("Gulberg Green", "Pakistan Town", 8.9);
	add_edges("Gulberg Green", "PWD", 8.4);
	add_edges("Gulberg Green", "Rehmanabad", 17);
	add_edges("Gulberg Green", "Saddar", 16);
	add_edges("Gulberg Green", "Saidpur Road", 17);
	add_edges("Gulberg Green", "Satellite Town", 17);
	add_edges("Gulberg Green", "Shamsabad", 14);
	add_edges("Gulberg Green", "Soan Garden", 16);
	add_edges("I-8", "I-9", 2.1);
	add_edges("I-8", "Murree Road", 4.6);
	add_edges("I-8", "Pakistan Town", 18.2);
	add_edges("I-8", "PWD", 5.3);
	add_edges("I-8", "Saidpur Road", 5.4);
	add_edges("I-8", "Satellite Town", 5.4);
	add_edges("I-8", "Shakarparian", 8);
	add_edges("I-8", "Westridge", 15);
	add_edges("I-9", "Murree Road", 4.7);
	add_edges("I-9", "Pakistan Town", 18.6);
	add_edges("I-9", "Park View City", 21);
	add_edges("I-9", "PWD", 6.1);
	add_edges("I-9", "Saidpur Road", 4.6);
	add_edges("I-9", "Satellite Town", 4.6);
	add_edges("I-9", "Westridge", 13);
	add_edges("Margalla Town", "Murree Road", 4);
	add_edges("Margalla Town", "Park View City", 15);
	add_edges("Margalla Town", "Shakarparian", 5.9);
	add_edges("Margalla Town", "Shehzad Town", 6.7);
	add_edges("Margalla Town", "Soan Garden", 15);
	add_edges("Margalla Town", "Tramri", 12);
	add_edges("Murree Road", "Shamsabad", 1);
	add_edges("Murree Road", "Shehzad Town", 4.2);
	add_edges("Murree Road", "Tramri", 10);
	add_edges("Pakistan Town", "PWD", 22);
	add_edges("Pakistan Town", "Rehmanabad", 18);
	add_edges("Pakistan Town", "Saddar", 14);
	add_edges("Pakistan Town", "Saidpur Road", 17);
	add_edges("Pakistan Town", "Satellite Town", 17);
	add_edges("Pakistan Town", "Shakarparian", 20);
	add_edges("Pakistan Town", "Shamsabad", 15);
	add_edges("Pakistan Town", "Soan Garden", 3.7);
	add_edges("Park View City", "Shakarparian", 15);
	add_edges("Park View City", "Tramri", 14);
	add_edges("PWD", "Rehmanabad", 8.6);
	add_edges("PWD", "Saddar", 19);
	add_edges("PWD", "Saidpur Road", 17);
	add_edges("PWD", "Shakarparian", 8.5);
	add_edges("PWD", "Soan Garden", 2.2);
	add_edges("Rehmanabad", "Saidpur Road", 2.7);
	add_edges("Rehmanabad", "Satellite Town", 2.3);
	add_edges("Rehmanabad", "Shamsabad", 4);
	add_edges("Rehmanabad", "Westridge", 6.4);
	add_edges("Saddar", "Saidpur Road", 6.6);
	add_edges("Saddar", "Satellite Town", 7.5);
	add_edges("Saddar", "Westridge", 4.5);
	add_edges("Saidpur Road", "Satellite Town", 0.5);
	add_edges("Saidpur Road", "Westridge", 6);
	add_edges("Satellite Town", "Shamsabad", 3.4);
	add_edges("Shakarparian", "Shehzad Town", 6.3);
	add_edges("Shakarparian", "Tramri", 14);
	add_edges("Shamsabad", "Westridge", 6.3);
	add_edges("Shehzad Town", "Tramri", 4.9);
	
    cout<<"Emergency Response System"<<endl;
    for(int i=0;i<vertixcount;i++){
    	cout<<i+1<<"."<<" "<<vertices[i].label<<endl;
	}
	cout<<endl;
	int option;
    cout<<endl<<"Select Your Current Location From the Above:";
    cin>>option;
    cout<<endl<<endl;
    string goal=vertices[option-1].label;
    string source=getSource(goal);
    if(source!=goal){
    	pCost=dijkstra_algorithm(source,goal);
	}
    else{
    	pCost=1;
	}
    cout<<"Nearest Hospital: "<<Hospital<<endl<<endl;
    cout << "Shortest Route From Hospital to Your Location: "<<Hospital<<"->"<<source;
	if(source!=goal){
    	printpath(parent,get_index(goal));
	}
    cout<<endl<<endl;
    cout<<"Total Distance: "<<pCost+1<<" km"<<endl<<endl;
    cout<<"Don't worry! we'll be reaching you soon.";
    return 0;
}

