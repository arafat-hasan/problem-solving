import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        int n, t, tmp;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        t = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            tmp = scanner.nextInt();
            t -= (86400 - tmp);
            if (t <= 0) {
                System.out.println(i + 1);
                return;
            }
        }
    }
}

