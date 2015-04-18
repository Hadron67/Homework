#ifndef ARRAY_H
#define ARRAY_H
template<class _data_type>
	class Array{
		private:
			_data_type * data;
			int size;
		public:
			Array(int size);
			Array(Array & a);
			~Array();
			_data_type & operator[](int index);
			Array & operator=(_data_type a);
			Array operator+(Array & a);
			Array operator-(Array & a);
			Array operator*(Array & a);
			
			void push(_data_type a);
			void shift();
			int length();
	};

#include "Array.cpp"
#endif

