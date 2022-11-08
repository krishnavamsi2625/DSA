// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=9;
        String str="111011";
        String temp[]=str.split("");
        int cash=7,swap=3,flip=2;
        if(swap>flip)
        {
            for(int i=0;i<temp.length;i++)
            if(temp[i].equals("1"))
            {
                cash=cash-flip;
                if(cash<0)
                break;
                temp[i]="0";
            }
            if(cash>0)
            {
            int index=-1;
            for(int i=0;i<temp.length;i++)
            if(temp[i].equals("1"))
            {  index=i;
                break;
            }
            int j=index+1;
            while(j<temp.length &&j>0)
            {
                if(temp[j].equals("0"))
                {   cash=cash-swap;
                    if(cash<0)
                    break;
                    temp[index]=temp[j];
                    cash=cash-swap;
                    index++;
                    
                }
                j++;
            }
            }
            
            
        }
        else 
        {   
        int index=-1;
        for(int i=0;i<temp.length;i++)
            if(temp[i].equals("1"))
            {   index=i;
                break;
            }
        int j=index+1;
        while(j<temp.length&&j>0)
        {
            if(temp[j].equals("0"))
            {   cash=cash-swap;
                if(cash<0)
                break;
                temp[index]=temp[j];
                temp[j]="1";
                index++;
            }
            j++;
        }
        //System.out.println(Arrays.toString(temp)+" "+cash);
        if(cash>0)
        {
        for(int i=0;i<temp.length;i++)
        if(temp[i].equals("1"))
        {
            cash=cash-flip;
            //System.out.println(cash);
            if(cash<0)
            break;
            temp[i]="0";
        }
        }
        }
        String str1="";
        for(int i=0;i<temp.length;i++)
        str1=str1+temp[i];
        
        System.out.print(Integer.parseInt(str1,2));
    }
}
            
            