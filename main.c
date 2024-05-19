#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  char titulo[50];
  char autor[50];
  char editora[50];
  int ano;
  char assunto[100];
} livraria;

main(){
  int novotamanho, tamanho, escolha, x, cont, cont2, remover, busca;
  char frase[255];
  livraria *livros, *aux;
  system("clear");
  printf("Digite o número iniciais de livros: ");
  scanf("%i", &tamanho);
  getchar();
  livros = malloc(tamanho*sizeof(livraria));
  for(x = 0; x < tamanho; x++){
    printf("\nDigite o título do livro: ");
    gets(livros[x].titulo);
    printf("Digite o(a) autor(a) do livro: ");
    gets(livros[x].autor);
    printf("Digite a editora do livro: ");
    gets(livros[x].editora);
    printf("Digite o ano de lançamento: ");
    scanf("%d", &livros[x].ano);
    getchar();
    printf("Digite o assunto do livro: ");
    gets(livros[x].assunto);
  }
  system("clear");
  do{
    printf("Escolha uma opção\n[0] - Registrar livro\n[1] - Remover livro\n[2] - Mostrar livros\n[3] - Buscar livro específico\n[4] - Alterar dados\n[5] - Sair do programa\n");
    scanf("%i", &escolha);
    getchar();
    switch(escolha){
      case 0:
        novotamanho = tamanho + 1;
        livros = realloc(livros, novotamanho*sizeof(livraria));
        system("clear");
        printf("Digite o título do livro: ");
        gets(livros[tamanho].titulo);
        printf("Digite o(a) autor(a) do livro: ");
        gets(livros[tamanho].autor);
        printf("Digite a editora do livro: ");
        gets(livros[tamanho].editora);
        printf("Digite o ano de lançamento: ");
        scanf("%d", &livros[tamanho].ano);
        getchar();
        printf("Digite o assunto do livro: ");
        gets(livros[tamanho].assunto);
        tamanho = novotamanho;
        printf("\n");
      break;
      case 1:
        cont = 0;
        novotamanho = tamanho - 1;
        printf("\nDigite o número do livro que deseja deletar: ");
        scanf("%i", &remover);
        getchar();
        if(remover >= tamanho){
          printf("Posição inválida");
          getchar();
        } else {
          aux = malloc(novotamanho*sizeof(livraria));
          for(x = 0; x < tamanho; x++){
            if(remover != x){
              strcpy(aux[cont].titulo, livros[x].titulo);
              strcpy(aux[cont].autor, livros[x].autor);
              strcpy(aux[cont].editora, livros[x].editora);
              aux[cont].ano = livros[x].ano;
              strcpy(aux[cont].assunto, livros[x].assunto);
              cont++;
            }
          }
          free(livros);
          livros = aux;
          tamanho = novotamanho;
        }
      break;
      case 2:
        system("clear");
        printf("//--Livros--// \n");
        for(x = 0; x < tamanho; x++){
          if(livros[x].ano != 0){
            printf("Livro na posição %i\n", x);
            printf("Título: %s\nAutor(a): %s\nEditora: %s\nAno de lançamento: %i\nAssunto: %s\n", livros[x].titulo, livros[x].autor, livros[x].editora, livros[x].ano, livros[x].assunto);
            printf("--------\n");
          }
        }
        printf("\n");
      break;
      case 3:
        system("clear");
        printf("Deseja buscar livro como?\n[0] - Buscar por título\n[1] - Buscar por autor\n[2] - Buscar por editora\n");
        scanf("%i", &busca);
        getchar();
        cont2 = 0;
        if(busca == 0){
          printf("\nDigite o título da obra: ");
          gets(frase);
        } else if(busca == 1){
          printf("\nDigite o autor(a) da obra: ");
          gets(frase);
        } else if(busca == 2){
          printf("\nDigite a editora da obra: ");
          gets(frase);
        } else{
          printf("\nBusca inválida\n\n");
          busca = -1;
        }
        if(busca != -1){
          for(x = 0; x < tamanho; x++){
            if(busca == 0){
              cont = strcmp(livros[x].titulo, frase);
            } else if(busca == 1){
              cont = strcmp(livros[x].autor, frase);
            } else{
              cont = strcmp(livros[x].editora, frase);
            }
            if(cont == 0){
              cont2++;
              printf("\nLivro na posição %i\n", x);
              printf("Título: %s\nAutor(a): %s\nEditora: %s\nAno de lançamento: %i\nAssunto: %s\n", livros[x].titulo, livros[x].autor, livros[x].editora, livros[x].ano, livros[x].assunto);
              printf("--------");
            }
            if(cont2 == 0){
              printf("\nLivro não encontrado\n\n");
            }
          }
        }
        printf("\n\n");
      break;
      case 4:
        printf("\nDigite a posição absoluta do livro que deseja alterar uma informação: ");
        scanf("%i", &remover);
        getchar();
        if(remover >= tamanho){
          printf("\nPosição inválida");
          getchar();
        } else{
          printf("\nEscolha que informação deseja alterar: \n[0] - Título\n[1] - Autor\n[2] - Editora\n[3] - Ano de lançamento\n[4] - Assunto\n");
          scanf("%i", &x);
          getchar();
          printf("\n");
          switch(x){
            case 0:
              printf("Título atual: %s\nNovo título: ", livros[remover].titulo);
              gets(livros[remover].titulo);
              printf("\nAtualizado com sucesso");
              getchar();
            break;
            case 1:
              printf("Autor(a) atual: %s\nNovo(a) autor(a): ", livros[remover].autor);
              gets(livros[remover].autor);
              printf("\nAtualizado com sucesso");
              getchar();
            break;
            case 2:
              printf("Editora atual: %s\nNova editora: ", livros[remover].editora);
              gets(livros[remover].editora);
              printf("\nAtualizado com sucesso");
              getchar();
            break;
            case 3:
              printf("Ano de lançamento atual: %i\nNovo ano: ", livros[remover].ano);
              scanf("%d", &livros[remover].ano);
              getchar();
              printf("\nAtualizado com sucesso");
              getchar();
            break;
            case 4:
              printf("Assunto atual: %s\nNovo assunto: ", livros[remover].assunto);
              gets(livros[remover].assunto);
              printf("\nAtualizado com sucesso");
              getchar();
            break;
          }
        }
        system("clear");
      break;
      case 5:
        printf("\nFinalizando programa\n");
        getchar();
      break;
      default:
        printf("\nEscolha inválida\n\n");
    }
  }while(escolha != 5);
}