#include<bits/stdc++.h>

using namespace std;

void sparse_array(){
	int n,q,count=0;
	cin>>n;
	vector<string> str(n+1);
	for(int i=0;i<=n;i++){
		string str_item;
		getline(cin,str_item);
		str[i]=str_item;
	}
	cin>>q;
	vector<string> que(q+1);
	for(int j=0;j<=q;j++){
		string query_item;
		getline(cin,query_item);
		que[j]=query_item;
	}
	for(int i=1;i<=q;i++){
		count=0;
		for(int j=1;j<=n;j++){
			if(str[j]==que[i])
			++count;
		}
		cout<<count<<"\n";	}
}

int main()
{
	sparse_array();
	return 0;
	
}
