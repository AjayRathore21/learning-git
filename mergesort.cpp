#include<iostream>
#include<climits>
using namespace std;
  int partition(int input[],int si,int end){
	int key = input[si];
	int count =0;
	for(int i=si+1;i<=end;i++){
		if(input[i]<key){
			count++;
		}
	}
	int pi = si+count;
	int temp = input[si];
	input[si]=input[pi];
	input[pi]=temp;
	int i=si,j=end;
	  while(i<=pi&&j>=pi)
    {
        while(input[i]<=key)
        {
            i++;
        }
        while(input[j]>key)
        {
            j--;
        }
        if(i<pi&&j>pi)
        {
            int temp=input[i];
            input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
    }
  
    return pi;
}

 void  helper(int input[],int si,int end){
	if(end<=si){
		return;
	}
	int c = partition(input,si,end);
	helper(input,si,c);
	helper(input,c+1,end);
	return;
}

 void quicksort(int input[],int size){
	if(size==0 || size==1){
		return;
	}
	int si=0;
	int end=8;
	helper(input,si,end);
	return;
	
}

int main(){
	int input[9] = {10,4,43,5,57,91,45,9,7};
	quicksort(input,9);
	for(int i=0;i<9;i++){
		cout<<input[i]<<" ";
		
	}
}

// hello my name is ajay.