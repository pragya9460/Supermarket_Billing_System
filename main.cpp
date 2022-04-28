#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
  private:
    int pcode;
    float price;
    string pname;
    float discount;
    
  public:
    void menu(); //done->26
    void administrator(); //done->
    void buyer(); //done->
    void add(); //done->
    void edit(); //done->
    void rem(); //done->
    void list(); //done->
    void receipt(); //done->
    
};

void shopping:: menu()
{
    m:
    int choice;
    string email;
    string password;
    
    cout<<"\t\t\t\t\t\t_____________________________\n";
    cout<<"\t\t\t\t\t\t                             \n";
    cout<<"\t\t\t\t\t\t     SUPERMARKET MAIN MENU   \n";
    cout<<"\t\t\t\t\t\t_____________________________\n";
    cout<<"\t\t\t\t\t\t|                           |\n";
    cout<<"\t\t\t\t\t\t|    1) Administrator       |\n";
    cout<<"\t\t\t\t\t\t|                           |\n";
    cout<<"\t\t\t\t\t\t|    2) Buyer               |\n";
    cout<<"\t\t\t\t\t\t|                           |\n";
    cout<<"\t\t\t\t\t\t|    3) Exit                |\n";
    cout<<"\t\t\t\t\t\t|                           |\n";
    cout<<"\t\t\t\t\t\t_____________________________\n";
    cout<<"\t\t\t\t\t\t\tPlease select ";
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            cout<<"\t\t\t   Please Login     \n";
            cout<<"\t\t\t   Enter Email      \n";
            cin>>email;
            cout<<"\t\t\t   Enter Password   \n";
            cin>>password;
            
            if(email=="admin@admin.com" && password=="Admin@#123")
            {
                administrator();
            }
            else
            {
                cout<<"Invaild email/password";
            }
            break;
            
            
        case 2:
            {
                buyer();
            }
            
            
        case 3:
            {
                exit(0);
            }
            
        default:
            {
                cout<<"Please select from the given options";
            }
            
            
            
    }
    goto m;
}

void shopping:: administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator menu";
    cout<<"\n\t\t\t|_____1) Add the product_____|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____2) Modify the product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____3) Delete the product__|";
    cout<<"\n\t\t\t|                            |";
    cout<<"\n\t\t\t|_____4) Back to main menu___|";
    cout<<"\n\t\t\t                              ";
    cout<<"\n\n\t\t Please enter your choice ";
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            add();
            break;
        
        case 2:
            edit();
            break;
            
        case 3:
            rem();
            break;
            
        case 4:
            menu();
            break;
        
        default:
            cout<<"Invaild choice";
            
    }
    goto m;
}

void shopping:: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t       Buyer      \n";
    cout<<"\t\t\t__________________\n";
    cout<<"                        \n";
    cout<<"\t\t\t__1) Buy product__\n";
    cout<<"                        \n";
    cout<<"\t\t\t__2) Go Back    __\n";
    cout<<"                        \n";
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            receipt();
            break;
        
        case 2:
            menu();
            break;
        default:
        
            cout<<"Invaild choice";
            
    }
    
    goto m;
    
    
}

void shopping:: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    
    cout<<"\n\n\t\t\t  Add new product";
    cout<<"\n\n\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product ";
    cin>>price;
    cout<<"\n\n\t Discount on product ";
    cin>>discount;
    
    data.open("database.txt", ios::in);
    
    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
                
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        
        
        
        
        if(token==1)
            goto m;
        else{
            data.open("database.txt", ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            data.close();    
            
        }
        cout<<"\n\n\t\t Record inserted !";
    }
}

void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    
    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code :";
    cin>>pkey;
    
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\nFile doesn't exist !";
    }
    else{
        
        data1.open("database.txt", ios::app|ios::out);
        
        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount";
                cin>>d;
                data1<<" "<<c<<" "<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
                
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        
        remove("database.txt");
        rename("database1.txt", "database.txt");
        
        if(token==0)
        {
            cout<<"\n\n Record not found sorry!";
        }
    }
    
    
    
}
void shopping:: rem()
{
    
    fstream data, data1;
    int pkey;
    int token;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File doesn't exist";
        
    }
    
    else{
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
                
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        
        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n_______________________________________________________\n";
    cout<<"Product Code\t\tName\t\t\tPrice\n";
    cout<<"_______________________________________________________\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;
        
    }
    data.close();
}

void shopping:: receipt()
{
    fstream data;
    
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float discount =0;
    float total =0;
    
    cout<<"\n\n\t\t RECEIPT";
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    
    else{
        data.close();
        
        list();
        cout<<"\n\n\n_______________________________________________\n";
        cout<<"|                                             |\n";
        cout<<"|          Please place the order             |\n";
        cout<<"|_____________________________________________|\n";
        do
        {
            m:
            cout<<"\n\nEnter Product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity :";
            cin>>arrq[c];
            for(int i=0; i<c; i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? If yes then press y else n ";
            cin>>choice;
        }
        while(choice=='y');
        
        cout<<"\n\n___________________________________________RECEIPT____________________________________________\n";
        cout<<"\nProduct No\tProduct Name \t\t  Product quantity \t Price  \t     Amount \t  Amount with discount\n";
        
        for(int i=0; i<c; i++)
        {
            data.open("database.txt", ios::in);
            data>>pcode>>pname>>price>>discount;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    discount=amount-(amount*discount/100);
                    total=total+discount;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t\t"<<arrq[i]<<"\t\t  "<<price<<"\t\t\t"<<amount<<"\t\t"<<discount;
                }
                data>>pcode>>pname>>price>>discount;
            }
        }
        data.close();
        
        
    }
    cout<<"\n\n__________________________________________________________________________________________________";
    cout<<"\n Total Amount : "<<total<<"\n\n";
    
}
int main()
{
    shopping s;
    s.menu();
    return 0;
}

