import java.util.*;


class FractionalKnapsack{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n,w;
        n=sc.nextInt();
        w=sc.nextInt();

        int wt[]=new int[n];
        int val[]=new int[n];
        for(int i=0;i<n;i++){
            wt[i]=sc.nextInt();
        }
        for(int i=0;i<n;i++){
            val[i]=sc.nextInt();
        }
        System.out.println(String.format("%.6f",fractionalKnapsack(n,w,wt,val)));
    }

    static class ItemValue {
        Double cost;
        double wt, val, ind;
  
        public ItemValue(int wt, int val, int ind)
        {
            this.wt = wt;
            this.val = val;
            this.ind = ind;
            cost = (double)((double)val/(double)wt);
        }
    }
    static double fractionalKnapsack(int n, int capacity, int[] wt, int[] val)
    {
         ItemValue[] item = new ItemValue[wt.length];
  
        for (int i = 0; i < wt.length; i++) {
            item[i] = new ItemValue(wt[i], val[i], i);
        }
        Arrays.sort(item,(a,b)->
                b.cost.compareTo(a.cost));
   
     double totalValue = 0d;
  
        for (ItemValue i : item) {
  
            int curWt = (int)i.wt;
            int curVal = (int)i.val;
  
            if (capacity - curWt >= 0) {
                capacity = capacity - curWt;
                totalValue += curVal;
            }
            else {
               double fraction = ((double)capacity / (double)curWt);
                totalValue += (curVal * fraction);

               capacity
                    = (int)(capacity - (curWt * fraction));
                break;
            }
        }
  
        return totalValue;
    }  
}