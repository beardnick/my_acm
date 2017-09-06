10 #include<iostream>
11 using namespace std;
12
13 bool chess[6][6]={false};//���õ�ֻ�����ĵ�4x4
14 bool flag;
15 int step;
16 int r[]={-1,1,0,0,0};//���ڷ������
17 int c[]={0,0,-1,1,0};
18
19 bool judge_all(void)//�жϡ���һɫ��
20 {
21     int i,j;
22     for(i=1;i<5;i++)
23         for(j=1;j<5;j++)
24             if(chess[i][j]!=chess[1][1])
25                 return false;
26     return true;
27 }
28
29 void flip(int row,int col)//����
30 {
31     int i;
32     for(i=0;i<5;i++)
33         chess[row+r[i]][col+c[i]]=!chess[row+r[i]][col+c[i]];
34     return;
35 }
36
37 void dfs(int row,int col,int deep) //���ѵĵ����������ص㣬�����׻���
38 {
39     if(deep==step)
40     {
41         flag=judge_all();
42         return;
43     }
44
45     if(flag||row==5)return;
46
47     flip(row,col);       //����
48     if(col<4)
49         dfs(row,col+1,deep+1);
50     else
51         dfs(row+1,1,deep+1);
52
53     flip(row,col);      //�������򷭻���
54     if(col<4)
55         dfs(row,col+1,deep);
56     else
57         dfs(row+1,1,deep);
58
59     return;
60 }
61
62 int main(void)
63 {
64     char temp;
65     int i,j;
66     for(i=1;i<5;i++)
67         for(j=1;j<5;j++)
68         {
69             cin>>temp;
70             if(temp=='b')
71                 chess[i][j]=true;
72         }
73
74     for(step=0;step<=16;step++)  //��ÿһ�������Ŀ����Խ���ö��
75     {                            //����Ϊʲô��16�����ǵ�4x4=16�񣬶�ÿһ��ֻ�кڰ������������ȫ���Ŀ�����Ϊ2^16
76         dfs(1,1,0);
77         if(flag)break;
78     }
79
80     if(flag)
81         cout<<step<<endl;
82     else
83         cout<<"Impossible"<<endl;
84     return 0;
85 }
