#include<iostream>
#include<climits>
using namespace std;
void merge(int input[],int si,int end){
	int arr[end-si+1];
	int mid = (si+end)/2;
	int i = si;
	int j=mid+1;
    int k=0;
    while(i<=mid && j<=end){
    if(input[i]<input[j]){
        arr[k++]=input[i];
        i++;
    
    }else{
        arr[k++]=input[j];
        j++;
        
    }
    }
    for( i; i<=mid;i++){
        arr[k++]=input[i];
        //k++;
    }
    for( j; j<=end; j++){
        arr[k++]=input[j];
       // k++;
    }
    
    k=0;
    for(int i=si;i<=end;i++){
        input[i]=arr[k++];
    }
    return;
    
}




void helper(int input[],int si,int end){
	if(end<=si){
		return;
	}
	int mid = (si+end)/2;
	helper(input,si,mid);
	helper(input,mid+1,end);
	merge(input,si,end);
	return;
}


void mergesort(int input[],int size){
	if(size==0 || size==1){
		return;
	}
	int si = 0;
	int end = size-1;
	helper(input,si,end);
	return;
}
int main(){
	int input[9] = {10,4,43,5,57,91,45,9,7};
	mergesort(input,9);
	for(int i=0;i<9;i++){
		cout<<input[i]<<" ";
		
	}
}


// My Name Is Ajay Rathore
