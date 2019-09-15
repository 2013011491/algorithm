//2013011491_¾ÈÂù¿µ_508
#include<stdio.h>
#include<stdlib.h>

void selectionSort(int*data,int length,int stop){
	int i,j=0;
	int min=0;
	int minindex;
	for(minindex=0; minindex<stop; minindex++){
		min=data[minindex];
		j=minindex;
		for(i=minindex+1;i<length;i++){
			if(min>data[i]){
				min=data[i];
				j=i;
			}
		}
		i=data[j];
		data[j]=data[minindex];
		data[minindex]=i;
	}
}

int main(){
	int a,b;
	int i;
	scanf("%d %d",&a,&b);
	int*data=(int*)malloc(sizeof(int)*a);
	for(i=0; i<a; i++){
		scanf("%d",&data[i]);
	}
	selectionSort(data,a,b);
	for(i=0; i<a; i++){
		printf("%d\n",data[i]);
	}
	free(data);
	return 0;
} 
