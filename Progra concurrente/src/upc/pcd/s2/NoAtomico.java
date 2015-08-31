package upc.pcd.s2;

public class NoAtomico {
  static long contador;
  public static void main(String args[]) {
    contador = 0;
    (new Thread() {
      public void run() {
        for (int i = 0; i < 1000; ++i) contador++;
      }
    }).start();
    (new Thread() {
      public void run() {
        for (int i = 0; i < 1000; ++i) contador++;
      }
    }).start();
    (new Thread() {
      public void run() {
        for (int i = 0; i < 1000; ++i) contador++;
      }
    }).start();
    (new Thread() {
      public void run() {
        for (int i = 0; i < 1000; ++i) contador++;
      }
    }).start();
    Thread.sleep(1000);
    System.out.println(contador);
  }
}