#include <stdlib.h>
#include <stdio.h>
#include <string.h>



typedef struct agenda{ //Typedef serve para definir um nome para simplificar, e o nome é definido no final, nesse está contato
    char nome[30]; 
    char numero[12]; //11 = 47 99999 9999 sem os espaços
}contato;



//Prototipos das funções
void addContato(void);
void pesquisarContato(void); 
void excluirContato(void);   


int main(void){
    //variaveis
    char opcao;

    do {
        printf("---------------------------------------\n");
        printf("       AGENDA DE CONTATOS - MENU   \n\n");
        printf("[a] Criar Contato \n");
        printf("[b] Pesquisar Contato \n");
        printf("[c] Excluir Contato \n");
        printf("[d] Fechar Agenda\n\n");
        printf("Digite a sua opcao: ");
        scanf("%c",&opcao);
        fflush(stdin);

        switch(opcao) {
            case 'a':
                addContato();
                break;
            case 'b':
                pesquisarContato();
                break;
            case 'c':
                excluirContato();
                break;
            case 'd':
                break;
        }
    } while (opcao != 'd');

    printf("\nSaindo...\n");

    return 0;
}


//Funções

void addContato(void){
    
    contato AddContato; //Define estrutura "Nome" e "Numero", usado la no struct
    FILE *contatos; //Declarar variavel "contatos"

    contatos = fopen("contatos.txt","a");
       
	if (contatos == NULL) {
        printf("Erro ao abrir arquivo.\n");
		return;
    }

    printf("Digite o nome do contato: ");
    fgets(AddContato.nome, 30, stdin); //variavel, tamanho maximo, tipo da entrada
    fflush(stdin);

    printf("Digite o numero do telefone: ");
    fgets(AddContato.numero, 12, stdin);
    fflush(stdin);

    fprintf(contatos, "%s%s\n", AddContato.nome, AddContato.numero); //Não precisa do \n para dar um "enter" porque o gets pega o espaço do enter quando a gente escreve
	
    fclose(contatos);
    printf("\nContato adicionado\n");
    fflush(stdin);
}

void pesquisarContato(void) {


}

void excluirContato(void) {

    char NomeExcluir[30];
    FILE *excluirContato, *Auxiliar;
    contato c;

    excluirContato = fopen("contatos.txt", "r");     //Abrir arquivo original para leitura
    if (excluirContato == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

	
    Auxiliar = fopen("temp.txt", "w");    //Abrir arquivo temporario
    if (Auxiliar == NULL) {
        printf("Erro ao abrir arquivo temporario.\n");
        fclose(excluirContato);
        return;
    }


    printf("Digite o nome do contato a ser excluido: ");
    scanf("%29s", NomeExcluir);


   
    while (fscanf(excluirContato, "%s %s\n", c.nome, c.numero) == 2) {  //Verifica os contatos já salvos e salva no arquivo temporario, exceto o que será excluído.
        if (strcmp(c.nome, NomeExcluir) != 0) {
            fprintf(Auxiliar, "%s\t%s\n", c.nome, c.numero);
        }
    }

    fclose(excluirContato);
    fclose(Auxiliar);
    
	remove("contatos.txt");  // Remover o arquivo original e renomear o arquivo temporário para o original
    rename("temp.txt", "contatos.txt");
    printf("Contato excluido com sucesso.\n");
    fflush(stdin);
}