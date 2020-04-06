#include<iostream>

using namespace std;
void array_rev()
{
	int temp,N,i,j,arr[1000];
	cin>>N;
	for(i=0;i<N;i++){
	cin>>arr[i];
	}
	for( i=0, j=N-1;i<j;i++,j--) {
	temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;	
	}
	for(int i=0;i<N;i++){
	cout<<arr[i]<<" ";
	}
}
int main()
{
	array_rev();
}
