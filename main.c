#include <stdio.h>

//--------JOGO DA VELHA---------

int escolhaX()
{
    int posX = 0;
    printf("\n\n\x1b[32mDigite a posicao do [ X ]: ");
    while (scanf("%d", &posX) != 1)
    {
        printf("\n\x1b[31Digite somente numeros\n");
        while (getchar() != '\n')
            ;
        return escolhaX();
    }
    if (posX > 0 && posX < 10)
    {
        return posX;
    }
    else
    {
        printf("\n\x1b[31mDigite somente as posicoes de 1 a 9\n");
        return escolhaX();
    }
}

int escolhaO()
{
    int posO = 0;
    printf("\n\n\x1b[33mDigite a posicao do [ O ]: ");
    while (scanf("%d", &posO) != 1)
    {
        printf("\n\x1b[31mDigite somente numeros\n");
        while (getchar() != '\n')
            ;
        return escolhaO();
    }
    if (posO < 10 && posO > 0)
    {
        return posO;
    }
    else
    {
        printf("\n\x1b[31mDigite somente as posicoes de 1 a 9\n");
        return escolhaO();
    }
}

int coluna(int pos)
{
    if (pos == 1 || pos == 4 || pos == 7)
    {
        int coluna = 0;
        return coluna;
    }
    if (pos == 2 || pos == 5 || pos == 8)
    {
        int coluna = 1;
        return coluna;
    }
    if (pos == 3 || pos == 6 || pos == 9)
    {
        int coluna = 2;
        return coluna;
    }
}

int linha(int pos)
{
    if (pos > 0 && pos < 4)
    {
        int linha = 0;
        return linha;
    }
    if (pos > 3 && pos < 7)
    {
        int linha = 1;
        return linha;
    }
    if (pos > 6 && pos < 10)
    {
        int linha = 2;
        return linha;
    }
}

void img_jogo(char a, char b, char c, char d, char e, char f, char g, char h, char i)
{
    printf("\n\x1b[34m__%c__|__%c__|__%c__", a, b, c);
    printf("\n\x1b[34m__%c__|__%c__|__%c__", d, e, f);
    printf("\n\x1b[34m__%c__|__%c__|__%c__", g, h, i);
    printf("\n\x1b[34m     |     |    \n\n\n");
}

void jogo()
{
    char tabuleiro[3][3] = {{'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'}};
    int X[9], O[9];
    int v = 0;
    int result = 0;
    printf("\n\033[4;37m-----------Jogo da Velha---------\033[0m \n");
    printf("\n\x1b[34m__1__|__2__|__3__");
    printf("\n\x1b[34m__4__|__5__|__6__");
    printf("\n\x1b[34m__7__|__8__|__9__");
    printf("\n\x1b[34m     |     |    \n\n\n");
    for (int i = 0; i < 5; i++)
    {
        if (v == 5)
        {
            printf("\n\n\n\n\033[4;37mDEU VELHA!!!!!! \033[0m [o jogo foi reiniciado]\n\n\n\n");
            jogo();
        }
        X[i] = escolhaX();
        int L = linha(X[i]);
        int C = coluna(X[i]);
        if (X[i] != O[i] && tabuleiro[L][C] == '_')
        {
            tabuleiro[L][C] = 'X';
        }
        else
        {
            printf("\n\x1b[31mA posicao que voce deseja jogar ja esta ocupada, tente novamente!\n");
            return jogo();
        }
        img_jogo(tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2], tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2], tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
        for (int x = 0; x < 3; x++)
        {
            if (tabuleiro[x][0] == 'X' && tabuleiro[x][1] == 'X' && tabuleiro[x][2] == 'X')
            {
                result = 1;
            }
            else if (tabuleiro[0][x] == 'X' && tabuleiro[1][x] == 'X' && tabuleiro[2][x] == 'X')
            {
                result = 1;
            }
            else if ((tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X') || (tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X'))
            {
                result = 1;
            }
        }
        if (result == 1)
        {
            printf("\n\n\n\n\n\n\033[1;35m||||||||||||---------!!! O [X] venceu o jogo !!!---------||||||||||||\n\n\n\n\n\n");
            return jogo();
        }
        O[i] = escolhaO();
        int Lo = linha(O[i]);
        int Co = coluna(O[i]);
        if (O[i] != X[i] && tabuleiro[Lo][Co] == '_')
        {
            tabuleiro[Lo][Co] = 'O';
        }
        else
        {
            printf("\n\033[1;36mA posicao que voce deseja jogar ja esta ocupada, tente novamente!\n");
            return jogo();
        }
        img_jogo(tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2], tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2], tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
        for(int y = 0; y < 3; y++)
        {
            if (tabuleiro[y][0] == 'O' && tabuleiro[y][1] == 'O' && tabuleiro[y][2] == 'O')
            {
                result = 2;
            }
            else if (tabuleiro[0][y] == 'O' && tabuleiro[1][y] == 'O' && tabuleiro[2][y] == 'O')
            {
                result = 2;
            }
            else if (tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O' || tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O')
            {
                result = 2;
            }
        }
        if (result == 2)
        {
            printf("\n\n\n\n\n\n\033[1;35m||||||||||||---------!!! Bolinha [O] venceu o jogo !!!---------||||||||||||\n\n\n\n\n\n");
            return jogo();
        }
        v++;
    }
}

int main()
{
    jogo();
    return 0;
}

// By: Mikael Shumacher
// Version: 1.3
// Date: 10/11/2023
