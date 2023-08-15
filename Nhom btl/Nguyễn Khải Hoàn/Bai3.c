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
int check(int *a, int n){
	int i,dem=0;
	for(i=0; i<n; i++){
		if(*(a+i)<=6){
			dem++;
		}
	}
	return dem;	
}
void nhapx(int *x){
	printf("\nNhap x: ");
	scanf("%d", x);
}
void xoa(int *a, int *n ,int vt){
	int i;
	a = (int*) realloc(a,(*n)*sizeof (int));
	for(i=vt; i<*n; i++){
		*(a+i)=*(a+i+1);
	}
	(*n)--;
}
void xoaX(int *a, int *n, int x){
	int i;
	for(i=0; i<*n; i++){
		if(*(a+i) == x){
			xoa(a,n,i);
			i--;
		}
	}
}
main(){
	int *a,n,x;
	a = (int*)malloc(n*sizeof(int));
	nhapsl(&n);
	nhapM(a,n);
	xuatM(a,n);
	if(check(a,n)==0){
		printf("\nMang a hop le!!!");
	}else{
		printf("\nMang a khong hop le!!!");
	}
	nhapx(&x);
	xoaX(a,&n,x);
	printf("\nMang sau khi xoa x: ");
	xuatM(a,n);
}
