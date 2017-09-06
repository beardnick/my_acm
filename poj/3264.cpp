#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define N 200010
int data[N],ma,mi;
struct
{
    int left,right;
    int ma,mi;
}tree[N];
void build(int k)
{
    if(tree[k].left==tree[k].right)
    {
         tree[k].ma=tree[k].mi=data[tree[k].left];
       //  cout<<tree[k].left<<endl<<tree[k].right<<endl<<tree[k].ma<<endl;
    }
    else
    {
        int mid=(tree[k].right+tree[k].left)/2;
        tree[k*2].left=tree[k].left;
        tree[k*2].right=mid;
        tree[k*2+1].left=mid+1;
        tree[k*2+1].right=tree[k].right;
        build(2*k);
        build(2*k+1);
    tree[k].ma=max(tree[k*2].ma,tree[k*2+1].ma);
    tree[k].mi=min(tree[k*2].mi,tree[k*2+1].mi);
    }

}
void fin(int a,int b,int beg)
{
    int mid=(tree[beg].right+tree[beg].left)/2;
    if(a==tree[beg].left&&b==tree[beg].right){ma=max(tree[beg].ma,ma);mi=min(tree[beg].mi,mi);}
   else if(b<=mid)fin(a,b,beg*2);
    else if(a>mid)fin(a,b,beg*2+1);
    else  {
            fin(a,mid,beg*2);
            if(!(ma>=tree[beg].ma&&mi<=tree[beg].mi))
            fin(mid+1,b,beg*2+1);
            }
}
//int finmi(int a,int b,int beg)
//{
//    int mid=(tree[beg].right+tree[beg].left)/2;
//    if(a==tree[beg].left&&b==tree[beg].right)return tree[beg].mi;
//   else if(b<=mid)return finmi(a,b,beg*2);
//    else if(a>mid)return finmi(a,b,beg*2+1);
//    else  return min(finmi(a,mid,beg*2),finmi(mid+1,b,beg*2+1));
//}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        ma=0;
        mi=1000000;
        tree[1].left=1;
        tree[1].right=n;
        for(int i=1;i<=n;i++)
            scanf("%d",&data[i]);
        build(1);
//        for(int i=1;i<=n*2-1;i++)
//        {
//            cout<<tree[i].left<<' '<<tree[i].right<<' '<<tree[i].ma<<' '<<tree[i].mi<<endl;
//        }
        int a,b;
        while(q--)
        {
            ma=0;
            mi=1000001;
            scanf("%d%d",&a,&b);
            fin(a,b,1);
           printf("%d\n",ma-mi);
        }
    }
    return 0;
}
