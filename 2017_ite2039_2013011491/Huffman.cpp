//2013011491_¾ÈÂù¿µ_508
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct data{
	char str[4];
	int freq;
	int nbit;
	struct data *left;
	struct data *right;
}fdata; 

void heapify(fdata*data,int index,int*length){
	int j;
	fdata key,min;
	key = data[index];
	if(index*2 > *length)
	return;
	if(index*2 == *length){
		min=data[2*index];
		j=2*index;
	}else{
		if(data[2*index].freq<data[2*index+1].freq){
			min = data[2*index];
			j=2*index;
		}else{
		    min = data[2*index+1];
		    j=2*index+1;
		}}
	if(min.freq<data[index].freq){
			data[index]=data[j];
			data[j]=key;
			heapify(data,j, length);
			}
}

void buildheap(fdata data[30000],int*length){
	int i;
	for(i=(*length/2); i>0; i--){
		heapify(data,i,length);
	}
}

void insertheap(fdata*data,int length,fdata temp){
	length++;
	data[length]=temp;
	buildheap(data,&length);
}

fdata *extramin(fdata*data,int *length,fdata*sortdata,int *slength){
	sortdata[*slength]=data[1];
	slength++;
	data[1]=data[*length];
	length--;
	buildheap(data,length);
	return &sortdata[*slength-1];
}
void nbit(fdata*sortdata,int nNbit){
	if(sortdata->left == NULL && sortdata->right== NULL){
		sortdata->nbit=nNbit;
	}
	nNbit++;
	if(sortdata->left!= NULL){
		nbit(sortdata->left,nNbit);
	}
	if(sortdata->right!= NULL){
		nbit(sortdata->right,nNbit);
	}
	
}
void huffman(fdata data[30000],int length){
	fdata temp;
	fdata sortdata[(length)*2];
	int slength=1;
	int n=length;
	int i;
	int t=0;
	for(i=1;i<n;i++){
		if(length==1){
			sortdata[slength]=data[1];
			break;
		}
		sortdata[slength]=data[1];
		slength++;
		data[1]=data[length];
		length--;
		buildheap(data,&length);
		temp.left=&sortdata[slength-1];
		sortdata[slength]=data[1];
		slength++;
		data[1]=data[length];
		length--;
		buildheap(data,&length);
		temp.right=&sortdata[slength-1];
	    temp.freq=sortdata[slength-2].freq+sortdata[slength-1].freq;
	    length++;
		data[length]=temp;
		buildheap(data,&length);
		}
nbit(&sortdata[slength],0);
	
		for(i=1;i<slength;i++){
			t=t+(sortdata[i].freq*sortdata[i].nbit);
		}
		printf("%d",t);
		
	}

int main(){
	fdata data[30001];
	int length,i;
	int j=1;
	int total;
	scanf("%d",&length);
	for(i=1;i<=length;i++){
		scanf("%s %d",data[i].str,&data[i].freq);
	}
	scanf("%d",&total);
	i=1;
	while(length>2*i){
		i=i*2;
		j++;
	}
	printf("%d\n",total*j);
	buildheap(data,&length);
	huffman(data,length);
	return 0;
}
