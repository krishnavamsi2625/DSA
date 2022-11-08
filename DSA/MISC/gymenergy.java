/******************************************************************************

                           GYM ENERGY

*******************************************************************************/
import java.util.*;
public class Main
{   int workout(List<Integer>l,int energy)
    {
        int size=l.size();
        Collections.sort(l);
        int mc=0;
        int work_min=0;
        for(int i=size-1;i>-1;i--)
        {   mc=0;
            
            while(energy>0 && mc<2){
                //System.out.println(l.get(i));
                energy=energy-(l.get(i));
                mc++;
                work_min+=1;
            }
        }
        if(energy>0)
        return -1;
        return work_min;
    }
	public static void main(String[] args) {
		int energy=10;
		int tools[]={1,2};
		List<Integer>l=new LinkedList<>();
		l.add(1);
		l.add(1);
		l.add(1);
		l.add(1);
		l.add(2);
		l.add(4);
		System.out.println(new Main().workout(l,energy));
	}
}
