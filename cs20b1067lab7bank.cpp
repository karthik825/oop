//CS20B1067
//kodam karthik
//bank operations code with menu driven code and linkedlists,objects.


#include<iostream>
using std::cout;
using std::cin;
using std::endl;


struct list     //a structure containing account number and its type
{
    int account_no;
    int account_type;
    struct list* next;
};
list* head= NULL;
bool Account(int account_no)    //function for checking account number matching
{
  list* temp = head;
  while (temp != NULL)
  {
    if (temp->account_no == account_no)
      return true;
    temp = temp->next;
  }
  return false;
}

class account       //creating a class named accout
{
     public:
    int account_no;
    double balance;

    account()   //constructor
    {
        double balance;
        cout << "enter the initial balance present in the account : ";
        cin >> balance;
    
        if (balance < 0)
        {
            this->balance = 0;
            cout << "By default the balance is assigned to zero" << endl;
        }
        else
            this->balance = balance;
        cout << "Amount is successfully added to the account" << endl;
    }
    void getInfo()  //function for getting account number and creating account
    {
        int account_no;
        list *temp = head;
        while (1)
        {
            cout << " ENTER AN ACCOUNT NUMBER  BETWEEN 0 AND 999: ";
            cin >> account_no;
      
        if (account_no < 0 || account_no > 999)
        {
            cout << "THE NUMBER YOU HAVE ENTERED IS INVALID" << endl;
            continue;
        }
      
        if (Account(account_no))
        {
            cout << "account is already exist" << endl;
            continue;
        }
            this->account_no = account_no;
            break;
        }
    cout << "New account  created successfully" << endl;
        
    }
    double credit(double amount)    //adding credit and returning total balance
    {
         if (amount < 0)
            cout << "Please enter valid amount" << endl;
        else
        {
            balance += amount;
            cout  << amount << " is credited into " << this->account_no << " successfully" << endl;
        }
        return this->balance;
     
    }
    double debit(double amount)     //debit amount and return balance
    { 
         if (amount < 0)
            cout << "please enter valid amount" << endl;
    
        else if (amount > this->getBalance())
            cout << "please enter amount correctly" << endl;
         else
        {
            this->balance -= amount;
            cout << amount << " is debited from  " << this->account_no << " successfully" << endl;
        }
    return this->balance;   
    }
    double getBalance()     //function for returning balance
    { 
        return this->balance;
    }

};
class savingsAccount:public account     //inherited from account (saving)
{
    public: 
    double int_rate;

    savingsAccount()    //constructor
    {
        double int_rate;
    cout << "ENTER THE Interest Rate:";
    cin >> int_rate;
    
    if (int_rate < 0)
    {
      this->int_rate = 1;
      cout << "Interest rate is assigned as 1 by default can be changed by user" << endl;
    }
    else
        this->int_rate = int_rate;
        cout << "Savings accoount created" << endl;
    }
    
    double calculateIntrestData()       //function for calculating the Intrest
    { 
        return (this->balance*12*this->int_rate)/100;
    }
    
    
    
};
class checkingAccount:public account        //inherited from accountclass(checking)
{ 
    public:
     
    double fee;
    checkingAccount()               //constructor
    { 
        double fee;
        cout << "Enter the fee per transaction: ";
        cin >> fee;
        if (fee < 0)
        {
            this->fee = 1;
            cout << "By default fee is set to 1 ,you can change it manually" << endl;
        }
        else
            this->fee = fee;
            cout << "ckecking account is successfully created" << endl;
    }
   
    double credit(double amount)    //adding credit
    {
        if (amount < 0)
            cout << "enter amount in correct figures" << endl;
        else
        {
            this->balance += amount;
      
            this->balance -= this->fee;
            cout  << amount << " + " << this->fee << "is credited into" << this->account_no <<"successfully" << endl;
        }
              return this->balance;
    }
    double debit(double amount)     //debit amount
    {
        if (amount < 0)
            cout << "enter amount in correct figures" << endl;
        else if (amount > this->balance)
            cout << "please enter amount correctly,withdrawal exceeds balance amount" << endl;
        else
        {
            this->balance -= amount;
      
            this->balance -= this->fee;
            cout << amount << " + " << this->fee<< " is debited from " << this->account_no << " successfully" << endl;
        }   
    return this->balance;
  }

};

struct Saving   //structure for saving account
{
  savingsAccount savingAccount;
  Saving *next;
};

struct checkingAccounts    // structure for checking account
{
  checkingAccount checkingaccount;
  checkingAccounts *next;
};

