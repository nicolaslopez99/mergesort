#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void mergelist(int a[],int start1,int end1,int start2,int end2){
	int finalStart=start1;
	int finalEnd=end2;
	int indexc=1;
	int result[end1+end2];
	while(start1<=end1 && start2<=end2){
		if(a[start1]<a[start2]){
			result[indexc]=a[start1];
			start1++;
		} else{
			result[indexc]=a[start2];
			start2++;
		}
		indexc++;
	}
	if(start1<=end1){
		for(int i=start1;i<=end1;i++){
			result[indexc]=a[i];
			indexc++;
		}
	}else{
		for(int i=start2;i<=end2;i++){
			result[indexc]=a[i];
			indexc++;
		}
	}
	indexc=1;
	for(int i=finalStart;i<=finalEnd;i++){
		a[i]=result[indexc];
		indexc++;
	}
}



void mergesort(int a[],int izq,int der){
	if(izq<der){
		int mitad=(izq+der)/2;
		mergesort(a,izq,mitad);
		mergesort(a,mitad+1,der);
		mergelist(a,izq,mitad,mitad+1,der);
	}	
}



int main(int argc, char** argv) {
	int n=5;
	int a[n];
	srand(time(NULL));
	for(int i=0;i<n;i++){
		a[i] = 500+rand() % (500);
		//a[i]=(6-i)*100;
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	mergesort(a,0,n-1);
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}
	return 0;
}
