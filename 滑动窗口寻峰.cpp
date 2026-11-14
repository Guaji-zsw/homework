#include <stdio.h>
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int *p=a;
	int *q=a+k;
	int i;
	int s=0;
	int b=0;
	for(i=0;i<n+1-k;i++){
		int sum=0;
		for(int j=i;j<k+i;j++){
			sum+=a[j];
		}
		if(sum>s){
			s=sum;
			b=i;
		}
		p++;
		q++;
	}
	printf("%d",b);
	
	
}
