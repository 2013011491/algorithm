//2013011491_¾ÈÂù¿µ_508
#include<stdio.h>
#include<stdlib.h>


int main(){
	int n,i,j;
	int data[101]={0};
	int q=0;
	scanf("%d",&n);
	int *rod = (int*)malloc(sizeof(int)*(n+1));
	int*slice=(int*)malloc(sizeof(int)*(n+1));
	rod[0]=slice[0]=0;
	for(i=1; i<=n; i++){
		scanf("%d",&data[i]);
	}
	for(j=1; j<=n; j++){
		for(i=1; i<=j; i++){
			if(q<data[i]+rod[j-i]){
				q=data[i]+rod[j-i];
				slice[j]=i;
			}
		}
		rod[j]=q;
	}
	q=0;
	for(i=1;i<=n;i++){
		if(q<rod[i]){
			q=rod[i];
			j=i;
		}
	}
	printf("%d\n",q);
	while(j>0){
	printf("%d ",slice[j]);
	j=j-slice[j];
}
	return 0;
}
