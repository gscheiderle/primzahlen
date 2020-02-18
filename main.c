#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUF 16384


int main()  {

    int max;         // Obergrenze, bis zu der Primzahlen gesucht werden

    int i = 0;
    int counter= 0;
    // int zaehler=0;

    int *value;

    int ii=0;
    int j=0;

    char *zeile;

    static int k;    // Devisor

    char meth;
    int auswahl;


    printf("\n\n  BIS ZU WELCHER OBERGRENZE SOLLEN\n  PRIMZAHLEN GESUCHT WERDEN.\n\n  Geben Sie die Zahl ein: \n\n  ");scanf("%d,%s",&max, &meth);

    printf("\n\n\n");



    printf("   Wie soll die Ausgabe erfolgen:\n");
    printf("\n");
    printf("   Auf der Console   ( 1 )\n");
    printf("   In eine Datei     ( 2 )\n");
    printf("   Beides            ( 3 )\n");
    printf("   Nur Zeit messen   ( 4 )\n\n");
    printf("   Treffen Sie Ihre Wahl:\n");


    printf("\n  -- ");scanf("%d",&auswahl);
    printf("\n");


    // Array deklarieren und initialisieren

    int array[max];

    array[0]=2; // erste Primzahl ist 2

    int max_2 = max/2; // Halbe Anzahl, da nur ungeraden Zahlen in Frage kommen

   // Speicherplatz für das Array reservieren
   // Halbe Anzahl der Obergrenze, da nur ungerade Zahlen gespeichert werden

   value = malloc(max*sizeof(int));

   if( NULL == value ) {
      printf("Fehler bei malloc....\n");

      return EXIT_FAILURE;
      }

    // Array mit ungeraden Zahlen gewäß Obergrenze befüllen

    for ( i = 3, ii = 1; ii < max_2; i+=2, ii++ ) {

            array[ii] = i;

            }

/////////////////////////////////////////////////////////////////////////////////////////////////////

       // Die Vielfachen von Prim 3, 5 und 7 mit 0 markieren
       // Hat sich als vorteilhaft rausgestellt

       for ( i = 4; i < max_2; i++ ) {

            if ( array[i] % 3 == 0 ) {

                 array[i] = 0;
            }

            if ( array[i] % 5 == 0 ) {

                 array[i] = 0;
            }

            if ( array[i] % 7 == 0 ) {

                 array[i] = 0;

            }

       }

/////////////////////////////////////////////////////////////////////////////////////////////////////



    for ( i = 4 ; i < max_2; i++ ) {


             k = i;



if ( k < sqrt(max_2) ) {


        for ( ii = k; ii < max_2; ii++ ) {


           if ( array[ii] > array[i] && array[i] > 0 ) {


              if ( array[ii] % array[i] == 0 ) { // nicht prim, mit 0 markieren

                   array[ii] = 0;

                }
            }
        }
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////


    FILE *fp;
    fp=fopen("primzahlen.csv","w");

    if( fp != NULL ) {


        for ( j = 0; j < max_2; j++ ) {

        if (array[j] > 0 ) { // Primzahlen ausgeben

            counter++;

        if (counter == 10 ) { zeile = "\n"; counter = 0; } // Zeilenumbruch


            if ( auswahl == 1 ) {

                printf("%6d %s", array[j], zeile );       // Ausgabe auf der Konsole

                zeile = " ";
            }

            if ( auswahl == 2 ) {
                fprintf(fp, "%6d, %s", array[j], zeile );  // Ausgabe in Datei

                zeile = " ";
            }


            if ( auswahl == 3 ) {
                fprintf(fp, "%6d, %s", array[j], zeile );  // Ausgabe in Datei
                printf("%6d %s", array[j], zeile );       // Ausgabe auf der Konsole

                zeile = " ";
            }


            if ( auswahl == 4 ) {

            }

            // Bei Bedarf prüfen, ob alles prim ist
            for ( i = 3; i < max_2; i+=2 ) {

                if ( array[j] % i == 0 && array[j] > i ) {

                printf("array[%d] ist nicht prim ( %3d )\n", array[j], i);

            }
        }
    }
 }

            if ( auswahl == 2 || auswahl == 3 ) {

                printf("\n\n  Die Datei \"primzahlen.csv\" liegt in dem Verzeichnis,\n  in welches die \"Sieb_des_Eratosthenes.exe\" kopiert wurde.\n  Die Datei ist evtl. anzulegen");
            }

    }


    if ( auswahl != 4 ) {

    printf("\n\n");

    printf("beenden mit \"0\": ");scanf("%s",&meth);

    if ( meth == 0 ) {

    EXIT_SUCCESS;

    }
    }

    if ( auswahl == 4 ) {

       EXIT_SUCCESS;

    }

}



