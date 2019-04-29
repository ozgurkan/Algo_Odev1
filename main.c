#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
int  solvable(int  start, int  leapCount[], int n);//fonksiyon ba�lang�� de�erini,diziyi ve uzunlu�unu parametre olarak al�r.
static int markarray[1000];//Dizinin her eleman�na ka� kez gidildi�ini tutmak i�in kullan�ld�.
int rastgele;// random say� tutmak i�in kullan�ld�.
int kontrol=-1;// recursive fonksiyondan d�nen de�eri tutmak i�in kullan�ld�.
int i=0;//D�ng�lerde kullanmak i�in tan�mland�.
int n;// Kullan�c�n�n girece�i dizi uzunlu�u
int *leapCount;//her ta�taki  s��rama say�lar�n�n sakland��� dizi

int main()
{
    srand(time(NULL));
    printf("n degerini giriniz:");
    scanf("%d",&n);
    leapCount = (int*) calloc(n, sizeof(int));
        for(i=0;i<n-1;i++){
            leapCount[i]=1+rand()%(n/2+1);
            printf("%d  ",leapCount[i]);
        }
    printf("%d \n Gecilen yollar=>",leapCount[n-1]);
    kontrol=solvable(0,leapCount,n);//recursive fonksiyon �a��r�ld�.
        if(kontrol==1){
            printf("\n yol bulundu.");
        }else{
            printf("\n yol bulunamadi.");
        }
    return 0;
}

int  solvable(int  start, int  leapCount[], int n) {

    printf("%d",leapCount[start]);//�zerinde oldu�umuz h�cre yazd�r�ld�
    //printf("%d",start); //�zerinde olunan h�crenin indisini yazd�rmak i�in opsiyonel.
    if(markarray[start]<-10){//E�er bir noktaya 10dan fazla gidilirse 0 d�nd�r.
        return 0;
    }else{
        markarray[start]=markarray[start]-1;
    }

    if(start-leapCount[start]<0 && start+leapCount[start]>n-1){//E�er bulunan h�credeki say� ile sa�a ve sola hareket edemezse 0 d�nd�r.
        return 0;
    }

    if(start!=n-1){//e�er hala son elemana ula�amam��sak
        if(start-leapCount[start]<0){//sola gidemez saga git
            start=start+leapCount[start];
            }
        else if(start+leapCount[start]>n-1){//saga gidemez sola git
            start=start-leapCount[start];
            }
        else{//sola ve sa�a yol var random hareket et
            rastgele=rand()%2;
            if(start+leapCount[start]==n-1 || rastgele==1 ){//��k��a ula��yor veya 1 geldiyse saga git
                start=start+leapCount[start];
            }
            else if(rastgele==0){//0 geldiyse sola git
                start=start-leapCount[start];
            }
        }
        return solvable(start,leapCount,n);//recursive fonskiyonu yeni start de�eriyle �a��r
    }
    else{
        return 1;//��k��� buldun 1 de�erini d�nd�r.
    }
}




