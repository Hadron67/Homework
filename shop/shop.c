#include "shop.h"
//methods define

//class repository
static int repository_add(Repository* _this,Product* newp){
	for(int i=0;i<_this->count;i++){
		if(product_equals(newp,_this->products[i])){
			_this->num[i]++;
			return 0;
		}
	}
	if(_this->size==_this->count){
		return -1;
	}
	else {
		_this->products[_this->count++]=newp;
	}
}
static int repository_print(Repository* r){
	for(int i=0;i<r->count;i++){
		printf("-----------------\n"
			 "product: %s \n"
			 "version: %s \n"
			 "price  : %f \n"
			 "remain : %d \n",r->products[i]->name,r->products[i]->version,r->products[i]->price,r->num[i]);
	}
}
//end define
Product* product_new(char* name,char* version,float price){
	Product* p=(Product*)malloc(sizeof(Product));
	p->name=strdup(name);
	p->version=strdup(version);
	p->price=price;
	return p;
}
void product_free(Product* p){
	free(p->name);
	free(p->version);
	free(p);
}
int product_equals(Product* p1,Product* p2){
	return (!strcmp(p1->name,p2->name))&&(!strcmp(p1->version,p2->version))&&(p1->price,p2->price);
}
Repository* repository_new(char* name,int size){
	Repository* r=(Repository*)malloc(sizeof(Repository));
	r->name=strdup(name);
	r->products=(Product**)malloc(sizeof(void*)*size);
	r->num=(int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		r->num[i]=0;
	}
	r->size=size;
	r->count=0;
	
	//init methods
	r->add=repository_add;
	r->print=repository_print;
	return r;
}
void repository_free(Repository* r){
	free(r->name);
	free(r->num);
	for(int i=0;i<r->count;i++){
		product_free(r->products[i]);
	}
	free(r->products);
	free(r);
}
