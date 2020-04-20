//200407 stack_implement practice
#include <iostream>

using namespace std;

class Stack
{
    private:
        int e_size;
        int *element;

    public:
        Stack():e_size(0){element = new int[10001];}
        Stack(int n):e_size(0){element = new int[n];}
        ~Stack(){delete element;}

        bool push(int x){ element[e_size++]=x; }

        int pop(){ return empty()==1? -1: element[--e_size]; }

        int empty(){ return e_size==0? 1: 0; }

        int size(){ return e_size; }

        int top(){ return empty()==1? -1: element[e_size-1]; }
};


int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n,x;
    char *cmd; 
    cin>>n;
    Stack stack(n+1);
    
    for(int i=0; i<n; ++i)
    {
        cin>>cmd;
        if(cmd[0]=='p')
        {
            if(cmd[1]=='u')
            {               
                cin>>x;
                stack.push(x);
            }else cout<<stack.pop()<<"\n";
        }else if(cmd[0]=='t') cout<<stack.top()<<"\n";
        else if(cmd[0]=='s') cout<<stack.size()<<"\n";
        else if(cmd[0]=='e') cout<<stack.empty()<<"\n"; 
    }
    return 0;
}