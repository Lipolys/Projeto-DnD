#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define TAM 50

struct Personagens
{
    char NomePersonagem [TAM], NomeJogador [TAM], NomeClasse [TAM], MagiasConhecidas [TAM]; 
    int QuantMagias, QuantTruques, QuantGrimorio;
    int Forca, Destreza, Constituicao, Inteligencia, Sabedoria, Carisma;
    int ModForca, ModDestreza, ModConstituicao, ModInteligencia, ModSabedoria, ModCarisma;
    int Nivel; // Nivel do personagem de 1 a 3
    int Classe;
    // 1 - Bárbaro
    // 2 - Bardo
    // 3 - Bruxo
    // 4 - Clérigo
    // 5 - Druida
    // 6 - Feiticeiro
    // 7 - Guerreiro
    // 8 - Ladino
    // 9 - Mago
    // 10 - Monge
    // 11 - Paladino
    // 12 - Patrulheiro
};

int MenuPrincipal (int Valor) //Menu principal, responsável por selecionar criação ou exclusão, além da interface
{
    do
    {
        printf ("//====================================//\n");
        printf ("//GERENCIADOR DE PERSONAGENS DE DND 5E//\n");
        printf ("//====================================//\n");
        printf ("\n\n\n\n");
        printf ("//====================//   //======================//\n");
        printf ("//1 - CRIAR PERSONAGEM//   //2 - EXCLUIR PERSONAGEM//\n");
        printf ("//====================//   //======================//\n");
        printf ("Opção desejada: ");
        scanf ("%i", &Valor);
        system ("cls");
    }
    while (Valor != 1 && Valor != 2); //Verifica se o valor digitado é válido
    return Valor;
}

void MenuNomePersonagem (int I, Personagens *Personagem) //Menu responsável por receber o nome do personagem, além da interface
{
    char NomePersonagem [TAM];
    printf ("//=============================\n");
    printf ("//Digite o nome do personagem: ");
    fflush (stdin);
    gets (NomePersonagem);
    strcpy (Personagem[I].NomePersonagem, NomePersonagem); //Copia o nome digitado para a struct
    system ("cls");
}

void MenuNomeJogador (int I, Personagens *Personagem) //Menu responsável por receber o nome do jogador, além da interface
{
    char NomeJogador [TAM];
    printf ("//==========================\n");
    printf ("//Digite o nome do jogador: ");
    fflush (stdin);
    gets (NomeJogador);
    strcpy (Personagem[I].NomeJogador, NomeJogador); //Copia o nome digitado para a struct
    system ("cls");
}

void MenuNivel (int I, Personagens *Personagem) //Menu responsável por receber o nivel do personagem, além da interface
{
    int Nivel;
    do
    {
        printf ("//=============================//\n");
        printf ("Digite o nivel do personagem: ");
        scanf ("%i", &Nivel);
        system ("cls");
    }
    while (Nivel < 1 || Nivel > 3); //Verifica se o valor digitado é válido
    Personagem[I].Nivel = Nivel; //Copia o valor digitado para a struct
}

void MenuClasse (int I, Personagens *Personagem) //Menu responsável por receber a classe do personagem, além da interface
{
    int Classe;
    do
    {
        printf ("//====================//\n");
        printf ("//1 - Bárbaro         //\n");
        printf ("//2 - Bardo           //\n");
        printf ("//3 - Bruxo           //\n");
        printf ("//4 - Clérigo         //\n");
        printf ("//5 - Druida          //\n");
        printf ("//6 - Feiticeiro      //\n");
        printf ("//7 - Guerreiro       //\n");
        printf ("//8 - Ladino          //\n");
        printf ("//9 - Mago            //\n");
        printf ("//10 - Monge          //\n");
        printf ("//11 - Paladino       //\n");
        printf ("//12 - Patrulheiro    //\n");
        printf ("//====================//\n");
        printf ("Opção desejada: ");
        scanf ("%i", &Classe);
        system ("cls");
    }
    while (Classe < 1 || Classe > 12); //Verifica se o valor digitado é válido
    Personagem[I].Classe = Classe; //Copia o valor digitado para a struct
}

