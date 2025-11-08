#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    char isim[20];
    char soyisim[20];
    char telefon[15];
}kişiler;
void menü();
int telefonekle();
int telefonlistele();
int aramayap(char*);
int main () {
    int seçim=0;
    char *aranacakisim;
    int aramasonucu=0;
    menü();
    printf("\n\n");
    while(seçim!=4)
    {
        printf("Seçiminizi girin: ");
        scanf("%d",&seçim);
        switch(seçim)
        {
            case 1:if(telefonekle()==0)
            {
                printf("Telefon ekleme işlemi başarılı\n");
            }
            else
            {
                printf("Telefon ekleme işlemi başarısız\n");
            }
                break;
            case 2:if(telefonlistele()==0)
            {
                printf("\nTelefon listeleme başarılı\n");
            }
            else
            {
                printf("Telefon listeleme başarısız\n");
            }
                break;
            case 3:printf("Aranacak ismi girin: ");
            scanf("%s",aranacakisim);
            aramasonucu=aramayap(aranacakisim);
            if(aramasonucu==0)
            {
                printf("Aranan kişi bulunamadı\n");
            }
            else
            {
                printf("Aranan isimde %d adet kişi var\n",aramasonucu);
            }
                break;
            case 4: printf("Çıkış yaptınız.Görüşürüz\n");
            return 1;
                break;
            default: printf("Lütfen 1-4 arasında bir sayı girin!!!\n\n");
        }
    }
}
void menü()
{
    printf("****************************\n");
    printf("*                          *\n");
    printf("*                          *\n");
    printf("*   1) Telefon Ekle        *\n");
    printf("*   2) Telefonları Listele *\n");
    printf("*   3) Arama Yap           *\n");
    printf("*   4) Çıkış Yap           *\n");
    printf("*                          *\n");
    printf("*                          *\n");
    printf("****************************\n");
    
}
int telefonekle()
{
    kişiler eklenecekkişi;
    FILE *fptr;
    fptr=fopen("C:\\Users\\melih\\Desktop\\ProgramlamaGiriş Bir İle İlgili Dosyalar\\Dosya İşlemleri\\Rehber.txt","a");
    if(fptr==NULL)
    {
        printf("Dosya açma işlemi başarısız\n");
        return -1;
    }
    printf("İsim girin: ");
    scanf("%s",eklenecekkişi.isim);
    printf("Soyisim girin: ");
    scanf("%s",eklenecekkişi.soyisim);
    printf("Numara girin: ");
    scanf("%s",eklenecekkişi.telefon);
    fprintf(fptr,"\n%s %s %s",eklenecekkişi.isim,eklenecekkişi.soyisim,eklenecekkişi.telefon);
    fclose(fptr);
    return 0;
}
int telefonlistele()
{
    FILE *fptr;
    fptr=fopen("C:\\Users\\melih\\Desktop\\ProgramlamaGiriş Bir İle İlgili Dosyalar\\Dosya İşlemleri\\Rehber.txt","r");
    if(fptr==NULL)
    {
        printf("Dosya açma işlemi başarısız\n");
        return -1;
    }
    while(!feof(fptr))
    {
        printf("%c",getc(fptr));
    }
    fclose(fptr);
    return 0;
}
int aramayap(char* ptr)
{
    kişiler kayıtlıkişiler;
    int sayaç=0;
    FILE *fptr;
    fptr=fopen("C:\\Users\\melih\\Desktop\\ProgramlamaGiriş Bir İle İlgili Dosyalar\\Dosya İşlemleri\\Rehber.txt","r");
    if(fptr==NULL)
    {
        printf("Dosya açma işlemi başarısız\n");
        return -1;
    }
    while(!feof(fptr))
    {
        fscanf(fptr,"%s%s%s",kayıtlıkişiler.isim,kayıtlıkişiler.soyisim,kayıtlıkişiler.telefon);
        if(!strcmp(ptr,kayıtlıkişiler.isim))
        {
            printf("%s ",kayıtlıkişiler.isim);
            printf("%s ",kayıtlıkişiler.soyisim);
            printf("%s \n",kayıtlıkişiler.telefon);
            sayaç++;
        }
    }
    fclose(fptr);
    return sayaç;
}