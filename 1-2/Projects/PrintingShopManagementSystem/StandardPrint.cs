// Derived Class 1 : StandardPrint
namespace PrintingShopManager
{
    public class StandardPrint : PrintTask
    {
       
        public StandardPrint(int printId,string docType,int pageCount,bool colored):base(printId,docType,pageCount,colored)
        {}
        public override int CalculatePrice()
        {
            int Price = 0;
            if(DocType.ToLower() == "pdf")
            {
                if (Colored)
                {
                    Price = PageCount*5;
                }
                else
                {
                    Price = PageCount*2;
                }
                
            }
            else if(DocType.ToLower() == "image")
            {
                if (Colored)
                {
                    Price = PageCount*10;
                }
                else
                {
                    Price = PageCount*5;
                }
                               
                
            }
            return Price;
        }

    }
}