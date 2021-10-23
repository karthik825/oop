#include<iostream>
#include<string>

using namespace std;

class Bank
{
    private:
    int accountNo;
    string accName;
    int accountType;
    int balance;
    int stDebt;
    public:
    Bank()
    {
        accountNo = 0;
        balance = 0;
        accName = '\0';
        stDebt = 0;
    }
    Bank(int aN,string acNa,int acT,int amount)
    {
        accName = acNa;
        accountNo = aN;
        accountType = acT;
        balance = amount;
    }
    void createAcc()
    {
        int choice;
        cout<<"Enter account holders Name:";
        cin>>accName;
        cout<<"Enter account Number:";
        cin>>accountNo;
        cout<<"1.Savings\n2.Current\n";
        cout<<"Enter which type of account you want to create:";
        cin>>accountType;
        cout<<"Enter amount in account:";
        cin>>balance;
        cout<<"are you willing to take debt\n1.yes\n2.No\nEnter your choice:";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter amount you want as debt:";
            cin>>stDebt;
        }
        if(choice==2)
        {
            stDebt = 0;
        }
        cout<<"----Account created successfully-----";
    }
    void display()
    {
  
        cout<<"Account Number:"<<accountNo<<"\n";
        cout<<"Account holder Name:"<<accName<<"\n";
        if(accountType==1)
        cout<<"Account type: Savings\n";
        if(accountType==2)
        cout<<"Account type: Current\n";
        cout<<"Balance in account"<<balance<<"\n";
        cout<<"Debt on account:"<<stDebt<<"\n";

    }
    void deleteAcc()
    {

    }
    
};

int main()
{
    int choice,n;
    cout<<"Enter number accounts in bank:";
    cin>>n;
    Bank acc[n];
    int exist=0,accNo,i,size=0;

    while(1)
    {
        cout<<"\n1.Create Account\n2.Delete Account\n3.Display\n4.EXIT\n";
        cout<<"Enter your Choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                if(size<n)
                {
                acc[size].createAcc();
                size++;
                }
                else
                {
                    cout<<"Max no of accounts in bank exceeded";
                }
                
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                cout<<"Displaying all accounts in bank";
                for(i=0;i<size;i++)
                {
                    acc[i].display();
                }
            }
            break;
            case 4:
            {
                cout<<"\nPROGRAM EXITED BY THE USER\n";
                exit(0);
                break;
            }
            default:
            {
                cout<<"\nInvalid Choice.TRY AGAIN!!!\n";
            }
        }
    }
    return 0;
}