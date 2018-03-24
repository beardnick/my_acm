#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
bool failed;
const int maxn=280;
struct Node
{
    bool have_value;
    int v;
    Node *left,*right;
    Node():have_value(false),left(NULL),right(NULL){}
};
Node *root;
Node* newnode(){return new Node();}
void addnode(int v,char*s)
{
    int n=strlen(s);
    Node* u=root;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L')
        {
            if(u->left==NULL)u->left=newnode();
            u=u->left;
        }
        else if(s[i]=='R')
        {
            if(u->right==NULL)u->right=newnode();
            u=u->right;
        }
    }

        if(u->have_value)failed=true;
        u->v=v;
        u->have_value=true;
}
char s[maxn];
bool read_input()
{
    failed=false;
    root=newnode();
    for(;;)
    {
        if(scanf("%s",s)!=1)return false;
        if(!strcmp(s,"()"))break;
        int v;
        sscanf(&s[1],"%d",&v);
        addnode(v,strchr(s,',')+1);
    }
    return true;
}
bool bfs(vector<int>& ans)
{
    queue<Node*>q;
    ans.clear();
    q.push(root);
    while(!q.empty())
    {
        Node* u=q.front();q.pop();
        if(!u->have_value)return false;
        ans.push_back(u->v);
        if(u->left!=NULL)q.push(u->left);
        if(u->right!=NULL)q.push(u->right);
    }
    return true;
}
int main()
{
    vector<int>ans;
    read_input();
    bfs(ans);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<' ';
    return 0;
}
