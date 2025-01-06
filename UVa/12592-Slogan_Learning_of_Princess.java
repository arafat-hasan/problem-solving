import java.util.*;
import java.io.*;


class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, q;
        Map<String, String> mp = new HashMap<String, String>();
        String first, sec;
        n = in.nextInt();
        first = in.nextLine();
        for (int i = 0; i < n; i++) {
            first = in.nextLine();
            sec = in.nextLine();
            mp.put(first, sec);
        }
        q = in.nextInt();
        first = in.nextLine();
        for (int i = 0; i < q; i++) {
            first = in.nextLine();
            System.out.println(mp.get(first));
        }
    }
}
