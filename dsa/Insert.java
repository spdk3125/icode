public class Insert{
    public static void main(String[] args){
        int[] array={1,2,9,8,7,5,6,4,3};
        int n=array.length;

        for(int i=1; i<n; i++){
            int index=i;
            int nowval=array[i];
            int j=i-1;
            while(j>=0 && array[j] > nowval){
                array[j+1]=array[j];
                index=j;
                j--;
            }
            array[index]=nowval;
        }
        System.out.print("A[]=");
        for(int value : array){
            System.out.print(value+" ");
        }
    }
}
