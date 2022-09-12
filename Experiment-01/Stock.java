import java.util.*;

public class Stock {
    String date;
    double open, high, low, close, volume;
    static double mini = 0, maxi = 0, mid = 0, min1 = 0, max1 = 0;

    Stock() {
    }

    Stock(String date, double open, double high, double low, double close, double volume) {
        this.date = date;
        this.open = open;
        this.high = high;
        this.low = low;
        this.close = close;
        this.volume = volume;
    }

    public String toString() {
        return ("Date - " + date + "\nOpen - " + open + " Close - " + close + " High - " + high + " Low - " + low
                + " Vol - " + volume);
    }

    public static void BruteForce(ArrayList<Stock> arr) {
        Iterator<Stock> itr = arr.iterator();
        double min = 111111, max = -11111;
        while (itr.hasNext()) {
            Stock s = itr.next();
            if (s.close < min) {
                min = s.close;
            }
            if (s.close > max) {
                max = s.close;
            }
        }
        System.out.println("Brute Force Approach Answers");
        System.out.println("Maximum Stock Price is = " + max);
        System.out.println("Minimum Stock Price is = " + min);
    }

    double min(double i, double j) {
        if (i < j) {
            return i;
        } else {
            return j;
        }
    }

    double max(double i, double j) {
        if (i > j) {
            return i;
        } else {
            return j;
        }
    }

    public void max_min(double[] arr, int i, int j) {
        if (i == j) {
            mini = arr[i];
            maxi = arr[i];
        } else if (i == j - 1) {
            mini = min(arr[i], arr[j]);
            maxi = max(arr[i], arr[j]);
        } else {
            int mid = (i + j) / 2;
            max_min(arr, i, mid);
            min1 = mini;
            max1 = maxi;
            max_min(arr, mid + 1, j);
            mini = min(mini, min1);
            maxi = max(maxi, max1);
        }
    }

    public void DAC(ArrayList<Stock> lst, int i, int j) {
        //Collections.sort(lst, new sortOnClosing());

        double arr[] = new double[23];
        int l = 0;
        Iterator<Stock> itr = lst.iterator();
        while (itr.hasNext()) {
            arr[l] = itr.next().close;
            l++;
        }
        
        max_min(arr, 0, 22);
        System.out.println("Divide and Conquer Approach");
        System.out.println("Maximum Stock Price is = " + maxi);
        System.out.println("Minimum Stock Price is = " + mini);
    }
}
