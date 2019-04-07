#include<bits/stdc++.h>
using namespace std;

string x, y, z;
int c[27], s = 0;
bool f[27], t[27];

int main()
{
    memset(c,0,sizeof(c));
    memset(f,false,sizeof(f));
    memset(t,false,sizeof(t));
    cin>>x>>y>>z;
    for(int i = 0; i <x.size(); ++i)
    {
        if(!f[x[i]-'A'+1]&&!t[y[i]-'A'+1])
        {
            c[x[i]-'A'+1]=y[i];
            f[x[i]-'A'+1]=t[y[i]-'A'+1]=true;
            ++s;
        }    
        else if(c[x[i]-'A'+1]!=y[i])
        {
            cout<<"Failed";
            return 0;    
        }
    }
    if(s!=26)
    {
        cout<<"Failed";
        return 0;    
    }
    for(int i=0;i<z.size();++i)
    {
        printf("%c",c[z[i]-'A'+1]);    
    }
	return 0;
}    
