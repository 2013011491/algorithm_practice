//200203 15:18 start   17:38 end
#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<array>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    string num;
    int times=0;

    cin>>t;
    for(int tc=1; tc<=t; ++tc)
    {
        cout<<"#"<<tc<<" ";
        cin>>num>>times;

        if(num.size()==1)
        {
            cout<<num<<"\n";
            continue;
        }
        stack<string> nums;
        stack<array<int,2>> timess;

        nums.push(num);
        timess.push({times,0});

        int max=0;
        while(!nums.empty())
        {
            string prestr=nums.top();
            nums.pop();
            array<int,2> pres = timess.top();
            timess.pop();
            if(pres[0]==0 || pres[1]== num.size())
            {
                int ans;
                if(pres[0]%2==0)
                {
                    ans = stoi(prestr);
                }else 
                {
                    swap(prestr[prestr.size()-1],prestr[prestr.size()-2]);
                    ans = stoi(prestr);
                }
                if(ans>max) max=ans;
                continue;
            }
            int maxi=pres[1];
            for(int i=pres[1]+1; i<num.size(); ++i)
            {
                if(prestr[i]>prestr[maxi]) maxi=i;               
            }
            for(int i=pres[1]+1; i<num.size(); ++i)
            {
                if(prestr[i]==prestr[maxi])
                {
                    string temp = prestr;
                    swap(temp[pres[1]], temp[i]);
                    nums.push(temp);
                    timess.push({pres[0]-1,pres[1]+1});
                }
            }
            if(maxi==pres[1])
            {
                nums.push(prestr);
                timess.push({pres[0],pres[1]+1});
            }
        }
        cout<<max<<"\n";
    }
    return 0;
}