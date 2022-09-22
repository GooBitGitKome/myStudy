class ToyClassificationApplication{
    public static void main(String[] args){
        int[][] sides = { {3, 4, 5}, {2, 3, 4},
                {5, 12, 13},
                {19, 19, 19},
                {9, 40, 41}
            };
        // your code
        for(int i = 0 ; i < sides.length; i++)
        {
            int a =sides[i][0];
            int b = sides[i][1];
            int c = sides[i][2]; 
            String str = "";
            if((a*a - (b*b + c*c)) == 0)
            {
                str = "right-angled";
            }
            else if((b*b - (a*a + c*c)) == 0)
            {
                str = "right-angled";
            }
            else if((c*c - (a*a + b*b)) == 0)
            {
                str = "right-angled";
            }
            else
            {
                str = "not right-angled";
            }
            System.out.println(String.format("(%d, %d, %d) is %s",a,b,c,str));
        }
    } 
}