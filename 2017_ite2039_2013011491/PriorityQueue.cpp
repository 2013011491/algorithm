//2013011491_¾ÈÂù¿µ_508
#include<stdio.h>
#include<stdlib.h>

void heapify(int*data,int index,int length){
	int key,j,max;
	key = data[index];
	if(index*2 > length)
	return;
	if(index*2 == length){
		max=data[2*index];
		j=2*index;
	}else{
		if(data[2*index]>data[2*index+1]){
			max = data[2*index];
			j=2*index;
		}else{
		    max = data[2*index+1];
		    j=2*index+1;
		}}
	if(max>data[index]){
			data[index]=data[j];
			data[j]=key;
			heapify(data,j, length);
			}
}

void buildheap(int*data,int length){
	int i;
	for(i=(length/2); i>0; i--){
		heapify(data,i,length);
	}
}
int main(){
	int a,l=0,e=0,i,key;
	int data[100000];
	int tempdata[100000];
	while(1){
		a=fgetc(stdin);
		switch(a)
		{
			case '0' : if(e!=0){
				for(i=1;i<=e;i++){
				printf("%d ",tempdata[i]);
			}}
			if(l!=0){
				printf("\n");
				for(i=1;i<=l;i++){
				printf("%d ",data[i]);
			}}
			return 0;
			
			case '1' : 
			scanf("%d",&data[++l]);
			buildheap(data,l);
			break;
			
			case '2' : if(l!=0){
			tempdata[++e]=data[1];
			data[1]=data[l];
			buildheap(data,--l);}
			break;
			
			case '3' : scanf("%d %d",&i, &key);
			if(i<=l && l>=1){
			
			data[i]=key;
			buildheap(data,l);}
			break;
			
			default : break;
	
			
		}
	}
	
	
	
}
