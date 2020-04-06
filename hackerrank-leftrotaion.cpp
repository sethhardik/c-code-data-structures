#include<bits/stdc++.h>

using namespace std;

void left_rotation(){
	int n, d,j,k,temp, a[100000];
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<d;i++){
		temp=a[0];
		for(j=0;j<n;j++){
			a[j]=a[j+1];
		
		}
		a[n-1]=temp;
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
}
int main(){
	left_rotation();
	
	return 0;
}
