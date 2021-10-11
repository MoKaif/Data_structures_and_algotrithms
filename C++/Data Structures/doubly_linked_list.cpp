#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int key;
        int data;
        Node *prev;
        Node *next;


        Node()
        {
            key = 0;
            data = 0;
            prev = NULL;
            next = NULL;
        }

        Node(int k, int d)
        {
            key = k;
            data = d;
        }
};

class DoublyLinkedList
{
    public:
        Node *head;


        DoublyLinkedList()      
        {
            head =NULL;
        }
        DoublyLinkedList(Node *n)
        {
            head = n;
        }

        Node * checkIfNodeExists(int k)
        {
            Node *temp = NULL;
            Node *ptr = head;

            while(ptr!=NULL)
            {
                if(ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            }
            return temp;
        }

        void appendNode(Node *n)
        {
            if (checkIfNodeExists(n -> key) != NULL) 
            {
                cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
            } 
            else
            {
                if (head == NULL) 
                {
                    head = n;
                    cout << "Node Appended as Head Node" << endl;
                } 
                else 
                {
                    Node * ptr = head;
                    while (ptr -> next != NULL) {
                    ptr = ptr -> next;
                }
                ptr -> next = n;
                n -> prev = ptr;
                cout << "Node Appended" << endl;
      }
    }
  }

        void prependNode(Node *n)
        {
            if(checkIfNodeExists(n->key)!=NULL)
            {
                cout<<"Node Already Exists with key value: "<<n->key<<" .Prepend another node with different value"<<endl;
            }
            else
            {
                if(head ==NULL)
                {
                    head  = n;
                    cout<<"Node prepended as head";
                }
                else
                {
                    head ->prev = n;
                    n->next = head;

                    head = n;
                    cout<<"Node Prepended"<<endl;
                }
            }
        }

        void insertNodeAfter(int k, Node *n)
        {
            Node* ptr = checkIfNodeExists(k);
            if(ptr == NULL)
            {
                cout<<"No Node exists"<<endl;
            }
            else
            {
                if(checkIfNodeExists(n->key)!=NULL)
                    cout<<"Node already exists with key : "<<n->key<<" . insert another node."<<endl;
                else
                {
                    Node *nextNode = ptr->next;
                    if(nextNode == NULL)
                    {
                        ptr->next = n;
                        n->prev = ptr;
                        cout<<"Node Inserted at END<<endl";

                    }
                    else
                    {
                        n->next = nextNode;
                        nextNode -> prev = n;
                        n->prev = ptr;
                        ptr -> next = n;
                        cout<<"Node inserted in between"<<endl;
                    }

                }
            }
        }
        void deleteNodeByKey(int k)
        {
            Node *ptr = checkIfNodeExists(k);
            if(ptr == NULL)
            {
                cout<<"No Node Exists with key value "<<k<<endl;
            }
            else
            {
                if(head->key ==k)
                {
                    head = head->next;
                    cout<<"Node Unlinked with key value "<<k<<endl;
                }
                else
                {
                    Node *nextNode = ptr->next;
                    Node *prevNode = ptr->prev;
                    if(nextNode ==NULL)
                    {
                        prevNode->next = NULL;
                        cout<<"Node deleted at end"<<endl;
                    }
                    else
                    {
                        prevNode->next = nextNode;
                        nextNode->prev = prevNode;
                        cout<<"Node deleted in between"<<endl;  
                    }
                }
            }
        }
        void updateNodeByKey(int k, int d)
        {
            Node *ptr = checkIfNodeExists(k);
            if(ptr!=NULL)
            {
                ptr->data = d;
                cout<<"Node updated successfully"<<endl;
            }
            else
            {
                cout<<"Node doesn't exists"<<endl;
            }
        }
        void printList()
        {
            if(head == NULL)
            {
                cout<<"No nodes in the linked list"<<endl;
            }
            else
            {
                cout<<"Doubly Linked List Values: "<<endl;
                Node *temp = head;
                while(temp!=NULL)
                {
                    cout<<"("<<temp->key<<","<<temp->data<<")"<<"<--->";
                    temp = temp->next;
                }
                cout<<endl;
            }
        }

};

int main() {

  DoublyLinkedList obj;
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
      obj.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      obj.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);

      break;
    case 6:
      obj.printList();

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