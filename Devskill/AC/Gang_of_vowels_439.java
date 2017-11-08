import java.util.Scanner;

class Gang_of_vowels_439 {
    static boolean isvowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc, n, cs = 0, cnt;
        String str;
        tc = sc.nextInt();
        while (tc-- > 0) {
            n = sc.nextInt();
            str = sc.next();
            cnt = 0;
            for (int i = 1; i < n; i++) {
                if (isvowel(str.charAt(i)) == false) {
                    if (isvowel(str.charAt(i - 1)))cnt++;
                }
            }
            //debug1(cnt);
            //if (!isvowel(str[0])) cnt--;
            if (isvowel(str.charAt(n - 1)) == true) cnt++;
            cnt = (cnt < 0 ? 0 : cnt);
            System.out.println("Case " + (++cs) + ": " + cnt);
        }
    }
}
