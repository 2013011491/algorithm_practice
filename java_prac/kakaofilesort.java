import java.util.Collections;
import java.util.ArrayList;
import java.util.List;

public class strnum implements Comparable<strnum>
{
    public String str;
    public int num;
    public strnum(){str=""; num=0;}
    public strnum(String str, int num)
    {
        this.str=str;
        this.num=num;
    }
    public int compareTo(strnum rhs)
    {
        String lhead="",rhead="";
        String lnum="00000",rnum="00000";
        int numst,numfi;
        for(numst=0; numst<this.str.length(); ++numst)
        {
            if(Character.isDigit(this.str.charAt(numst)))
            {
                lhead=this.str.substring(0,numst).toLowerCase();
                break;
            }
        }
        for(numfi=numst+1; numfi<this.str.length(); ++numfi){if(!Character.isDigit(this.str.charAt(numfi))) break;}
        lnum=lnum.substring(0,5-numfi+numst)+this.str.substring(numst,numfi);
           
        for(numst=0; numst<rhs.str.length(); ++numst)
        {
            if(Character.isDigit(rhs.str.charAt(numst)))
            {
                rhead=rhs.str.substring(0,numst).toLowerCase();
                break;
            }
        }
        for(numfi=numst+1; numfi<rhs.str.length(); ++numfi){if(!Character.isDigit(rhs.str.charAt(numfi))) break;}
        rnum=rnum.substring(0,5-numfi+numst)+rhs.str.substring(numst,numfi);
        if(lhead.compareTo(rhead)==1) return 1;
        else if(lhead.compareTo(rhead)==0)
        {
            if(lnum.compareTo(rnum)==1) return 1;
            else if(lnum.compareTo(rnum)==0)
            {
                if(this.num>rhs.num) return 1;
            }
        }
        return -1;
    }
    
    
}
class Solution {
  public String[] solution(String[] files) {
      List<strnum> answer = new ArrayList<>();
      for(int i=0; i<files.length; ++i)
      {
          answer.add(new strnum(files[i],i));
      }
      Collections.sort(answer);
      String[] result= new String[files.length];
      for(int i=0; i<result.length; ++i)
      {
        result[i]=answer.get(i).str;
      }
      return result;
  }
}