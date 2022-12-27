#include<iostream>
using namespace std;
class sort
{
 float m[30];
 int i,j,n;
public:
 void insert()
 {
  cout<<"ENTER NUMBER OF STUDENTS:"<<endl;
  cin>>n;
  cout<<"ENTER MARKS:"<<endl;
  for(i=0;i<n;i++)
  {
   cin>>m[i];
  }
 }
 void display()
 {
  cout<<"ENTERED MARKS ARE:"<<endl;
  for(i=0;i<n;i++)
  cout<<m[i]<<endl;
 }

 void bubble()
 {
  float temp;
  for(i=0;i<n-1 ;i++)
  {
   for(j=0;j<(n-1)-i;j++)
   {
    if(m[j]>m[j+1])
    {
     temp=m[j];
     m[j]=m[j+1];
     m[j+1]=temp;
    }
   }
  }
cout<<"TOP FIVE:"<<endl;
  for(i=n-1;i>=(n-5);i--)
  {
   cout<<m[i]<<endl;

  }
 }
 void selection()
 {
  int min;
  float temp;
  for(i=0;i<(n-1);i++)
  {
   min=i;
   for(j=i+1;j<n;j++)
   {
    if(m[j]<m[min])
    {
     min=j;
    }
   }
    temp=m[i];
    m[i]=m[min];
    m[min]=temp;

  }
  cout<<"TOP FIVE:"<<endl;
  for(i=n-1;i>= (n-5);i--)
  {
   cout<<m[i]<<endl;
  }
 }
};
int main()
{
 sort s;
 int ch,x;
 cout<<"LIST OF TOP FIVE STUDENTS:"<<endl;
 do
 {
 cout<<"1.CREATE \n2.DISPLAY\n3.TOP FIVE BY BUBBLE SORT\n4.TOP FIVE BY INSERTION SORT\nENTER CHOICE:"<<endl;
  cin>>ch;
  switch(ch)
  {
  case 1:
   s.insert();
   break;
  case 2:
   s.display();
   break;
  case 3:
   s.bubble();
   break;
  case 4:
   s.selection();
   break;
  default:
   cout<<"INVALID CHOICE!"<<endl;
  }
  cout<<"DO YOU WANT TO CONTINUE? 1.YES 2.NO"<<endl;
  cin>>x;
 }while(x==1);
 return 0;
}
// Algorithm:-
//1)	Start
//2)	Declare the variables such as,n array,ele,ch,i=0
//3)	Input how many no. of students in first year
//4)	Input the Enter percentage marks of students
//5)	Print Menu:
        //1)	Selection Sort
        //2)	Bubble Sort and display Top 5 scores
        //3)	Exit 
    //ch= Input enter your choice
//6)	If ch==1 then call function SelectionSort(array,n) 
//7)	else if ch==2 then call function BubbleSort(array,n) 
//8)	else If ch==3 then go to step 9 else print wrong choice
//9)	Stop

