//2020_01_30 16:53 start 1730 end
#include<iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int tc=1; tc<=10; ++tc)
    {  
        cout<<"#"<<tc<<" ";

        int tclen=0;
        int lheight=0;
        int rheight=0;
        int temp[5];
        int ans=0;
        
        cin>>tclen;
        cin>>temp[0]>>temp[1]>>temp[2]>>temp[3]>>temp[4];
        
        rheight=temp[3];
        if(rheight<temp[4]) rheight=temp[4];

        if(temp[2]>rheight) ans+=(temp[2]-rheight);

        for(int i=0; i<tclen-5; ++i)
        {  
            int newb;
            int maxheihgt;
            cin>>newb;
            if(temp[1]<temp[2]) lheight=temp[2];
            else lheight=temp[1];

            if(temp[4]<newb) rheight=newb;
            else rheight=temp[4];

            if(lheight>rheight) maxheihgt=lheight;
            else maxheihgt=rheight;

            if(temp[3]>maxheihgt) ans+=(temp[3]-maxheihgt);
            for(int j=0; j<4; ++j){ temp[j]=temp[j+1];}
            temp[4]=newb;
        }
        cout<<ans<<"\n";
    }
    return 0;
}