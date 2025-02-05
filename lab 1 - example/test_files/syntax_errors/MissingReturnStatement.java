public class MissingReturnStatement {
    public static void main(String[] args) {
        System.out.println((2 + 3) * (5 - 1));

    }
}

class MyClass {
    public int test() {
        int a;
        a = 5;
        int b;
        b = 10;
    } // @error - syntax (Missing return statement)
}
