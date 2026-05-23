// Parent Class : PrintTask
namespace PrintingShopManager
{
    public abstract class PrintTask
    {
      public int PrintId{get;set;}
      public string DocType{get;set;}
      private int pageCount;

      public int PageCount   
        {
            get { return pageCount; }

            set
            {
                if (value >= 0)
                {
                    pageCount = value;
                }
                else
                {
                    System.Console.WriteLine();
                    Console.WriteLine("Nah man! you can't put Page count negative\n");
                }
            }
        }
      public bool Colored{get;set;}
      public PrintTask(int printId,string docType,int pageCount,bool colored)
        {
            PrintId = printId;
            DocType = docType;
            PageCount = pageCount;
            Colored = colored;

        }
     public abstract int CalculatePrice();
   
    }
    
}