#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//%5s of%-8s biçimi beliretci bir karakter dizininin beþ karakterlik bir alanda saða dayalý olarak yazdýrýr ardýndan of dizesi gelir ve bir karakter dizinini sekiz karakterlik
// bir alanda sola dayalý olarak yazdýrýr.%-8s içerisindeki eksi iþareti sola dayalý olmasý durumunu belirtir.
 
#define SUITS 4
#define FACES 13
#define CARDS 52
//prototipler
void shuffle(unsigned int wDeck[][FACES]);//karýþtýrma wDeck üzerinden deðiþiklik yapar
void deal(unsigned int wDeck[][FACES],const char *wFace[],
	const char *wSuit[]);//daðýtmak diziler üzerinde deðiþiklik yapmaz
	
int main(void)
{
	//suit dizisini yükle 
	const char *suit[SUITS]={"Hearts","Diamonds","Clubs","Spades"};
	//face dizisini yükle
	const char *face[FACES]={
	"Ace","Deuce","Three","Four",
	"Five","Six","Seven","Eight","Nine",
	"Ten","Jack","Queen","King"};
	//deck dizisini yükle
	unsigned int deck[SUITS][FACES]={0};
	srand(	time(NULL));//çekirdek rastgele sayý üretici
	shuffle (deck);//desteyi karýþtýr 
	deal(deck,face,suit);//desteyi daðýt
}

//deck içerisindeki kartlarý karýþtýracaðýz
void shuffle(unsigned int wDeck[][FACES])
{
	size_t row;//satýr numarasý
	size_t column;//sütun numarasý
	size_t card;//sayaç
	//kartlarýn her biriiçin deck yuvasýný rastgele olarak seç
	for(card=1;card<=CARDS;++card){
		//kullanýlmayan yuva bulunanan kadar rasy-tgele bir yer seç
		do{
			row=rand() % SUITS;
			column=rand() % FACES;
		}while(wDeck[row][column]!=0);
		
		//seçilen deck yuvasý içerisine kart numarasý yerleþtir
		wDeck[row][column]=card;
	}
}

//deck içerisindeki kartlarý daðýt
void deal(unsigned int wDeck[][FACES],const char *wFace[],const char *wSuit[])
{
	size_t card;//kart sayacý
	size_t row;//satýr sayacý
	size_t column;//sütun sayacý
	
	
//kartlarýn her birini daðýt
for(card=1;card<=CARDS;++card)
{
	//wDeck satýrlarý boyunca döngü oluþtur
	for(row=0;row<SUITS;++row)
	{
		//geçerli satýrlar için wdeck boyunca döngü oluþtur
		for(column=0;column<FACES;++column)
		{
			//eðer slot geçerli kartý içeriyorsa kartý görüntüle
			if(wDeck[row][column]==card){
				printf("%5s of%-8s%c",wFace[column],wSuit[row],card%2==0 ? '\n':'\t');
			}
		}
	}
}
}

