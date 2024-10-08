public class SelectSwap{
    public static void main(String[] args){
        int[] array={1,2,9,8,7,5,6,4,3};
        int n=array.length;

        for(int i=0; i<n; i++){
            int minin=i;
            for(int j=i+1; j<n; j++){
                if(array[j]<array[minin]){
                    minin=j;
                }
            }
            int temp = array[minin];
            array[minin] = array[i];
            array[i] = temp;
        
        }
        System.out.print("A[]=");
        for(int i=0; i<n; i++){
            System.out.print(array[i]+" ");
        }
        System.out.println();

    }
}