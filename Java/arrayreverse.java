/*Read an array of 5 integers and reverse the contents inside the array. The element in index 0 should be moved to index 4 .
The element in index 5 should be moved to index 0 and so on. The entire array elements should be reversed and displayed to the
user. (5marks) */
import java.util.*;
public class arrayreverse {
    public static void main(String args[]){
        int[] arr = new int[5];
        Scanner input= new Scanner(System.in);
        for(int i=0; i<5;i++){
            arr[i]= input.nextInt();
        }
        for(int i=0; i<5;i++){
            if(i==(4-i)){
                break;
            }
            int temp= arr[i];
            arr[i]= arr[4-i];
            arr[4-i]= temp;
        }
        for(int i=0; i<5;i++){
            System.out.print(arr[i]+" ");
        }
        input.close();
    }
}