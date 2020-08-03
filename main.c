#include <stdio.h>
#include <stdlib.h>

// constantes
#define JOGADOR_X 1
#define JOGADOR_O 2
#define JOGO_STATUS_CONTINUA 3
#define JOGO_STATUS_VENCEU_X 4
#define JOGO_STATUS_VENCEU_O 5
#define JOGO_STATUS_VELHOU 0

// matriz responsavel por guardar o jogo
char jogo_da_velha[3][3];

/** indica de qual dos dois jogadores é a vez
    caso seja 1 = a vez é do jogador 1
    caso seja 2 = a vez é do jogador 2
*/
int jogador_atual;
int status_do_jogo;

void iniciar_novo_jogo(char jogo[3][3])
{
    // inicia a matriz com ' ' (espaços vazios)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            jogo[i][j] = ' ';
        }
    }
}

void desenhar_jogo_atual(int jogador_atual, char jogo[3][3])
{
    // preciso realmente explicar essa função??
    system("clear");
    for (int i = 0; i <= 3; i++)
    {
        if (i == 0)
        {
            printf("\t      1  2  3 \n");
            printf("\t      v  v  v \n");
        }
        else if (i == 1)
        {
            printf("\t 1 > [%c][%c][%c]\n", jogo[0][0], jogo[0][1], jogo[0][2]);
        }
        else if (i == 2)
        {
            printf("\t 2 > [%c][%c][%c]\n", jogo[1][0], jogo[1][1], jogo[1][2]);
        }
        else if (i == 3)
        {
            printf("\t 3 > [%c][%c][%c]\n", jogo[2][0], jogo[2][1], jogo[2][2]);
        }
    }

    if (jogador_atual == 1)
    {
        printf("\n -->[ JOGADOR X ]<-- [JOGADOR O]\n\n");
    }
    else
    {
        printf("\n [JOGADOR X] -->[ JOGADOR O ]<--\n\n");
    }
}

void jogar(int jogador_atual, char jogo[3][3])
{
    int pos_x, pos_y;

    do
    {
        printf("POSIÇÃO HORIZONTAL --> ");
        scanf("%d", &pos_x);
        printf("POSIÇÃO VERTICAL   --> ");
        scanf("%d", &pos_y);
        if (jogo[pos_y - 1][pos_x - 1] != ' ')
        {
            printf("POSIÇÃO INVÁLIDA! - JOGUE EM UMA CASA VAZIA\n\n");
        }
    } while (jogo[pos_y - 1][pos_x - 1] != ' ');

    if (jogador_atual == JOGADOR_X)
    {
        jogo[pos_y - 1][pos_x - 1] = 'X';
    }
    else
    {
        jogo[pos_y - 1][pos_x - 1] = 'O';
    }
}

int verificar_status(int jogador_atual, char jogo[3][3])
{
    // verifica e define qual é o jogador atual se é o X ou o O
    char jogador;
    if (jogador_atual == JOGADOR_X)
    {
        jogador = 'X';
    }
    else
    {
        jogador = 'O';
    }

    // verifica na diagonal da casa superior-esquerda ate a casa inferior-direita se o jogador atual ganhou.
    if (jogo[0][0] == jogador && jogo[1][1] == jogador && jogo[2][2] == jogador)
    {
        if (jogador_atual == JOGADOR_X)
        {
            return JOGO_STATUS_VENCEU_X;
        }
        else
        {
            return JOGO_STATUS_VENCEU_O;
        }
    }
    // verifica na diagonal da casa superior-direita ate a casa inferior-esquerda se o jogador atual ganhou.
    else if (jogo[0][2] == jogador && jogo[1][1] == jogador && jogo[2][0] == jogador)
    {
        if (jogador_atual == JOGADOR_X)
        {
            return JOGO_STATUS_VENCEU_X;
        }
        else
        {
            return JOGO_STATUS_VENCEU_O;
        }
    }
    // verifica se algum jogador ganhou nas linhas horizontais
    else if (jogo[0][0] == jogador && jogo[0][1] == jogador && jogo[0][2] == jogador)
    {
        if (jogador_atual == JOGADOR_X)
        {
            return JOGO_STATUS_VENCEU_X;
        }
        else
        {
            return JOGO_STATUS_VENCEU_O;
        }
    }
    else if (jogo[1][0] == jogador && jogo[1][1] == jogador && jogo[1][2] == jogador)
    {
        if (jogador_atual == JOGADOR_X)
        {
            return JOGO_STATUS_VENCEU_X;
        }
        else
        {
            return JOGO_STATUS_VENCEU_O;
        }
    }
    else if (jogo[2][0] == jogador && jogo[2][1] == jogador && jogo[2][2] == jogador)
    {
        if (jogador_atual == JOGADOR_X)
        {
            return JOGO_STATUS_VENCEU_X;
        }
        else
        {
            return JOGO_STATUS_VENCEU_O;
        }
    }
    // verifica se algum jogador ganhou nas colunas verticais
    else if (jogo[0][0] == jogador && jogo[1][0] == jogador && jogo[2][0] == jogador)
    {
        if (jogador_atual == JOGADOR_X)
        {
            return JOGO_STATUS_VENCEU_X;
        }
        else
        {
            return JOGO_STATUS_VENCEU_O;
        }
    }
    else if (jogo[0][1] == jogador && jogo[1][1] == jogador && jogo[2][1] == jogador)
    {
        if (jogador_atual == JOGADOR_X)
        {
            return JOGO_STATUS_VENCEU_X;
        }
        else
        {
            return JOGO_STATUS_VENCEU_O;
        }
    }
    else if (jogo[0][2] == jogador && jogo[1][2] == jogador && jogo[2][2] == jogador)
    {
        if (jogador_atual == JOGADOR_X)
        {
            return JOGO_STATUS_VENCEU_X;
        }
        else
        {
            return JOGO_STATUS_VENCEU_O;
        }
    }
    // cai no else se jogador atual não ganhar de nenhuma forma
    else
    {
        // for com if para verificar se ainda a casas vazias, ou seja se ainda ha jogadas disponiveis
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (jogo[i][j] == ' ')
                {
                    return JOGO_STATUS_CONTINUA;
                }
            }
        }
        return JOGO_STATUS_VELHOU;
    }
}

