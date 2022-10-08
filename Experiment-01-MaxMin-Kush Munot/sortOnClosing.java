import java.util.*;

public class sortOnClosing implements Comparator<Stock> {
    public int compare(Stock a, Stock b){
        if(a.close > b.close)
            return 1;
        else if(a.close < b.close)
            return -1;
        else
            return 0;
    }
}
