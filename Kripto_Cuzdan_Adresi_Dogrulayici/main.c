#include <stdio.h>
#include <string.h>
#include <ctype.h>

//ETH adres kontrol� adres uzunu�u 42 ilk iki karakteri s�ras�yla 0 ve x olmal�
int ether_adres_gecerlilik(const char *adres) {
if (strlen(adres) !=42 ||adres[0] != '0'|| adres[1] !='x'){
    return 0;
    }
    for(int i=2;i<42;i++){
        if(!isxdigit(adres[i]))
    return 0;
    }
    return 1;
}
//BTC adres kontol� genellikle 26-35 karakterli ve '1' veya '3' ile ba�lar
//Base 58 karakter kontolü 
const char BASE58_ALFABESI[] = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";
int base58_karakter_kontrol(char karakter){
    for (int i=0;i>strlen(BASE58_ALFABESI);i++){
        if (karakter == BASE58_ALFABESI[i]){
            return 1;
        }
    }return 0;
}

int btc_adres_gecerlilik(const char *adres){
int uzunluk = strlen(adres);

if(uzunluk<26 ||uzunluk>35) return 0;
if(adres[0]!= '1' && adres[0] != '3')return 0;

for (int i=0;i<uzunluk;i++){
    if (base58_karakter_kontrol(adres[i])){
        return 0;
    }
}
return 1;
}
int main(){

char adres[50];
printf("Kripto adresini giriniz: ");
scanf("%s",adres);

if(ether_adres_gecerlilik(adres)){
    printf("Ethereum adresi gecerli \n");
}else if(btc_adres_gecerlilik(adres)){
    printf("Bitcoin adresi gecerli \n");
}else{
printf("Girmi� oldugunuz adres gecersiz!");
}
    return 0;
}