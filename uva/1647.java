import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  static BigInteger a[] = new BigInteger[1010];
  static BigInteger b[] = new BigInteger[1010];

  public static void init() {
    BigInteger bb = BigInteger.valueOf(2);
    b[0] = BigInteger.valueOf(1);
    for (int i = 1; i <= 1000; i++)
      b[i] = b[i - 1].multiply(bb);
    a[1] = BigInteger.valueOf(0);
    a[2] = BigInteger.valueOf(1);
    a[3] = BigInteger.valueOf(1);
    for (int i = 4; i <= 1000; i++) {
      a[i] = a[i - 2].add(b[i - 3]);
    }
  }

  public static void main(String[] args) {
    init();
    try {
      FileInputStream fis = new FileInputStream("g.in");
      System.setIn(fis);
      Scanner sc = new Scanner(System.in);
      while (sc.hasNext()) {
        int n = sc.nextInt();
        System.out.println(a[n]);
      }
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }
}