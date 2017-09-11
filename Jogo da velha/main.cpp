#include <iostream>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

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
bool verificaDiagonalP(char mat[3][3], int l, int c){ //Verifica a diagonal principal
    int vdO = 0 ; // verifica diagonal O
    int vdX = 0 ; // verifica diagonal X

    for(l=0; l<3; l++){ //Percorre as linhas
        for(c=0; c<3; c++){ //Percorre as colunas
            if ((l==c) && (mat[l][c] == 'O')){
                vdO++; //Encrementa a verificação
                }
            if ((l==c) && (mat[l][c] == 'X')){
                vdX++; //Encrementa a verificação
           }
       }
}
    if (vdO == 3){
        cout<< "Jogador 1 (O) ganhou";
        return true;
    }else if (vdX == 3){
        cout<< "Jogador 2 (X) ganhou";
        return true;
    }else{
        return false;
    }
}
bool verificaDiagonalS(char mat[3][3], int l, int c){ //Mesmo esquema da verificação anterior só que para a Diagonal secundária

    int vdO = 0 ; // verifica diagonal O
    int vdX = 0 ; // verifica diagonal X

    for(l=0; l<3; l++){
        for (c=0; c<3; c++){
            if ((l+c)==2 && (mat[l][c]=='O')){
                vdO++;
            }
            if ((l+c)==2 && (mat[l][c]=='X')){
                vdX++;
            }
        }
    }

    if (vdO == 3){
        cout<< "Jogador 1 (O) ganhou";
        return true;
    }else if (vdX == 3){
        cout<< "Jogador 2 (X) ganhou";
        return true;
    }else{
        return false;
    }
}
bool verificaLinhas(char mat[3][3], int l, int c){ // verifica as linhas com a mesma lógica de score

    int vdO, vdX;
    for(l=0; l<3; l++){
        vdO = 0 ; // verifica diagonal O
        vdX = 0 ; // verifica diagonal X
        for(c=0; c<3; c++){
            if (mat[l][c] == 'O'){
                vdO++;
            }
            if (mat[l][c] == 'X'){
                vdX++;
            }
        }
        if (vdO == 3){
            cout<< "Jogador 1 (O) ganhou";
            return true;
        }
        else if (vdX == 3)
        {
            cout<< "Jogador 2 (X) ganhou";
            return true;
        }
    }
    return false;
}
bool verificaColunas(char mat[3][3], int l, int c){ //Verifica coluna com a mesma lógica

    int vdO, vdX;
    for(c=0; c<3; c++){
        vdO = 0 ; // verifica diagonal O
        vdX = 0 ; // verifica diagonal X
        for(l=0; l<3; l++){
            if (mat[l][c] == 'O'){
                vdO++;
            }
            if (mat[l][c] == 'X'){
                vdX++;
            }
        }
        if (vdO == 3){
            cout<< "Jogador 1 (O) ganhou";
            return true;
        }
        else if (vdX == 3){
            cout<< "Jogador 2 (X) ganhou";
            return true;
        }
    }
    return false;
}
bool error(char mat[3][3],int l, int c){ //Verificação de erro caso o usuário digita valor inválido

    if (l<0 || l>2 || c<0 || c>2){
        cout<<"Posicao inválida, digite uma posicao válida.\n";
        return true;
    }if (mat[l][c]== 'O' || mat[l][c]=='X'){
        cout<<"Posição ocupada, digite uma posição válida.\n";
    return true;
    }
return false;
}
bool ganhou (char mat[3][3], int l, int c){
    if (verificaDiagonalP(mat, l, c)){ // se ganha na diagonal principal
        return true;
    }
    if (verificaDiagonalS(mat, l, c)){ //se ganha na diagonal secundaria
        return true;
    }
    if (verificaColunas(mat, l, c)){ //se ganha na coluna
        return true;
    }
    if (verificaLinhas(mat, l, c)){ //se ganha na linha{
        return true;
    }
    return false;
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