Saving* saving_head=NULL;
checkingAccounts* checking_head = NULL;

void updateInfo(int account_no, int account_type)   //giving acno and actype
{
  list *ptr = new list;
  ptr->account_no = account_no;
  ptr->account_type = account_type;
  ptr->next = NULL;
  if (head == NULL)
    head = ptr;
  else
  {
    list *temp = head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = ptr;
  }
}

double updateSavingsAcc()       //update info in saving account
{
  Saving *current = new Saving;
  current->savingAccount.getInfo();
  current->next = NULL;
  //initiailising head
  if (saving_head == NULL)
    saving_head = current;
  else
  {
    Saving *temp = saving_head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = current;
  }
  return current->savingAccount.account_no;
}


double updatecheckingAccounts()     //update info in checking account
{
  checkingAccounts *current = new checkingAccounts;
  current->checkingaccount.getInfo();
  current->next = NULL;
  
  if (checking_head == NULL)
    checking_head = current;
  else
  {
    checkingAccounts *temp = checking_head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = current;
  }
  return current->checkingaccount.account_no;
}

int checkAccountType(int account_no)
{
  list *temp = head;
  while (temp != NULL)
  {
    if (temp->account_no == account_no)
      return temp->account_type;
    temp = temp->next;
  }
  return temp->account_type;
}

void savingAccountchoices(int account_no, int ch)
{
  Saving *temp =saving_head;
  
  while (temp != NULL)
  {
    if (temp->savingAccount.account_no == account_no)
      break;
    temp = temp->next;
  }
  
  switch (ch)
  {
  case 2:
  {
    double amount;
    cout << "Enter the amount  to credit into your account: ";
    cin >> amount;
    amount = temp->savingAccount.credit(amount);
    cout << "Balance after the credit: " << amount << endl;
  }
  break;
  case 3:
  {
    double amount;
    cout << "Enter the amount  to debit from your account: ";
    cin >> amount;
    amount = temp->savingAccount.debit(amount);
    cout << "Balance after the debit: " << amount << endl;
  }
  break;
  case 4:
  {
    double int_rate;
    cout << "Enter the new intrest_Rate: ";
    cin >> int_rate;
    temp->savingAccount.int_rate = int_rate;
    cout << "Intrest rate is changed to " << int_rate << " per month" << endl;
  }
  break;
  case 5:
  {
    cout << "Intrest for acc no. " << account_no << " is " << temp->savingAccount.calculateIntrestData() << "per annum" << endl;
  }
  break;
  case 6:
  {
    cout << "Intrest for acc no. " << account_no << " is " << temp->savingAccount.calculateIntrestData() << " per annum" << endl;
    double interestRate;
    cout << "Enter the new intrest_Rate: ";
    cin >> interestRate;
    temp->savingAccount.int_rate = interestRate;
    cout << "Intrest rate changed to " << interestRate << " monthly" << endl;
  }
  break;
  }
}

void checkingAccountchoices(int account_no, int ch)
{
  checkingAccounts *temp = checking_head;
  
  while (temp != NULL)
  {
    if (temp->checkingaccount.account_no == account_no)
      break;
    temp = temp->next;
  }
  
  switch (ch)
  {
  case 2:
  {
    double amount;
    cout << "Enter the amount  to credit into your account: ";
    cin >> amount;
    amount = temp->checkingaccount.credit(amount);
    cout << "Balance after the credit: " << amount << endl;
  }
  break;
  case 3:
  {
    double amount;
    cout << "Enter the amount  to debit from your account: ";
    cin >> amount;
    amount = temp->checkingaccount.debit(amount);
    cout << "Balance after the credit: " << amount << endl;
  }
  break;
  case 7:
  {
    double fee;
    cout << "Enter the new interestRate: ";
    cin >> fee;
    temp->checkingaccount.fee = fee;
    cout << "fee is updated to " << fee<< " per transaction" << endl;
  }
  break;
  case 8:
  {
    cout << "Fee for acc no. " << account_no << " is " << temp->checkingaccount.fee << " per transaction" << endl;
  }
  break;
  }
}


