#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define LOGIN_MAX 64
#define SENHA_MAX 32
#define MAX 100
struct usuario
{
    char login[20];
    char senha[10];
};
struct cadastrop
{
  int codigop,quantidade;
  char nome[30];
  float preco;
};
int main(){

    setlocale (LC_ALL, "");

  int caso;

  printf("\n***MENU***\n");
  printf("1- Criar Usuario\n");
  printf("2- Iniciar sess�o\n");
  printf("3- Finalizar\n");
  scanf ("%d",&caso);
  system("cls");
  switch (caso)
  {
  case 1: {
    login_adm();
    break;
  }
  case 2: {
    login_fun();
    break;
  }
  case 3: {
    return 0;
  }
  default: {
    system("cls");
    printf ("Selecione uma opcao valida!\n");
    printf ("Digite qualquer tecla para continuar...");
    getch();
    system("cls");
    main();
    break;
  }
  }

}

void login_adm(){
    char admlog[6] = "admin";
    char admpass[6] = "admin";
    char admlog2[6], admpass2[6];
    int comp,comp2;

    printf("Login de administrador: ");
    scanf("%s",&admlog2);
    printf("Senha de administrador: ");
    scanf("%s",&admpass2);
    system("cls");
    comp = strcmp(admlog,admlog2);
    comp2 = strcmp(admpass,admpass2);

    if (comp == 0 && comp2 ==0)
    {
        cadastro();
    }
    else {
      printf ("Login ou senha errado!");
      getch();
      system("cls");
      login_adm();
    }
}

void cadastro(){
FILE *fp;
struct usuario user;
printf("Digite o nome de usuario: ");
scanf("%s",&user.login);
printf("Digite a senha: ");
scanf("%s",&user.senha);

fp = fopen("login.txt","a+");
if (!fp) {
  printf("Nao foi possivel efetuar o cadastro!");
  getch();
  main();
}
fprintf(fp, "%s %s\n",user.login,user.senha);
fclose(fp);
system("cls");
printf("Cadastro efetuado!");
main();
}

void login_fun(){
FILE *fp;
      struct usuario user;
      char login[LOGIN_MAX];
      char senha[SENHA_MAX];
      printf ("Login: ");
      scanf ("%s",&login);
      printf ("Senha :");
      scanf ("%s",&senha);
      system("cls");
      fp = fopen("login.txt","r");
      if (validacao(fp, login,senha)) {
        menu();
    }
      else {
        printf ("Login ou Senha errado!!!\n");
        printf ("Digite qualquer tecla para continuar...\n");
        getch();
        system ("cls");
        login_fun();
      }

}

int validacao (FILE* file, char* login,char* senha) {
  char log[LOGIN_MAX];
  char pass[SENHA_MAX];

  fscanf(file,"%s",log);

  while(!feof(file))
  {
    if(!strcmp(log,login))
    {
      fscanf(file,"%s",pass);
      if(!strcmp(pass,senha))
      return 1;
    }
    else {
             fscanf(file,"%*s");
    }
    fscanf(file, "%s",log);
  }
  return 0;
}

void menu(){
  int escolha;
printf("***AutoTiger***\n");
printf("***Bem-Vindo***\n");
printf("1- Cadastrar\n");
printf("2- Finalizar sessao\n");
printf("Selecione a opcao\n");
scanf("%d",&escolha);
system("cls");
switch(escolha){
  case 1:
  cadastro_peca();
break;
  case 2:
main();
  break;
  default:
  system("cls");
  printf("Digite uma opcao valida!");
  menu();
  break;
}
}
void cadastro_peca(){
FILE *p;
struct cadastrop peca;
int escolha;
  printf("Digite o nome do produto: ");
  scanf("%s",&peca.nome);
  peca.codigop = rand()%100;
  printf("\nCodigo do produto %d",&peca.codigop);
  printf ("\nQuantidade de produtos: ");
  scanf("%d",&peca.quantidade);
  printf ("\nPreco: ");
  scanf("%f",&peca.preco);
  p = fopen ("estoque.txt","a+");
  fprintf(p, "%s %d %d %2.f\n",peca.nome,peca.codigop,peca.quantidade,peca.preco);
  fclose(p);
  printf("\nDeseja continuar cadastrando? \n");
  printf("1- SIM\n");
  printf("2- NAO\n");
  scanf("%d",&escolha);
  system ("cls");
  switch (escolha) {
    case 1:
    system("cls");
    cadastro_peca();
    break;

    case 2:
    menu();
    break;
    default:
        menu();
  }
}
