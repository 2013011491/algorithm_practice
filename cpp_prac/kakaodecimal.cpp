#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string trans="0123456789ABCDEF";
    
    int check=1;
    int limit=p+((t-1)*m)-1;
    int num=0;
    string bitstr="0";
    while(check<=limit)
    {
        num++;
        int cpnum=num;
        string revstr="";
        while(cpnum!=0)
        {
            revstr.push_back(trans[cpnum%n]);
            cpnum/=n;
        }
        check+=revstr.size();
        reverse(revstr.begin(),revstr.end());
        bitstr.append(revstr);
    }
    for(int i=p-1; i<=limit; i+=m){answer.push_back(bitstr[i]);}
    return answer;
}