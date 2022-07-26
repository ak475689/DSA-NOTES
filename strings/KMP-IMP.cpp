#include <bits/stdc++.h>
using namespace std;
vector<int>prefix_function(string s){
	int n=s.size();
	vector<int>pi(n,0);
	for(int i=1;i<n;i++){
		int j=pi[i-1];
		while(j>0&&s[i]!=s[j]){
			j=pi[j-1];
		}
		if(s[i]==s[j])j++;
		pi[i]=j;
	}
	return pi;
}
int main() {
	
	int t;
	cin>>t;
	while(t--){
		string s,pat;
		cin>>s>>pat;
		int pos=-1;
		vector<int>pi=prefix_function(pat);
		int i=0,j=0;
        vector<int>vec;
		while(i<s.size()&&j<pat.size()){
            // cout<<i<<" "<<j<<"\n";
			if(s[i]==pat[j]){
				i++;
				j++;
			}
			else{
				if(j>0){
					j=pi[j-1];
				}
				else{
					i++;
				}
			}
			if(j==pat.size()){
				pos=i-pat.size();
                vec.push_back(pos+1);
                j=0;
				// break;
			}
		}
        if(vec.size()==0){
            cout<<"Not Found"<<"\n";
            continue;
        }
		cout<<(int)vec.size()<<"\n";
        for(auto it:vec)cout<<it<<" ";
        cout<<"\n";
	}
	return 0;
}