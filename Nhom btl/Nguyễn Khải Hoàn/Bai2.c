#include<stdio.h>
#include<stdlib.h>
void nhapsl(int *n){
	do{
		printf("Nhap n: ");
		scanf("%d", n);
	}while(*n<=0 || *n>30);
}
void nhapM(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		printf("Nhap a[%d]: ",i);
		scanf("%d", (a+i));
	}
}
void xuatM(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", *(a+i));
	}
}
int tong(int *a, int n){
	int i,tong=0;
	for(i=0; i<n; i++){
		if(*(a+i)>0 && *(a+i)%3==0){
			tong+=*(a+i);
		}
	}
	return tong;
}
void nhapx(int *x){
	printf("\nNhap x: ");
	scanf("%d", x);
}
void chenx(int *a, int *n, int vt, int x){
	int i;
	a = (int*) realloc(a,(*n)*sizeof (int));
	for(i=*n; i>vt; i--){
		*(a+i)=*(a+i-1);
	}
	(*n)++;
	*(a+vt)=x;
}
void chen(int *a, int *n, int x) {
	int i;
	for(i=0; i<*n; i++) {
		if(*(a+i)<0) {
			chenx(a,n,i+1,x);
		}
	}
}

main(){
	int n,x;
	int *a;
	a=(int*)malloc(n*sizeof(int));
	nhapsl(&n);
	nhapM(a,n);
	printf("\nMang sau khi nhap: ");
	xuatM(a,n);
	printf("\nTong cac phan tu duong chia het cho 3: %d", tong(a,n));
	nhapx(&x);
	chen(a,&n,x);
	printf("\nMang sau khi chen: ");
	xuatM(a,n);
}
