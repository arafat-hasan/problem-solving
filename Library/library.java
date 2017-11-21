
class Sieve {

    private static final int MAXS = 10000000;
    public static Boolean[] primelst = new Boolean[MAXS]; //for sieve
    public static int[] prime = new int[MAXS]; //for sieve

    int Sieve(int n) {

        int i, res, j;
        double root = Math.sqrt(n);
        primelst[0] = primelst[1] = true;

        for (i = 4; i < n; i += 2)
            primelst[i] = true;

        for (i = 3, j = 0; i <= root; i += 2) {
            if (!primelst[i]) {
                for (j = i * i; j < n; j += 2 * i)
                    primelst[j] = true;
            }
        }

        for (i = 0, res = 0; i < n; i++) {
            if (primelst[i] == false) {
                prime[res++] = i;
            }
        }

        return (res - 1);
    }
}

class Prime_factors {

    private static final int MAXS = 10000000;
    int[][] fact = new int[100][2]; //for prime factor
    private final Sieve sieve;

    Prime_factors(Sieve sieve) {
        this.sieve = sieve;
    }

    public int primefactor(int n, int primesize) {
        // res is return value of seive
        int i, j;

        if (n == 0 || sieve.primelst[n] == false)
            return 0;

        for (i = 0, j = 0; i < primesize; i++) {
            if (n % sieve.prime[i] == 0) {
                fact[j][0] = sieve.prime[i];
                fact[j][1] = 0;
                while (n % sieve.prime[i] == 0) {
                    n /= sieve.prime[i];
                    fact[j][1]++;
                }
                j++;
            }
        }
        return j;
    }

}

