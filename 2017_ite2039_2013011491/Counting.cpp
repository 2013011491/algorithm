//2013011491_¾ÈÂù¿µ_508
#include<stdio.h>
#include<stdlib.h>



int main(){
	int n,m,k,i;
	int data[100000];
	int count[100001]={0};
	int range_a[100000];
	int range_b[100000];
	scanf("%d %d %d",&n,&m,&k);
	for(i=0; i<k; i++){
		scanf("%d %d",&range_a[i],&range_b[i]);
	}
	for(i=0; i<n; i++){
		scanf("%d",&data[i]);
	}
	for(i=0; i<n; i++){
		count[data[i]]=count[data[i]]+1;
	}
	for(i=1; i<=m; i++){
		count[i]=count[i]+count[i-1];
	}
	for(i=0; i<k; i++){
		printf("%d\n",count[range_b[i]]-count[range_a[i]-1]);
	}
	return 0;

}
