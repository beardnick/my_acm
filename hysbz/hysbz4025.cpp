#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define V 100100
struct edge {int to,be,en;};
int color[V],v,e;
vector<edge>g[V];
bool dfs(int v,int c,int t)
{
    color[v]=c;
    for(int i=0;i<g[v].size();i++)
    {
        if(t>=g[v][i].be&&t<g[v][i].en)
        {
              if(color[g[v][i].to]==c)return false;
        if(color[g[v][i].to]==0&&!dfs(g[v][i].to,-c,t))return false;
        }

    }
    return true;
}
void solve(int t)
{
    for(int i=0;i<v;i++)
    {
        if(color[i]==0)
        {
            if(!dfs(i,1,t)){cout<<"NO"<<endl;return;}
        }
    }
//    for(int i=1;i<=v;i++)cout<<color[i]<<' ';
//    cout<<endl;
    cout<<"YES"<<endl;
}
int main()
{
    int fin;
    while(cin>>v>>e>>fin)
    {
        int t,sub;
        edge a;
        for(int i=0;i<e;i++)
        {
            int form;
            cin>>sub>>a.to>>a.be>>a.en;
            g[sub].push_back(a);
            form=a.to;
            a.to=sub;
            g[form].push_back(a);
        }
//        for(int j=1;j<=v;j++)
//        {     cout<<j<<' ';
//             for(int i=0;i<g[j].size();i++)
//                    cout<<g[j][i].to<<' ';
//            cout<<endl;
//        }

        for(int i=0;i<fin;i++)
        {
            solve(i);
            memset(color,0,sizeof(color));
        }
    }
    return 0;
}