int proximo_jogador(int jogador_atual)
{
    // apenas atualiza o jogador atual
    if (jogador_atual == 1)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int escolher_X_ou_O(void)
{
    // preciso explicar??
    int op;

    system("clear");
    printf("---------------------------------------\n");
    printf("-------------JOGO-DA-VELHA-------------\n");
    printf("---------------------------------------\n\n");

    do
    {
        printf("\tCOMEÇAR COM:\n");
        printf("\t[1] - X\n");
        printf("\t[2] - O\n");
        printf("\n\t--> ");
        scanf("%d", &op);
        if (op != JOGADOR_X && op != JOGADOR_O)
        {
            printf("\n\tOPÇÃO INVÁLIDA!\n\n");
        }
    } while (op != JOGADOR_X && op != JOGADOR_O);

    return op;
}

int menu(void)
{
    int op;
    printf("---------------------------------------\n");
    printf("-------------JOGO-DA-VELHA-------------\n");
    printf("---------------------------------------\n\n");

    do
    {
        printf("\t[1] - NOVO JOGO\n");
        printf("\t[2] - COMO JOGAR\n");
        printf("\t[3] - CREDITOS\n");
        printf("\n\t[4] - SAIR\n");
        printf("\n\t--> ");
        scanf("%d", &op);
        if (op < 1 || op > 4)
        {
            printf("\n\tOPÇÃO INVÁLIDA!\n\n");
        }
    } while (op < 1 || op > 4);

    return op;
}

int main(void)
{
    switch (menu())
    {
    case 1:
        // inicia novo jogo
        iniciar_novo_jogo(jogo_da_velha);
        // escolher começar começar com X ou O
        jogador_atual = escolher_X_ou_O();
        // desenha jogo atual
        desenhar_jogo_atual(jogador_atual, jogo_da_velha);

        // loop principal do jogo, equanto alguem não vencer ou velhar
        do
        {
            // jogador atual joga
            jogar(jogador_atual, jogo_da_velha);

            // verifica status do jogo, se o ultimo jogador a jogar venceu ou não ou se ainda ha jogadas disponiveis
            status_do_jogo = verificar_status(jogador_atual, jogo_da_velha);

            if (status_do_jogo == JOGO_STATUS_CONTINUA)
            {
                jogador_atual = proximo_jogador(jogador_atual);
                desenhar_jogo_atual(jogador_atual, jogo_da_velha);
            }
            else if (status_do_jogo == JOGO_STATUS_VENCEU_X)
            {
                desenhar_jogo_atual(jogador_atual, jogo_da_velha);
                printf("\nJOGADOR X VENCEU!!\n\n");
                main();
            }
            else if (status_do_jogo == JOGO_STATUS_VENCEU_O)
            {
                desenhar_jogo_atual(jogador_atual, jogo_da_velha);
                printf("\nJOGADOR O VENCEU!!\n\n");
                main();
            }
            else if (status_do_jogo == JOGO_STATUS_VELHOU)
            {
                desenhar_jogo_atual(jogador_atual, jogo_da_velha);
                printf("\nJOGO VELHOU!!\n\n");
                main();
            }
        } while (1);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        // sair
        exit(1);
        break;
    default:
        break;
    }
}