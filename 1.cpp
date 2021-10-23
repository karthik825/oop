#include <iostream>
using namespace std;
void add_node(int data,int pos);
void display();
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;

void add_node(int data, int position)//overloading add_node function
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

            printf("Data is add_nodeed\n");
        }
        else
        {
            printf("Unable to add node at given position\n");
        }
    }
    }

void display() 
{
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) 
   {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() 
{
   add_node(3,1);
   add_node(1,2);
   add_node(7,5);
   add_node(2,4);
   add_node(9,3);
   cout<<"The linked list is: ";
   display();
   return 0;
}