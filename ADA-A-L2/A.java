import java.util.*;

public class A2 {
    static int size = 1001;
    static boolean[][] dp = new boolean[size][size];

    static void solve() {
        int i = 0, j = 0;
        while (i < size) {
                if (!dp[i][j] && i <= j) {
                    for (int x = 0; x < size; x++) {
                        dp[x][j] = true;
                        dp[x][i] = true;
                        dp[j][x] = true;
                        dp[i][x] = true;
                    }
                    
                    for (int x = 1; x < size; x++) {
                        if (i + x >= size || j + x >= size) break;
                        dp[i + x][j + x] = true;
                        dp[j + x][i + x] = true;
                    }

                    for (int x = 1; x < size; x++) {
                        if (i - x < 0 || j - x < 0) break;
                        dp[i - x][j - x] = true;
                        dp[j - x][i - x] = true;
                    }

                    dp[i][j] = false;
                    dp[j][i] = false;

                    i++;
                    j = 0;
                } else {
                    j++;
                    if (j >= size) {
                        i++;
                        j = 0;
                    }
                }
        }
    
    }



    public static void main(String[] args) {
        solve();

        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T-- > 0) {
            int A = in.nextInt();
            int B = in.nextInt();
            if (dp[Math.max(A, B)][Math.min(B, A)]) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
