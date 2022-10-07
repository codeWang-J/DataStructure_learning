#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

int main(void)
{
    int n; cin>>n;
    while(n--)
    {
        string s; cin>>s;
        map<char,int> mp;
        int p=0, t=0;
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]] ++;
            if(s[i] == 'P') p = i;
            if(s[i] == 'T') t = i;
        }
        if(mp.size()==3 && mp['T']==1 && mp['P']==1 && mp['A']!=0 && (p-t-1)>=1 && p*(p-t-1) == (s.size()-t-1))
            //mp里面仅有三种字母  只有一个T和P             A的数量不等于0    pt之间至少一个A  
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
      }
}

