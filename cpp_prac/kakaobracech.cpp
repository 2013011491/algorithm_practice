#include <string>
#include <vector>

using namespace std;

string balance(string p)
{
    if(p=="") return p;
    int count=0;
    string u,v;
    for(int i=0; i<p.size(); i++)
    {
        if(p[i]=='(') count++;
        else if(p[i]==')') count--;
        if(count==0)
        {
            u=p.substr(0,i+1);
            if(i==p.size()-1) v="";
            else v=p.substr(i+1);
            break;
        }
    }
    int isright=1;
    count=0;
    if(u[0]=='(')
    {
        for(int i=0; i<u.size(); i++)
        {
            if(u[i]=='(') count++;
            else if(count!=0) count--;
            else
            {
                isright=0;
                break;
            }
        }
    }else isright=0;
    if(isright) return u+balance(v);
    else
    {
        string temp;
        for(int i=1; i<u.size()-1; i++)
        {
            if(u[i]=='(') temp.push_back(')');
            else temp.push_back('(');
        }
        return "("+balance(v)+")"+temp;
    }
    
}
string solution(string p) {
    string answer = "";
    answer=balance(p);
    
    return answer;
}