public class PermutedMultiples {
    public static void main(String[] args) {
        System.out.print(smallestNumber());
    }

    public static boolean areNumbersPermuted(int numberA, int numberB){
        int K = 10;
        int[] strengthOfDigits = new int[K];
        for(int i = 0; i < K; i++){
           strengthOfDigits[i] = 0;
        }

        while (numberA > 0){
            strengthOfDigits[numberA % 10]++;
            numberA /= 10;
        }

        while(numberB > 0){
            strengthOfDigits[numberB % 10]--;
            if(strengthOfDigits[numberB % 10] < 0) return false;
            numberB /= 10;
        }

        return true;
    }

    public static int smallestNumber(){
        int i = 1;
        int j;
        do{
            i++;

            j = i * 2;
            if(!areNumbersPermuted(i, j)) continue;

            j += i;
            if(!areNumbersPermuted(i, j)) continue;

            j += i;
            if(!areNumbersPermuted(i, j)) continue;

            j += i;
            if(!areNumbersPermuted(i, j)) continue;

            j += i;
            if(!areNumbersPermuted(i, j)) continue;
            break;
        }while (true);
        return i;
    }
}
