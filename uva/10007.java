import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  static BigInteger num[] = new BigInteger[310];
  static BigInteger p[] = new BigInteger[310];
  public static void init() {
    num[1] = p[1] = new BigInteger("1");
    for (int i = 2; i <= 300; i++) {
      num[i] = new BigInteger(String.valueOf(4 * i - 2))
                   .multiply(num[i - 1])
                   .divide(new BigInteger(String.valueOf(i + 1)));
      p[i] = p[i - 1].multiply(new BigInteger(String.valueOf(i)));
    }
  }

  public static void main(String[] args) {
    init();
    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      int x = sc.nextInt();
      if (x == 0)
        break;
      System.out.println(num[x].multiply(p[x]));
    }
  }
}