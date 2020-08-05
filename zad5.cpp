#include <iostream>
#include <stdio.h>
using namespace std;

// Komentarz

void print_binary(int number) {

    unsigned int mask_tmp = 0x80000000;
    bool start = false;

    int count = 0;
    for(unsigned int mask = 0x80000000; mask >= 1; mask = mask >> 1) //Tworzę maskę w postaci 1000 ... 0000, którą co każdą iterację przesuwam o 1 miejsce w prawo, żeby przejrzeć wszystkie bity w liczbie
    {
        if(mask & number) start = true; //W momencie, gdy maska spotka pierwszą jedynkę zmeinną bool ustawiam na true w ten sposób mogę pominąć wiodące zera
        if((mask & number) && start == true) {cout << 1; count++;}//Sprawdzam warunek koniunkcji maski i liczby, ktorą chce zapisac w formie binarnej równocześnie sprawdzając czy zmienna bool ustawiona jest na wartosc true, jeżeli tak zapisuje pierwszą jedynkę bez wiodących zer
        if(!(mask & number) && start == true) {cout << 0; count++;} //
    }
    printf("\nbinary: %d\n",count);
}

int main() {

    int choice;
    cin >> choice;

    switch(choice)
    {
        case 1:
        {
            unsigned int number;
            cin >> number;
            unsigned int mask_tmp = 0x80000000;
            printf("Value of a: Hex: %X, Decimal: %d\n",number,mask_tmp);
            bool start = false; //Tworzę zmienną bool, która pozwala mi pominąć wiodące zera

            int count = 0;
            unsigned int mask = 0x80000000;
            for(mask = 0x80000000; mask >= 1; mask = mask >> 1) //Tworzę maskę w postaci 1000 ... 0000, którą co każdą iterację przesuwam o 1 miejsce w prawo, żeby przejrzeć wszystkie bity w liczbie
            {
                if(mask & number) start = true; //W momencie, gdy maska spotka pierwszą jedynkę zmeinną bool ustawiam na true w ten sposób mogę pominąć wiodące zera
                if((mask & number) && start == true) {cout << 1; count++;}//Sprawdzam warunek koniunkcji maski i liczby, ktorą chce zapisac w formie binarnej równocześnie sprawdzając czy zmienna bool ustawiona jest na wartosc true, jeżeli tak zapisuje pierwszą jedynkę bez wiodących zer
                if(!(mask & number) && start == true) {cout << 0; count++;} //
            }
            printf("\nbits: %d\n",count);
            break;
        }
        case 2:
        {
            /*
             * 1 znalezienie skrajnej jedynki po lewej stronie
             * 2 przesuniecie maski w prawo i sprawdzenie czy jest zero, jak tak przesuwac maske do konca w celu sprawdzenia czy pierwsza jedynka bez wiodących zer nie jest jedyna cyfra w liczbie, jak tak wyswietlic 0
             * 3 przesuniecie maski w prawo i sprawdzenie czy jest jedynka jak tak przesunac maske i sprawdzic czy jest zero
             * nie wiem jak pózniej sprawdzić kiedy występuje skrajna prawa jedynka, myslalme o pętli while, ale nic sensownego nie przyszlo mi do glowy
             * Myslalem jeszcze czy nie sprobowac znalezc skrajnej prawej jedynki z wykorzsytaniem maski 00000...001, a lewej skrajnej jedynki z wykorzsytaniem maski 10000...000
             */

            int number;
            cin >> number;
            print_binary(number);
            bool start = false;
            int counter = 0;

            int min = 31, bit = 31;
            for(unsigned int mask = 0x80000000; mask >= 1; mask = mask >> 1) //Tworzę maskę w postaci 1000 ... 0000, którą co każdą iterację przesuwam o 1 miejsce w prawo, żeby przejrzeć wszystkie bity w liczbie
            {

                if(mask & number)
                    start = true; //W momencie, gdy maska spotka pierwszą jedynkę zmeinną bool ustawiam na true w ten sposób mogę pominąć wiodące zera
                if((mask & number) && start == true) {
                    min = bit;
                }//Sprawdzam warunek koniunkcji maski i liczby, ktorą chce zapisac w formie binarnej równocześnie sprawdzając czy zmienna bool ustawiona jest na wartosc true, jeżeli tak zapisuje pierwszą jedynkę bez wiodących zer
                if(!(mask & number) && start == true) {
                    cout << 0;
                    counter++;
                } //
                bit--;
            }
            counter = counter - min;
            cout<<"\n";
            cout<< counter;
            break;
        }
        case 3:
        {
            /*
             * Tu podobny sposób, korzystam z dwóch masek 100..00 i 000..001
             * sprawdzam koniunkcją po lewej stronie czy jest 1 czy 0 i zapisuje to w zmiennej bitL
             * sprawdzam koniunkcją po prawej stronie czy jest 1 czy 0 i zapisuje to w zmiennej bitR
             * nastepnie porownuje czy bitL i bitR są takie same i jeśli tak to zmienna counter zwiekszam o 1 w przeciwnym wypadku wychodze z petli i przerywam program, poniewaz warunek palindromu nie jest spelniony
             * W ostatnim kroku, jezeli counter bedzie rowny 32 to wszystkie bity sa takie same i liczba jest palindromem w innym wypadku nie jest

             * dobre podejscie, ale chyba wymaga znalezienia skrajnej 1 - patrz przykład 101
             */
            int number, counter = 0, bitL, bitR;
            cin >> number;
            print_binary(number);
            unsigned int mask1 = 0x80000000, mask2 = 1;
            for(mask1 = 0x80000000; mask1 >= 1; mask1 = mask1 >> 1) //Tworzę maskę w postaci 1000 ... 0000, którą co każdą iterację przesuwam o 1 miejsce w prawo, żeby przejrzeć wszystkie bity w liczbie
            {
                if(mask1 & number) break; //W momencie, gdy maska spotka pierwszą jedynkę zmeinną bool ustawiam na true w ten sposób mogę pominąć wiodące zera
            }

            for( ; mask1 > 0; mask1 = mask1 >> 1, mask2 = mask2 << 1)
            {
                if(number & mask1)
                    bitL = 1;
                else
                    bitL = 0;

                if(number & mask2)
                    bitR = 1;
                else
                    bitR = 0;

                if(bitL == bitR)
                    counter++;
                else
                    break;
            }
            if(mask1 == 0) cout<< "1";
            else cout<<"0";
            break;
        }
    }

    return 0;
}
