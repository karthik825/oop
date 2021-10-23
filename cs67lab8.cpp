#include<iostream>

using std::cout;
using std::cin;
using std::endl;

struct list
{
    int employee_id;
    char name[20];
    int employee_type;
    struct list* next;
};
list* head=NULL;
bool Account(int employee_id)    //function for checking account number matching
{
  list* temp = head;
  while (temp != NULL)
  {
    if (temp->employee_id == employee_id)
      return true;
    temp = temp->next;
  }
  return false;
}

class Employee
{   
    protected: 
    int employee_id;
    char name[100];
    int employee_type;
    public: 
    void emch()
    {
       int em_id=employee_id;

    }

};
class contract:protected Employee
{ 
    protected: 
    int pay_per_hour;
    char name[100];

    public:
    int employee_id;
     
    void setPay()
    {   
        cout<<"Enter employee name:"<<endl;
        cin>>name;
        cout<<"Enter employee id:"<<endl;
        cin>>employee_id;
        cout<<"Enter the pay amount for contract employee: ";
        cin>>pay_per_hour;

    }
    void getPay()
    { 
        cout<<"Name is:"<<name<<endl;
        cout<<"Employee id is:"<<employee_id<<endl;
        cout<<"Payment is:"<< pay_per_hour<<""<<endl;
        
    }
    int c1()
    {
        return employee_id  ;
    }
    void c11()
    { 
        c1();
    }

};
class salaried:protected Employee
{ 
    protected:
    int monthPay;
    
    char name[100];
    public:
    int employee_id;
 
    void setPay()
    {
        cout<<"Enter employee name:"<<endl;
        cin>>name;
        cout<<"Enter employee id:"<<endl;
        cin>>employee_id;
        cout<<"Enter the pay amount for contract employee: ";
        cin>>monthPay;

    }

    void getPay()
    { 
        cout<<"Name is:"<<name<<endl;
        cout<<"Employee id is:"<<employee_id<<endl;
        cout<<"Payment is:"<<monthPay<<""<<endl;
    }
    int c2()
    { 
        return employee_id;
    }
    void c22()
    {
        c2();
    }
    
};
class manager:private salaried
{ 
    public: 
    int employee_id;
    void getDetails()
    { 
        cout<<"Enter employee name:"<<endl;
        cin>>name;
        cout<<"Enter employee id:"<<endl;
        cin>>employee_id;
        cout<<"Enter the pay amount for contract employee: ";
        cin>>monthPay;
    }
    void pp()
    { 
        setPay();
    }
    void setDetails()
    {
        cout<<"Name is:"<<name<<endl;
        cout<<"Employee id is:"<<employee_id<<endl;
        cout<<"Payment is:"<<monthPay<<""<<endl;
    }
    
    void setSalary()
    { 
        cout<<"enter the updated monthly pay:"<<endl;
        cin>>monthPay;
    }
    double calculateSalary()
    { 
        int no_of_months ;
        cout<<"Enter no of months the employee worked"<< endl;
        cin>>no_of_months;
        return (monthPay*no_of_months);

    }

};
class intern: private contract
{ 
    public:
    int employee_id; 
    void setDetails()
    {
        cout<<"Enter employee name:"<<endl;
        cin>>name;
        cout<<"Enter employee id:"<<endl;
        cin>>employee_id;
        cout<<"Enter the pay amount for contract employee: ";
        cin>>pay_per_hour;
    }
    void getDetails()
    { 
        cout<<"Name is:"<<name<<endl;
        cout<<"Employee id is:"<<employee_id<<endl;
        cout<<"Payment is:"<<pay_per_hour<<""<<endl;
    }
    
    void setSalary()
    {
        cout<<"enter the updated pay amount per hour:";
        cin>>pay_per_hour;
    }
    void pp1()
    {    
        setPay();
    }
    double calculateSalary()
    { 
        int no_of_hours;
        cout<<"enter the no of working hours:";
        cin>>no_of_hours;
        return (no_of_hours*pay_per_hour);
    }

};

struct managing
{
    manager managerS;
    managing* next;

};
struct interning
{
    intern internS;
    interning* next;
};
managing* m_head=NULL;
interning* i_head=NULL;

int checkAccountType(int employee_id)
{
  list *temp = head;
  while (temp != NULL)
  {
    if (temp->employee_id == employee_id)
      return temp->employee_type;
    temp = temp->next;
  }
  return temp->employee_type;
}

void updateInfo(int employee_id, int employee_type)   //giving acno and actype
{
  list *ptr = new list;
  ptr->employee_id = employee_id;
  ptr->employee_type =employee_type;
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

int updateManagerd()       //update info in managing account
{
  managing *current = new managing;
  
  current->managerS.pp();
  current->next = NULL;
  //initiailising head
  if (m_head == NULL)
    m_head = current;
  else
  {
    managing *temp = m_head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = current;
  }
  return current->managerS.employee_id;
}


int updateInternAccounts()     //update info in checking account
{
  interning *current = new interning;
  current->internS.pp1();
  current->next = NULL;
  
  if (i_head == NULL)
    i_head = current;
  else
  {
    interning *temp = i_head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = current;
  }
    return current->internS.employee_id;
}


int main()
{
    int choice,employee_id,employee_type,employee_name ;
    cout<<"______________MENU_______________"<< endl;
    cout<<"1).Create Employee(Manager or Intern)\n";
    cout<<"2).Update Employee Details (Manager or Intern)\n";
    cout<<"3).Print Employee Details (Manager or Intern)\n";
    cout<<"4).Update Pay (Manager or Intern)\n";
    cout<<"5).Calculate Salary (Manager or Intern)\n";
    cout<<"6).exit\n";

    while(1)
    {
        cout<<"Enter your choice as per menu"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout << "Guide for creating account" << endl;
            while (1)
            {
                cout << "Which type of account  you wanna create?" << endl;
                cout << "1. Manager" << endl;
                cout << "2. Intern" << endl;
                cout << "Enter your choice: ";
                cin >> employee_type;

                if (employee_type == 1 || employee_type == 2)
                    break;
                cout << "ENTER A VALID CHOICE" << endl;
            }
            if (employee_type == 1)
            {
                updateInfo(updateManagerd(),1);
            }
            else
            {
                updateInfo(updateInternAccounts(),2);
            }
                break;
            case 2: 
                cout << "UPDATING EMPLOYEE DETAILS" << endl;
                cout << "Enter the employee_id: " << endl;
                cin >> employee_id;
      
                if (!Account(employee_id))
                    cout << "ACCOUNT DOESN'T EXIST" << endl;
                else
                {
                    employee_type = checkAccountType(employee_id);
                if (employee_type == 1)
                    updateManagerd();
                else
                    updateInternAccounts();
                }    
                break;
            case 3: 
                break;
            case 4: 
                break;
            case 5: 
                break;
            case 6: 
                exit(0);
                break;

        }
    }
    return 0;
}