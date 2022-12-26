#include<iostream>
#include<stdlib.h>
#define size 5
using namespace std;
class pizza
{		
	 int front,rear,q[size];
 public:
	 pizza()
	 {
		 front=-1;
		 rear=-1;
	 }
	int isfull();
	int isempty();
	void add();
	void serve();
	void display();
};
	 int pizza::isfull()
	 {
		if((front==0&&rear==size-1)||front==rear+1)
		 {
			 return 1;
		 }
		else
		{
			 return 0;
		 }
	 }

	int pizza::isempty()
	{
		 if(front==-1&&rear==-1)
		 {
			 return 1;
		 }
		 else
		{
			 return 0;
		 }
	 }

	 void pizza::add()
	 {
		 if(isfull()==0)
		 {
			 cout<<"\n Enter the Pizza ID: ";
			 if(front==-1&&rear==-1)
			 {
				 front=0;
				 rear=0;
				 cin>>q[rear];
			 }
			 else
			 {
				 rear=(rear+1)%size;
				 cin>>q[rear];
			 }
			 char c;
			 cout<<" Do you want to add another order ? ";
			 cin>>c;
			 if(c=='y'||c=='Y')
				 add();
		 }
		 else
		 {
			 cout<<"\n Orders are full ";
		 }
	 }

	void pizza::serve()
	 {
		 if(isempty()==0)
		 {
			 if(front==rear)
			 {
				 cout<<"\n Order served is : "<<q[front];
				 front=-1;
				 rear=-1;
			 }
			 else
			 {
				 cout<<"\n Order served is : "<<q[front];
				 front=(front+1)%size;
			 }
		 }
		 else
		 {
			 cout<<"\n No pending orders ";
		 }
	}
	 void pizza::display()
	 {
		 if(isempty()==0)
		 {
			 for(int i=front;i!=rear;i=(i+1)%size)
			 {
				cout<<q[i]<<"<- ";
			}
			 cout<<q[rear];
		 }
		 else
		 {
			 cout<<"\n No pending orders";
		 }
	 }

int main()
{

 pizza p1;
 int ch;
 while(1)
 {
 
		cout<<"\n\n * * * * PIZZA PARLOUR * * * * \n\n";
		cout<<"1. Add a Pizza \n";
		cout<<"2. Display the Orders \n";
		cout<<"3. Serve a pizza \n";
		cout<<"4. Exit \n Enter your choice : ";
		 cin>>ch;
		switch(ch)
		{
		 case 1:		
		 p1.add();		
		  break;
		 case 2:		
		 p1.display();	 
		 break;
		 case 3:		
		 p1.serve();	 
		 break;
		 case 4:		
		 exit(0);
		 default:
			cout<<"Invalid choice ";
				
		}
}
 
 return 0;
}
