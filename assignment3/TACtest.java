public class TACtest {
  public static void main(String[] a) {
    System.out.println(new Sum().calcSum(100));
  }
}

class Sum {
  public int calcSum(int num) {
    int x;
    int[] y;
    y = new int[50];
    int i;
    i = 0;
    while (i < 50) {
      y[i] = i * 5;
      x = y[i];
      i = i + 1;
    }
    return x;
  }
}