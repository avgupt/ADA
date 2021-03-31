import java.util.PriorityQueue;
import java.util.Scanner;

class Stock implements Comparable<Stock>{
    private long a;
    private long b;
    private long gain;
    private long shares_bought;
    private float maximum_x, maximum_y;

    Stock(long a, long b) {
        this.a = a;
        this.b = b;
        shares_bought = 0;
        gain = a + b;
    }

    public float getMaximum_x() {
        return maximum_x;
    }

    public float getMaximum_y() {
        return maximum_y;
    }

    public long getGain() {
        return gain;
    }

    public void updateGain() {
        shares_bought++;
        gain = 2 * a * shares_bought + a + b;
    }

    public int compareTo(Stock s) {
        if (s.gain > this.gain)
            return 1;
        return -1;
    }

    @Override
    public String toString() {
        return a + " " + b;
    }
}


public class B2 {

    static long calcMaxProfit(PriorityQueue<Stock> pq, long B) {
        long profit = 0;
        
        while (B > 0 && !pq.isEmpty()) {
            Stock s = pq.poll();
            B--;
            profit += s.getGain();
            s.updateGain();
            if (s.getGain() > 0) pq.add(s);
        }
        
        return profit;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long B = in.nextLong();

        PriorityQueue<Stock> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            long a = in.nextLong();
            long b = in.nextLong();
            Stock s = new Stock(a, b);
            if (s.getGain() > 0) pq.add(s);
        }
        in.close();

        System.out.println(calcMaxProfit(pq, B));
    }
}