void MenuAtributosComprados (int I, Personagens *Personagem)
{
    int Forca, Destreza, Constituicao, Inteligencia, Sabedoria, Carisma;
    int ModForca, ModDestreza, ModConstituicao, ModInteligencia, ModSabedoria, ModCarisma;
    do
    {
        printf ("//===============================//\n");
        printf ("//Digite os valores dos atributos//\n");
        printf ("//===============================//\n");
        printf ("Força: ");
        scanf ("%i", &Forca);
        printf ("Destreza: ");
        scanf ("%i", &Destreza);
        printf ("Constituição: ");
        scanf ("%i", &Constituicao);
        printf ("Inteligência: ");
        scanf ("%i", &Inteligencia);
        printf ("Sabedoria: ");
        scanf ("%i", &Sabedoria);
        printf ("Carisma: ");
        scanf ("%i", &Carisma);
        system ("cls");
    }
    while (Forca < 3 || Forca > 18 || Destreza < 3 || Destreza > 18 || Constituicao < 3 || Constituicao > 18 || Inteligencia < 3 || Inteligencia > 18 || Sabedoria < 3 || Sabedoria > 18 || Carisma < 3 || Carisma > 18); //Verifica se os valores digitados são válidos
    Personagem[I].Forca = Forca; //Copia os valores digitados para a struct
    Personagem[I].Destreza = Destreza;
    Personagem[I].Constituicao = Constituicao;
    Personagem[I].Inteligencia = Inteligencia;
    Personagem[I].Sabedoria = Sabedoria;
    Personagem[I].Carisma = Carisma;
    ModForca = (Forca - 10) / 2; //Calcula os modificadores dos atributos
    ModDestreza = (Destreza - 10) / 2;
    ModConstituicao = (Constituicao - 10) / 2;
    ModInteligencia = (Inteligencia - 10) / 2;
    ModSabedoria = (Sabedoria - 10) / 2;
    ModCarisma = (Carisma - 10) / 2;
}

void RolagemDados (int *Total)
   {
    int I = 0, J = 0, MenorDado[6], Dado[6][4];
    srand (time(NULL));
    for (I = 0; I < 6; I++)
    {
        for (J = 0; J < 4; J++)
        {
            Dado[I][J] = (rand () % 6 + 1);
            Total[I] = MenorDado [I] = 0;
        }
	}
    for (I = 0; I < 6; I++)
    {
        MenorDado[I] = 6;
        for (J = 0; J < 4; J++)
        {
            if (Dado[I][J] < MenorDado[I])
            {
                MenorDado[I] = Dado[I][J];
            }
            Total[I] += Dado[I][J];
        }
    }
    for (I = 0; I < 6; I++)
    {
        Total[I] -= MenorDado[I];
    }
   }

void AtributosAleatorios(int I, int *Atributos, Personagens *Personagem)
{
    int Forca, Destreza, Constituicao, Inteligencia, Sabedoria, Carisma;
    int ModForca, ModDestreza, ModConstituicao, ModInteligencia, ModSabedoria, ModCarisma;

    Forca = Atributos[0];
    Personagem[I].Forca = Forca;
    ModForca = (Forca - 10) / 2;
    Personagem[I].ModForca = ModForca;

    Destreza = Atributos[1];
    Personagem[I].Destreza = Destreza;
    ModDestreza = (Destreza - 10) / 2;
    Personagem[I].ModDestreza = ModDestreza;

    Constituicao = Atributos[2];
    Personagem[I].Constituicao = Constituicao;
    ModConstituicao = (Constituicao - 10) / 2;
    Personagem[I].ModConstituicao = ModConstituicao;

    Inteligencia =  Atributos[3];
    Personagem[I].Inteligencia = Inteligencia;
    ModInteligencia = (Inteligencia - 10) / 2;
    Personagem[I].ModInteligencia = ModInteligencia;

    Sabedoria = Atributos[4];
    Personagem[I].Sabedoria = Sabedoria;
    ModSabedoria = (Sabedoria - 10) / 2;
    Personagem[I].ModSabedoria = ModSabedoria;

    Carisma = Atributos[5];
    Personagem[I].Carisma = Carisma;
    ModCarisma = (Carisma - 10) / 2;
    Personagem[I].ModCarisma = ModCarisma;
}

