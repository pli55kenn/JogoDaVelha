#ifndef OLDLADYGAME_H_INCLUDED
#define OLDLADYGAME_H_INCLUDED

using namespace std;
bool verificaDiagonalP(char mat[3][3], int l, int c) //Verifica linha principal
{
    int vdO = 0 ; // verifica diagonal O
    int vdX = 0 ; // verifica diagonal X

    for(l=0; l<3; l++) //Percorre as linhas
    {
        for(c=0; c<3; c++) //Percorre as colunas
        {
            if ((l==c) && (mat[l][c] == 'O'))
            {
                vdO++; //Encrementa a verifica��o
            }
            if ((l==c) && (mat[l][c] == 'X'))
            {
                vdX++; //Encrementa a verifica��o
            }
        }
    }
    if (vdO == 3)
    {
        cout<< "Jogador 1 (O) ganhou";
        return true;
    }
    else if (vdX == 3)
    {
        cout<< "Jogador 2 (X) ganhou";
        return true;
    }
    else
    {
        return false;
    }
}

bool verificaDiagonalS(char mat[3][3], int l, int c) //Mesmo esquema da verifica��o anterior s� que para Diagonal secund�ria
{
    int vdO = 0 ; // verifica diagonal O
    int vdX = 0 ; // verifica diagonal X

    for(l=0; l<3; l++)
    {
        for (c=0; c<3; c++)
        {
            if ((l+c)==2 && (mat[l][c]=='O'))
            {
                vdO++;
            }
            if ((l+c)==2 && (mat[l][c]=='X'))
            {
                vdX++;
            }
        }
    }

    if (vdO == 3)
    {
        cout<< "Jogador 1 (O) ganhou";
        return true;
    }
    else if (vdX == 3)
    {
        cout<< "Jogador 2 (X) ganhou";
        return true;
    }
    else
    {
        return false;
    }
}

bool verificaLinhas(char mat[3][3], int l, int c) // verifica as linhas com a mesma l�gica de score
{
    int vdO, vdX;
    for(l=0; l<3; l++)
    {
        vdO = 0 ; // verifica diagonal O
        vdX = 0 ; // verifica diagonal X
        for(c=0; c<3; c++)
        {
            if (mat[l][c] == 'O')
            {
                vdO++;
            }
            if (mat[l][c] == 'X')
            {
                vdX++;
            }
        }
        if (vdO == 3)
        {
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


bool verificaColunas(char mat[3][3], int l, int c) //Verifica coluna com a mesma l�gica
{
    int vdO, vdX;
    for(c=0; c<3; c++)
    {
        vdO = 0 ; // verifica diagonal O
        vdX = 0 ; // verifica diagonal X
        for(l=0; l<3; l++)
        {
            if (mat[l][c] == 'O')
            {
                vdO++;
            }
            if (mat[l][c] == 'X')
            {
                vdX++;
            }
        }
        if (vdO == 3)
        {
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

bool error(char mat[3][3],int l, int c) //Verifica��o de erro quando o usu�rio digita valor inv�lido
{
    if (l<0 || l>2 || c<0 || c>2)
    {
        cout<<"Posicao inv�lida, digite uma posicao v�lida.\n";
        return true;
    }
    if (mat[l][c]== 'O' || mat[l][c]=='X'){
        cout<<"Posi��o ocupada, digite uma posi��o v�lida.\n";
    return true;
    }

return false;
}

bool ganhou (char mat[3][3], int l, int c)
{
    if (verificaDiagonalP(mat, l, c)) // se ganha na diagonal principal
    {
        return true;
    }
    if (verificaDiagonalS(mat, l, c)) //se ganha na diagonal secundaria
    {
        return true;
    }
    if (verificaColunas(mat, l, c)) //se ganha na coluna
    {
        return true;
    }
    if (verificaLinhas(mat, l, c)) //se ganha na linha
    {
        return true;
    }
    return false;
}


#endif // OLDLADYGAME_H_INCLUDED
