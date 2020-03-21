import java.util.ArrayList;
import java.util.HashMap;

class Solution {
  public int[] solution(String msg) {
      ArrayList<Integer> answer = new ArrayList<Integer>();
      HashMap<String,Integer> trans = new HashMap<String,Integer>();
      for(int i=0; i<26; ++i)
      {
          String temp="";
          temp=temp+Character.toString('A'+i);
          trans.put(temp,i+1);
      }
      int count=27;
      int st=0;
      int index;
      while(true)
      {
          for(index=1; index<=msg.length()-st; ++index)
          {
              if(!trans.containsKey(msg.substring(st,st+index)))
              {
                  trans.put(msg.substring(st,st+index),count++);
                  break;
              }
          }
          answer.add(trans.get(msg.substring(st,st+index-1)));
          st+=index-1;
          if(st==msg.length()) break;
      }
      int[] result = new int[answer.size()];
      for(int i=0; i<result.length; ++i){result[i]=answer.get(i);}
      return result;
  }
}