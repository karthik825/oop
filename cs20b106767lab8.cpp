#include<iostream>
#include<string>

using namespace std;

class Employee      //class employee (base class)
{
  protected:        //data members in protected mode
    int employee_id;
    string Employee_Name;
};

class contract : protected Employee     //contract class inherited from base class in pro>mode
{
  protected:
   int pay_per_Hour;
  public:               //member functions of contract class
    int getPay()
    {
       return this->pay_per_Hour;
    }
    void setPay()
    {
      int pay;
      cout << "Enter the pay_per_Hour of employee: ";
      cin >> pay;
      this->pay_per_Hour = pay;     //returns pay
    }
};

class Salaried : protected Employee     //salaried class inherited from base class
{
    protected:
      int monthlyPay;
    public:
    int getpay()
    {
       return this->monthlyPay;         //returns monthlypay
    }
    void setPay()
    {
      int pay;
      cout << "Enter the monthlyPay of employee: ";
      cin >> pay;
      this->monthlyPay = pay;
    }
};

class manager : private Salaried        //manager class inherited inn  private mode
{
  public:
    int get_employee_id()
    {
        return this->employee_id;       //returns employee id
    }
    void setDetails_of_Employee(int Id)
    {
      string Name;
      cout << "Enter Name of Employee: ";
      cin >> Name;
      this->employee_id = Id;
      this->Employee_Name = Name;
      this->setPay();
    }
    void setDetails(int id)
    {
        int pay;
        string name;
        this->employee_id = id;
        cout << "Enter the  name of manager " << '\n';
        cin >> name;
        this->Employee_Name = name;
        cout << "Enter the  MonthlyPay of Employee" ;
        cin >> pay;
        this->monthlyPay = pay;
    }
    void getDetails()
    {
      cout << "employee_id: " << employee_id << '\n';
      cout << "Employee_Name: " << Employee_Name << '\n';
      cout << "monthlyPay: " << monthlyPay << '\n';
    }
    
    void setSalary(int pay)
    {
        this->monthlyPay = pay;
    }
    int calculateSalary(int months_worked)
    {
      return this->monthlyPay * months_worked;      //returns salary
    }
};

class intern : private contract     //class intern inherited in private mode from contract
{
  public:
    int get_employ_id()
    {
        return this->employee_id;       //returns employee id of intern member
    }
    void setDetails_of_Employee(int id)
    {
      string Name;
      cout << "Enter Name of Employee: ";
      cin >> Name;
      this->employee_id = id;
      this->Employee_Name = Name;
      this->setPay();
    }
    void setDetails(int id)
    {
        int pay;
        string name;
        this->employee_id = id;
        cout << "Enter the  name of manager " << '\n';
        cin >> name;
        this->Employee_Name = name;
        cout << "Enter the  MonthlyPay of Employee" ;
        cin >> pay;
        this->pay_per_Hour = pay;
    } 
    void getDetails()
    {
      cout << "employee_id: " << employee_id << '\n';
      cout << "Employee_Name: " << Employee_Name << '\n';
      cout << "monthlyPay: " << this->pay_per_Hour << '\n';
    }

    void setSalary(int Pay)
    {
       this->pay_per_Hour = Pay;
    }
    
    int calculateSalary(int hours_worked)
    {
      return this->pay_per_Hour * hours_worked;     //returns salary of intern
    }
};

