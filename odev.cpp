#include <iostream>
#include<conio.h>

using namespace std;



class node //node icin clas olustutma
{
public:
  int data;
  node *next;
};

class singly_linked_list//singel linked list icin clas olustutma
{
private:
  node *head;
public:
  int length;
  singly_linked_list();
  ~singly_linked_list();

  void add_first(int);
  void add_last(int);
  int Count();
  void add_particularposition(int,int);
  void delete_first();
  void delete_last();
  void delete_all();
  void delete_particularposition(int);
  void display_all();
bool isEmpty()const{
	if(head==NULL)
		return false;
	return true;	
}
 
};


singly_linked_list::singly_linked_list()//singel linked list icin kurucu fonksiyon
{
  this->length = 0;
  this->head = NULL;
}

singly_linked_list::~singly_linked_list()//singel linked list icin yikici fonksiyon
{
  cout << "neseny silindi "  << endl;
}

void singly_linked_list::add_particularposition(int pos,int n)//singel linked list icin ekleme fonksiyonu
{
  node *pre = new node();
  node *cur = new node();
  node *temp = new node();
  
  if(pos==0)
  {
    temp->data = n;
    temp->next = this->head;
    this->head = temp;
  }
  else
  {
    cur=this->head;
    for (int i = 0; i < pos ; i++)
    {
      pre = cur;
      cur = cur->next;
    }
    temp->data = n;
    temp->next = cur;
    pre->next = temp;
  }
  this->length++;
}

void singly_linked_list::add_first(int n)//singel linked list icin baslangicta ekleme fonksiyonu
{
  add_particularposition(0,n);
}

void singly_linked_list::add_last(int n)//singel linked list icin sonunda ekleme fonksiyonu
{
  add_particularposition(this->length,n);
}

 void singly_linked_list::delete_particularposition(int pos)//singel linked list icin  silme fonksiyonu
{
  node *pre = new node();
  node *cur = new node();
  cur = this->head;

  if(pos == 0)
  {
    pre = this->head;
    head = head->next;
  }
  else
  {
    for (int i = 0; i < pos; i++)
      {
	pre = cur;
	cur = cur->next;
      }
    pre->next = cur->next;
  }
  this->length--;
}

void singly_linked_list::delete_first()//singel linked list icin baslangicta silme fonksiyonu
{
	if(isEmpty()){
  delete_particularposition(0);
  cout<<endl<<" eleman cikarma islemi gerceklendi. ";
  }
  else
  cout<<endl<< "Empty linked list" << endl;
}

void singly_linked_list::delete_last()//singel linked list icin sonunda silme fonksiyonu
{
  
  if(isEmpty()){
  delete_particularposition(this->length-1);
  cout<<endl<<" eleman cikarma islemi gerceklendi. ";
  }
  else
  cout<<endl<< "Empty linked list" << endl;
  
}


void singly_linked_list::display_all()//singel linked list icin ekrana gosterme fonksiyonu
{
  node *new_node = this->head;
  
 
  if(isEmpty()){
  	cout<<endl<<"Linked list girisi : "	;
  while(new_node)
  {
     cout << new_node->data <<" -> ";
    new_node=new_node->next;
    
  }
  cout<<"cikis . "<<endl;
  
 }
 else
  cout<<endl<< "Empty linked list" << endl;
  
  
  
}
int singly_linked_list::Count()//singel linked list icin sayac fonksiyonu
{
	int count=0;
  node *new_node = this->head;
  
  while(new_node)
  {
    count++;
    new_node=new_node->next;
    
  }
  return count;
}

void singly_linked_list::delete_all()//singel linked list icin butun elmanlari silme fonksiyonu
{
		
  node *new_node = this->head;
  if(isEmpty()){
  while(isEmpty())
  {
    delete_particularposition(0);
    new_node=new_node->next;
    
  }
  cout<<endl<<"singel linked list temizlendi. ";
 }
 else
  cout<<endl<< "Empty linked list" << endl;
 
}

////////////////////////////////////////////

class LinkedListStack{ //yigin clas olusturma

public:

	LinkedListStack()//yigin icin kurucu fonksiyonu
	{
		top = NULL;
		size = 0;
	}

	~LinkedListStack()//yigin icin yikici fonksiyonu

	{
		node * tempNode;
		while (top)
		{
			tempNode = top;
			delete top;
			top = tempNode->next;
		}

		delete tempNode;
	}

	void push(int value)//yigin icin ekleme fonksiyonu
	{
		node * n = new node;

		n->data = value;
		n->next = top;

		top = n;

		size++;
	}