int main()
{ 
    int choice,account_no,account_type ;
    cout<<"____________________________MENU CARD______________________________"<<'\n';
    cout<<"1).Open Account (Savings or Checking Account)\n";
    cout<<"2).Credit (Savings or Checking Account)\n";
    cout<<"3).Debit (Savings or Checking Account)\n";
    cout<<"4). Change/Update Interest rate (Savings Account)\n";
    cout<<"5).Calculate Interest (Savings Account - Print)\n";
    cout<<"6).Calculate and Update Interest (Savings Account - Credit)\n";
    cout<<"7).Change/Update Fee Amount (Checking Account)\n";
    cout<<"8).Print Checking Fee (Checking Account)\n";
    cout<<"9).Transact and Update (Checking Account - Debit)\n";
    cout<<"10).EXIT\n";

    while(1)
    {    
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: 
                cout << "Guide for creating account" << endl;
            while (1)
            {
                cout << "Which type of account  you wanna create?" << endl;
                cout << "1. Savings account" << endl;
                cout << "2. Checking account" << endl;
                cout << "Enter your choice: ";
                cin >> account_type;

                if (account_type == 1 || account_type == 2)
                    break;
                cout << "ENTER A VALID CHOICE" << endl;
            }
            if (account_type == 1)
            {
                updateInfo(updateSavingsAcc(), 1);
            }
            else
            {
                updateInfo(updatecheckingAccounts(), 2);
            }
            break;
            case 2:
                cout << "______details for credit________" << endl;
                cout << "Enter the account number: " << endl;
                cin >> account_no;
      
                if (!Account(account_no))
                    cout << "ACCOUNT DOESN'T EXIST" << endl;
                else
                {
                    account_type = checkAccountType(account_no);
                if (account_type == 1)
                    savingAccountchoices(account_no, choice);
                else
                    checkingAccountchoices(account_no, choice);
                }
            break;
            case 3:
                cout << "_________details for debit_________" << endl;
            cout << "Enter the account number: " << endl;
            cin >> account_no;
            if (!Account(account_no))
                cout << "ACCOUNT DOESN'T EXIST" << endl;
            else
            {
                account_type = checkAccountType(account_no);
            if (account_type == 1)
                savingAccountchoices(account_no, choice);
            else
                checkingAccountchoices(account_no, choice);
            }
            break;
            case 4:
                cout << "details for changing intrest rate" << endl;
                cout << "Enter the account number: " << endl;
                cin >> account_no;
                if (!Account(account_no))
                    cout << "ACCOUNT DOESN'T EXIST" << endl;
                else if (checkAccountType(account_no) == 1)
                    savingAccountchoices(account_no, choice);
                 else
                     cout << "account exist but not a saving account" << endl;
            break;
            case 5:
                cout << "_____details for calculating intrestRate" << endl;
                cout << "Enter the account number: " << endl;
                cin >> account_no;
                if (!Account(account_no))
                    cout << "ACCOUNT DOESN'T EXIST" << endl;
                else if (checkAccountType(account_no) == 1)
                    savingAccountchoices(account_no, choice);
                else
                    cout << "account exist but not a saving account" << endl;
            break;
            case 6:
                cout << "details for calculating and changing intrest rate" << endl;
                cout << "Enter the account number: " << endl;
                cin >> account_no;
                if (!Account(account_no))
                    cout << "ACCOUNT DOESN'T EXIST" << endl;
                else if (checkAccountType(account_no) == 1)
                    savingAccountchoices(account_no, choice);
                 else
                     cout << "account exist but not a saving account" << endl;
            break;
            case 7:
                cout << "details for changing fee amount" << endl;
                cout << "Enter the account number: " << endl;
                cin >> account_no;
                if (!Account(account_no))
                    cout << "ACCOUNT DOESN'T EXIST" << endl;
                else if (checkAccountType(account_no) == 2)
                    checkingAccountchoices(account_no, choice);
                else
                    cout << "account exist but not checking account" << endl;
            break;
            case 8:
                cout << "details for printing fee amount" << endl;
                cout << "Enter the account number: " << endl;
                cin >> account_no;
                if (!Account(account_no))
                    cout << "ACCOUNT DOESN'T EXIST" << endl;
                else if (checkAccountType(account_no) == 2)
                    checkingAccountchoices(account_no, choice);
                else
                    cout << "account exist but not a checking account" << endl;
            break;
            case 9:
                cout << "details for transaction in checking account" << endl;
                cout << "Enter the account number: " << endl;
                cin >> account_no;
                if (!Account(account_no))
                    cout << "ACCOUNT DOESN'T EXIST" << endl;
                else if (checkAccountType(account_no) == 2)
                    checkingAccountchoices(account_no, 3);
                else
                    cout << "account exist but not checking account" << endl;
            break;
            case 10:
                exit(0);
                break;
            default :
                break;
        
        }
    }
}