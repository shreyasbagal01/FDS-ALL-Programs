#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 50
struct node
{
   char c;
   int ind;
   struct node *next, *down;
  }*head;
  class GList
   {
     public:
        GList();
        struct node *create(char *);
        void display(struct node*);
        int depth(node *p);
        int max(int i, int j);
   };
    GList :: GList()
    {
     head=NULL;
   }
   node *GList :: create(char *a)
   { 
     static int i;
     node *New;
     if(a[i]=='\0')
      	return NULL;
     for(;a[i]==',' || a[i]==' ' ; i++);
      New= new node;
     if(New==NULL)
     {
      cout<<"Allocation failed!!!!!!";
        return NULL;
     }
     if (a[i]=='{')
      {
        New->ind=1;
        New->c='{';
        New->next=NULL;
        i++;
        New->down=create(a);
        if(a[i]!='\0')
          New->next=create(a);
        else
          { 
            i=0;
          }
      } 
    else if (a[i]!='}'&&a[i]!=',')
      {
       New->ind=0;
       New->c=a[i];
       New->down=NULL;
       i++;
       New->next=create(a);
      }
      else if (a[i]=='}')
      {
       i++;
       free(New);
       return NULL; 
      }
   
    return New;
 }
 int GList:: max(int i ,int j)
   {
    return i>j?i:j;
   }
  void GList:: display(node *temp)
   {
     if(temp==NULL)
        return;
       if(temp->ind==1)
         {
          cout<<"{";
          display(temp->down);
          cout<<"}";
          if(temp->next!=NULL)
              display(temp->next);
         }
        else
         {
            cout<<" "<<temp->c;
            display(temp->next);
         }
    }
   int GList :: depth(node *temp)
    {
     int i=0 ,j=0;
     if( temp==NULL)
             return 0;
       if(temp->ind=1)
           {
            j=1+(depth(temp->down));
              if(temp->next!=NULL)
                  i=depth(temp->next);
            }
              else
                             i= depth(temp->next);
             return max(i,j);
    }
         int main()
          {
            int choice,d;
            char set[MAX];
            node *start=NULL; 
           GList obj;
           char ans;
           do
            {
             cout<<"\n\t\tThe program for GLL:";
             cout<<"\n\t1.create";
             cout<<"\n\t2.display";
             cout<<"\n\t3.depth";
             cout<<"\n\nEnter your choice :";
             cin>>(choice);
             switch(choice)
              {
               case 1:
                       set[0]='\0';
                       cout<<"\nEnter string";
                       cin>>set;
                       start=obj.create(set);
                       break;
              case 2 :
                       cout<<"\nDisplaying List :";
                       obj.display(start);
                       break;
             case 3 :
             			if(start==NULL)
             			cout<<"\nDepth of the list is :0";
             			else
             			{
						    d=obj.depth(start);
                        	cout<<"\nDepth of the list is :"<<d-1;
                        }
                        break;
            default :
                        exit(0);
                        break;
               }
              cout<<"\nDo you want to continue?";
                cin>>ans;
           }
          while(ans=='y' || ans=='Y');
             return 0;
   }
