#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1009
#define MM 1008

/* 

Burak Boz

Hashing algoritmasýnýn kullanýlmasý
Problem: Bu ödevde, bir kelimenin geçtiði dokümanlarý listeleyen bir sistem tasarlanacaktýr. Bir
kelimenin hangi dokümanlarda geçtiðini bulmak için her seferinde bütün dokümanlara bakmak çok
zaman alýcýdýr. Bunun yerine bu ödevde, yeni gelen bir dokümandaki kelimeler hashing ile bir sözlüðe
yerleþtirilecek ve bir kelime arandýðýnda yine hashing yöntemi ile sözlükte aranarak içinde yer aldýðý
dokümanlar bulunacaktýr. 

Açýklama:
Program çalýþýr çalýþmaz bulunduðu konumda 18011706.txt isimli dosyayý çalýþtýrýr. Bu dosya içerisindeki veriler
1 indexli satýrdan itibaren (0. index baþlýk satýrýdýr) verileri okuyarak hashTable isimli structlardan oluþan diziye doldurur.
Bu dosyada satýrlar;
	key kelime bulunduguDosya1 bulunduguDosya2 ...
þeklinde düzenlenmiþtir. Tekrar kaydedileceði zaman yine ayný düzende kayýt edilecektir.


***MENÜ KULLANIMI***
	1)Ýnput eklemek için kullanýlýr. dosya adýný dosyaadi.txt þeklinde yazýnýz.
	2)Kelime aramak için kullanýlýr. Ýnputlar eklendikten sonra sadece kelime adýný yazarak arama yapýnýz
	3)LoadFactor'ü yazdýrmak için kullanýlýr. Seçimi yapmanýz yeterlidir.
	4)Tüm hashTable deðerlerini ekrana yazdýrmak için kullanýlýr.
	5)Elde bulunan hashTable dizisindeki tüm deðerleri 18011706.txt isimde ve exe dosyasýyla ayný lokasyonda olacak þekilde dosyaya yazar
	6)18011706.txt dosyasýnýn içindeki verileri ekrana yazdýrmak için kullanýlýr.
	0)Çýkýþ yapmak için
*/

int kelimeAra(char[],int);//Kelime ararken kullanýlacak fonksiyondur. (aranacakKelime,horner metodundan gelen deðer)
int h2(int);//DobuleHashing yaparken kullanýlacak fonksiyon
int h1(int);//DobuleHashing yaparken kullanýlacak fonksiyon
struct Node * newNode();//Yeni düðüm oluþturmak için kullanýlacak fonksyion. Bu düðümlerde dosya isimleri saklanacak
int hash(char[],int,char[]);//Hashing yaparken kullanýlacak fonksiyondur. (hashlenecek kelime,horner metodundan gelen deðer, bulunduðu dosy adý)
int getPower(int, int);//Üs almak için kullanýlacak fonksyion (Taban,Üs)
int horner (char[]);//Kelimeye horner metodu uygulanarak üretilecek olan deðer (kelime)
void satirOku(char[]);//Txt dosyasýndan satýr satýr okumayý saðlayan fonksiyon (dosya adý)
void kelimeOku(char[]);//Txt dosyasýndan kelime kelime okumayý saðlayan foknsiyon (dosya adý)

struct Node { //Bu düðümlerde dosya adlarý saklanacaktýr
	char dosyaAdi[100];
	struct Node* next; 
};

typedef struct {//Hash tipinde bir dizi tanýmlanacak ve burada kelimeler saklanacaktýr.
	char kelime[1000];
	struct Node* head;
}HASH;


HASH *hashTable;
int loadFactor;

