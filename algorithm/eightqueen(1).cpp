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
    else for(int i=0;i<n;i++)//��ѭ�����ٶ�һ�����лʺ��λ��
    {
        int ok=1;
        C[cur]=i;
        for(int j=0;j<cur;j++)//��ѭ��������Ƿ���j�е�ì�ܣ�����ì��������һ���ߣ�ì����ı䱾�лʺ�λ��
            if(C[cur]==C[j]||cur-C[cur]==j-C[j]||cur+C[cur]==j+C[j])
        {
            ok=0;break;
        }
        if(ok)search(cur+1);
    }//���ȫ��ì�ܣ�����·�Ͳ�������������ˣ�������������Ӱ��tot��ֵ
}
int main()
{
    tot=0;
    cin>>n;
    search(0);
    cout<<tot<<endl;
    return 0;
}
