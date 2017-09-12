#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "OldLadyGame.h"

using namespace std;

//Protótipos de função
void menu();
void OpcoesdeJogo();
void imprimir();
int jogo1();
int jogo2();

void imprimir(char mat[3][3],int l,int c){

            for (int l=0; l<3; l++){
                for (int c=0; c<3; c++){
                cout<<"["<<mat[l][c]<<"]";
            }
            cout<<"\n";
        }
}
void instrucoes(){
    int opcao=0;
    system ("cls");
    cout << "\t\tINSTRUÇÕES:";
    cout << "\n\nOlá! Bem vindo ao Jogo da Velha!" << endl;
    cout << "Regra: Uma jogada para cada jogador." << endl<<endl;
    cout << "Posições:      "<< endl;
    cout << "                    Colunas:" << endl;
    cout << "                0|  0  1  2" << endl;
    cout << "        Linhas: 1|  0  1  2"<< endl;
    cout << "                2|  0  1  2"<< endl;
    cout << "\n\n1.Voltar ao menu principal";
    cout << "\n2.Sair";
    cout << "\n\nO que deseja fazer agora?";
    cin>>opcao;
    switch (opcao){
    case 1:
        system("cls");
        menu();
    }
}
void menu(){
    int opcao=0;

    cout<<"\tJOGO DA VELHA\n";
    cout<<"\n1.JOGAR";
    cout<<"\n2.INSTRUÇÕES";
    cout<<"\n3.SAIR";
    cout<<"\n\nO que deseja fazer?: ";
    cin>>opcao;

    switch(opcao){
    case 1:
        system("cls");
        OpcoesdeJogo();
        break;
    case 2:
        system("cls");
        instrucoes();
        break;
    }
}
void OpcoesdeJogo(){
    int opcao=0;

        cout<<"\tEscolha o modo de jogo:\
            \n\n 1- Player vs Player \
            \n 2- Contra o computador\
            \n\n Digite a opcao desejada: ";
        cin>>opcao;

        if (opcao==1){
            system("cls");
            jogo1();
        }else if(opcao==2){
            system("cls");
            jogo2();
        }else{
            cout<<"Invalido.\n";
        }
}

int jogo1(){ // PVP

    int l, c, tentativa=0;
    char mat[3][3]= {0};
    bool PosicaoInvalida;

    do{
        cout<<"\tJOGO DA VELHA\n\n\n";
        imprimir(mat,l,c);

        cout<<"\nJogador O, escolha uma linha e uma coluna.\n";
        do{
            cin>>l>>c;
            cout<<"\n";
            PosicaoInvalida=error(mat,l,c);
        }while (PosicaoInvalida);

        mat[l][c]='O';
        imprimir(mat,l,c);

        if (ganhou(mat, l, c)){

            return 0;
        }

        cout<<"\nJogador X, escolha uma linha e uma coluna.\n";
        do{
            cin>>l>>c;
            cout<<"\n";
            PosicaoInvalida=error(mat,l,c);
        }while (PosicaoInvalida);

        mat[l][c]= 'X';
        system("cls");

        if (ganhou(mat, l, c)){

            return 1;
        }
        tentativa++;

    }while (tentativa<5);
    if (ganhou(mat, l, c)==false){
         cout<<"Ihhh....Deu Velha!";
    }
}
int jogo2(){ //Player vs PC

    int l, c, tentativa=0;
    char mat[3][3]= {0};
    bool PosicaoInvalida;

    do{
        cout<<"\tJOGO DA VELHA\n\n\n";
        imprimir(mat,l,c);

        cout<<"Jogador O, escolha uma linha e uma coluna.\n";
        do{
            cin>>l>>c;
            cout<<"\n";
            PosicaoInvalida=error(mat,l,c);
        }while (PosicaoInvalida);

        mat[l][c]='O';
        imprimir(mat,l,c);
        system("cls");

        if (ganhou(mat, l, c)){
            cout<<"\nO jogador <0> ganhou";
            return 0;
        }
        do{
            srand (time(NULL)); //Para que as posições escolhidas randomicamente não sejam as mesmas em cada execução
            l= rand()%3;
            c= rand()%3;

        }while (mat[l][c]== 'O' || mat[l][c]=='X');

        mat[l][c]= 'X';

        if (ganhou(mat, l, c)){

            return 0;
        }
        tentativa++;

    }while (tentativa<5);
    if (ganhou(mat, l, c)==false){
        cout<<"Ihhh....Deu Velha!";
    }
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    menu();
}
