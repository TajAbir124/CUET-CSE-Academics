// Derived Class 2 : BindingPrint
namespace PrintingShopManager
{
  public class BindingPrint : PrintTask
    {
      public int Bindtype{get;set;}
      public BindingPrint(int printId,string docType,int pageCount,bool colored,int bindtype):base(printId,docType,pageCount,colored)
      {
        Bindtype = bindtype;
      }
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

        if(Bindtype == 1)Price+=20;
        else if(Bindtype == 2)Price+=50;
        else if(Bindtype == 3)Price+=100;
        return Price;          
          
      }
    } 
}