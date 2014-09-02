#include<iostream>
#include "Graph.h"
#include "Hamiltonian.h"
using namespace std;
int main()
{
	int V,E,v1,v2,T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cin>>V>>E;
		Graph g(V);
		for(int e=0;e<E;e++){
			cin>>v1>>v2;
			if(v1!=v2){
				//cout<<"Edge Added between "<<v1<<" "<<v2<<endl;
				g.addEdge(v1,v2);
			}
		}
		//cout<<"After creating graph"<<endl;
		Hamiltonian hPath(g);
		//cout<<"After ceration of hPath";
		if(hPath.cycleSize()==g.nVertices()){
			cout<<"Hamiltonian Cycle exists. Cycle: ";
			for(int i=0;i<hPath.cycleSize();i++)	
				cout<<hPath.cycle[i]<<" ";
		}else
			cout<<"No Hamiltonian cycle exists.";
		cout<<"\n";
	}
	return 0;
}
