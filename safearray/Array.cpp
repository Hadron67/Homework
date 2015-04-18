//#include "Array.hpp"
template<class _data_type>
	Array<_data_type>::Array(int size){
		this->data=new _data_type[size];
		this->size=size;
	}
template<class _data_type>
	Array<_data_type>::Array(Array& a){
		this->data=new _data_type[a.size];
		this->size=a.size;
		for(int i=0;i<a.size;i++){
			this->data[i]=a.data[i];
		}
	}
template<class _data_type>
	Array<_data_type>::~Array(){
		delete [] this->data;
	}
template<class _data_type>
	_data_type & Array<_data_type>::operator[](int index){
		if(index>=0&&index<this->size){
			return this->data[index];
		}
		else {
			//TODO:throw exception.
		}
	}
template<class _data_type>
	Array<_data_type> & Array<_data_type>::operator=(_data_type a){
		for(int i=0;i<this->size;i++){
			this->data[i]=a;
		}
		return *this;
	}
template<class _data_type>
	void Array<_data_type>::push(_data_type a){
		_data_type * newdata=new _data_type[this->size+1];
		for(int i=0;i<this->size;i++){
			newdata[i]=this->data[i];
		}
		newdata[this->size]=a;
		delete [] this->data;
		this->data=newdata;
		this->size++;
	}
template<class _data_type>
	void Array<_data_type>::shift(){
		if(this->size<=1){
			return;
		}
		_data_type * newdata=new _data_type[this->size-1];
		for(int i=0;i<this->size-1;i++){
			newdata[i]=this->data[i];
		}
		delete [] this->data;
		this->data=newdata;
		this->size--;
	}
template<class _data_type>
	int Array<_data_type>::length(){
		return this->size;
	}