	int pop()//yigin icin sileme fonksiyonu
	{
		 cout<<endl;
         node * tempNode = top;
		if (top != NULL)
		{
			int value = top->data;
			tempNode=top;
			 top=top->next;
            tempNode->next=NULL;
             delete tempNode;
             
			return value;
		}
		else
		{
			cout << "Empty stack" << endl;
			return 0;
		}
	}


   void pop_all()//yigin icin butun elemanlari sileme fonksiyonu
   {
   	    
		if(top != NULL){
		    cout<<endl<<"yigin temizlendi...";
		    
        while(top != NULL)
		{
		    
        	node * tempNode = top;
            delete top;
			top = tempNode->next;
			delete tempNode;
    
        }
		}
        else
		{
			cout << "Empty stack" << endl;
			
		}
    
   }

   void display_all_stack()//yigin icin ekrana gosterme fonksiyonu
   {	
        cout<<endl;
        
        	node * tempNode = top;
		if(tempNode != NULL)
		{
			cout<<"yigin girisi : "	;
        while(tempNode != NULL)
        {
        
           cout << tempNode->data <<" -> ";	
		   tempNode = tempNode->next;
	
        }
		cout<<"cikis . "<<endl;	
		}
        else
		{
			cout << "Empty stack" << endl;
			
		
		}
   }
   int count_stack()//yigin icin sayma fonksiyonu
   {
   	return size;
   }

private:

	node * top;
	int size;

};
/////////////////////////////////
class Queue//kuyruk icin clas olustutma
{
    node *head;
    node *tail;
    node *prev;
    node *temp;
    bool isEmpty()
    {
        return head == NULL;
    }
public:
    Queue()//kuyruk icin kurucu fonksiyonu
    {
        head = NULL;
        tail = NULL;
    }

