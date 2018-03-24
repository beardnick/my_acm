#include<iostream>
using namespace std;
int tot,C[100],n;
void search(int cur)

{
    if(cur==n)
    {
        tot++;
//        for(int i=0;i<n;i++)
//            cout<<"("<<i+1<<","<<C[i]+1<<")"<<' ';
//        cout<<"     "<<tot<<endl;
    }
    else for(int i=0;i<n;i++)//外循环，假定一个本列皇后的位置
    {
        int ok=1;
        C[cur]=i;
        for(int j=0;j<cur;j++)//内循环，检查是否与j列的矛盾，若不矛盾则向下一列走，矛盾则改变本列皇后位置
            if(C[cur]==C[j]||cur-C[cur]==j-C[j]||cur+C[cur]==j+C[j])
        {
            ok=0;break;
        }
        if(ok)search(cur+1);
    }//如果全都矛盾，这条路就不会继续往下走了，废弃掉，不会影响tot的值
}
int main()
{
    tot=0;
    cin>>n;
    search(0);
    cout<<tot<<endl;
    return 0;
}
