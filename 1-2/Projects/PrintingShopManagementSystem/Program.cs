// Program.cs file
namespace PrintingShopManager
{
    class PrintingShopManager
    {
        public static List<PrintTask>list =new List<PrintTask>();
        public static int printCount = 0;
        static void Main()
        {
            System.Console.WriteLine(".............This is a Printing Shop Manager Console program............");
            while (true)
            {
                System.Console.WriteLine("[Choose what you want:]");
                System.Console.WriteLine("[1].Add a print work");
                System.Console.WriteLine("[2].View all print works");
                System.Console.WriteLine("[3].Update a print work");
                System.Console.WriteLine("[4].Delete a print work");
                System.Console.WriteLine("[5].Exit");
                System.Console.WriteLine();
                System.Console.Write("Enter your choice:");
                int choice;
                try
                {
                   choice = int.Parse(Console.ReadLine());
                }
                catch (FormatException)
                {
                    System.Console.WriteLine("Invalid format!\n");
                    continue;
                }
                catch(Exception e)
                {
                    System.Console.WriteLine(e.Message);
                    continue;
                }
                switch (choice)
                {
                    case 1:JobType();
                    break;
                    case 2:ViewWork();
                    break;
                    case 3:UpdateWork();
                    break;
                    case 4:DeleteWork();
                    break;
                    case 5:
                    return;
                    default:
                    System.Console.WriteLine("Invalid choice\n");
                    break;
                }
            }
        }
        public static void JobType()
        {
            System.Console.WriteLine(".........................................................................");
            
            System.Console.WriteLine("1.Standard Printing");
            System.Console.WriteLine("2.Print and Binding\n");
            System.Console.Write("Choose a type :");
            int choice ;
            try
            {
               choice = int.Parse(Console.ReadLine());
            }
            catch (FormatException)
            {
              System.Console.WriteLine("Invalid Format!\n");
              return;
            }
            catch (Exception e)
            {
               System.Console.WriteLine(e.Message);
               return; 
            }
            CreatePrintJob(choice);

        }
        public static int printTaskNo = 0;
        public static void CreatePrintJob(int type)
        {

            System.Console.Write("Enter document type : ");
            string s = Console.ReadLine();
            if (s.ToLower() != "pdf" && s.ToLower() != "image")
            {
                System.Console.WriteLine("Invalid Document type");
                return;
            }
            System.Console.Write("Enter Number of pages: ");
            int p;
            try
            {
             p = int.Parse(Console.ReadLine());
            }
            catch (FormatException)
            {
                System.Console.WriteLine("Invalid Format!\n");
                return;
            }
            catch(Exception e)
            {
                System.Console.WriteLine(e.Message);
                return;
            }
            System.Console.Write("Colored print (yes/no) : ");
            string t = Console.ReadLine();
            if (t.ToLower() != "yes" && t.ToLower() != "no")
            {
                System.Console.WriteLine("Invalid Option!\n");
            }

            bool ok;
            if(t.ToLower()=="yes")ok = true;
            else ok = false;

            if(type == 1) list.Add(new StandardPrint(++printTaskNo,s,p,ok));
            if(type == 2)
            {
                System.Console.WriteLine("......................................................................");
                System.Console.WriteLine("Choose binding type : ");
                System.Console.WriteLine("1.Staple (20 BDT)");
                System.Console.WriteLine("2.Spiral (50 BDT)");
                System.Console.WriteLine("3.Hardcover (100 BDT)\n");
                System.Console.WriteLine("Enter choice : ");
                int bindType = int.Parse(Console.ReadLine());

                list.Add(new BindingPrint(++printTaskNo,s,p,ok,bindType));
            }

            
            
        }
        public static void ViewWork()
        {
            System.Console.WriteLine("............................List of Printworks..........................");
            foreach(PrintTask pj in list)
            {
                System.Console.WriteLine("Printing ID: "+pj.PrintId);
                System.Console.WriteLine("Document Type: "+pj.DocType);
                System.Console.WriteLine("Number of pages: "+pj.PageCount);
                if(pj.Colored)System.Console.WriteLine("Print type : "+"Colored");
                else System.Console.WriteLine("Print type : "+"Black&White");
                
                if(pj is BindingPrint bp){ 
                switch (bp.Bindtype)
                    {
                        
                        case 1:System.Console.WriteLine("Binding type : "+"Staple");break;
                        case 2:System.Console.WriteLine("Binding type : "+"Spiral");break;
                        case 3:System.Console.WriteLine("Binding type : "+"Hardcover");break;
                        
                    }
                }
                else
                {
                   System.Console.WriteLine("Binding type : "+"None");
                }
                System.Console.WriteLine("Total price : "+pj.CalculatePrice());
                System.Console.WriteLine(".........................................................................");    

                    

                
            }
        }
        public static void UpdateWork()
        {
            System.Console.Write("Enter the print ID to update: ");
            int id ;
            try
            {
                id = int.Parse(Console.ReadLine());
            }
            catch (FormatException)
            {
                System.Console.WriteLine("Invalid Format!");
                return;
            }
            catch(Exception e)
            {
                System.Console.WriteLine(e.Message);
                return;
            }
            bool found = false;
            foreach(PrintTask pj in list)
            {
                if(pj.PrintId == id)
                {
                    System.Console.Write("Update number of pages :");
                    int page = int.Parse(Console.ReadLine());
                    pj.PageCount+=page;
                    found = true;
                    break;
                


                }
                
            }
            if(!found)System.Console.WriteLine("Id not found in the list!");return;
        }
        public static void DeleteWork()
        {
            System.Console.Write("Enter the print id to remove: ");
            int id ;
            try
            {
                id = int.Parse(Console.ReadLine());
            }
            catch (FormatException)
            {
                System.Console.WriteLine("Invalid Format!");
                return;
            }
            catch (Exception e)
            {
                System.Console.WriteLine(e.Message);
                return;
            }
            bool found = false;
            foreach(PrintTask pj in list)
            {
                if(pj.PrintId == id)
                {
                    list.Remove(pj);
                    System.Console.WriteLine("Removed succesfully!");
                    found = true;
                    break;
                    
                }
                

            }
            if(!found)System.Console.WriteLine("Id not found in the list!");
            return;
        }

    }
    
}
