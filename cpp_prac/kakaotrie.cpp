#include <string>
#include <vector>
#include <map>

using namespace std;

class Trie
{
    bool finish;
    Trie* next[26];
    
    Trie()
    {
        finish=false;
        for(int i=0; i<26; ++i){next[i]=NULL;}
    }
    ~Trie()
    {
        for(int i=0; i<26; ++i){delete next[i];}
    }
    
    void insert(string str, int index)
    {
        if(index == str.size()) finish=true;
        else
        {
            int ni= str[index]-'a';
            if(next[ni]==NULL) next[ni] = new Trie();
            next[ni]->insert(str,index+1);
        }
    }
    int find(string str,int index, int depth, int ans)
    {
        if(index==str.size()) return ans;
        int count=0;
        for(int i=0; i<26; ++i)
        {
            if(next[i]!=NULL) count++;
        }
        if(count>1) ans=depth;
        return next[str[index]-'a']->find(str, index+1, depth+1, ans);
    }
}

int solution(vector<string> words) {
    int answer = 0;
return answer;
}