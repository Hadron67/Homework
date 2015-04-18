//#include "tree.hpp"
template<class _data_type>
	Node<_data_type>::Node(_data_type data){
		this->data=data;
		this->parient=NULL;
	}
template<class _data_type>
	Node<_data_type>::~Node(){
		//this->child.~vector();
		//data.~_data_type();
	}
template<class _data_type>
	void Node<_data_type>::append(Node* a){
		this->child.push_back(a);
		a->parient=this;
	}
template<class _data_type>
	void Node<_data_type>::get_count(int & n){
		int size=this->child.size();
		n+=size;
		for(int i=0;i<size;i++){
			this->child[i]->get_count(n);
		}
	}
template<class _data_type>
	int Node<_data_type>::count(){
		int n=0;
		this->get_count(n);
		return n;
	}
template<class _data_type>
	int Node<_data_type>::childcount(){
		return this->child->size();
	}
template<class _data_type>
	void Node<_data_type>::destroy(){
		int size=this->child.size();
		for(int i=0;i<size;i++){
			this->child[i]->destroy();
		}
		delete this;
	}
template<class _data_type>
	Node<_data_type>* Node<_data_type>::operator[](int index){
		if(index==-1){
			return this->parient;
		}
		return this->child[index];
	}
template<class _data_type>
	_data_type Node<_data_type>::getdata(){
		return this->data;
	}
template<class _data_type>
	Node<_data_type>* Node<_data_type>::childAt(int index){
		return this->child[index];
	}
template<class _data_type>
	Node<_data_type>* Node<_data_type>::_parient(){
		return this->parient;
	}
template<class _data_type>
	void Node<_data_type>::to_string(int tabs,string & s){
		string tab="";
		for(int i=0;i<tabs;i++){
			tab+="    ";
		}
		int n=this->child.size();
		if(n==0){
			s+=tab+"<Node cfy:data=\""+this->data+"\" />\n";
			return;
		}
		s+=tab+"<Node cfy:data=\""+this->data+"\">\n";
		for(int i=0;i<n;i++){
			this->child[i]->to_string(tabs+1,s);
		}
		s+=tab+"</Node>\n";
	}
template<class _data_type>
	string Node<_data_type>::toXML(){
		string s="<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<document xmlns:cfy=\"http://www.wikipedia.org\">\n";
		this->to_string(1,s);
		s+="</document>";
		return s;
	}
