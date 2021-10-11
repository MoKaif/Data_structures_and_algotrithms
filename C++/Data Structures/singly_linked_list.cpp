#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node *next;

    Node()
    {
        key = 0;
        data=0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key  = k;
        data = d;

    }
};

class Singly_linked_list{
 public:
    Node *head;

    Singly_linked_list(){
        head = NULL;
    }

    Singly_linked_list(Node *n)
    {
        head = n;
    }

    Node* node_exists(int k)   // 1. To check if node exists
    {
        Node* temp = NULL;
        Node* ptr = head;
        while(ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void append_node(Node* n)    //2. To append a node to the linked list
    {
        if (node_exists(n->key)!=NULL)
        {
            cout<<"\n Node Already Exists with key value:  "<< n->key <<". Append another node with different key value";
        }
        else 
        {
            if(head==NULL)
            {
                head = n;
                cout<<"\n Node appended. ";
            }
            else
            {
                Node *ptr = head;
                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout<<"\n Node Appended. ";
            }
        }
        
    }
    void prepend_node(Node *n)
    {
        if (node_exists(n->key)!=NULL)
        {
            cout<<"\n Node Already Exists with key value:  "<< n->key <<". Append another node with different key value";
        }
        else
        {
            n->next = head;
            head = n;
            cout<<"Node Prepended. ";
        }
    }
    void insert_node(int k, Node *n)
    {
        Node *ptr = node_exists(k);
        if(ptr==NULL)
        {
            cout<<"\n No Node exists: with key value: "<< k ;
        }
        else
        {
            n->next = ptr->next;
            ptr->next = n;
            cout<<"\n Node Inserted";
        }
    }
    void delete_node(int k)
    {
        if (head==NULL)
        {
            cout<<"\n Linked list already empty";
        }
        else if(head!=NULL)
        {
            if(head->key ==k)
            {
                head = head->next;
                cout<<"\n Node Unlinked from key: "<< k;
            }
            else
            {
                Node *temp = NULL;
                Node *prevptr = head;
                Node *currptr = head->next;
                while(currptr!=NULL)
                {
                    if(currptr->key = k)
                    {
                        temp = currptr;
                        currptr= NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currptr = currptr->next;
                    }
                }
                if(temp!=NULL)
                {
                    prevptr->next = temp->next;
                    cout<<"\n Node Unlinked with key " << k;
                }
                else
                {
                    cout<<"\n Node doesn't exist";
                }

            }
        }

    }
    void update_key(int k, int d)
    {
        Node *ptr = node_exists(k);
        if (ptr!=NULL)
        {
            ptr->data = d;
            cout<<"\nNode Data Updated Successfully";
        }
        else
        {
            cout<<"\n Node Doesn't exist";
        }
    }
    void print_list()
    {
        if(head==NULL)
        {
            cout<<"\n No node in singly linked list";
        }
        else
        {
            cout<<"\n Values in Singly Linked List: ";
            Node *temp = head;
            while (temp!=NULL)
            {
                cout<<"\n"<<temp->key<<": "<<temp->data;
                temp=temp->next;
            }
            
        }
    }
};

int main()
{
    
  Singly_linked_list s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.append_node(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prepend_node(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.insert_node(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.delete_node(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.update_key(key1, data1);

      break;
    case 6:
      s.print_list();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

    return 0;
}