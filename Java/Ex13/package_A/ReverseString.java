package package_A;
import java.io.*;

public class ReverseString{
    public static void main(String[] args) throws IOException
    {
        File file = new File("./input.txt");
        File fileOut = new File("./output.txt");
        FileInputStream fin = new FileInputStream(file);
        FileOutputStream fout = new FileOutputStream(fileOut);
        Integer[] bf = new Integer[1000000];
        try
        {
            int tmp;
            int i;
            for(i = 0 ; (tmp =fin.read()) != -1 ; i++)bf[i] = tmp;
            for(i = i -1; i-1 >= 0 ; i--)fout.write(bf[i].intValue());
        }
        finally
        {
            fin.close();
            fout.close();
        }
    }
}