    void push(int x)//kuyruk icin yikici fonksiyonu
    {
        temp = new node;
        temp->data = x;
        temp->next = NULL;
        if(isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }

    int pop()//kuyruk icin sileme fonksiyonu
    {
    
         if(!isEmpty())
        {
		
        temp=head;
		int value=temp->data;
        head = head->next;
        delete(temp);
        return value;
        
        }
        else
        {
        		cout <<endl<< "Queue is Empty!" << endl;
            return 0;
        }
    }
    
    void pop_all()//kuyruk icin butun elemanlari sileme fonksiyonu
   {
		if(!isEmpty())
		{
	       cout<<endl<<"Queue temizlendi...";
        while(!isEmpty())
		{
		    
        	temp = head;
            head = head->next;
            delete temp;
    
        }
		}
        else
		{
			cout <<endl<< "Queue is Empty!" << endl;
			
		}
    
   }
    void display()//kuyruk icin ekrana gosterme fonksiyonu
    {
        if(!isEmpty())
        {  
        	cout<<endl<<"kuyruk girisi : "	;
            for(temp = head; temp != NULL; temp=temp->next)
               cout << temp->data <<" -> ";
               
            cout<<"cikis . "<<endl;
        }
        else
        {
            	cout <<endl<< "Queue is Empty!" << endl;
        }
    }
    int count_kuyruk()//kuyruk icin sayma fonksiyonu
   { 
        int count=0;
        cout<<endl;
        if(!isEmpty())
        {
        	
            for(temp = head; temp != NULL; temp=temp->next)
                count++;
                
            return count;
        }
        else
        {
            
            return 0;
        }
   }
};

void ana_menu();//ana menu ekran gosterme fonksiyonu
int main() {
	
	ana_menu();
    char secim='0';
	 char control='0' ;
	singly_linked_list *sll = new singly_linked_list();//singel linked list icin neseny olustutma
	LinkedListStack *yigin = new LinkedListStack();//yigin icin neseny olustutma
	Queue *kuyruk = new Queue();//kuyruk icin neseny olustutma
   do
	{//ana menu isin dongu olustutma
		cout<<endl<<"seciminiz: ";
    	secim = putch(getch());//yanlis basma icin putch(getch()) fonksiyonu kontrol eder
    	cout<<endl;
	switch (secim)//ana menuden baska bir menu gecmek icin switch anahitiri kullandik
		{
      	    case '1':
        		     
			         cout<<"--------------------------------------------------------------------"<<endl
			             <<"*                    Yigin islemleri                               *"<<endl
 	                     <<"*        1.Yigina eleman ekle                                      *"<<endl
                    	 <<"*        2.Yigindan eleman cikar                                   *"<<endl
 	                     <<"*        3.Yigini temezle                                          *"<<endl
 	                     <<"*        4.Yigindaki elemanlari goster                             *"<<endl
 	                     <<"*        5.Yigindaki elemanlari syaisini goster                    *"<<endl
 	                     <<"*        6.Ana menuye geri don                                     *"<<endl
	                   	 <<"--------------------------------------------------------------------"<<endl;
	                   	 
		    do
            { //Yigin menu isin dongu olustutma
	        	    cout<<endl<<"seciminiz: ";
    	            control = putch(getch());
            	
            	if(control=='1'){
            		int temp;
            		cout<<endl<<"Yigina eleman ekleyin : ";
	                    cin>>temp;
	                    yigin->push(temp);
	                    
            		
				}
				else if(control=='2'){
					int temp=yigin->pop();
					if(temp!=0)
            		cout<<endl<<"cikaran eleman  : "<<temp;
	               }
				else if(control=='3')
					yigin->pop_all();
				
				else if(control=='4')
					yigin->display_all_stack();
				
				else if(control=='5'){
				cout<<endl<<"yigindeki elman sayisi :" <<yigin->count_stack();			
                    
				}
				else if(control=='6'){
				cout<<endl;
				ana_menu();
				}
				else 
					cout<<endl<<" yanilis secim tekrar seciniz .....! ";
					
				}
                while(control!='6');
				break;
	        case '2':
	       		 	     
			         cout<<"--------------------------------------------------------------------"<<endl
			             <<"*                    Kuyruk islemleri                               *"<<endl
 	                     <<"*        1.Kuyruga eleman ekle                                      *"<<endl
                    	 <<"*        2.Kuyruktan eleman cikar                                   *"<<endl
 	                     <<"*        3.Kuyrugu temezle                                          *"<<endl
 	                     <<"*        4.Kuyruktaki elemanlari goster                             *"<<endl
 	                     <<"*        5.Kuyruktaki elemanlari syaisini goster                    *"<<endl
 	                     <<"*        6.Ana menuye geri don                                      *"<<endl
	                   	 <<"--------------------------------------------------------------------"<<endl;
	                   	 
				do
               	{//Kuyruk menu icin dongu olustutma
	        	    cout<<endl<<"seciminiz: ";
    	            control = putch(getch());
            	
            	if(control=='1'){
            		int temp;
            		cout<<endl<<"kuyryga a eleman ekleyin : ";
	                    cin>>temp;
            		kuyruk->push(temp);
            	}
				else if(control=='2'){
            		int temp=kuyruk->pop();
					if(temp!=0)
            		cout<<endl<<"cikaran eleman  : "<<temp;
				}
				else if(control=='3')
					kuyruk->pop_all();
									
				else if(control=='4')
				    kuyruk->display();
				    
				else if(control=='5')
			    	cout<<endl<<"kuyrukteki elman sayisi :" <<kuyruk->count_kuyruk();	                
				
				else if(control=='6'){
				    cout<<endl;
				    ana_menu();
				}
				else 
				    cout<<endl<<" yanilis secim tekrar seciniz .....! ";
			}while(control!='6');
                
			break;
				
			case '3':
			     	     
			         cout<<"--------------------------------------------------------------------"<<endl
			             <<"*              bagli liste islemleri                                *"<<endl
 	                     <<"*        1.listeye eleman ekle                                      *"<<endl
                    	 <<"*        2.listeden eleman cikar                                    *"<<endl
 	                     <<"*        3.listeyi temezle                                          *"<<endl
 	                     <<"*        4.listedeki elemanlari goster                              *"<<endl
 	                     <<"*        5.listedeki elemanlari syaisini goster                     *"<<endl
 	                     <<"*        6.Ana menuye geri don                                      *"<<endl
	                   	 <<"--------------------------------------------------------------------"<<endl;
	                   	 
	    	 do
            {//bagli liste menu icin dongu olustutma
	        	    cout<<endl<<"seciminiz: ";
    	             control = putch(getch());
    	             cout<<endl;
            	
            	if(control=='1'){
            		
            		 char control1='0';
            		 cout<<"--------------------------------------------------------------------"<<endl
			             <<"*        bagli liste ekleme liste islemleri                         *"<<endl
 	                     <<"*        1.Araya eleman ekle                                        *"<<endl
                    	 <<"*        2.Sona eleman ekle                                         *"<<endl
 	                     <<"*        3.liste islemlerine geri don                               *"<<endl
	                   	 <<"--------------------------------------------------------------------"<<endl;
	                do
                 	{//bagli liste ekleme liste menu icin dongu olustutma
	        	    cout<<endl<<"seciminiz: ";
    	            control1 = putch(getch()); 	
					cout<<endl; 
	               	if(control1=='1'){
	               		int temp;   
	             		cout<<endl<<"eleman ekleyin : ";
	                    cin>>temp;
	                     sll->add_first(temp);
			    	}
			    	else if(control1=='2'){
			    		int temp;
                        cout<<endl<<"eleman ekleyin : ";
	                    cin>>temp;
	                    sll->add_last(temp);	       
				
				    }
				    else if(control1=='3'){
				    	cout<<endl;
				    	cout<<"--------------------------------------------------------------------"<<endl
			             <<"*              bagli liste islemleri                                *"<<endl
 	                     <<"*        1.listeye eleman ekle                                      *"<<endl
                    	 <<"*        2.listeden eleman cikar                                    *"<<endl
 	                     <<"*        3.listeyi temezle                                          *"<<endl
 	                     <<"*        4.listedeki elemanlari goster                              *"<<endl
 	                     <<"*        5.listedeki elemanlari syaisini goster                     *"<<endl
 	                     <<"*        6.Ana menuye geri don                                      *"<<endl
	                   	 <<"--------------------------------------------------------------------"<<endl;
				    	
				    }
				    else
	               cout<<endl<<" yanilis secim tekrar seciniz .....! ";	
				
			       
	               
	              }while(control1!='3');
				  	
				}
				else if(control=='2'){
					char control2='0';
            		 cout<<"--------------------------------------------------------------------"<<endl
			             <<"*        bagli liste cikarma liste islemleri                         *"<<endl
 	                     <<"*        1.Aradan eleman cikar                                        *"<<endl
                    	 <<"*        2.Sondan eleman cikar                                       *"<<endl
 	                     <<"*        3.liste islemlerine geri don                                *"<<endl
	                   	 <<"--------------------------------------------------------------------"<<endl;
	                do
                 	{//bagli liste cikarma liste dongu olusturma
	        	    cout<<endl<<"seciminiz: ";
    	            control2 = putch(getch()); 
					cout<<endl; 	 
	               	if(control2=='1')
	                     sll->delete_first();

			    	else if(control2=='2')
	                     sll->delete_last();
				
				    else if(control2=='3'){
					   	cout<<endl;////bagli liste menuye don
				    	cout<<"--------------------------------------------------------------------"<<endl
			             <<"*              bagli liste islemleri                                *"<<endl
 	                     <<"*        1.listeye eleman ekle                                      *"<<endl
                    	 <<"*        2.listeden eleman cikar                                    *"<<endl
 	                     <<"*        3.listeyi temezle                                          *"<<endl
 	                     <<"*        4.listedeki elemanlari goster                              *"<<endl
 	                     <<"*        5.listedeki elemanlari syaisini goster                     *"<<endl
 	                     <<"*        6.Ana menuye geri don                                      *"<<endl
	                   	 <<"--------------------------------------------------------------------"<<endl;
				    	
				
			       }
	               else
	               cout<<endl<<" yanilis secim tekrar seciniz .....! ";
	              }while(control2!='3');
				
				}
				else if(control=='3')
					sll->delete_all();//listeyi temezle
				
				else if(control=='4')
					sll->display_all();	 //listedeki elemanlari goster
			
				else if(control=='5')
					cout<<endl<<"listedeki elman sayisi :" <<sll->Count();			
                    
				else if(control=='6'){
				    cout<<endl;
				    ana_menu();
				}
				else {
					cout<<endl<<" yanilis secim tekrar seciniz .....! ";
				}
				
				 
		    	}
                while(control!='6'); 
				break;
		
			case '4':
			 	cout<<endl<<"\t\t.....programi kullandiginiz icin tesekkurler.....";
			 	break;
			 	
			default:
				cout<<endl<<"lutfen 1-4 arasinda bir secim yapiniz...";
		}
	}while(secim!='4');
	
	return 0;
}

void ana_menu(){
	                 cout<<"--------------------------------------------------------------------"<<endl
	                     <<"*                    Ana Menu                                      *"<<endl
 	                     <<"*        1.Yigin Uygulamassi                                       *"<<endl
                    	 <<"*        2.Kuyruk Uygulamassi                                      *"<<endl
 	                     <<"*        3.tek yonlu bagli liste Uygulamassi islemleri             *"<<endl
 	                     <<"*        4.programdan Cikis                                        *"<<endl
	                   	 <<"--------------------------------------------------------------------"<<endl;
}
