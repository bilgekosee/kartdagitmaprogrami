#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//%5s of%-8s bi�imi beliretci bir karakter dizininin be� karakterlik bir alanda sa�a dayal� olarak yazd�r�r ard�ndan of dizesi gelir ve bir karakter dizinini sekiz karakterlik
// bir alanda sola dayal� olarak yazd�r�r.%-8s i�erisindeki eksi i�areti sola dayal� olmas� durumunu belirtir.
 
#define SUITS 4
#define FACES 13
#define CARDS 52
//prototipler
void shuffle(unsigned int wDeck[][FACES]);//kar��t�rma wDeck �zerinden de�i�iklik yapar
void deal(unsigned int wDeck[][FACES],const char *wFace[],
	const char *wSuit[]);//da��tmak diziler �zerinde de�i�iklik yapmaz
	
int main(void)
{
	//suit dizisini y�kle 
	const char *suit[SUITS]={"Hearts","Diamonds","Clubs","Spades"};
	//face dizisini y�kle
	const char *face[FACES]={
	"Ace","Deuce","Three","Four",
	"Five","Six","Seven","Eight","Nine",
	"Ten","Jack","Queen","King"};
	//deck dizisini y�kle
	unsigned int deck[SUITS][FACES]={0};
	srand(	time(NULL));//�ekirdek rastgele say� �retici
	shuffle (deck);//desteyi kar��t�r 
	deal(deck,face,suit);//desteyi da��t
}

//deck i�erisindeki kartlar� kar��t�raca��z
void shuffle(unsigned int wDeck[][FACES])
{
	size_t row;//sat�r numaras�
	size_t column;//s�tun numaras�
	size_t card;//saya�
	//kartlar�n her birii�in deck yuvas�n� rastgele olarak se�
	for(card=1;card<=CARDS;++card){
		//kullan�lmayan yuva bulunanan kadar rasy-tgele bir yer se�
		do{
			row=rand() % SUITS;
			column=rand() % FACES;
		}while(wDeck[row][column]!=0);
		
		//se�ilen deck yuvas� i�erisine kart numaras� yerle�tir
		wDeck[row][column]=card;
	}
}

//deck i�erisindeki kartlar� da��t
void deal(unsigned int wDeck[][FACES],const char *wFace[],const char *wSuit[])
{
	size_t card;//kart sayac�
	size_t row;//sat�r sayac�
	size_t column;//s�tun sayac�
	
	
//kartlar�n her birini da��t
for(card=1;card<=CARDS;++card)
{
	//wDeck sat�rlar� boyunca d�ng� olu�tur
	for(row=0;row<SUITS;++row)
	{
		//ge�erli sat�rlar i�in wdeck boyunca d�ng� olu�tur
		for(column=0;column<FACES;++column)
		{
			//e�er slot ge�erli kart� i�eriyorsa kart� g�r�nt�le
			if(wDeck[row][column]==card){
				printf("%5s of%-8s%c",wFace[column],wSuit[row],card%2==0 ? '\n':'\t');
			}
		}
	}
}
}

