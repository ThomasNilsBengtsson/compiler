public class Sum{
    public static void main(String[] a){
        System.out.println(new Test().sum(100));
    }
}

class Test{
    public int sum(int num){
        int sum;
        sum = 0;
        while (0 < sum){
            sum = sum + num;
            num = num - 1;
        }
        return sum;
    }
}