int main()
{
    int choice, n, pay, worked,semi_choice,semi_choice1,g_var, id,New_id;
    int  i,j = 1,k = 1;
    cout << "Enter total number of Employees: " << '\n';
    cin >> n;
    manager mang[n];    //array of objects in manager class
    intern intn[n];     //array of objects in intern class
    while(1)
    {   
      cout<<"__________________________MENU_____________________"<<'\n';  
      cout << "1.Create Employee (manager or intern)" << '\n';
      cout << "2.Update Employee Details (manager or intern)" << '\n';
      cout << "3.Print Employee Details (manager or intern)" << '\n';
      cout << "4.Update Pay (manager or intern)" << '\n';
      cout << "5.Calculate Salary (manager or intern)" << '\n';
      cout << "6.Exit" << '\n';
      cout << "Enter  Choice of your own: ";
      cin >> choice;
      switch(choice)
      {
          case 1:
             cout << "1.Creating Manager Detils: " << '\n';
             cout << "2.Creating Intern Detils: " << '\n';
             cout << "Enter your choice: ";
             cin >> semi_choice;
             if(semi_choice == 1)       //creating manager account
             {
                cout << "Enter the employee_id ";
                cin >> id;
                for(i=0; i < n; i++)
                {
                   if(id == mang[i].get_employee_id())
                   {
                      semi_choice1 = 0;
                      break;
                   }
                   else
                   {
                      semi_choice1 = 1;
                   }   
                }
                if(semi_choice1 == 1)
                {
                    mang[j].setDetails_of_Employee(id);
                    j++;
                }
                else
                {
                  cout << "The entered employee_id is already given to someone else  " << '\n'; 
                }
             }
             else if(semi_choice == 2)      //creating intern account 
             {
                cout << "Enter the employee_id: ";
                cin >> id;
                for(i=0; i < n; i++)
                {
                    if(id == intn[i].get_employ_id())
                    {
                       semi_choice1 = 0;
                       break;
                    }
                    else
                    {
                       semi_choice1 = 1;
                    }   
                }
                if(semi_choice1 == 1)
                {
                    intn[k].setDetails_of_Employee(id);
                    k++;
                }
                else
                {
                    cout << "Employee already exist " << '\n';
                }
             }
             else
             {
                cout << "Please enter right choice" << '\n';    
             }
             break;
        case 2:
            cout << "1.update Manager details " << '\n';
            cout << "2.update Intern details " << '\n';
            cout << "Enter your Choice: ";
            cin >> semi_choice;
            if(semi_choice == 1)        //updating manager details
            {
               cout << "Enter Employee id of employee: " << '\n';
               cin >> id;
               for(int i = 0; i < n; i++)
               {
                  if(mang[i].get_employee_id() == id)
                  {
                     cout << "Enter the New employee_id " << '\n';
                     cin >> New_id;
                     mang[i].setDetails(New_id);
                     break;
                  }
                  else
                  {
                     g_var = 0;
                  }
               }
               if(g_var == 0)
                  cout << "Entered id  does not exist " << '\n';
            }
            else if(semi_choice == 2)       //updating intern details
            {
              cout << "Enter Employee id : " << '\n';
              cin >> id;
               for(int i = 0; i < n; i++)
               {
                  if(intn[i].get_employ_id() == id)
                  {
                     cout << "Enter the New employee_id " << '\n';
                     cin >> New_id;
                     intn[i].setDetails(New_id);
                     break;
                  }
                  else
                  {
                     g_var = 0;
                  }
               }
               if(g_var == 0)
                  cout << "Entered id does not exits " << '\n';
            else
            {
                cout << "please enter right choice " << '\n';
            }
            break;
        case 3:
           cout << "1.Manager Details " << '\n';
           cout << "2.Intern Details " << '\n';
           cout << "ENTER your Choice ";
           cin >> semi_choice;
           if(semi_choice == 1)         //print manager details
           {
               cout << "Enter Employee id  ";
               cin >> id;
               for(int i = 0; i < n; i++)
               {
                  if(mang[i].get_employee_id() == id)
                  {
                    mang[i].getDetails();
                    break;
                  }
                  else
                  {
                    g_var = 0;
                  }
               }
               if(g_var == 0)
                  cout << "Entered id is not exits " << '\n';
           }
           else if(semi_choice == 2)        //print intern details
           {
               cout << "Enter Employee id which you need: ";
               cin >> id;
               for(int i = 1; i <= n; i++)
               {
                  if(intn[i].get_employ_id() == id)
                  {
                    intn[i].getDetails();
                    break;
                  }
                  else
                  {
                    g_var = 0;
                  }
               }
               if(g_var == 0)
                  cout << "Entered id doesnot exist " << '\n';
           }
           else
           {
               cout << "Please Enter a right choice " << '\n';
           }
           break;
        case 4:
           cout << "1.update pay in Manager Employee " << '\n';
           cout << "2.update pay in Intern Employee " << '\n';
           cout << "Enter your choice: " << '\n';
           cin >> semi_choice;
           if(semi_choice == 1)     //updating pay of manager
           {
              cout << "Enter Employee id: ";
              cin >> id;
              for(int i = 1; i <= n; i++)
              {
                  if(mang[i].get_employee_id() == id)
                  {
                    cout << "Enter the new pay for employee:";
                    cin >> pay;
                    mang[i].setSalary(pay);
                    break;
                  }
                  else
                  {
                    g_var = 0;
                  }
               }
               if(g_var == 0)
                  cout << "Entered id does not exist " << '\n';
           }
           else if(semi_choice == 2)        //update pay of intern
           {
              cout << "Enter Employee id : ";
              cin >> id;
              for(int i = 0; i < n; i++)
              {
                  if(intn[i].get_employ_id() == id)
                  {
                    cout << "Enter the new pay for employee";
                    cin >> pay;
                    intn[i].setSalary(pay);
                    break;
                  }
                  else
                  {
                    g_var = 0;
                  }
              }
              if(g_var == 0)
                 cout << "Entered id does not exist " << '\n';
           }
           else
           {
              cout << "Please choose a right choice" << '\n';
           }
           cout << '\n';
           break;
        case 5:
           cout << "Salary Calculation " << '\n';
           cout << "1.calculating salary in manager list of employees" << '\n';
           cout << "2.calculating salary in intern list of employees " << '\n';
           cout << "Enter Your Choice: ";
           cin >> semi_choice;
           if(semi_choice == 1)
           {
              cout << "Enter Employee id : ";
              cin >> id;
              for(int i = 1; i <= n; i++)
              {
                  if(mang[i].get_employee_id() == id)
                  {
                    cout << "Enter the number of months worked ";
                    cin >> worked;
                    cout << "The salary he/she paid is: " << mang[i].calculateSalary(worked) << '\n'; 
                    break;
                  }
                  else
                  {
                    g_var = 0;
                  }
              }
              if(g_var == 0)
                  cout << "Entered id does not exist " << '\n';
               
           }
           else if(semi_choice == 2)
           {
              cout << "Enter Employee id  : ";
              cin >> id;
              for(int i = 1; i <= n; i++)
              {
                  if(intn[i].get_employ_id() == id)
                  {
                    cout << "Enter the how many hrs worked ";
                    cin >> worked;
                    cout << "The salary he/she paid is: " << intn[i].calculateSalary(worked) << '\n'; 
                    break;
                  }
                  else
                  {
                    g_var = 0;
                  }
              }
              if(g_var == 0)
                 cout << "Entered id does not exist " << '\n';
           }
           else
           {
              cout << "Please enter  correct choice" << '\n';  
           }
           cout << '\n';
           break;
        case 6:
           exit(0);
        default:
            cout << "Invalid choice chosen,enter correct option " << '\n';
      }
    }  
  }
    return 0;
}