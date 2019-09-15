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
void heapSort(int*data,int length,int stop){
	int i,temp;
	buildheap(data,length);
	for(i=1; i<=stop; i++){
		temp=data[length];
		data[length]=data[1];
		data[1]=temp;
		length--;
		buildheap(data,length);
	}
}

int main(){
	int a,b;
	int i;
	scanf("%d %d",&a,&b);
	int*data=(int*)malloc(sizeof(int)*(a+1));
	for(i=1; i<=a; i++){
		scanf("%d",&data[i]);
	}
	heapSort(data,a,b);
	for(i=a; i>a-b; i--){
		printf("%d ",data[i]);
	}
	printf("\n");
	for(i=1; i<=(a-b); i++)
	{printf("%d ",data[i]);
	}
	free(data);
	return 0;
}
