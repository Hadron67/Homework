#include "shop.h"
//

//

Product* product_new(char* name,char* version,float price){
	Product* p=(Product*)malloc(sizeof(Product));
	p->name=strdup(name);		
	p->version=strdup(version);
	p->price=price;
	p->num=1;
	p->id=0;
	return p;
}
void product_free(Product* p){
	if(p!=NULL){
		free(p->name);
		free(p->version);
		free(p);
	}
}
int product_equals(Product* p1,Product* p2){
	return (!strcmp(p1->name,p2->name))&&(!strcmp(p1->version,p2->version))&&(p1->price==p2->price);	
}
static int findproductById(Product* p1,Product* p2){
	return p1->id==p2->id;
}
void product_print(Product* p){
		if (p->num>0) printf(
		       "-----------id: %d -------------------\n"
		       "Product : %s \n"
		       "Version : %s \n"
		       "Price   : %f \n"
		       "Remain  : %d \n",p->id,p->name,p->version,p->price,p->num);
}
Repository* repository_new(){
	return list_new();	
}
void repository_free(Repository* r){
	if(r!=NULL) list_free(r,product_free);
}
void repository_print(Repository* r){
		list_print(r,(nodeprint)product_print);
}
void repository_add(Repository* r,Product* newp){
	Node* n=list_find(r,newp,(nodeequal)product_equals);
	if (n!=NULL){
		((Product*)n->data)->num++;
		product_free(newp);	
	}
	else {
		newp->id=r->count+1;
		list_push(r,node_new(newp));	
	}
}
int repository_remove(Repository* r,int which){
	which++;
	Node* n=list_get(r,which);
	if(n==NULL) return -1;
	Product* temp=(Product*)n->data;
	if(temp->num==1){
		node_free(list_delete(r,which),product_free);
	}
	else {
		temp->num--;
	}
	return 0;
}
void repository_printproductsByName(Repository* r,char* name){
	Node* n=r->start;
	for(int i=0;i<r->count;i++){
		Product* temp=(Product*)n->data;
		if(!strcmp(r,temp)){
			product_print(temp);
		}
		n=n->next;
	}
}
