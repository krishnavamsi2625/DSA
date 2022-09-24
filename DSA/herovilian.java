/******************************************************************************

                           HERO VILLIAN

*******************************************************************************/
import java.util.*;
public class Main
{   int mincount(List<Integer>h,List<Integer>v)
    {   int hi=0;
        int vi=0;
        int c=0;
        while(h.size()!=0 &&v.size()!=0)
        {
            if(h.get(hi)>v.get(vi))
            {   
                h.set(0,h.get(hi)-v.get(vi));
                v.remove(vi);
                //System.out.println(v.size()+" |"+h.size()+"|"+c+"|"+h.get(0));
                
                
            }
            else if(h.get(hi)<v.get(vi))
            {   
                h.remove(hi);
                //System.out.println(v.size()+" |"+h.size()+"|"+c+"|"+h.get(0));
                
            }
            else if(h.get(hi)==v.get(vi))
            {  
                h.remove(hi);
                v.remove(vi);
                //System.out.println(v.size()+" |"+h.size()+"|"+c+"|"+h.get(0));
                
                
            }
            c++;
            
        }
        return v.size();
    }
	public static void main(String[] args) {
		
		List<Integer>h=new LinkedList<>();
		List<Integer>v=new LinkedList<>();
		h.add(3);
		h.add(3);
		h.add(3);
		v.add(1);
		v.add(2);
		v.add(3);
		v.add(1);
		v.add(1);
		System.out.println(new Main().mincount(h,v));
		//System.out.println(new Main().workout(l,energy));
	}
}