void ListaMagias (int I, Personagens *Personagem) // IMPLEMENTAR
{
    int QuantMagias, QuantTruques, QuantGrimorio;
    switch (Personagem[I].Classe)
    {
        case 1:
            QuantMagias = 0;
            QuantTruques = 0;
            strcpy (Personagem[I].NomeClasse, "Bárbaro");
            break;
        case 2:
            QuantMagias = 4;
            QuantTruques = 2;
            strcpy (Personagem[I].NomeClasse, "Bardo");
            break;
        case 3:
            QuantMagias = 2;
            QuantTruques = 3;
            strcpy (Personagem[I].NomeClasse, "Bruxo");
            break;
        case 4:
            QuantMagias = Personagem[I].Nivel + Personagem[I].ModSabedoria;
            QuantTruques = 2;
            strcpy (Personagem[I].NomeClasse, "Clérigo");
            break;
        case 5:
            QuantMagias = Personagem[I].Nivel + Personagem[I].ModSabedoria;
            QuantTruques = 2;
            strcpy (Personagem[I].NomeClasse, "Druida");
            break;
        case 6:
            QuantMagias = 3;
            QuantTruques = 3;
            strcpy (Personagem[I].NomeClasse, "Feiticeiro");
            break;
        case 7:
            QuantMagias = 0;
            QuantTruques = 0;
            strcpy (Personagem[I].NomeClasse, "Guerreiro");
            break;
        case 8:
            QuantMagias = 0;
            QuantTruques = 0;
            strcpy (Personagem[I].NomeClasse, "Ladino");
            break;
        case 9:
            QuantGrimorio = 6;
            QuantMagias = Personagem[I].Nivel + Personagem[I].ModInteligencia;
            QuantTruques = 3;
            strcpy (Personagem[I].NomeClasse, "Mago");
            break;
        case 10:
            QuantMagias = 0;
            QuantTruques = 0;
            strcpy (Personagem[I].NomeClasse, "Monge");
            break;
        case 11:
            QuantMagias = 0;
            QuantTruques = 0;
            strcpy (Personagem[I].NomeClasse, "Paladino");
            break;
        case 12:
            QuantMagias = 0;
            QuantTruques = 0;
            strcpy (Personagem[I].NomeClasse, "Patrulheiro");
            break;
    }
    Personagem[I].QuantGrimorio = QuantGrimorio;
    Personagem[I].QuantMagias = QuantMagias;
    Personagem[I].QuantTruques = QuantTruques;
}

void MenuEscolhaMagias (int I, int Aux, Personagens *Personagem) // IMPLEMENTAR
{
    char NomeArquivo [TAM], NomeMagia [TAM], NomeClasse [TAM], Caracter;
    char NumeroMagia [1] = {'1'};
    int J = 0;
    FILE *ArquivoMagias;
    if (Personagem[I].QuantMagias != 0)
    {
    	system ("cls");
        printf ("//================================================//\n");
        printf ("// VOCÊ PODE ESCOLHER DENTRE AS SEGUINTES MAGIAS: //\n");
        printf ("//================================================//\n");
        do
        {
        	NumeroMagia [1] = {'\0'};
            strcpy (NomeArquivo, Personagem[I].NomeClasse);
            strcat (NomeArquivo, NumeroMagia);
            strcat (NomeArquivo, ".txt");
            ArquivoMagias = fopen (NomeArquivo, "r");
            if (ArquivoMagias != NULL)
            {
				if (fgets (NomeMagia, TAM, ArquivoMagias) != NULL)
                {
                    printf ("%s -- ", NumeroMagia);
                    printf ("%s", NomeMagia);
                }
                fclose (ArquivoMagias);
                NumeroMagia[0]++;
            }
        } while (ArquivoMagias != NULL);
        printf ("Você já escolheu %i magias, faltam %i.\n\n", Aux, Personagem[I].QuantMagias - Aux);
        printf ("Insira o número da magia que deseja escolher para visualizar sua descrição: ");
        fflush (stdin);
        gets (NumeroMagia);
        strcpy (NomeArquivo, Personagem[I].NomeClasse);
        strcat (NomeArquivo, NumeroMagia);
        strcat (NomeArquivo, ".txt");
        ArquivoMagias = fopen (NomeArquivo, "r");
        if (ArquivoMagias != NULL)
        {
        	system ("cls");
            while (fscanf (ArquivoMagias, "%c", &Caracter) != EOF)
            {
                printf ("%c", Caracter);
            }
            fclose (ArquivoMagias);
            printf ("\n\n\n");
            printf ("//=================================//\n");
            printf ("//DESEJA ESCOLHER ESSA MAGIA? (S/N)//\n");
            printf ("//=================================//\n");
            scanf ("%c", &Caracter);
            if (strchr(Personagem[I].MagiasConhecidas, Caracter) != NULL && Caracter == 'S' || Caracter == 's')
            {
                Caracter = NomeMagia [0];
                Personagem[I].MagiasConhecidas[J] = Caracter;
                J++;
            }
        }
    }
    else
    {
        printf ("Nenhuma magia disponível para a classe %s.\n", Personagem[I].NomeClasse);
    }
    system ("pause");
    system ("cls");
}

