#include "shop.h"
#include <stdio.h>
#ifdef _Win32
	#define CLEAR system("cls")
#else 
	#define CLEAR system("clear")
#endif
void app_query(Repository* r){
	char name[100];
	printf("please input the name of the product you are looking for:");
	scanf("%s",name);
	printf("the following product(s) were found:\n");
	repository_printproductsByName(name);
}
void app_add(Repository* r){
	char name[100];
	char version[100];
	int price;
	int n;
	printf("input the name of the product you wish to add:");
	scanf("%s",name);
	printf("input the version of the product you wish to add:");
	scanf("%s",version);
	printf("input the price of the product you wish to add:");
	scanf("%d",&price);
	Product* p=product_new(name,version,price);
	printf("How many would you like to add?");
	scanf("%d",&n);
	if(n<=0){
		printf("add failed:Input error.\n");
		return;
	}
	p->num=n;
	repository_add(r,p);
	printf("product added successfully!\n");
}
void app_remove(Repository* r){
	int id;
	printf("please input the Id the product you wish to remove:");
	scanf("%d",&id);
	if(repository_remove(r,id)){
		printf("remove failed:product not found.\n");
		return;
	}
	printf("remove succeed!\n");
}
void app_main_loop(){
	Repository* r=repository_new();
	while(1){
		CLEAR;
		printf(
		"Please select options:\n"
		"1--List all the products.\n"
		"2--Query.\n"
		"3--add product to reposotory.\n"
		"4--remove product from repository.\n"
		"others--quit.\n");
		printf("Repository Manager> ");
		char* key[10];
		scanf("%s",key);
		if(!strcmp(key,"1")){
			repository_print(r);
		}
		else if(!strcmp(key,"2")){
			app_query(r);
		}
		else if(!strcmp(key,"3")){
			app_add(r);
		}
		else if(!strcmp(key,"4")){
			app_remove(r);
		}
		printf("would you like to quit ?(y/n)");
		scanf("%s",key);
		if(!strcmp(key,"y")) break;
	}
}
int main(int agv,char* ags[]){
	printf(
	"=========================================\n"
	"===This is computer Repository manager===\n"
	"=========================================\n");
	app_main_loop();
	printf("good bye.\n");
	return 0;
}
