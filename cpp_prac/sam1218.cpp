#include<iostream>
#include<stack>

using namespace std;

int main(void)
{
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);

    int leng;
    for(int tc=0; tc<1; tc++)
    {
        int possi=0;
        stack<char> bucket;
        cin>>leng;
        char data[leng+1];
        cin>>data;

        cout<<"#"<<tc+1<<" ";

        //first char error extraction
        if(data[0]==')' || data[0]=='}' || data[0]==']' || data[0]=='>')
        {
            cout<<possi<<"\n";
            continue;
        }

        for(int i=0; i<leng; i++)
        {
            if(data[i]=='(' || data[i]=='{' || data[i]=='[' || data[i]=='<') bucket.push(data[i]);
            else if(data[i]==')')
            {
                if(bucket.top()=='(') bucket.pop();
                else break;
            }else if(data[i]=='}')
            {
                if(bucket.top()=='{') bucket.pop();
                else break;
            }else if(data[i]==']')
            {
                if(bucket.top()=='[') bucket.pop();
                else break;
            }else if(data[i]=='>')
            {
                if(bucket.top()=='<') bucket.pop();
                else break;
            }
        }
        if(bucket.empty()) possi=1;
        cout<<possi<<"\n";
    }
    return 0;
}