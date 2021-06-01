import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
  static BigInteger f[] = new BigInteger[10010];

  public static void init() {
    f[1] = BigInteger.valueOf(1);
    f[2] = BigInteger.valueOf(2);
    for (int i = 3; i <= 10000; i++)
      f[i] = f[i - 1].add(f[i - 2]);
  }

  public static void main(String[] args) {
    init();
    // try {
    // FileInputStream fis=new FileInputStream("data.in");
    // System.setIn(fis);
    Scanner sc = new Scanner(System.in);
    while (sc.hasNext()) {
      int n = sc.nextInt();
      System.out.println(f[n].add(f[n - 2]));
    }
    // } //catch (FileNotFoundException e) {
    // e.printStackTrace();
  }
}
