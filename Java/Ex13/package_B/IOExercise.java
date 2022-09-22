package package_B;
import java.io.*;
public class IOExercise{
    public static void main(String[] args) throws IOException
    {
        final String fileUrl = "number.data";
        BufferedReader br = null;
        DataOutputStream out = null;
        DataInputStream in = null;
        try{
            System.out.println("Enter the number:");
            //user input
            br = new BufferedReader(new InputStreamReader(System.in));
            double s0 = Double.parseDouble(br.readLine());
            double s1 = Math.sqrt(s0);
            System.out.println("Square of "+ s0 +" is "+s1);

            //create the file to save the value s1
            out = new DataOutputStream(new BufferedOutputStream(new FileOutputStream(fileUrl)));
            out.writeDouble(s1);
            System.out.println("The square root value "+s1+" is written to the file \""+ fileUrl +"\".");
            out.close();

            //read the data from the file
            in = new DataInputStream(new BufferedInputStream(new FileInputStream(fileUrl)));
            double s2 = in.readDouble();
            System.out.println("The value read from the file \""+fileUrl+"\" is "+ s2);
            
            System.out.println("Square of "+ s2 +" is "+s2*s2);
        }
        finally
        { 
            in.close();   
        }
    }
}
