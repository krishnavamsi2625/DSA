// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
class HelloWorld {
     int  cardss(List<String> l,int start,String target)
    {
        int size=l.size();
        start=start;
        
        int rm=0,lm=0,ri=start,li=start;
        while(true)
        { lm++;
          rm++;
          li--;
          ri++;

          if(l.get(li).equals(target))
          return lm;
          if(l.get(ri).equals(target))
          return rm;
        if(ri==size-1)
        ri=-1;
        if(li==0)
        li=size-1;

            
        }
        
    
    }
    public static void main(String[] args) {
        String tools[]={"red","blue","green","yellow"};
        List<String> l=new LinkedList<>();
        Collections.addAll(l,tools);
        int start=1;
        String target="yellow";
        System.out.println(new HelloWorld().cardss(l,start,target));
    }
}