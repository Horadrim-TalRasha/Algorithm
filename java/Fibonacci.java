class Febonacci
{
    public int febonacci(int i)
    {
        if(i = 0)
        {
            return 0;
        }
        else if(i == 1)
        {
            return 1;
        }
        return febonacci(i - 1) + febonacci(i - 2);
    }


    public static void main(String [] args)
    {


    }

};
