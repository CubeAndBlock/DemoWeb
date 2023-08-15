#include<stdio.h>
#include<stdlib.h>
void nhapsl(int *n){
	do{
		printf("Nhap n: ");
		scanf("%d",n);
	}while(*n<=0 || *n>=30);
}
void nhapM(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		printf("Nhap a[%d]: ", i);
		scanf("%d", (a+i));
	}
}
void xuatM(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", *(a+i));
	}
}
void inDC(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		if(*(a+i)>0 && *(a+i)%2==0){
			printf("%d ", *(a+i));
		}
	}
}
void sapxep(int *a, int n){
	int i,j,temp;
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(*(a+i) > *(a+j)){
				temp = *(a+i); 
				*(a+i) = *(a+j);
				*(a+j) = temp;
			}
		}
	}
}
int inMin(int *a, int n){
	int i,min;
	for(i=0; i<n; i++){
		if(*(a+i)>0){
			if(*(a+i)<min){
				min=*(a+i);
			}
		}
	}
	return min;
}
int max(int *a, int n){
	int i, max = *(a+0);
	for(i=1; i<n; i++){
		if(*(a+i) > max){
			max = *(a+i);
		}
	}
	int max2 = max;
	for(i=0; i<n; i++){
		if(*(a+i)!=max){
			max2=*(a+i);
			break;
		}
	}
	for(i=0; i<n; i++){
		if(*(a+i)!=max && *(a+i)>max2){
			max2=*(a+i);
		}
	}
	return max2;
}
main(){
	int *a,n;
	a=(int*)malloc(n*sizeof(int));
	nhapsl(&n);
	nhapM(a,n);
	printf("\nMang sau khi nhap: ");
	xuatM(a,n);
	printf("\nCac phan tu chan duong trong mang: ");
	inDC(a,n);
	sapxep(a,n);
	printf("\nMang sau khi sap xep: ");
	xuatM(a,n);
	printf("\nPhan tu duong nho nhat trong mang: %d", inMin(a,n));
	printf("\nGia tri lon thu 2 trong mang: %d",max(a,n));
}
