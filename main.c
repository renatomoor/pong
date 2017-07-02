#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>


#define V 21
#define H 75


void inicio (char campo[V][H], int pelX,int pelY, int inijug, int finjug, int iniia, int finia);
void borde (char campo[V][H]);
void raqjug (char campo [V][H], int inijug, int finjug);
void raqia (char campo[V][H], int iniia, int finia);
void pelota (char campo[V][H], int pelX, int pelY);
void leercamp (char campo[V][H]);
void gameloop (char campo[V][H], int pelX,int pelY, int inijug, int finjug, int iniia, int finia, int modX, int modY, int modia);
void draw (char campo[V][H], int* goljug, int* golia);
void input (char campo[V][H], int *pelX, int* pelY, int* inijug, int* finjug, int* iniia, int* finia, int* modX, int* modY, int* modia, int* goljug, int* golia);
void update (char campo[V][H], int pelX,int pelY, int inijug, int finjug, int iniia, int finia);
void hidecursor();
int numeroAleatoreo();
void titilante();



int main(){
    srand(time(NULL));
    int pelX, pelY, inijug, finjug, iniia, finia; // Variables Posicion
    int modX, modY, modia;//Modificacion
    char campo [V][H];

    hidecursor();
    //posicion
    pelX = 37;
    pelY = 10;

    inijug = 6;
    finjug = 12;

    iniia = 6;
    finia = 12;

    //Modificacion

    modX = -1;
    modY = -1;


    inicio(campo,pelX,pelY,inijug,finjug,iniia,finia);
    //system("pause");
    gameloop(campo,pelX,pelY,inijug,finjug,iniia,finia,modX,modY,modia);
    system("pause");
    return 0;
}

void inicio (char campo[V][H], int pelX,int pelY, int inijug, int finjug, int iniia, int finia){
    hidecursor();
    borde (campo);
    raqjug(campo, inijug, finjug);
    raqia (campo, iniia, finia);
    pelota(campo, pelX, pelY);
    leercamp(campo);
}

void borde (char campo[V][H]){

    int i, j;
    for (i = 0; i < V ; i++){
        for( j = 0; j <= H; j++)

            if (i == 0 || i == V-1){
                campo[i][j] = '.';
            }
            else if (j == 0 || j == H){
                campo[i][j] = '.';
            }
            else if (j== 37){
                campo[i][j] = '|';
            }
            else{
                campo[i][j] = ' ';
            }
    }
}
void raqjug (char campo [V][H], int inijug, int finjug){
    int i, j;

    for (i = inijug; i <= finjug; i++){
        for (j = 2; j <=3; j++){
            campo[i][j] = 'K';
        }
    }
}

void raqia (char campo[V][H], int iniia, int finia){

    int i, j;
    for (i = iniia; i <= finia; i++){
        for (j = H-4; j <=H-3; j++){
            campo[i][j] = 'R';
        }
    }
}
void pelota (char campo[V][H], int pelX, int pelY){
    campo[pelY][pelX]='O';
}

void leercamp (char campo[V][H]){
    int i, j;
    for (i = 0; i < V; i++){
        for (j = 0; j <= H; j++){
            printf("%c", campo[i][j]);
        }
        printf("\n");
    }

}

void gameloop (char campo[V][H], int pelX,int pelY, int inijug, int finjug, int iniia, int finia, int modX, int modY, int modia){

    int goljug, golia;
    goljug = 0;
    golia = 0;

    titilante();

    do{
        draw (campo, goljug, golia);//dibujar en pantalla
        input(campo ,&pelX, &pelY, &inijug, &finjug, &iniia, &finia, &modX, &modY, &modia, &goljug, &golia);//verificar y modifical la posicion
        update(campo, pelX, pelY, inijug, finjug, iniia, finia);//actualiza la matriz campo
        //Sleep (1);
    }while(goljug <= 3 || golia <= 3);
}

void draw (char campo[V][H], int* goljug, int* golia){
    system("cls");
    hidecursor();
    contador(goljug, golia);
    leercamp(campo);

}

