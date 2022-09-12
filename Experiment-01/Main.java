import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) {

        ArrayList<Stock> arr = new ArrayList<Stock>();
        try {
            BufferedReader o = new BufferedReader(new FileReader("Stock-data.csv"));
            for (int i = 0; i < 23; i++) {
                String s = o.readLine();

                String attr[] = s.split(",");

                arr.add(new Stock(attr[0], Double.parseDouble(attr[1]), Double.parseDouble(attr[2]),
                        Double.parseDouble(attr[3]), Double.parseDouble(attr[4]), Double.parseDouble(attr[5])));
            }
            o.close();

        } catch (Exception e) {
            e.printStackTrace();
        }

        Stock.BruteForce(arr);

        Stock s = new Stock();
        s.DAC(arr, 0, 23);
    }

}