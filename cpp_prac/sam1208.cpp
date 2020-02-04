// 200204 13:34 start 13:46 end
#include<iostream>
#include<algorithm>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int tc=1; tc<=10; ++tc)
    {
        int dump;
        int box[100]={0,};

        cout<<"#"<<tc<<" ";
        cin>>dump;
        for(int i=0; i<100; ++i) { cin>>box[i]; }
        sort(box, box+100);
        
        for(int i=0; i<dump; ++i)
        {
            box[0]++;
            box[99]--;
            for(int j=1; j<100; ++j)
            {
                if(box[0]<=box[j])
                {
                    swap(box[0],box[j-1]);
                    break;
                }
            }
            for(int j=98; j>=0; --j)
            {
                if(box[99]>=box[j])
                {
                    swap(box[99],box[j+1]);
                    break;
                }
            }
        }
        cout<<box[99]-box[0]<<"\n";
    }
    return 0;
}