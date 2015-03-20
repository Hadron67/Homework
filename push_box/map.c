// this program is free software
// you can redistribute it and/or
// modify under the terms of the 
// GNU General Public License.
#include "map.h"
char* strreplicate(const char* s);
void map_init(Map* m,int width,int height){
	m->data=(char*)malloc(sizeof(char)*width*height);
	m->boxes=(int*)malloc(sizeof(int)*width*height);
	for(int i=0;i<width*height;i++) {
		m->data[i]='#';
		m->boxes[i]=0;
	}
	m->width=width;
	m->height=height;
	m->p_x=m->p_y=0;
}
void map_init_from_string(Map* m,int width,int height,const char* s){
	m->data=(char*)malloc(sizeof(char)*width*height);
	m->boxes=(int*)malloc(sizeof(int)*width*height);
	m->width=width;
	m->height=height;
	for(int i=0;i<width*height;i++) {
		if(s[i]=='#'||s[i]=='.'||s[i]=='_'){
			m->data[i]=s[i];
			m->boxes[i]=0;
		}
		else if(s[i]=='A'){
			m->data[i]='_';
			m->boxes[i]=0;
			m->p_x=i%width;
			m->p_y=(i-m->p_x)/width;
		}
		else if(s[i]=='M'){
			m->data[i]='_';
			m->boxes[i]=1;
		}
	}
}
Map* map_new(int width,int height){
	Map* output=(Map*)malloc(sizeof(Map));
	map_init(output,width,height);
	return output;
}
Map* map_new_from_string(int width,int height,const char* s){
	Map* output=(Map*)malloc(sizeof(Map));
	map_init_from_string(output,width,height,s);
	return output;
}
void map_free(Map* m){
	free(m->data);
	free(m->boxes);
	free(m);
}
Map* map_get(int which){
	static const char* mapdata1=
	"___###____" 
	"___#.#____"
	"___#_#____"
	"___#M#####"
	"___#__M._#"
	"####A_####"
	"#._M_M#___"
	"#####_#___"
	"____#.#___"
	"____###___";
	static const char* mapdata2=
	"__######__" 
	"###__._###"
	"#_M.MMM__#"
	"#_#_#._#_#"
	"#_A._._#_#"
	"####_M___#"
	"___#M.####"
	"___#__#___"
	"___####___"
	"__________";
	static const char* mapdata3=
	"__#####___"
	"_##___##__"
	"_#__M..##_"
	"##M_#.M.#_"
	"#___#...#_"
	"#_M###M_#_"
	"#__M_M_##_"
	"##A____#__"
	"_#######__"
	"__________";
	static const char* mapdatas[10];
	mapdatas[0]=mapdata1;
	mapdatas[1]=mapdata2;
	mapdatas[2]=mapdata3;
	return map_new_from_string(10,10,mapdatas[which]);
}
void map_setbox(int which){
	//static 
}
void map_print(Map* map){
	for(int i=0;i<map->height;i++){
		for(int j=0;j<map->width;j++){
			if(i==map->p_y&&j==map->p_x){
				printf("%c ",'A');
			}
			else if(map->boxes[j+i*map->width]){
				printf("%c ",'M');
			}
			else {
				printf("%c ",map->data[j+i*map->width]);
			}
		}
		printf("\n");
	}
}
char* strreplicate(const char* s){
	int l=strlen(s);
	char* output=(char*)malloc(sizeof(char)*(l+1));
	for(int i=0;i<l;i++){
		output[i]=s[i];
	}
	output[l]='\0';
	return output;
}
int map_isblocked(Map* map,int x,int y){
	if(x<0||y<0||x>map->width-1||y>map->height-1) return 1;
	else {
		return map->data[x+y*map->width]=='#';
	}
}
int map_isbox(Map* map,int x,int y){
	if(x<0||y<0||x>map->width-1||y>map->height-1) return 0;
	return map->boxes[x+y*map->width];
}
void map_move(Map* map,int action){
	static int m_y[]={-1,0,1,0};
	static int m_x[]={0,1,0,-1};
	if(!map_isblocked(map,map->p_x+m_x[action],map->p_y+m_y[action])){
		if(map_isbox(map,map->p_x+m_x[action],map->p_y+m_y[action])){
			int x1=map->p_x+m_x[action]*2;
			int y1=map->p_y+m_y[action]*2;
			if(map_isblocked(map,x1,y1)||map_isbox(map,x1,y1)){
				return;
			}
			else{
				map->boxes[x1+y1*map->width]=map->boxes[map->p_x+m_x[action]+map->width*(map->p_y+m_y[action])];
				map->boxes[map->p_x+m_x[action]+map->width*(map->p_y+m_y[action])]=0;
				map->p_x+=m_x[action];
				map->p_y+=m_y[action];
			}
		}
		else{
			map->p_x+=m_x[action];
			map->p_y+=m_y[action];
			
		}
	}
}
int map_iswin(Map* map){
	for(int i=0;i<map->width*map->height;i++){
		if(map->boxes[i]){
			if(map->data[i]!='.') return 0;
		}
	}
	return 1;
}
