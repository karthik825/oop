//cs20b1067
//kodam karthik
//implement linkedlists using functional overloading



#include <iostream>
#include <cstdlib>

using namespace std;

struct Node //structure for linked lists
{
    int data;
    struct Node *next;
};

class list //using class
{
private:
    Node *head;
    int size;

public:
    list()          //constructor
    {
        head = NULL;
        size = 0;
    }
    bool isEmpty()      //function for checking if the list is empty
    {
        if(head == NULL)
        { 
            return false;
        }
        else
        { 
            return false;
        }
    }
    void add_node(int data) //function for inserting new node at end of list 
    {
        Node *newNode;
        newNode = new Node;
        Node *tmp = newNode;
        tmp->data = data;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
        }
        else
        {
            Node *tmp2 = head;
            while (tmp2->next != NULL)
            {
                tmp2 = tmp2->next;
            }
            tmp2->next = tmp;
        }
        size++;
    }
    void add_node(int data, int position)//overloading insert function
    {
        int i;
        struct Node *newNode, *temp;

         newNode = new Node;

        if(newNode == NULL)
        {
            printf("Unable to allocate memory.");
        }
        else
        {
            newNode->data = data; // Link data part
            newNode->next = NULL;

            temp = head;

            for(i=2; i<=position-1; i++)
            {
                temp = temp->next;

                if(temp == NULL)
                    break;
            }

            if(temp != NULL)
            {
                newNode->next = temp->next; 
                temp->next = newNode;

            printf("Data is inserted\n");
        }
        else
        {
            printf("Unable to add node at given position\n");
        }
    }
    }

    int length() //function for returning length of list
    {
        return size;
    }

    void display() //function for displaying the list
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "" << "->";
            temp = temp->next;
        }
        cout<<"\n";
    }
    void deleteNode()
    { 
        struct Node *ptr,*ptr1;  
        if(head == NULL)  
        {  
            printf("\nlist is empty");  
        }  
        else if(head -> next == NULL)  
        {  
            head = NULL;  
            free(head);  
            printf("\nOnly node of the list deleted ...");  
        }  
              
        else  
        {  
            ptr = head;   
            while(ptr->next != NULL)  
                {  
                    ptr1 = ptr;  
                    ptr = ptr->next;  
                }  
                ptr1->next = NULL;  
                free(ptr);  
                printf("\n Deleted Node from the last ..."); 
        }        
    }
   
    void deleteNode(int position) //function for deleting node at given position
    {
        if (isEmpty())
        {
            cout << "list is empty" << endl;
            return;
        }
        struct Node *temp = head;
        if (position == 1)
        {
            head = temp->next;
            free(temp);
            return;
        }
        for (int i = 2; temp != NULL && i < position - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL)
        {
            return;
        }
        struct Node *next = temp->next->next;
        free(temp->next);
        temp->next = next;
        size--;
    }

    ~list()         //destructor
    {
        free(head);
    }
};

int main()
{
    int choice, ch;
    struct Node *head = NULL;

    list l1;
    cout << "_______________MENU_______________" << endl;
    cout << "1).insert at end\n2).insert at given position\n3).delete(end and at given position)\n4).display\n5).exit\n"<< endl;
    while (1)           //menu for various operations
    {
        cout << "enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
                
                int data1;
                cin >> data1;
                
                cout << "the item added to list1 is->" << data1 << "" <<endl;

                l1.add_node(data1);
                break;

        case 2: 

                int data2;
                cin>>data2;
                cout<<"enter the position"<<endl;
                int pos1 ;
                cin>>pos1;
                l1.add_node(data2,pos1);
                break;

        case 3:
            cout << "enter sub choice" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                    l1.deleteNode();
                    break;

            case 2:

                    int k2;
                    cin >> k2;
                    if (k2 > l1.length())
                        cout << "enter valid index" << endl;
                     else
                        l1.deleteNode(k2);
                     break;
            }
            break;
        case 4:
             cout << "the list1 is"<<"\t";
                l1.display();
                break;
       
        case 5:
            exit(1);
        default:
            cout << "Enter valid choice" << endl;
            break;
        }
    }
    return 0;
}