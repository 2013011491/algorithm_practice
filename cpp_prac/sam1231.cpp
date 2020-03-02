//200302 16:04 start d4 81.54% 16:36 end
//string 처리 미숙 getline(cin,str) 알아둘것 그전에 buffer제거하는거랑
#include<iostream>
#include<string>

using namespace std;
int n;
void inorder(string storag,int index)
{
    if(index*2<=n) inorder(storag,index*2);
    cout<<storag[index];
    if(index*2+1<=n) inorder(storag,index*2+1);
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int tc=1; tc<=10; ++tc)
    {
        cin>>n;
        string instr;
        string storag="0";
        int trash;
        getline(cin,instr);
        for(int i=0; i<n; ++i)
        {
            cin>>trash;
            getline(cin,instr);
            storag.push_back(instr[1]);
        }
        cout<<"#"<<tc<<" ";
        inorder(storag,1);
        cout<<"\n";
    }
    return 0;
}