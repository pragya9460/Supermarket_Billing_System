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
    void menu(); 
    void administrator(); 
    void buyer(); 
    void add(); 
    void edit(); 
    void rem(); 
    void list(); 
    void receipt(); 
    
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
    fstream data; // Creating object of fstream class
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
    //as product will be added by admin so it need to be stored somewhere and for that we'll open the file.
    data.open("database.txt", ios::in); // we are opening the file "database.txt" in reading mode (ios::in open the file in reading mode)
     
    if(!data) //if this doesn't exist
    {
        /*ios::app stands for append mode and ios::out stands for writing mode, which means if there is no such file with given name then file with this name will be created(appended) or will be opened in writting mode.
        */
        data.open("database.txt", ios::app|ios::out);
      
        // to write in file "database.txt", with the help of object data
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close(); //for closing the file
    }
    else //if file exist
    {
        data>>c>>n>>p>>d; //to read from file, here we are initiallizing the index of file to iterate on the file using while loop
        
        while(!data.eof()) // eof() -> end of file function, to check if data of file is not ended and till then we'll interate over the file
        {
            if(c==pcode) // if entered pcode matches with any code inside the file, then it will be marked with token++
            {
                token++;
                
            }
            data>>c>>n>>p>>d; //for iteration purpose we are reading from the file
        }
        data.close(); //close the file
        
        
        
        
        if(token==1) //if there is duplicacy, which means product code entered by admin already exist
            goto m; //goto add function again and add another product with different product code
        else{ //product code entered by admin is unique
            // add that product in file
            data.open("database.txt", ios::app|ios::out); // if there is file with given name then append this data inside the file or open a new file with this name in writting mode
          
            // to write in file "database.txt", with the help of object data
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n"; 
            data.close();    //close file
            
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
    
    data.open("database.txt", ios::in); // we are opening the file "database.txt" in reading mode (ios::in open the file in reading mode)
    if(!data) // if File doesn't exist
    {
        cout<<"\n\nFile doesn't exist !";
    }
    else{
        
        data1.open("database1.txt", ios::app|ios::out); // we are saving our edited data in this file
        
        data>>pcode>>pname>>price>>discount; // for interating in data , here we are initializing
        while(!data.eof())
        {
            if(pkey==pcode) // if entered code matches with code inside file database.txt
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount";
                cin>>d; 
                data1<<" "<<c<<" "<<" "<<n<<" "<<p<<" "<<d<<"\n"; //all the updated details will be saved in file database1.txt with the help of data1 object
                cout<<"\n\n\t\t Record edited ";
                token++; // to mark that record with this code exist in the file
            }
            else // if this is not the entered product code
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n"; // update data1 with with values of data.
                
            }
            data>>pcode>>pname>>price>>discount;  // for interating in data
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
    
    //making a copy of our database and while copying every line if our product code matchs with product code in file then in new database we'll write a edited line
    
}
void shopping:: rem()
{
    
    fstream data, data1;
    int pkey;
    int token;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code :";
    cin>>pkey;
    data.open("database.txt", ios::in); //open file in read mode
    if(!data)
    {
        cout<<"File doesn't exist";
        
    }
    
    else{
        data1.open("database1.txt", ios::app|ios::out); //open file in read mode
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
  
   //making a copy of our database and while copying every line if our product code matchs with product code in file then in new database we'll not write that line
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

