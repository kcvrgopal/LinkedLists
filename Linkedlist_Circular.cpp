#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class Linkedlist_Circular
{
	private:
	int s;
	node *head,*tail;
	public :
	Linkedlist_Circular()
	{
		s=0;		
//		head=new node;
//		tail=new node;
		head=tail=NULL;
	}
	void insert(int d)
	{
		node *p=new node;
		p->data=d;
		if(head==NULL)
		{
			head=p;
			tail=head;
		}
		else
		{
			tail->next=p;
		}
		tail=p;
		tail->next=head;
		s++;
	}
	void remove()
	{
		if(head==tail)
		{
			head=tail=NULL;
		}
		else
		{
			node *p=new node;
			node *bp=new node;
			p=head->next;
			bp=head;
			while(p->next!=tail)
			{
				p=p->next;
				bp=bp->next;
			}
			p->next=tail->next;
			tail=p;
		}
		s--;
	}
	void display()
	{
		if(s!=0)
		{
			cout<<"Here you go\n";
			node *p=new node;
			p=head;
			cout<<p->data<<"->";
			p=p->next;
			int l=0;
			while(p!=head)
			{
				cout<<p->data<<"->";
				p=p->next;
				l++;
			}
			cout<<p->data<<endl;
			//cout<<tail->data<<endl;
			cout<<"Done!\n";
		
		}
	}
	void siz()
	{
		
		cout<<"Size : "<< s<<endl;
	}
	~Linkedlist_Circular()
	{
		
	}
};
int main()
{
	Linkedlist_Circular l;
	char ch;
	int o,data;
	cout<<"MENU"<<endl;
	do{
		cout<<"1. Insert\n2. Remove\n3. Display\n4. Size\n";
		cin>>o;
		switch(o)
		{
			case 1: cout<<"Enter element to insert"<<endl;
					cin>>data;
					l.insert(data);
					break;
			case 2: l.remove();
					break;
			case 3: l.display();
					break;
			case 4: l.siz();
					break;
			default: cout<<"Choose a correct option\n";
		}
		cout<<"Do you want to continue? Y or N\n";
		cin>>ch;
	}while(ch=='Y'||ch=='y');
	return 0;
}