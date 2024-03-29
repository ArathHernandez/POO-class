/*Programa creado para jugar loteria mediante el programa C++
 Creado por Erbey Arath Hernandez Villarreal (A00825343) y Jamir Leal Cota (A00826275)
 Creado el 04 de Noviembre del 2018*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int ManGanar=0;

// FUNCION PARA REVISAR EL N�MERO QUE SE GRIT�

void revisarNUM(int arrF[], int n, int &v, int &x, int y, int &z, int &m) // FUNCION PARA REVISAR EL N�MERO QUE SE GRIT�
{
    if(n>54||n<=0) //VALIDAR EL NUMERO INGRESADO
    {
        m=2;
    }
    else{
        y=z+1;
        for(int i=0; i<v; i++)
        {
            if(n!=arrF[i])
            {
                y--;
            }
        }
        if(y==0)
        {
            arrF[x]=n;
            x++;
            m=1;
        }
    }}

void revisarTABLA(int matriz[][4], int n) // FUNCION HECHA PARA REVISAR SI EL NUMERO QUE SE TECLE� APARECE EN LA TABLA
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(n==matriz[i][j]) // SI APARECE EN LA TABLA SE MARCA CON UN 0
            {
                matriz[i][j]=0;
            }
        }
    }
    cout<<endl;
    cout<<"TU TABLA ES"<<endl; // DESPLEGAR LA TABLA CON LAS MODIFICACIONES
    cout<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
// FUNCION PARA CUANDO EL USUARIO  ESCOGE LA OPCION UNO QUE ES LA LINEA VERTICAL

void vertical(int matriz[][4], int &x, int matrizAux[][4], int arr[])
{
    int a0=4; int a1=4; int a2=4; int a3=4;
    for(int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if(j==0&&matriz[i][j]==0)
            {
                a0--;
            }
            else if(j==1&&matriz[i][j]==0)
            {
                a1--;
            }
            else if(j==2&&matriz[i][j]==0)
            {
                a2--;
            }
            else if(j==3&&matriz[i][j]==0)
            {
                a3--;
            }
        }
    }
    if(a0==0||a1==0||a2==0||a3==0)
    {
        x=1;
        if(a0==0)
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(j==0){
                        arr[i]=matrizAux[i][j];}
                }
            }
        }
        else if(a1==0)
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(j==1){
                        arr[i]=matrizAux[i][j];}
                }
            }
        }
        else if(a2==0)
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(j==2){
                        arr[i]=matrizAux[i][j];}
                }
            }
        }
        else if(a3==0)
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(j==3){
                        arr[i]=matrizAux[i][j];}
                }
            }
        }
    }
}

// FUNCION PARA CUANDO EL USUARIO  ESCOGE LA OPCION DOS QUE ES LA LINEA HORIZONTAL

void horizontal(int matriz[][4], int &x, int matrizAux[][4], int arr[])
{
    int a0=4; int a1=4; int a2=4; int a3=4;
    for(int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            if(i==0&&matriz[i][j]==0)
            {
                a0--;
            }
            else if(i==1&&matriz[i][j]==0)
            {
                a1--;
            }
            else if(i==2&&matriz[i][j]==0)
            {
                a2--;
            }
            else if(i==3&&matriz[i][j]==0)
            {
                a3--;
            }
        }
    }
    if(a0==0||a1==0||a2==0||a3==0)
    {
        x=1;
        if(a0==0)
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(i==0){
                        arr[j]=matrizAux[i][j];}
                }
            }
        }
        else if(a1==0)
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(i==1){
                        arr[j]=matrizAux[i][j];}
                }
            }
        }
        else if(a2==0)
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(i==2){
                        arr[j]=matrizAux[i][j];}
                }
            }
        }
        else if(a3==0)
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(i==3){
                        arr[j]=matrizAux[i][j];}
                }
            }
        }
    }
}

// FUNCION PARA CUANDO EL USUARIO  ESCOGE LA OPCION TRES QUE ES LA LINEA DIAGONAL

void diagonal(int matriz[][4], int &x, int matrizAux[][4], int arr[])
{
    int a0=4; int a1=4;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(i==j&&matriz[i][j]==0)
            {
                a0--;
            }
            else if((i==0&&j==3&&matriz[i][j]==0)||(i==1&&j==2&&matriz[i][j]==0)||(i==2&&j==1&&matriz[i][j]==0)||(i==3&&j==0&&matriz[i][j]==0))
            {
                a1--;
            }
        }
    }
    if(a0==0||a1==0)
    {
        x=1;
        int p=0;
        if(a0==0)
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if(i==j)
                    {
                        arr[p]=matrizAux[i][j];
                    }
                }
                p++;
            }
        }
        else if(a1==0)
        {
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {
                    if((i==0&&j==3)||(i==1&&j==2)||(i==2&&j==1)||(i==3&&j==0))
                    {
                        arr[p]=matrizAux[i][j];
                    }
                }
                p++;
            }
        }
    }
}

// FUNCION PARA CUANDO EL USUARIO  ESCOGE LA OPCION CUATRO QUE SON LAS CUATRO ESQUINAS DE LA TABLA

void cuatroesq(int matriz[][4], int &x, int matrizAux[][4], int arr[])
{
    int a0=4;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if((i==0&&j==0&&matriz[i][j]==0)||(i==0&&j==3&&matriz[i][j]==0)||(i==3&&j==0&&matriz[i][j]==0)||(i==3&&j==3&&matriz[i][j]==0))
            {
                a0--;
            }
        }
    }
    if(a0==0)
    {
        x=1;
        int p=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if((i==0&&j==0)||(i==0&&j==3)||(i==3&&j==0)||(i==3&&j==3))
                {
                    arr[p]=matrizAux[i][j];
                    p++;
                }
            }
        }
    }
}

// FUNCION PARA CUANDO EL USUARIO  ESCOGE LA OPCION CINCO QUE POCITO CUADRO INTERIOR

void pocito(int matriz[][4], int &x, int matrizAux[][4], int arr[])
{
    int a0=4;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if((i==1&&j==1&&matriz[i][j]==0)||(i==2&&j==1&&matriz[i][j]==0)||(i==1&&j==2&&matriz[i][j]==0)||(i==2&&j==2&&matriz[i][j]==0))
            {
                a0--;
            }
        }
    }
    if(a0==0)
    {
        x=1;
        int p=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if((i==1&&j==1)||(i==2&&j==1)||(i==1&&j==2)||(i==2&&j==2))
                {
                    arr[p]=matrizAux[i][j];
                    p++;
                }
            }
        }
    }
}

// FUNCION PARA CUANDO EL USUARIO  ESCOGE LA OPCION SEIS QUE ES EL CUADRO EXTERIOR

void cuadroext(int matriz[][4], int &x, int matrizAux[][4], int arr[])
{
    int a0=12;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if((i==0&&matriz[i][j]==0)||(j==0&&matriz[i][j]==0)||(i==3&&matriz[i][j]==0)||(j==3&&matriz[i][j]==0))
            {
                a0--;
            }
        }
    }
    if(a0==0)
    {
        x=1;
        int p=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if((i==0)||(j==0)||(i==3)||(j==3))
                {
                    arr[p]=matrizAux[i][j];
                    p++;
                }
            }
        }
    }
}

// ESTA FUNCION ELIMINA LOS NUMEROS QUE ESTAN DUPLICADOS EN EL ARRAY

void eliminardup(int arrA[], int &x)
{
    int a;
    int c=0;
    int arrB[12];
    for(int b=0; b<x; b++)
    {
        arrB[b]=0;
    }
    for(int i=0; i<x; i++)
    {
        a=x;
        for(int j=0; j<x; j++)
        {
            if(arrB[j]!=arrA[i])
            {
                a--;
            }
        }
        if(a==0)
        {
            arrB[c]=arrA[i];
            c++;
        }
    }
    for(int i=0; i<c; i++)
    {
        arrA[i]=arrB[i];
    }
    x=c;
}

void mostrarOpciones(){ // FUNCION PARA MOSTRAR EN PANTALLA EL TABLERO

do{
        if(ManGanar<1||ManGanar>6){
    cout<<"BIENVENIDO A LA LOTERIA TEC"<<endl;
    cout<<endl;
    cout<<"Selecciona la opcion para ganar"<<endl;
    cout<<"1) Vertical"<<endl;
    cout<<"2) Horizontal"<<endl;
    cout<<"3) Diagonal" <<endl;
    cout<<"4) Cuatro esquinas"<<endl;
    cout<<"5) Pocito"<<endl;
    cout<<"6) Cuadro exterior"<<endl;
    cout<<endl;

    cin>>ManGanar;
    cout<<endl;

    if (ManGanar<1||ManGanar>6)
    {
       cout<< "NO ES UNA OPCION, ELIGE UNA CORRECTA PORFAVOR" << endl;
       cout<<endl;
    }}} while(ManGanar<1||ManGanar>6);
    return;
}

int main()
{
    int cMatTablero[4][4], matrizAux[4][4]; // DECLARACION DE MATRICES
    int iR, iC, iCont; // DECLARACION DE CONTADORES
    int Carta;
    int a=0, b=1, c=0, d=1, e=0, f;
    int arrSalida[54]; // ARRAY DE TODOS LOS NUMEROS QUE SE VAN MENCIONANDO
    int arrNumGanadores[12]; // ARRAY DE NUMEROS GANADORES QUE INCIA EN 12
    int tamGan; // TAMA�O DEL ARRAY QUE SE DESPLEGAR�

    mostrarOpciones(); // MOSTRAMOS EL TABLERO

    for(int i=0; i<54; i++)
    {
        arrSalida[i]=0;
    }

    //inicializa tablero
    for (iR = 0; iR < 4; iR++)
        for (iC = 0; iC < 4; iC++)
            cMatTablero[iR][iC] = 1;

    srand((int)time(0));
    for (iCont = 1; iCont <= 15; )
    {
        iR = rand() % 4; // esto genera un numero aleatorio
        iC = rand() % 4; // entre 0 y 3 para la posici�n
        if (cMatTablero[iR][iC] == 1)
        {
            cMatTablero[iR][iC] = rand() % 53+1;
            iCont++;
        }
    }

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            matrizAux[i][j]=cMatTablero[i][j]; // GUARDAMOS LOS DATOS DE LA MATRIZ EN OTRA MATRIZ AUXILIAR
        }
    }

    cout<<"TU TABLA ES"<<endl; // DESPLEGAMOS EL TABLERO
    cout<<endl;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout<<cMatTablero[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    do
    {
        if(a!=1)
        {
            cout<<"Teclea la carta que gritaron: ";
            f=0;
            cin>>Carta;
            revisarNUM(arrSalida, Carta, b, c, d, e, f);
            if(f==2) //EN CASO DE QUE NUESTRO NUMERO NO SE ENCUENTRE EN EL RANGO
            {
                cout<<endl;
                cout<<"NUMERO INVALIDO"<<endl;
                cout<<endl;
            }
            else if(f==0){ // EN CASO DE QUE NUESTRO NUMERO YA ESTE REPETIDO EN EL ARRAY
                cout<<endl;
                cout<<"NUMERO REPETIDO"<<endl;
                cout<<endl;}
            else if(f==1){
                b++;
                e++;
                revisarTABLA(cMatTablero, Carta);
                switch(ManGanar){ // ESTE SWITCH TIENE LOS 6 CASOS QUE PODRIA TECLEAR EL USUARIO AL PRINCIPIO
                    case 1:
                        vertical(cMatTablero, a, matrizAux, arrNumGanadores); // FUNCION PARA VERTICAL
                        break;
                    case 2:
                        horizontal(cMatTablero, a, matrizAux, arrNumGanadores); // FUNCION PARA HORIZONTAL
                        break;
                    case 3:
                        diagonal(cMatTablero, a, matrizAux, arrNumGanadores); // FUNCION PARA DIAGONAL
                        break;
                    case 4:
                        cuatroesq(cMatTablero, a, matrizAux, arrNumGanadores); // FUNCION PARA CUATRO ESQUINAS
                        break;
                    case 5:
                        pocito(cMatTablero, a, matrizAux, arrNumGanadores); // FUNCION PARA EL CUADRO DEL CENTRO
                        break;
                    case 6:
                        cuadroext(cMatTablero, a, matrizAux, arrNumGanadores); // FUNCION PARA EL CUADRO EXTERIOR
                        break;
                        cout << endl;
                }
            }}} while(a!=1);

    if(ManGanar==1||ManGanar==2||ManGanar==3||ManGanar==4||ManGanar==5) // EN CASO DE QUE ESCOGIMOS LAS PRIMERAS 5 OPCIONES
    {
        tamGan=4; // EL ARRAY MIDE 4
    }
    else
    {
        tamGan=12; // ELARRAY MIDE 12
    }
    eliminardup(arrNumGanadores, tamGan); // ESTA FUNCION ELIMINA LOS NUMEROS QUE ESTAN DUPLICADOS DEL ARRAY

    cout<<"�LOTERIA!"<<endl;
    cout<<endl;
    cout<<"GANASTE CON LOS SIGUIENTES NUMEROS: ";
    if(ManGanar==1||ManGanar==2||ManGanar==3||ManGanar==4||ManGanar==5)
    {
        for(int i=0; i<tamGan; i++)
        {
            cout<<arrNumGanadores[i]<<" "; // DESPLEGAMOS LOS NUMEROS CON LOS QUE GANAMOS
        }
        cout<<endl;
    }
    else
    {
        for(int i=0; i<tamGan; i++)
        {
            cout<<arrNumGanadores[i]<<" "; // DESPLEGAMOS LOS NUMEROS GANADORES EN CASO DE QUE SEA EL CUADR EXTERIOR
        }
        cout<<endl;
    }

    return 0;
}