int main()
{
	int i=0;
	hashTable = (HASH*)calloc(M, sizeof(HASH));
	loadFactor=0;//Doluluk oraný için sayaç olarak kullanýlacak
	float dolulukOrani=0.0f;//Doluluk oraný bu deðiþkende hesaplanacak
	char arananKelime[1000];//Aranan kelime bu deðiþkende tutulacak
	int arananHash=0;//Aranan kelimenin hash deðeri bu deðiþkende tutulacak
	char hashDosya[100];//Hash dosyasýnýn adý burada saklanacak
	char inputDosya[100];//input dosyasýnýn adý burada saklanacak
	int secim=-1;//Menü için kullanýlacaktýr.
	
	for(i=0;i<M;i++)//Hazýrlanan tablo temizleniyor.
	{
		hashTable[i].head=NULL;
		memset(hashTable[i].kelime,0,sizeof(hashTable[i].kelime));
	}
	
	baslangic("18011706.txt");
	do
	{
		printf("\n==========================================================");
		printf("\n\tMenu:\n");
		printf("1*Input ekle\n");
		printf("2*Kelime ara\n");
		printf("3*Loadfactor sorgula\n");
		printf("4*Hash Tablosunu ekrana yazdir (hashTable[i])\n");
		printf("5*Hash Tablosunu txt dosyasina yazdir (hashTable[i]-->hashtablosu.txt)\n");
		printf("6*hashtablosu.txt'yi(18011706.txt) ekrana yazdir\n");
		printf("0*Cikis\n");
		printf("==========================================================\n");
		printf("**Seciminizi yazin:");
		scanf("%d",&secim);
		
		if(secim==1)//Veri giriþi
		{
			printf("\nEklenecek txt dosyasini girin (Ornek:input1.txt):");
			scanf("%s",&inputDosya);
			kelimeOku(inputDosya);
			
			printf("\n\nMenuye donmek icin enter tusuna basin");
			getch();	
		}
		else if(secim==2)//Kelime ara
		{
			printf("Aradiginiz kelimeyi girin:");
			scanf("%s",&arananKelime);
			arananHash=kelimeAra(arananKelime,horner(arananKelime));
			if(arananHash!=-1)
			{
				printf("aranan hash : %d\n",arananHash);
				printf("Tablodan gelen kelime: %s\n ",hashTable[arananHash].kelime);
				printf("Bulunduklari dosyalar: ");
				struct Node *nodeTmp = hashTable[arananHash].head;
				while(nodeTmp != NULL)
				{
					printf("%5s ",nodeTmp->dosyaAdi);
					nodeTmp=nodeTmp->next;
				}
			}
			else{
				printf("Aradiginiz kelime bulunamadi");
			}
			
			printf("\n\nMenuye donmek icin enter tusuna basin");
			getch();
		}
		else if(secim==3)//LoadFactor'ü yazdýrmak için
		{
			dolulukOrani=(float) loadFactor/1009;
			printf("\n\n1009 gozlu tablonun doluluk orani:\n");
			printf("LoadFactor:%d/1009=%2f\n\n",loadFactor,dolulukOrani);
			
			printf("\n\nMenuye donmek icin enter tusuna basin");
			getch();
		}
		else if(secim==4)//hashTable içerisindeki tüm deðerler ekrana yazdýrýlýr. Aþaðýdaki açýklama satýrlarý açýlýrsa sadece dolu gözleri yazar.
		{
			if(loadFactor>0)
			{
				for(i=0;i<M;i++)
				{
					//if(hashTable[i].head!=NULL)
					//{
						printf("%d - %s",i,hashTable[i].kelime);
						struct Node *nodeTmp = hashTable[i].head;
						while(nodeTmp != NULL)
						{
							printf(" - %s",nodeTmp->dosyaAdi);
							nodeTmp=nodeTmp->next;
						}
						printf("\n");
					//}
				}
			}
			else
			{
				printf("Once inputlari ekleyerek tabloyu doldurunuz.\n");
			}
			printf("\n\nMenuye donmek icin enter tusuna basin");
			getch();
		}
		
		else if(secim==5)//hashTable dizisi içerisindeki verileri 18011706.txt dosyasýna yazar.
		{
			if(loadFactor>0)
			{
				FILE *yaz;
				if(yaz=fopen("18011706.txt","w")){
					fprintf(yaz,"Key Kelime BulunduguDosyalar\n");
					for(i=0;i<M;i++)
					{
						if(hashTable[i].head!=NULL)
						{
							fprintf(yaz,"%d %s",i+1,hashTable[i].kelime);
							struct Node *nodeTmp = hashTable[i].head;
							while(nodeTmp != NULL)
							{
								fprintf(yaz," %s",nodeTmp->dosyaAdi);
								nodeTmp=nodeTmp->next;
							}
							fprintf(yaz,"\n");
						}
					}
					fclose(yaz);
					printf("Veriler 18011706.txt dosyasina yazildi.");
				}
			}
			else
			{
				printf("Once inputlari ekleyerek tabloyu doldurunuz.\n");
			}
			
			printf("\n\nMenuye donmek icin enter tusuna basin");
			getch();
			
		}
		else if(secim==6)//18011706.txt isimli text dosyasýndaki tüm verileri satýr satýr ekrana yazdýrýr.
		{
			printf("\nHash Tablosu\n");
			satirOku("18011706.txt");
			printf("\n\nMenuye donmek icin enter tusuna basin");
			getch();
		}
	}while(secim!=0);
	free(hashTable);
	printf("\n**Bellek Temizlendi**\n");
	return 0;
}

