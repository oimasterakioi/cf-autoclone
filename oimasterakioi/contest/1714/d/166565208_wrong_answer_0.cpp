#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
bool cmp(string a,string b){
	return a.size()>b.size();
}
void solve(){
	string t;
	cin>>t;
	int n;
	cin>>n;
	string s[n+1];
	for(int i=1;i<=n;++i)
		cin>>s[i];
	for(int i=1;i<=n;++i)
		if(t.find(s[i])==string::npos)
			s[i]="";
	sort(s+1,s+n+1,cmp);
	while(n>0&&s[n]=="")
		--n;
//	for(int i=1;i<=n;++i)
//		cerr<<s[i]<<' ';
//	cerr<<endl;
	if(n==0){
		cout<<-1<<endl;
		return;
	}
	int m=t.size();
	t=" "+t;
	bool color[m+1];
	for(int i=1;i<=m;++i)
		color[i]=false;
	vector<pair<int,int>>ans;
	for(int i=1;i<=m;++i){ // m �� 
		bool flag=true; // ����Ƿ�ȫ������ 
		for(int i=1;i<=m;++i)
			if(color[i]==false){
				flag=false;
				break;
			}
		if(flag==true)
			break;
			
		int maxi=-1; //�����±� 1-n 
		int maxv=0; // ���ļ�ֵ 
		int maxid=-1; // ���ĸ�λ�ÿ�ʼ�� 1-m 
		for(int j=1;j<=n;++j){ // ö��ÿһ�� 
			int maxmat=0; // ��ǰ���ƥ�� 
			int tid=-1; // ƥ���Ӧ�±� 
			for(int k=1;k+s[j].size()-1<=m;++k){ // ö���±� 
				bool match=true; // ����Ƿ�ƥ�� 
				int cnt=0; // ƥ������ 
				for(int l=0;l<s[j].size();++l){ // ����ƥ�� 
					if(s[j][l]!=t[k+l]){ // ��������, �˳�ƥ�� 
						match=false;
						break;
					}
					if(color[k+l]==false) // ͳ������ 
						++cnt;
				}
				if(match&&cnt>maxmat){
					maxmat=cnt; // ���ƥ�� 
					tid=k; // ����±� 
				}
			}
//			cerr<<j<<' '<<maxmat<<' '<<tid<<endl;
			if(maxmat>maxv){
				maxv=maxmat;
				maxi=j; // ��Ӧ��� 
				maxid=tid; // ����±� 
			}
		}
		if(maxi==-1||maxid==-1){
//			cerr<<i<<endl; 
			cout<<-1<<endl; // ������ 
			return;
		}
//		cerr<<i<<'-'<<maxi<<'-'<<maxid<<endl;
		ans.emplace_back(maxi,maxid); // ��¼ 
		for(int i=0;i<s[maxi].size();++i)
			color[i+maxid]=true; // ������д 
	}
	cout<<ans.size()<<endl;
	for(auto i:ans){
		cout<<i.first<<' '<<i.second<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--)
		solve();
}
