#include<iostream>
#include "tree.hpp"
#include<string>
using namespace std;
int main(int agv,char* ags[]){
	//I drawn a picture of our present physics theories with Nodes.
	Node<string>* n=new Node<string>("Foundamental Physics");
	Node<string>* n1=new Node<string>("Relativity");
	Node<string>* n2=new Node<string>("Quatumn Theory");
	n->append(n1);
	n->append(n2);
	
	n1->append(new Node<string>("Special Relativity"));
	n1->append(new Node<string>("General Relativity"));
	
	Node<string>* n8=new Node<string>("Quatumn Gravity");
	n2->append(new Node<string>("Quatumn ElectroDynamics"));
	n2->append(new Node<string>("Quatumn ChromoDynamics"));
	n2->append(new Node<string>("Fermi Point Interaction Theory"));
	n2->append(n8);
	
	n8->append(new Node<string>("String Theory"));
	n8->append(new Node<string>("Loop quatumn gravity"));
	n8->append(new Node<string>("Non-communicative geometry"));
	n8->append(new Node<string>("Scaled Relativity"));
	
	cout<<n->toXML()<<endl;
	n->destroy();
}
