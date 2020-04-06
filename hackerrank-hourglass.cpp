#include<bits/stdc++.h>
using namespace std;
void array_hourglass()
{
	int i,j,arr[100][100],N,M,sum=0,max_sum=-63;  // as we are given that min value can be -9 so -9*7=-63
	for(i=0;i<6;i++){
	for(j =0;j<6;j++){
		cin>>arr[i][j];	
		}
	}
	for( i=0;i<4;i++) {
	for(j=0;j<4;j++){
		sum = (arr[i][j]+arr[i][j+1]+arr[i][j+2])+(arr[i+1][j+1])+(arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2]);
		if(max_sum<sum){
			max_sum=sum;
		}
	}	
	}
	cout<<max_sum;
}
int main()
{
array_hourglass();
}
