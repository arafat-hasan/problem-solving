import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int cs = 0;
        while (true) {
            int bacelor = scan.nextInt(), min = 999999999, tmp, ans;
            int spinter = scan.nextInt();
            if (bacelor == 0 && spinter == 0) break;
            for (int i = 0; i < bacelor; i++) {
                tmp = scan.nextInt();
                if (min > tmp) min = tmp;
            }
            for (int i = 0; i < spinter; i++) {
                tmp = scan.nextInt();
            }
            ans = bacelor < spinter ? 0 : bacelor - spinter;
            if (ans != 0)
                System.out.println("Case " + ++cs + ": " + ans + " " + min);
            else
                System.out.println("Case " + ++cs + ": " + ans);
        }
    }
}




