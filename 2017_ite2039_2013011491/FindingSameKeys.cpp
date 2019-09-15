//2013011491_¾ÈÂù¿µ_508
#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,m,a,i;
	int count = 0;
	int data1[100001]={0};
	scanf("%d %d",&n,&m);
	for(i=0; i<n; i++){
		scanf("%d",&a);
		data1[a]++;
	}
	for(i=0; i<m; i++){
		scanf("%d",&a);
		if(data1[a]>0)
		count++;
	}
	
printf("%d",count);
return 0;
}
