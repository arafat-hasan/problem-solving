import java.util.*;

class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        String frst, sec, foo, fun;
        while (in.hasNextLine()) {
            frst = in.nextLine();
            sec = in.nextLine();
            foo = "";
            for (String tmp : frst.split(" ")) {
                foo += tmp.charAt(0);
            }
            fun = "";
            for (String tmp : sec.split(" ")) {
                fun += tmp.charAt(0);
            }
            System.out.println((foo.equals(fun) ? "yes" : "no"));
        }
    }
}
