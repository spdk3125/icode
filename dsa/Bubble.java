public class Bubble {
    public static void main(String[] args){
        int[] array={7,3,2,6,9,4,1,0};
        int n = array.length;

        for(int i=0; i<n-1; i++){
            boolean swapped = false;
            for(int j=0; j<n-i-1; j++){
                if(array[j]>array[j+1]){
                    array[j]+=array[j+1];
                    array[j+1]=array[j]-array[j+1];
                    array[j]-=array[j+1];
                    swapped = true;   
                }

            }
            if(!swapped){
                break;
            }
        }
        System.out.print("A[]=");
        for(int i=0; i<n; i++){
            System.out.print(array[i]+" ");
        }
        System.out.println();
    }
}