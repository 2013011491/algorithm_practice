class Solution {
    public String solution(String m, String[] musicinfos) {
        String answer = "";
        int anst=0;
        int ansst=1441;
        for(int i=0; i<musicinfos.length; ++i)
        {
            String[] pres=musicinfos[i].split(",");
            String wholem="";
            int stt=Integer.parseInt(pres[0].substring(0,2))*60 + Integer.parseInt(pres[0].substring(3,5));
            int fit=Integer.parseInt(pres[1].substring(0,2))*60 + Integer.parseInt(pres[1].substring(3,5));
            int intert=fit-stt;
            int slen=pres[3].length();
            for(int j=0; j<pres[3].length(); ++j){if(pres[3].charAt(j)=='#') slen--;}
            for(int j=0; j<intert/slen; ++j){wholem=wholem+pres[3];}
            int count=intert%slen;
            for(int j=0; count!=0; j++)
            {
                wholem=wholem+pres[3].charAt(j);
                if(pres[3].charAt(j)!='#') count--;
            }
            wholem=wholem+"0";
            int k=-1;
            while(true)
            {
                k=wholem.indexOf(m,k+1);
                if(k==-1) break;
                else if(wholem.charAt(k+m.length())!='#') break; 
            }
            if(k!=-1)
            {
                if(intert>anst || (intert==anst && ansst>stt))
                {
                    answer=pres[2];
                    ansst=stt;
                    anst=intert;
                }
            }
        }
        if(answer=="") answer="(None)";
        return answer;
    }
  }