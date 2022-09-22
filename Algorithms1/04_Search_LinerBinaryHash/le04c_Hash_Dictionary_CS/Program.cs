using System;

class Program
{
    public const int PRIME = 1000037;
    public const int MAX = 1000001;
    public static string[] hashTable = new string[MAX];
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());//times
        for(int i = 0 ; i < n ; i++)
        {
            string[] str = Console.ReadLine().Split();
            if(str[0][0] == 'i')
            {
                MakeHash(str[1]);
            }else if(str[0][0] == 'f'){
                if(FindStr(str[1]) == true)
                {
                    Console.WriteLine("yes");
                }else Console.WriteLine("no");
            }

        }
    }

    public static void MakeHash(string str)
    {
        long strNum = StringToDigit(str);//used as an key(index for hashtable) made of this
        int s = 0;
        int hashValue = 0;
        while(true)
        {
            hashValue =  Hash1(s,strNum);
            if(hashTable[hashValue] != null)s++;
            else break;
        }
        hashTable[hashValue] = str;
    }
    public static int Hash1(int i,long strNum)
    {
        int hashValue;
        hashValue = ((int)(strNum % (long)PRIME) + i * Hash2(strNum)) % MAX ;
        return hashValue;
    }
    public static int Hash2(long strNum)
    {
        return 1 + (int)(strNum % (MAX-1));
    }
    public static bool FindStr(string str)
    {
        long strNum = StringToDigit(str);//used as an key(index for hashtable) made of this
        int s = 0;
        while(true)
        {
            if(hashTable[Hash1(s,strNum)] == str)return true;
            else if(hashTable[Hash1(s,strNum)] != null)s++;
            else return false;
        }
    }
    public static long StringToDigit(string str)
    {
        long strNum = 0;
        long weight = 0;
        int s = 0;
        for(int i = 0; i < str.Length; i++)
        {
            switch(str[i]){
                case 'A': s = 1;
                break;
                case 'C': s = 2;
                break;
                case 'G': s = 3;
                break;
                case 'T':s = 4;
                break;
            }
            weight *= (weight == 0 ? 1 : 4); //28 digit
            strNum = strNum +  (s * weight);
        }
        return strNum;
    }
}