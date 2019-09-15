//2013011491_¾ÈÂù¿µ_508
#include<stdio.h>
#include<stdlib.h>

#define MAX 2147483646

void print_parenthesis(int s[101][101],int st,int fi){
	int i=0;
	if(fi==st+1){
		printf("( %d %d ) ",st,fi);
	}else if(fi==st){
		printf("%d ",fi);
	}else{
		printf("( ");
		i=s[st][fi];
		print_parenthesis(s,st,i);
		print_parenthesis(s,i+1,fi);
		printf(") ");
	}
	 
	
	
}

void matrix_Chain(int *p, int n){
	int m[101][101]={0};
	int s[101][101]={0};
	int i,j,k,l,min;
	for(i=2; i<=n; i++){
		j=1;
		for(k=i; k<=n; k++,j++){
			min=MAX;
			for(l=j;l<k;l++){
				if(min>m[j][l]+m[l+1][k]+p[j-1]*p[l]*p[k]){
					min=m[j][l]+m[l+1][k]+p[j-1]*p[l]*p[k];
					m[j][k]=min;
					s[j][k]=l;
				}
			}
		}
	}
	printf("%d\n",m[1][n]);
	print_parenthesis(s,1,n);
}

int main(){
	int p[101]={0};
	int n;
	scanf("%d",&n);
	for(int i=0; i<=n; i++){
		scanf("%d",&p[i]);
	}
	matrix_Chain(p, n);
	return 0;
} 
