class Dog extends Animal {
    static int dogCount;
    public Dog() {};
    public void noise() {
        System.out.println("Woof");
        increment();
    }
    public static void increment() { dogCount++; }
    public static int getCount() { return dogCount; } 
 }