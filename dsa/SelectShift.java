public class SelectShift{
    public static void main(String[] args){
        int[] array={1,2,9,8,7,5,6,4,3};
        int n=array.length;

        for(int i=0; i<n-1; i++){
            int minin=i;
            for(int j=i+1; j<n; j++){
                if(array[j]<array[minin]){
                    minin=j;
                }
            }
            int minval=array[minin];
            for(int k=minin; k>i; k--){
                array[k]=array[k-1];
            }
            array[i]=minval;
        
        }
        System.out.print("A[]=");
        for(int i=0; i<n; i++){
            System.out.print(array[i]+" ");
        }
        System.out.println();

    }
}