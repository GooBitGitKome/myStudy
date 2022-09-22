abstract class Animal {
   private static int count;
   public static void increment() { count++; }
   public static int getCount() { return count; }
   abstract void noise();
}
