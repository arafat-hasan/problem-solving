import java.util.*;
import java.lang.Math.*;



class Main {

    static boolean isPrime(long n) {
        if (n == 2) return true;
        if (n < 2 || n % 2 == 0) return false;
        long root = (long) Math.sqrt(n) + 1;
        for (long i = 3; i < root; i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }
    static long pow(int n, int x) {
        long tmp = 1;
        for (int i = 0; i < x; i++) {
            tmp *= n;
        }
        return tmp;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n;
        while (in.hasNextInt()) {
            n = in.nextInt();
            if (n <= 0) break;
            long tmp = pow(2, n) - 1;
            if (isPrime(n))
                if (isPrime(tmp))
                    System.out.println("Perfect: " + tmp * (pow(2, n - 1)) + "!");
                else
                    System.out.println("Given number is prime. But, NO perfect number is available.");
            else
                System.out.println("Given number is NOT prime! NO perfect number is available.");
        }
    }
}
