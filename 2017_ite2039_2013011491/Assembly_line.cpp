//2013011491_¾ÈÂù¿µ_508
#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[2][100]={0};
	int t[2][99]={0};
	int s[2][2]={0};
	int l[2][99]={0};
	int p[99]={0};
	int e1,e2,x1,x2,n;
	int i;
	int bit=0;
	scanf("%d",&n);
	scanf("%d %d",&e1,&e2);
	scanf("%d %d",&x1,&x2);
	for(i=0; i<n; i++){
		scanf("%d",&a[0][i]);
	}
	for(i=0; i<n; i++){
		scanf("%d",&a[1][i]);
	}
	for(i=0; i<n-1; i++){
		scanf("%d",&t[0][i]);
	}
	for(i=0; i<n-1; i++){
		scanf("%d",&t[1][i]);
	}
	s[0][0]=e1+a[0][0];
	s[1][0]=e2+a[1][0];
	for(i=1; i<n; i++){
		if(s[0][bit]+a[0][i] < s[1][bit]+t[1][i-1]+a[0][i]){
			s[0][!bit]=s[0][bit]+a[0][i];
			l[0][i-1]=1;
		}else{
			s[0][!bit]=s[1][bit]+t[1][i-1]+a[0][i];
			l[0][i-1]=2;
		}
		if(s[1][bit]+a[1][i] < s[0][bit]+t[0][i-1]+a[1][i]){
			s[1][!bit]=s[1][bit]+a[1][i];
			l[1][i-1]=2;
		}else{
			s[1][!bit]= s[0][bit]+t[0][i-1]+a[1][i];
			l[1][i-1]=1;
		}
		bit=!bit;
	}

	if(s[0][bit]+x1<s[1][bit]+x2){
		printf("%d\n",s[0][bit]+x1);
		p[n-1]=1;
	}else{
		printf("%d\n",s[1][bit]+x2);
		p[n-1]=2;
	}
	for(i=n-2;i>=0;i--){
		p[i]=l[p[i+1]-1][i];
	}
	for(i=0; i<n; i++){
		printf("%d %d\n",p[i],i+1);
	}
	return 0;
}