void input (char campo[V][H], int *pelX, int* pelY, int* inijug, int* finjug, int* iniia, int* finia, int* modX, int* modY, int* modia, int* goljug, int* golia){
    int i;
    char key;

    /////////////verificacion////////////////
    if (*pelY == 1 || *pelY == V-2){
        *modY *= -1;

    }
    if (*pelX == 1){
        *golia += 1;
        *pelX = 37;
        *pelY = 10;
        printf("              Presiona ENTER 2 veces para seguir la partida\n");
        getchar();
        getchar();

    }
    if (*pelX == H-2){
        *goljug += 1;
        *pelX = 37;
        *pelY = 10;
        printf("             Presiona ENTER 2 veces para seguir la partida\n");
        getchar();
        getchar();

    }
    if (*pelX == 37 && *pelY == 10){

        *modX *= numeroAleatoreo();
        *modY *= numeroAleatoreo();
    }

    if (*pelX == 37){ // Barra del centro que cambia direccion de la pelota
        //*modX *= numeroAleatoreo();


        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);
        *pelX +=  (*modX);


    }


    if (*pelX == 4){
        for (i = (*inijug); i < (*finjug); i++){
            if (i == *pelY){
                *modX *= -1;
            }
        }

    }

    if (*pelX == H-4){
        for (i = (*iniia); i < (*finia); i++){
            if (i == (*pelY)){
                *modX *= -1;
            }
        }
    }

    ///////////modificacion//////////////
    if (*goljug < 3 && *golia  < 3){

        //PELOTA:
        *pelX +=  (*modX);
        *pelY +=  (*modY);

    }
    if (*goljug == 3 || *golia  == 3){

            if (*goljug == 3){
                printf("*****************El jugador 1 ha ganado la partida****************\n\n");
                printf("*****************El jugador 1 ha ganado la partida****************\n\n");
                printf("*****************El jugador 1 ha ganado la partida****************\n\n");
                printf("                Presiona ENTER 3 veces para jugar una nueva partida\n");
                getchar();
                getchar();
                getchar();
                main();

            }
            if (*golia == 3){
                printf("****************El jugador 2 ha gando la partida*****************\n\n");
                printf("****************El jugador 2 ha gando la partida*****************\n\n");
                printf("****************El jugador 2 ha gando la partida*****************\n\n");
                printf("                Presiona ENTER 3 veces para jugar una nueva partida\n");
                getchar();
                getchar();
                getchar();
                main();
            }

            }
        //Raqueta del Jugador

        if (kbhit()== 1){

            key = getch() ;// lo mismo que scanf solo que no hay que pulsar la tecla intro

            if (key == 'w'){
                if (*inijug != 1){
                    *inijug -= 1;
                    *finjug -= 1;
                }
            }

            if (key == 'x'){
                if(*finjug != V-2){
                    *inijug += 1;
                    *finjug += 1;
                }
            }
            if (key == '8'){
                if (*iniia != 1){
                    *iniia -= 1;
                    *finia -= 1;
                }
        }

        if (key == '2'){
            if(*finia != V-2){
                *iniia += 1;
                *finia += 1;
            }
        }


        }
    }




void update (char campo[V][H], int pelX,int pelY, int inijug, int finjug, int iniia, int finia){
    borde (campo);
    raqjug(campo, inijug, finjug);
    raqia (campo, iniia, finia);
    pelota(campo, pelX, pelY);

}

void contador (int goljug, int golia){
    printf("Jugador 1 --------------------- |%d|  :  |%d| -----------------------Jugador 2\n", goljug, golia);
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int numeroAleatoreo(){
    int myArray[2] = {-1,1};
    int randomIndex = rand() % 2;
    int randomValue = myArray[randomIndex];
    return randomValue;
}


void titilante(){

    int i = 0, x;



    while (i == 0){
        int key, x;

        if (kbhit()== 1){
        key = getch();


        if (key == getch()){

            printf("\r                                                                      ");
            printf("\r El juego comienza en :  \n");
            printf("\r 3 ");
            Sleep(500);
            printf("\r 2 ");
            Sleep(500);
            printf("\r 1 ");
            Sleep(500);
            i = 1;
            }

        }
        else{
            printf("\r             Presiona una tecla 2 veces para comenzar el juego !!!!");
            Sleep(500);
            printf("\r                                                                   ");
            Sleep(300);
        }





            }


    }







