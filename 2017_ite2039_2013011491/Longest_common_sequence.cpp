//2013011491_¾ÈÂù¿µ_508
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void long_c_sub(char a[502],char b[502]){
	int c[502][502]={0};
	int n,m,strtail;
	int i,j;
	char printstring[502];
	if(strlen(a)<strlen(b)){
		n=strlen(b);
		m=strlen(a);
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(a[i-1]==b[j-1]){
					c[i][j]=c[i-1][j-1]+1;
				}else if(c[i][j-1]<c[i-1][j]){
					c[i][j]=c[i-1][j];
				}else{
					c[i][j]=c[i][j-1];
				}
		}
	}
		strtail=c[m][n];
		printstring[strtail]='\0';
		while(m!=0&&n!=0){
		if(a[m-1]==b[n-1]){
			printstring[strtail-1]=b[n-1];
			strtail--,m--,n--;
		}else if(c[m-1][n]<c[m][n-1]){
			n--;
		}else{
			m--;
		}
		
	}}else{
		n=strlen(a);
		m=strlen(b);
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(a[j-1]==b[i-1]){
					c[i][j]=c[i-1][j-1]+1;
				}else if(c[i][j-1]<c[i-1][j]){
					c[i][j]=c[i-1][j];
				}else{
					c[i][j]=c[i][j-1];
				}
		}
	}
		strtail=c[m][n];
		printstring[strtail]='\0';
		while(m!=0&&n!=0){
		if(a[n-1]==b[m-1]){
			printstring[strtail-1]=a[n-1];
			strtail--,m--,n--;
		}else if(c[m-1][n]<c[m][n-1]){
			n--;
		}else{
			m--;
		}
	
}}
printf("%s",printstring);
}


int main(){
	char A[502];
	char B[502];
	scanf("%s",&A);
	scanf("%s",&B);
	
	long_c_sub(A,B);
	return 0;
} 