void kelimeOku(char dosyaAdi[100])
{
	FILE *fp=fopen(dosyaAdi,"r");
	if(fp=fopen(dosyaAdi,"r")){
		char bilgi[1000];
		while(!feof(fp)){
			fscanf(fp,"%s",bilgi);
			strcpy(bilgi,tolower(bilgi));
			int hashParameter = hash(bilgi,horner(bilgi),dosyaAdi);
			printf("%s - %d \n",bilgi,hashParameter);
		}
	}else{
		printf("Aradiginiz dosya yok.");
	}
	
}

void satirOku(char dosyaAdi[100])
{
	FILE *fp = fopen(dosyaAdi, "r");
	if(fp == NULL) {
        perror("Aradiginiz dosya yok. Lutfen once inputlari ekleyiniz. Ardindan menuden 5. secenek ile dosyaya yazdiriniz.\n");
    }
    else
    {
	    char satir[1000];
	    while(fgets(satir, sizeof(satir), fp) != NULL) {
			fputs(satir, stdout);
		}
		fclose(fp);
	}
}

int horner (char kelime[1000])
{
	int i=0,len=0, x =2;
	int sonuc=0;
	len = strlen(kelime);
	while(kelime[i]!='\0')
	{
		sonuc += kelime[i] * getPower(x,i);
		i++;
	}
	return sonuc;
}

int getPower(int number, int power){
	int i,sum = 1;
	for(i = 0; i<power; i++){
		sum *= number;
	}
	return sum;
}

