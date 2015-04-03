#include<stdio.h>
#include "shop.h"
int main(int agv,char* ags[]){
	Repository* r=repository_new("r1",3);
	Product* p1=product_new("Dell","Inspiron-7535",5600);
	Product* p2=product_new("Dell","Inspiron-7535",5600);
	r->add(r,p1);
	r->add(r,p2);
	r->print(r);
	repository_free(r);
}

