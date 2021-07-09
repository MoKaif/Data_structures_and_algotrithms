#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int front,rear, a[5];
    public:
        Queue()
        {
            front=-1;
            rear=-1;
            for(int i=0;i<5;i++)
            {
                a[i]=0;
            }
        }

        bool isEmpty()
        {
            if (front==-1 && rear==-1)
                return true;
            else    
                return false;
        }

        bool isFull()
        {
            if(rear==4)
                return true;
            else    
                return false;
        }

        void enqueue(int val)
        {
            if(isFull())
            {
                cout<<"Queue is Full"<<endl;
                return;
            }
            else if(isEmpty())
            {
                rear=0;
                front=0;
                a[rear]=val;
            }
            else
            {
                rear++;
            }
            a[rear]=val;
        }

        int dequeue()
        {
            int x;
            if(isEmpty())
            {
                cout<<"Queue is Empty"<<endl;
                return 0;
            }
            else if (front==rear)
            {
                x=a[front];
                a[front]=0;
                rear=-1;
                front=-1;
                return x;
            }
            else
            {
                x=a[front];
                a[front]=0;
                front++;
                return x;
            }
        }

        int count()
        {
            return rear-front+1;
        }

        void display()
        {
            for(int i=0;i<5;i++)
            {
                cout<<a[i]<<" ";
            }
            return;
        }

};

int main()
{
    Queue q1;
    int option,value;
    do
    {
        cout<<"What action do you want to perform ? Enter the option number. Press 0 to Exit"<<endl;
        cout<<"1.Enqueue()"<<endl;
        cout<<"2.Dequeue()"<<endl;
        cout<<"3.isEmpty"<<endl;
        cout<<"4.isFull"<<endl;
        cout<<"5.Count"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Clear Screen"<<endl<<endl;

        cin>>option;

        switch (option)
        {
        case 1:
            cout<<"Enter a value to Enqueue"<<endl;
            cin>>value;
            q1.enqueue(value);
            break;
        case 2:
            cout<<"Dequeue() called -- Removed value :"<<q1.dequeue()<<endl;
            break;
        case 3:
            if (q1.isEmpty())
                cout << "Queue is Empty" << endl;
            else
                cout << "Queue is not Empty" << endl;
            break;
        case 4:
            if (q1.isFull())
                cout << "Queue is Full" << endl;
            else
                cout << "Queue is not Full" << endl;
            break;
        case 5:
            cout << "Count Function Called - Number of Items in the Queue are: " << q1.count() << endl;
            break;
        case 6:
            cout << "Display Function Called - " << endl;
            q1.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
            }
        
    } while (option!=0);
    
    return 0;
}