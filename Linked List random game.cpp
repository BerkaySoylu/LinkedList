//-- ba�l� listelerde verilen 10 random say�yla oyun yapma --
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Node{
	public:
		int veri;
		Node *next;
};

class Liste{
	private:
		Node *head;
	public:
		Liste()
		{
		head=NULL;
		}
		bool bosmu();
		void ekle(int a); //say�lar random verilece�inden say� al�nmas�na gerek yok.
		void listele();
		void say();
		void basla(int a);
};

bool Liste::bosmu(){
	return(head==NULL)	;
}

void Liste::ekle(int a){  // sondan eklemeli.
	Node *yeniEl = new Node;
	if(bosmu())
	{	
		head=yeniEl;
		yeniEl->next=head;
		yeniEl->veri=a;
	}
	else
	{
		
		Node *gezici=head;
		while(gezici->next!=head)
		{
			gezici=gezici->next;
		}
			yeniEl->next=head;
			gezici->next=yeniEl;
			yeniEl->veri=a;
	}
}

void Liste::listele(){
	if(bosmu())
	cout << "HATA :Listede eleman yok!" <<endl;
	else
	{	
		int i=1;
		Node *gezici2 =head;
		do{
		cout << i <<".eleman= " << gezici2->veri << "\n";
		gezici2=gezici2->next;
		i++;				
		}while(gezici2!=head);	
	}	
}

void Liste::say(){
		Node *gezici = head;
	if(bosmu())
	{
		cout << "Listede eleman Yok!";
	}
	else
	{
	int sayac=0;
	do{
		gezici=gezici->next;
		sayac++;
	}	
	while(gezici!=head );
	
	cout <<"\nListede toplam =" << sayac << " tane eleman vardir"<< endl;
	}	
}

void Liste::basla(int a){ //random de�er ile ba�lan�r ve i�aret etti�i node silinir
	Node *silici;
	int deger;
	silici=head;
	for(int i=1;i<=10;i++)    
	{
		for(int j=0;j<a-1;j++)
		{
			silici=silici->next;	
		}	
		Node *b=silici->next;  
		a=b->veri;
		silici->next=silici->next->next;
		silici=silici->next;
	
	}
	cout << "KAZANAN SAYI = " <<silici->veri<<"!";
}



int main()
{
	srand (time(NULL));
	int sayi, Rsayi = rand()%10+1; //random say�lar 1 ile 10 aras� se�ilmi�tir.
	
	Liste listem;		
	for(int i=1;i<=Rsayi;i++)
	{
		sayi = rand()%10+1; //for i�inde say� tekrar de�i�tirilir ki hep ayn� say� olmas�n.
		listem.ekle(sayi);

		
	}
	listem.say();
	listem.listele();
	sayi = rand()%10+1;
	cout<<"\nSilinecek ilk eleman="<<sayi+1<<".elemandir.\n\n\n";	//sayi kadar �telenece�i i�in. Listedeki sayi+1. eleman silinir.
	cout<<"--------------------------------\n";
	listem.basla(sayi);
	return 0;
}

