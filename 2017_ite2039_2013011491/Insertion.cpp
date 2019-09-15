//2013011491_¾ÈÂù¿µ_508 
#include <stdio.h>
#include <stdlib.h>

void insertionsort(int *data, int length){
	int i,j;
	int key;
	for(j=1; j<length; j++){
		key = data[j];
		i=j-1;
		while(i>=0 && data[i]<key){
			data[i+1]=data[i];
			i=i-1;
		}
		data[i+1]=key;
	}
}

int main(){
	int a;
	int i;
	scanf("%d",&a);
	int*data=(int*)malloc(sizeof(int)*a);
	for(i=0; i<a; i++){
		scanf("%d",&data[i]);
	}
	insertionsort(data,a);
	for(i=0; i<a; i++){
		printf("%d\n",data[i]);
	}
	free(data);
	return 0;
}
