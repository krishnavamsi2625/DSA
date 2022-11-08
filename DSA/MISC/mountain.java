// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
class HelloWorld {
    int minmove(List<Integer> l)
        {
            int size=l.size();
            int min=size;
            int count=0;
            int i,j;
            if(size%2==0)
            {
                int mid=size/2-1;
                int temp=l.get(mid);
                for( i=mid,j=mid;i>-1&&j<size;i--,j++)
                {
                    if(l.get(i)!=temp)
                    count++;
                    if(l.get(j)!=temp)
                    count++;
                    temp--;
                }
                if(min>count)
                min=count;
                count=0;
                temp=l.get(0);
                for( i=0;i<size;i++)
                {
                    if(l.get(i)!=temp)
                    count++;
                    if(i<mid-1)
                    temp++;
                    else if(i==mid || i==mid+1)
                    continue;
                    else
                    temp--;
                }
                if(count<min)
                min=count;
            }
            else
            {
                int mid=size/2;
                int temp=l.get(mid);
                for(i=mid,j=mid;i>-1&&j<size;i--,j++)
                {
                    if(l.get(i)!=temp)
                    count++;
                    if(l.get(j)!=temp)
                    count++;
                    temp--;
                }
                if(min>count)
                min=count;
                count=0;
                temp=l.get(0);
                for( i=0;i<size;i++)
                {
                    if(l.get(i)!=temp)
                    count++;
                    if(i==mid)
                    continue;
                    else if(i<mid)
                    temp++;
                    else
                    temp--;
                }
                if(min>count)
                min=count;
            }
            return min;
        }
    public static void main(String[] args) {
        List<Integer> l=new LinkedList<>();
        l.add(1);
        l.add(2);
        l.add(3);
        l.add(4);
		l.add(5);
		System.out.print(new HelloWorld().minmove(l));
        }
        
    
}