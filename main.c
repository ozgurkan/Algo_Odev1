#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
int  solvable(int  start, int  leapCount[], int n);//fonksiyon baþlangýç deðerini,diziyi ve uzunluðunu parametre olarak alýr.
static int markarray[1000];//Dizinin her elemanýna kaç kez gidildiðini tutmak için kullanýldý.
int rastgele;// random sayý tutmak için kullanýldý.
int kontrol=-1;// recursive fonksiyondan dönen deðeri tutmak için kullanýldý.
int i=0;//Döngülerde kullanmak için tanýmlandý.
int n;// Kullanýcýnýn gireceði dizi uzunluðu
int *leapCount;//her taþtaki  sýçrama sayýlarýnýn saklandýðý dizi

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
    kontrol=solvable(0,leapCount,n);//recursive fonksiyon çaðýrýldý.
        if(kontrol==1){
            printf("\n yol bulundu.");
        }else{
            printf("\n yol bulunamadi.");
        }
    return 0;
}

int  solvable(int  start, int  leapCount[], int n) {

    printf("%d",leapCount[start]);//üzerinde olduðumuz hücre yazdýrýldý
    //printf("%d",start); //üzerinde olunan hücrenin indisini yazdýrmak için opsiyonel.
    if(markarray[start]<-10){//Eðer bir noktaya 10dan fazla gidilirse 0 döndür.
        return 0;
    }else{
        markarray[start]=markarray[start]-1;
    }

    if(start-leapCount[start]<0 && start+leapCount[start]>n-1){//Eðer bulunan hücredeki sayý ile saða ve sola hareket edemezse 0 döndür.
        return 0;
    }

    if(start!=n-1){//eðer hala son elemana ulaþamamýþsak
        if(start-leapCount[start]<0){//sola gidemez saga git
            start=start+leapCount[start];
            }
        else if(start+leapCount[start]>n-1){//saga gidemez sola git
            start=start-leapCount[start];
            }
        else{//sola ve saða yol var random hareket et
            rastgele=rand()%2;
            if(start+leapCount[start]==n-1 || rastgele==1 ){//çýkýþa ulaþýyor veya 1 geldiyse saga git
                start=start+leapCount[start];
            }
            else if(rastgele==0){//0 geldiyse sola git
                start=start-leapCount[start];
            }
        }
        return solvable(start,leapCount,n);//recursive fonskiyonu yeni start deðeriyle çaðýr
    }
    else{
        return 1;//çýkýþý buldun 1 deðerini döndür.
    }
}




