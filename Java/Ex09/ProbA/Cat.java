class Cat extends Animal {
    public static int catCount;
        public Cat() {};
        public void noise() {
        System.out.println("Meow");
        increment();
   }
   public static void increment() { catCount++; }
    public static int getCount() { return catCount; } 
}       