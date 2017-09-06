#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
    vector<double>j,f,t;
    int m,n,k;
    double sum=0;
    while(scanf("%d%d",&m,&n)&&m>=0&&n>=0)
    {
        j.clear();
        f.clear();
        t.clear();
        sum=0;
        for(int i=0;i<n&&n;i++)
          {
              double j1,f1;
              cin>>j1>>f1;
              j.push_back(j1);
             f.push_back(f1);
             if(f1==0)t.push_back(-1);
             else t.push_back(j1/f1);
          }
        while(m&&n)
        {
            k=0;
            for(int i=1;i<n;i++)
            {
                if(t[i]>t[k])k=i;
            }
            t[k]=0;
            if(m<f[k]){sum+=(m*j[k]/f[k]);m=0;}
            else {sum+=j[k];m-=f[k];}
        }
        for(int i=0;i<n&&n;i++)if(t[i]==-1)sum+=j[i];
        double sum1=0;
        for(int i=0;i<n&&n;i++)sum1+=j[i];
        if(sum>sum1)printf("%.3f\n",sum1);
        else printf("%.3f\n",sum);
    }
    return 0;
}
