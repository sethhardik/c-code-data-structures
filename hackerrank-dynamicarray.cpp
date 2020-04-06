#include<bits/stdc++.h>

using namespace std;

void dynamic_array(){
	int N,Q,lastanswer=0;
	int ch,x,y;
	int pos, loc;
	cin>>N>>Q;    // N= no fo sequence and Q = no. of queries
	vector<int> dp[N];
	for(int i=0;i<Q;i++){
		cin>>ch>>x>>y;
		pos=((x^lastanswer)%N);  // to choose which wequnce to append 
		if (ch==1){ 
			dp[pos].push_back(y);
		}
		else if(ch==2){
			loc=y%(dp[pos].size()); // to get loctaion of element in pos sequence
			lastanswer=dp[pos][loc]; // accessing the value
			cout<<lastanswer<<"\n";
		}
		
	}
}
int main()
{
	dynamic_array();
	return 0;
}
