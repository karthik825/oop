//CS20B1067
//kodam KARTHIK
//midsem


#include<iostream>
using namespace std;


class account       //declaring a class named account
{
    private: 
    int Account_number;     //data menmbers
    char name[100];
    int Account_type;
    double balance;
    double standing_debt;

    public: 
    account()   //constructor
    { 
        Account_number=0;
        name[0]='\0';
        Account_type=0;
        balance=0;
        standing_debt=0;
    }
    account(int account_number,char Name[100],int account_type,double Balance,double debt)
    {
        account_number=Account_number;      //parameterized constructor
        Name[0]=name[0];
        account_type= Account_type;
        Balance=balance;
        debt=standing_debt;
    }

    void createAccount()        //creating a new account
    { 
        cout<<"enter account number: ";
        cin>>Account_number;
        cout<<"enter The name:";
        cin>>name;
        cout<<"enter account type(1 for savings and 2 for current):";
        cin>>Account_type;
        cout<<"enter The balance: ";
        cin>>balance;
        cout<<"enter debt: ";
        cin>>standing_debt;
    }
    void deleting()        //deleting account from start index
    {
        Account_number = -1;
        
        Account_type=-1;
        balance=-1;
        standing_debt=-1;
    }
    void display()      //displaying function
    {   
        if(Account_number==-1)
            return;
        cout<<"The account number is:"<<Account_number<<'\n';
        cout<<"The account holder name is:"<<name<<'\n';
        cout<<"The account type is:"<<Account_type<<'\n';
        cout<<"The account balance is:"<<balance<<'\n';
        cout<<"The account debt is: "<<standing_debt<<'\n';

    }

};



int main()
{   
    int n,choice,k=0,i=0;
    cout<<"Enter The size of array of objects\n";
    cin>>n;
    account* acc=new account[n];            //array of objects
    cout<<"___________MENU___________"<<endl;
    cout<<"1).Create accoun\n2).Delete account\n3).Display\n4).Exit";
    while(1)
    {
        cout<<"Enter your choice"<<'\n';
        cin>>choice;
        switch(choice)
        {
            case 1:
                acc[i].createAccount();         //creating account
                i++;
                break;
            case 2:
                
                
                acc[k].deleting();      //deleting account from start.
                k++;
                cout<<"account deleted \n";
                break;
            case 3:                     //displaying all accounts
                for(int x=0;x<i;x++)
                {   
                    cout<<"Account details are:\n";
                    acc[x].display();
                }
                break;
            case 4:
                exit(0);
                break;
        }
    }

    return 0;
}