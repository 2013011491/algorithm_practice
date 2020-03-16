#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    int temp[n];
    for(int i=0; i<n; i++) temp[i]=arr1[i] | arr2[i];
    string line;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(temp[i]%2==1) line.insert(0,1,'#');
            else line.insert(0,1,' ');
            temp[i]/=2;
        }
        answer.push_back(line);
        line.clear();
    }
    return answer;
}