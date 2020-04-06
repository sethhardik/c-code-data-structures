#include<bits/stdc++.h>

using namespace std;

void array_manupilation(){
	int n,m,a,b,k;
	cin>>n>>m;
	vector<long> arr;
	for(int i=0;i<n;i++){
		arr.push_back(0);
	}
	for(int i=0;i<m;i++){
		cin>>a>>b>>k;
		arr[a]+=k;   //  index a is k
		arr[b+1]-=k;  // index b+1 =-k
		
	}
	long max=arr[0],sum=0;
	for(int l=0;l<=n;l++){
		sum=sum+arr[l];
		if(sum>max){
			max=sum;
		}
	}
	cout<<max;
}

int main()
{
	array_manupilation();
	
	return 0;
}
