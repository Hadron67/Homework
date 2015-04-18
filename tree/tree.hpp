#ifndef TREE_H
#define TREE_H
#include<vector>
#include<string>
using namespace std;
template<class _data_type>
	class Node{
		private:
			_data_type data;
			vector<Node*> child;
			Node* parient;
			void get_count(int & n);
			void to_string(int tabs,string & s);
		public:
			Node(_data_type data);
			~Node();
			void append(Node* a);
			int count();
			int childcount();
			Node* operator[](int index);
			Node* childAt(int index);
			Node* _parient();
			void destroy();
			_data_type getdata();
			string toXML();
	};
//XXX:Strange! this class failed to link with tree.cpp , so i have to use this foolish method. 
#include "tree.cpp"
#endif //TREE_H
