#ifndef SHOP_H
#define SHOP_H
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "list.h"
typedef struct {
	char* name;
	char* version;
	float price;
	int num;
	int id;
}Product;
typedef List Repository;
Product* product_new(char* name,char* version,float price);
void product_free(Product* p);
int product_equals(Product* p1,Product* p2);
void product_print(Product* p);
Repository* repository_new();
void repository_free(Repository* r);
void repository_print(Repository* r);
void repository_add(Repository* r,Product* newp);
int repository_remove(Repository* r,int which);
#endif
