abstract public class Entity {
    private String name;
    private int size;
    private File[] fileList = new File[100];
    private Directory[] directoryList = new Directory[100]; 
    private int numberOfFile = 0;
    private int numberOfDirectory = 0;
    abstract public String getName();
    abstract public void rename(String name);
    abstract public int getSize();
    public void add(Entity object){};
    public void display(){};
}