void ExibirPersonagem (int I, Personagens *Personagem)
{
    int J = 0;
    printf ("Nome do Personagem: %s\n", Personagem[I].NomePersonagem);
    printf ("Nome do Jogador: %s\n", Personagem[I].NomeJogador);
    printf ("Nível: %i\n", Personagem[I].Nivel);
    printf ("Classe: %s\n", Personagem[I].NomeClasse);
    printf ("Força: %i\n", Personagem[I].Forca);
    printf ("Destreza: %i\n", Personagem[I].Destreza);
    printf ("Constituição: %i\n", Personagem[I].Constituicao);
    printf ("Inteligência: %i\n", Personagem[I].Inteligencia);
    printf ("Sabedoria: %i\n", Personagem[I].Sabedoria);
    printf ("Carisma: %i\n", Personagem[I].Carisma);
    system ("pause");
}

void RegistrarPersonagem (int I, Personagens *Personagem)
{
    char NomeArquivo [TAM];
    FILE *ArquivoPersonagem;
    strcpy (NomeArquivo, Personagem[I].NomePersonagem);
    strcat (NomeArquivo, ".txt");
    ArquivoPersonagem = fopen (NomeArquivo, "w");
    if (ArquivoPersonagem != NULL)
    {
        fprintf (ArquivoPersonagem, "Nome do Personagem: %s\n", Personagem[I].NomePersonagem);
        fprintf (ArquivoPersonagem, "Nome do Jogador: %s\n", Personagem[I].NomeJogador);
        fprintf (ArquivoPersonagem, "Nível: %i\n", Personagem[I].Nivel);
        fprintf (ArquivoPersonagem, "Classe: %s\n", Personagem[I].NomeClasse);
        fprintf (ArquivoPersonagem, "Força: %i\n", Personagem[I].Forca);
        fprintf (ArquivoPersonagem, "Destreza: %i\n", Personagem[I].Destreza);
        fprintf (ArquivoPersonagem, "Constituição: %i\n", Personagem[I].Constituicao);
        fprintf (ArquivoPersonagem, "Inteligência: %i\n", Personagem[I].Inteligencia);
        fprintf (ArquivoPersonagem, "Sabedoria: %i\n", Personagem[I].Sabedoria);
        fprintf (ArquivoPersonagem, "Carisma: %i\n", Personagem[I].Carisma);
        fprintf (ArquivoPersonagem, "Magias Conhecidas: %s\n", Personagem[I].MagiasConhecidas);
        fclose (ArquivoPersonagem);
    }
}

int main ()
{
    setlocale (LC_ALL, "portuguese");
    srand(time(NULL));
    Personagens Personagem[TAM];
    int I = 0, J = 0, K = 0;
    int OpcaoMenuPrincipal = 0, OpcaoMenuAtributos = 0;
    int Atributos[6];
    char NomeArquivo[TAM];
	printf ("%c", 57);
    OpcaoMenuPrincipal = MenuPrincipal (OpcaoMenuPrincipal);
    if (OpcaoMenuPrincipal == 1)
    {
        MenuNomePersonagem (I, Personagem);
        MenuNomeJogador (I, Personagem);
        MenuNivel (I, Personagem);
        MenuClasse (I, Personagem);
        if (Personagem[I].Nivel > 1)
        {
            MenuAtributosComprados (I, Personagem);
        }
        else
        {
        	RolagemDados (Atributos);
            AtributosAleatorios (I, Atributos, Personagem);
        }
		ListaMagias (I, Personagem);
		do
        {
            MenuEscolhaMagias (I, J, Personagem);
            J++;
        } while (J < Personagem[I].QuantMagias);
        ExibirPersonagem (I, Personagem);
        RegistrarPersonagem (I, Personagem);
    }
    return 0;
}