int hash(char kelime[1000],int hornerKey,char dosyaAdi[100]){
	int i= 0,hash = 0;
	do{
		i++;
		hash = (h1(hornerKey) + i*h2(hornerKey)) % M;
	}while((hashTable[hash].head != NULL && strcmp(hashTable[hash].kelime,kelime) != 0));
	if(strcmp(hashTable[hash].kelime,kelime) == 0){
		printf("ortak kelime bulundu\n");
		struct Node *tmp = hashTable[hash].head;
		while(tmp->next != NULL && strcmp(tmp->dosyaAdi,dosyaAdi) != 0){
			tmp = tmp->next;
		}
		if(tmp->next == NULL && strcmp(tmp->dosyaAdi,dosyaAdi) != 0){
			struct Node * node = (struct Node *)calloc(1,sizeof(struct Node));
			tmp->next = node;
			strcpy(tmp->next->dosyaAdi,dosyaAdi);
			printf("Ayni kelime icin yeni dosya adi eklendi\n");
		}
		else
		{
			printf("%s Kelimesi icin dosya zaten eklendi\n",hashTable[hash].kelime);
		}
	}
		
	else if(hashTable[hash].head == NULL){
		if(loadFactor==800)//LoadFactor 0.8e ulaþtýðý zaman kullanýcýya uyarý veriliyor. Eðer kullanýcý devam etmek isterse veriler eklenmeye devam ediyor
		{
			char durum="";
			printf("Doluluk orani 0.8'e ulasti. Devam etmek icin 'd'. progami sonlandirmak icin 'c'\n");
			do
			{
				durum=getchar();
			}while(!(durum=='d' || durum=='c'));
			if(durum=='c')//Eger kullanýcý c girerse program kapatýlýyor.
			{
				exit(1);
			}
		}
		if(loadFactor<=1009)//Tabloda müsait yer varsa veriler eklenmeye devam eder.
		{
			strcpy(hashTable[hash].kelime,kelime);
			struct Node * node = (struct Node *)calloc(1,sizeof(struct Node));
			hashTable[hash].head = node;
			strcpy(node->dosyaAdi,dosyaAdi);
			printf("LoadFactor: %d Eklenen dosya adi: %s\n",loadFactor,dosyaAdi);
			loadFactor++;	
		}
		else//Tablo doluysa veri eklemesi durdurulur ve kullanýcýya uyarý verilir.
		{
			printf("\n\n***Yetersiz bellek boyutu***\n\n");
		}
		
	}
	
	return hash;
}



struct Node * newNode(){
	struct Node * node = (struct Node *)calloc(1,sizeof(struct Node));
	return node;
}

int h1(int key){
	return key % M;
}

int h2(int key){
	return 1 + ( key % MM);
}

int kelimeAra(char kelime[1000],int hornerKey){
	int i= 0,hash = 0;
	do{
		i++;
		hash = (h1(hornerKey) + i*h2(hornerKey)) % M;
	}while((hashTable[hash].head != NULL && strcmp(hashTable[hash].kelime,kelime) != 0));
	printf("%d",hash);
	if(strcmp(hashTable[hash].kelime,kelime) == 0){
		return hash;
		
	}
	else{
		return -1;
	}
	
}

void baslangic(char hashDosyaAdi[])
{
	int sayac=0,sayac2=0;;
	int key;
	char kelime[1000];
	char dosyalar[1000];
	
	FILE *fp = fopen("18011706.txt", "r");
	if(fp == NULL) {
        perror("Baslangicta 18011706.txt bulunamadi. Lutfen once inputlari ekleyiniz. Ardindan menuden 5. secenek ile dosyaya yazdiriniz.\n");
    }
    else
    {
    	printf("18011706.txt isimli dosyadan veriler okunuyor ve hashTable isimli diziye aktariliyor...\n");
    	char satir[1000];
	    while(fgets(satir, sizeof(satir), fp) != NULL) {
			if(sayac>=1)//Kelimeleri ekle
			{
				sscanf(satir,"%d %s\n",&key,kelime);
				strcpy(hashTable[key].kelime,kelime);
				loadFactor++;
				
				int init_size = strlen(satir);
				char delim[] = " \n";
				sayac2=0;
				char *ptr = strtok(satir, delim);
			
				while(ptr != NULL)
				{
					if(sayac2>=2)//Dosya adlarýný ekle
					{
						struct Node * node = (struct Node *)calloc(1,sizeof(struct Node));
						if(hashTable[key].head==NULL)
						{
							hashTable[key].head = node;
							strcpy(node->dosyaAdi,ptr);	
						}
						else
						{
							hashTable[key].head->next=node;
							strcpy(node->dosyaAdi,ptr);	
						}
					}
					ptr = strtok(NULL, delim);
					sayac2++;
				}
			}
			sayac++;
		}
		fclose(fp);
	}
}






