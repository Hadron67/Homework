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
	
	Node<string>* n3=new Node<string>("Special Relativity");
	Node<string>* n4=new Node<string>("General Relativity");
	n1->append(n3);
	n1->append(n4);
	
	Node<string>* n5=new Node<string>("Quatumn ElectroDynamics");
	Node<string>* n6=new Node<string>("Quatumn ChromoDynamics");
	Node<string>* n7=new Node<string>("Fermi Point Interaction Theory");
	Node<string>* n8=new Node<string>("Quatumn Gravity");
	n2->append(n5);
	n2->append(n6);
	n2->append(n7);
	n2->append(n8);
	
	Node<string>* n9=new Node<string>("String Theory");
	Node<string>* n10=new Node<string>("Loop quatumn gravity");
	Node<string>* n11=new Node<string>("Non-communicative geometry");
	Node<string>* n12=new Node<string>("Scaled Relativity");
	n8->append(n9);
	n8->append(n10);
	n8->append(n11);
	n8->append(n12);
	
	cout<<n->toXML()<<endl;
	n->destroy();
}
