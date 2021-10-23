//cs20b1067
//kodam karthik
//menu driven code for merging sorted linked lists using operator overloading

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
    list() //constructor
    {
        head = NULL;
        size = 0;
    }
    bool isEmpty() //function for checking if the list is empty
    {
        if (head == NULL)
        {
            return false;
        }
        else
        {
            return false;
        }
    }
    void add_node(int data) //function for inserting new node
    {
        Node *newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));
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
    int length() //function for returning length of list
    {
        return size;
    }

    void display() //function for displaying the list
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << ""
                 << "->";
            temp = temp->next;
        }
        cout << "\n";
    }
    list operator+(list &obj) //merging using operator overloading
    {
        Node *h1 = head;
        Node *h2 = obj.head;

        while (h1->next != NULL)
        {
            h1 = h1->next;
        }
        
        h1->next = obj.head;
        obj.head = NULL;

        struct Node *curr = head;
        struct Node *index = NULL;
        int temp;

        if (head == NULL)
        {
            list res;
            res.head = NULL;
            return res;
        }
        else
        {
            while (curr != NULL)
            {
                index = curr->next;

                while (index != NULL)
                {
                    if (curr->data > index->data)
                    {
                        temp = curr->data;
                        curr->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                curr = curr->next;
            }
        }
        list res;
        res.head = head;
        head = NULL;
        return res;
    }
    

   
};

int main()
{
    int choice, ch;
    struct Node *head = NULL;

    list l1, l2,l3;
    cout << "_______________MENU_______________" << endl;
    cout << "1).insert\n2).display \n3).merge\n4).exit\n"
         << endl;
    while (1) //menu for various operations
    {
        cout << "enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter sub choice :\n1).for inserting into l1\n2).for inserting into l2\n" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:

                int data1;
                cin >> data1;
                cout << "the item added to list1 is->" << data1 << "" << endl;
                l1.add_node(data1);
                break;

            case 2:
                int data2;
                cin >> data2;
                cout << "the item added to list2 is->" << data2 << "" << endl;
                l2.add_node(data2);
                break;
            }

            break;
        
        case 2:
            cout << "enter sub choice" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                cout << "the list1 is"<< "\t";
                l1.display();
                break;

            case 2:
                cout << "the list2 is"<< "\t";
                l2.display();
                break;
            }
            break;
        case 3:
            cout << "the merged list is" << endl;
            l3= l1 + l2;
            l3.display();
            break;
        case 4:
            exit(1);
        default:
            cout << "Enter valid choice" << endl;
            break;
        }
    }
}