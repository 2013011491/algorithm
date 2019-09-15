//2013011491_¾ÈÂù¿µ_508
#include<stdio.h>
#include<stdlib.h>

void merge(int *data, int p, int q, int r){
	int size=r-p+1;
	int tempdata[size];
	int lstart=p, i=0, rstart=q+1;
	
	while(lstart<=q && rstart<=r){
		if(data[lstart]<data[rstart]){
			tempdata[i]=data[rstart];
			rstart++;
		}else{
		    tempdata[i]=data[lstart];
		    lstart++;
			}
		i++;
	}
	while(lstart<=q)
		tempdata[i++]=data[lstart++];
	while(rstart<=r)
	    tempdata[i++]=data[rstart++];
	for(i=0; i<size; i++){
		data[p++]=tempdata[i];
	}
}

void mergeSort(int *data, int left, int right){
	int middle;
	if(left<right){
		middle =(left+right)/2;
		mergeSort(data,left,middle);
		mergeSort(data,middle+1,right);
		merge(data,left,middle,right);
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
	mergeSort(data,0,a-1);
	for(i=0; i<a; i++){
		printf("%d\n",data[i]);
	}
	free(data);
	return 0;
}

