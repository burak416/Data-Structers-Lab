#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct student{
	
	int age;
	int number;
	char name[40];
	struct student *next;
};

//Ogrenci bilgilerinin girilebilmesi için yer ayirma islemi.
struct student *newStudent(int number, char name[], int age) {
    struct student *newstudent = (struct student*)malloc(sizeof(struct student));
    newstudent->number=number;
    strcpy(newstudent->name, name);
    newstudent->age=age;
    newstudent->next = NULL;
    return newstudent;
	}
//Yeni ogrenci bilgisi girisi.	
void addStudent(struct student** head, int number, char name[], int age) {
    struct student* newstudent = newStudent(number, name, age);
    if (*head == NULL) {
        *head = newstudent;
    } else {
        struct student* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newstudent;
    }
}
//Girilen isimden sonraki deðeri silmek icin mevcut degeri next->next e bagliyor ardindan temp e atanmis silinecek degeri free ile siliyor.
void deleteNextStudent(struct student* head, char* name) {
    struct student* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->next != NULL) {
                struct student* temp = current->next;
                current->next = current->next->next;
                free(temp);
            }
        }
        current = current->next;
    }
}


void printStudents(struct student* head) {
    struct student* current = head;
    int i=1;
    while (current != NULL) {
        printf("%d.Ogrenci Isim: %s,No: %d, Yas: %d\n", i, current->name, current->number, current->age);
        current = current->next;
        i++;
    }
}

//Strcmp ile string ifadeler ayni mi farkli mi sorgulama.
struct student *arama(struct student* head, char name[]) {
    struct student* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current; 
        }
        current = current->next;
    }
    return NULL; 
}

//Listede dolasarak isimleri kiyasliyor.
struct student *enUzunIsimliOgrenci(struct student* head) {
    struct student* current = head;
    struct student* ogrenci = NULL;

    while (current != NULL) {
        if (ogrenci == NULL || strlen(current->name) > strlen(ogrenci->name)) {
            ogrenci = current;
        }
        current = current->next;
    }
    return ogrenci;
}


struct list {
    int data;
    struct list* next;
};

void addfront(struct list** bas, int x) {
    struct list* temp = (struct list*)malloc(sizeof(struct list));
    temp->data = x;
    temp->next = *bas;
    *bas = temp;
}

struct Node{
	
	int data;
	struct Node *next;
	
};

void InsertNode(struct Node **head2,int value){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=value;
	newNode->next=NULL;
	
	
	if (*head2==NULL){
		*head2=newNode;
	}
	else if (newNode->data%2!=0){
		struct Node *current = newNode;
		current->data=value;
		current->next=*head2;
		*head2=current;
	}
	else {
		struct Node *current = *head2;
		
		while (current->next != NULL){
			current=current->next;
		}
		current->next=newNode;
	}
}

int main(){
	int i = 0, k;
    srand(time(NULL));
	int secim,value;
	struct student* head = NULL;

    addStudent(&head, 120, "Burak", 22);
    addStudent(&head, 234, "Omer", 21);
    addStudent(&head, 345, "Eren", 25);
    addStudent(&head, 654, "Hakan", 23);
    addStudent(&head, 297, "Sude", 27);
    addStudent(&head, 427, "Abdullah", 20);
    
	printf("Klavyeden -1 girilinceye kadar, girilen tum tek sayilari listenin basina, cift sayilari ise listenin sonuna ekleyen fonksiyon icin-1\n\n");
	printf("Listeye rastgele uretilerek eklenen 100 sayiyi buyukten kucuge siralamak icin-2\n\n");
	printf("Ogrenci verilerinin ciktisi icin-3\n\n");	
	printf("Ogrenci kaydi aramak icin-4\n\n");
	printf("Listede aranan ogrencinin yer aldigi dugumden sonraki dugumu silmek icin-5\n\n");		
	printf("En uzun isme sahip ogrencinin kaydini yazdirmak icin-6 \n\n");	
	printf("Yapmak istediginiz islemi secin(1-6):");
	scanf("%d",&secim);
	
	char Name[40];
	struct list* bas = NULL;
	struct student* ogrenci = enUzunIsimliOgrenci(head);
	struct Node* head2 = NULL;

	switch(secim){
		case 1:
			printf("Lutfen sayilari giriniz(bitirmek icin -1):\n");
			while(1){
				scanf("%d",&value);
				if (value==-1){
				break;
				}	
			InsertNode(&head2,value);
			}	
	
			struct Node *current =head2;
	
			while (current!=NULL){
				printf("%d->",current->data);
				current=current->next;
			}
		break;
		case 2:
			while (i < 101) {
        	int rastgeleSayi = rand() % 1000;
        	k = rastgeleSayi;
        	if (bas== NULL) { //Basta bos olan listeye ilk eleman atamasi.
            	bas = (struct list*)malloc(sizeof(struct list));
            	bas->data = k;
            	bas->next = NULL;
        		}
        		else {
            		if (k < bas->data) {
                	addfront(&bas, k);
            		}
            		else {
                		struct list *current = bas;
                		while (current->next != NULL && k > current->next->data) {
                    		current = current->next;
                		}
                	addfront(&(current->next), k);
            		}
        		}
        		i++;
    		}
	
    		struct list* currentNode = bas;
    		while (currentNode != NULL) {
       			printf("%d-> ", currentNode->data);
        		currentNode = currentNode->next;
    		}
    		break;
		case 3:
			printStudents(head);
			break;
		case 4:	
    		printf("Aranacak ogrencinin adini girin: ");
    		scanf("%s", Name);
    		struct student *ogrenciArama = arama(head, Name);
    		if (ogrenciArama != NULL) {
        		printf("Ogrenci bulundu: Isim: %s, Ogrenci No: %d, Yas: %d\n", ogrenciArama->name, ogrenciArama->number, ogrenciArama->age);
    		} else {
        		printf("Ogrenci bulunamadi.\n");
    		}
    		break;
    	case 5:
    		printf("Aranacak ogrencinin adini girin: ");
    		scanf("%s", Name);
    		deleteNextStudent(head, Name);
    		printf("Sonraki dugum silindi.\n");
    		printStudents(head);
    		break;    		
    	case 6:
    		if (ogrenci != NULL) {
        	printf("En uzun isme sahip ogrenci: %s\n",ogrenci->name);
               printf("Ismin uzunlugu:%d",strlen(ogrenci->name));
    		} else {
        		printf("Ogrenci bulunamadi.\n");
    		}
    		break;
		}
    return 0;
}
