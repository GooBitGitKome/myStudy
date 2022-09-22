class TreeTraverseApplication{
    private static int N = 15;
    public static void main(String[] args){
        TreeTraverser traverser = new TreeTraverser(N);
        System.out.println("Depth First Search:"); 
        traverser.traverse(new Stack()); 
        System.out.println(); 
        System.out.println("Breadth First Search:"); 
        traverser.traverse(new Queue());
    } 
}