// homework of c language class in uestc
// this program is free software,you can redistrubute 
// it and/or modify under the terms of the GNU General 
// Public License.
#include <stdio.h>
#include <string.h>
void hanoi(int n,int a,int b,long*);
void hanoi(int n,int a,int b,long* steps){
	//int c=(a==1&&b==2||a==2&&b==1)?3:((a==1&&b==3||a==3&&b==1)?2:1);
	int c=6-a-b;
	if(n!=0){
		hanoi(n-1,a,c,steps);
		if(steps!=NULL) {
			(*steps)++;
			printf("step %ld : %d --> %d\n",*steps,a,b);
		}
		else{
			printf("%d --> %d\n",a,b);
		}
		hanoi(n-1,c,b,steps);
	}
}
int main(int agv,char* ags){
	printf("========Hanoi Tower Solver========\n");
	while(1){
		int n;
		long step=0;
		printf("input the number of disks to be solved:");
		scanf("%d",&n);
		hanoi(n,1,3,&step);
		printf("finished in %ld step(s).\n",step);
		printf("would you like to calculate again?(y/n)");
		//XXX:use scanf("%c") doesn't work,so i have to choose the following foolish way.
		char _continue[3];
		scanf("%s",_continue);
		if(!strcmp(_continue,"n")) break;
	}
	printf("good bye.\n");
}
