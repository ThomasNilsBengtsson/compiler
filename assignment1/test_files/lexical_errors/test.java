// Main class definition
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello, World!"); // Print a greeting message

        // Variable declarations
        int x = 10;
        boolean isTrue = true;

        // If-else statement
        if (x > 5) {
            System.out.println("x is greater than 5");
        } else {
            System.out.println("x is less than or equal to 5");
        }

        // While loop
        int counter = 0;
        while (counter < 5) {
            System.out.println("Counter: " + counter);
            counter++;
        }

        // Array and for-loop
        int[] numbers = new int[5];
        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = i * 2; // Assign values to the array
        }

        // Print array values
        for (int num : numbers) {
            System.out.println("Number: " + num);
        }
    }
}

// Additional class declaration
class Helper {
    public void printMessage(String message) {
        System.out.println(message);
    }

    public int addNumbers(int a, int b) {
        return a + b; // Return the sum of two numbers
    }
}

// Expression examples
class Expressions {
    public void examples() {
        int a = 10 + 20;   // Addition
        int b = a * 2;     // Multiplication
        boolean c = a > b; // Comparison

        // Logical operations
        boolean result = (a > 5) && (b < 50) || c;

        // Object creation
        Helper helper = new Helper();
        helper.printMessage("Testing expressions!");
    }
}
