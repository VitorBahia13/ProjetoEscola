/*#include <stdio.h>

int main(void){
    
    int a,b,x;
    
    a=4;
    b=7;
    
    x =a+b;
    
    printf("\n%d\n",x);
    
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include <unistd.h>

typedef struct data{
  
  int dia;
  int mes;
  int ano; 
} Data; 

typedef struct ficha_aluno{
	
    char sexo;
    char cpf[16];
    int matricula;  
    char nome[50];
    Data dt;

    struct ficha_aluno * prox;
	
} Aluno;

typedef struct ficha_professor{
   
    int matricula;
    char sexo;
    char nome[50];
    char cpf[16];
    Data dt;
    
    struct ficha_professor *prox;
    
} Professor;

typedef struct ficha_disciplina{
	
    Professor prof;
    char nome[50];
    char codigo[7];
    char semestre[7];
    Aluno aluno;
    // Aluno* alunos[40]; <<<<<<<Professor pediu alterar e fazer desse jeito
    struct ficha_disciplina *prox;
    
}  Disciplina;

void flush_in() {
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

void alocarAlunos(Aluno *inicio){

	Aluno* tmp;
	Aluno* novo = (Aluno*) malloc(sizeof(Aluno));

	if(!novo)
	{
		printf("Sem memoria disponivel");
		exit(1);
	}
	
	printf("Informe a matricula: ");
    scanf("%d",&novo->matricula);
    getchar();

  	printf("Informe o Nome do Aluno: ");
  	fgets(novo->nome,50,stdin);
    size_t ln = strlen(novo->nome) - 1;
    if (novo->nome[ln] == '\n')
    {
        novo->nome[ln] = '\0';
    }
  	//printf("Informe o Sexo do Aluno:\n=>[M]. Masculino\n=>[F]. Feminino\nENTRADA: ");
    //scanf("%c",&novo->sexo);
   
  //  novo->sexo = toupper(novo->sexo);
  //  while (novo->sexo != 'M' && novo->sexo != 'F') {
        
    //printf("Informe o Sexo do Aluno:\n=>[M]. Masculino\n=>[F]. Feminino\nENTRADA: ");
    //scanf("%c",&novo->sexo);
   
  //  novo->sexo = toupper(novo->sexo);
   
    // if((novo->sexo != 'M' && novo->sexo != 'F')){
      //  printf("ERRO !!! SEXO INVALIDO!\n");
       // printf("Informe um Sexo vaido");}
        //}
    
    
    do{
        printf("Informe o Sexo do Aluno:\n=>[M]. Masculino\n=>[F]. Feminino\nENTRADA: ");
        scanf("%c",&novo->sexo);
        flush_in();
        novo->sexo = toupper(novo->sexo);
        //printf("\n");
        
        if((novo->sexo != 'M' && novo->sexo != 'F')){
        printf("\nERRO !!! SEXO INVALIDO!\n");
        printf("INFORME UM SEXO VALIDO\n\n");}
    }while(novo->sexo != 'M' && novo->sexo != 'F');
 		
	
    printf("Informe o dia de nascimento: ");
    scanf("%d", &novo->dt.dia);

    printf("Informe o mes de nascimento: ");
    scanf("%d", &novo->dt.mes);

    printf("Informe o ano de nascimento: ");
    scanf("%d", &novo->dt.ano);
    getchar();

    printf("Informe o CPF: ");
    fgets(novo->cpf, 15, stdin); 
    ln = strlen(novo->cpf) - 1; 
    if (novo->cpf[ln] == '\n')
        novo->cpf[ln] = '\0';

    printf("\n");

	novo->prox = NULL;

	if(inicio->prox == NULL)
	{
		inicio->prox = novo;
	}
	else
	{	
		tmp = inicio->prox;
		while(tmp->prox != NULL)
		{
			tmp = tmp->prox;
		}
		tmp->prox = novo;
	}
  
  printf("========= Aluno Cadastrado com Sucesso =========\n");

}

void alocarProfessores(Professor *inicio){

	Professor* tmp;
	Professor* novo = (Professor*) malloc(sizeof(Professor));

	if(!novo)
	{
		printf("Sem memoria disponivel");
		exit(1);
	}
	
	printf("Informe a matricula: ");
    scanf("%d",&novo->matricula);
    getchar();

  	printf("Informe o Nome do Professor: ");
  	fgets(novo->nome,50,stdin);
        size_t ln = strlen(novo->nome) - 1;
    	if (novo->nome[ln] == '\n')
    	{
    		novo->nome[ln] = '\0';
		}
  	  do{
    printf("Informe o Sexo do Professor:\n=>[M]. Masculino\n=>[F]. Feminino\nENTRADA: ");
    scanf("%c",&novo->sexo);
    flush_in();
    novo->sexo = toupper(novo->sexo);
    //printf("\n");
    
    if((novo->sexo != 'M' && novo->sexo != 'F')){
    printf("\nERRO !!! SEXO INVALIDO!\n");
    printf("INFORME UM SEXO VALIDO\n\n");}
    }while(novo->sexo != 'M' && novo->sexo != 'F');
	
     printf("Informe o dia de nascimento: ");
    scanf("%d", &novo->dt.dia);

    printf("Informe o mes de nascimento: ");
    scanf("%d", &novo->dt.mes);

    printf("Informe o ano de nascimento: ");
    scanf("%d", &novo->dt.ano);
    getchar();

    printf("Informe o CPF: ");
    fgets(novo->cpf, 15, stdin); 
    ln = strlen(novo->cpf) - 1; 
    if (novo->cpf[ln] == '\n')
        novo->cpf[ln] = '\0';

    printf("\n");

	  novo->prox = NULL;

	if(inicio->prox == NULL)
	{
		inicio->prox = novo;
	}
	else
	{	
		tmp = inicio->prox;
		while(tmp->prox != NULL)
		{
			tmp = tmp->prox;
		}
		tmp->prox = novo;
	}

 printf("======= Professor Cadastrado com Sucesso =======\n");

}

void alocarDisciplinas(Disciplina* inicio){
	
    Disciplina* tmp;
	Disciplina* novo = (Disciplina*) malloc(sizeof(Disciplina));

  	if(!novo)
	{
		printf("Sem memoria disponivel");
		exit(1);
	}

   // size_t ln; 
     flush_in();
  	printf("Informe o Nome da Disciplina: ");
  	fgets(novo->nome,50,stdin);
     //    ln = strlen(novo->nome) - 1;
    	//if (novo->nome[ln] == '\n')
    	  //  novo->nome[ln] = '\0';
    printf("Informe o Codigo da Disciplina: ");
  	fgets(novo->codigo,7,stdin);
        //ln = strlen(novo->codigo) - 1;
    	//if (novo->codigo[ln] == '\n')
    	  //  novo->codigo[ln] = '\0';
  //       flush_in();

    printf("Informe o Semestre da Disciplina: ");
    fgets(novo->semestre, 7, stdin); 
    //ln = strlen(novo->semestre) - 1; 
    //if (novo->semestre[ln] == '\n')
      //  novo->semestre[ln] = '\0';
    
        // flush_in();
    //printf("OK=>%s",novo->semestre);

    printf("Informe o Nome do professor da Disciplina: ");
    fgets(novo->prof.nome, 50, stdin); 
    //ln = strlen(novo->prof.nome) - 1; 
    //if (novo->prof.nome[ln] == '\n')
      //  novo->prof.nome[ln] = '\0';

    printf("Informe o Nome do Aluno da Disciplina: ");
    fgets(novo->aluno.nome, 50, stdin); 
//    ln = strlen(novo->aluno.nome) - 1; 
  //  if (novo->aluno.nome[ln] == '\n')
    //    novo->aluno.nome[ln] = '\0';

    printf("\n");

	  novo->prox = NULL;

	if(inicio->prox == NULL)
	{
		inicio->prox = novo;
	}
	else
	{	
		tmp = inicio->prox;
		while(tmp->prox != NULL)
		{
			tmp = tmp->prox;
		}
		tmp->prox = novo;
	}

  printf("======== Disciplina Cadastrada com Sucesso ========\n");

}
/*
void alocarAlunosNasDisciplinas(Disciplina* inicio){
    

    int verificar;
    char remover[50];
    
     do{
    printf("Informe uma opcao para o Aluno:\n=>[1]. Inserir\n=>[2]. Remover\nENTRADA: ");
    scanf("%d",&verificar);
    flush_in();
    //printf("\n");
    
    if((verificar!= 1 && verificar != 2)){
    printf("\nERRO !!! OPCAO INVALIDA!\n");
    printf("INFORME UMA OPCAO VALIDA\n\n");}
    }while(verificar != 1 && verificar!= 2);
    
    
    switch(verificar)
		{
				
			case 1:
				{
                printf("Informe o Nome do Aluno da Disciplina: ");
                fgets(novo->aluno.nome, 50, stdin); 
                //  ln = strlen(novo->aluno.nome) - 1; 
                //  if (novo->aluno.nome[ln] == '\n')
                //  novo->aluno.nome[ln] = '\0';
                while(aux->prox != NULL)
                    {
                        printf("\nNome: %s",aux->nome);
                    }
        
                        printf("\nNome: %s",aux->nome);
                
				}
			case 2:
				{
                    printf("Informe o Nome do Aluno que sera removio da Disciplina: ");
                    fgets(remover, 50, stdin); 
                    
                    if(remover== novo->aluno.nome){
                        
                        	while(atual != NULL){

                                    tmp = atual->prox;

                                    free(atual);

                                    atual = tmp;
                                }

                        
                        
                        
                    }
					break;
				}

    
    }
    
}
*/
void listarAlunos(Aluno* inicio){

	Aluno* aux;
	aux = inicio->prox;

   if(inicio->prox == NULL ){

    printf("ERRO !!! NENHUM ALUNO MATRICULADO\n");
    printf("RETORNANDO PARA O MENU\n");

    return ;

  }
		
	printf("\n============= Alunos Matriculados ================ \n\n");		
	
	while(aux->prox != NULL)
	{
            printf("Matricula: %d\nNome: %s\nData Nascimento: %d/%d/%d\nCPF: %s\n",aux->matricula,aux->nome,aux->dt.dia, aux->dt.mes, aux->dt.ano,aux->cpf);

        
	}
	
	printf("Matricula: %d\nNome: %s\nData Nascimento: %d/%d/%d\nCPF: %s\n",aux->matricula,aux->nome,aux->dt.dia, aux->dt.mes, aux->dt.ano,aux->cpf);

    if(aux->sexo == 'M')
        printf("Sexo: Masculino\n");
    if(aux->sexo == 'F')
        printf("Sexo: Feminino\n");
	
}

void listarProfessores(Professor* inicio){
	
    Professor* aux;
	aux = inicio->prox;

   if(inicio->prox == NULL ){

    printf("ERRO !!! NENHUM PROFESSOR MATRICULADO\n");
    printf("RETORNANDO PARA O MENU\n");

    return ;

  }
		
	printf("\n=========== Professores Matriculados ============= \n\n");		
	
		while(aux->prox != NULL)
	{
        
		printf("Matricula: %d\nNome: %s\nData Nascimento: %d/%d/%d\nCPF: %s\n",aux->matricula,aux->nome,aux->dt.dia, aux->dt.mes, aux->dt.ano,aux->cpf);

        if(aux->sexo == 'M')
            printf("Sexo: Masculino\n");
        if(aux->sexo == 'F')
            printf("Sexo: Feminino\n");
	}
	
        printf("Matricula: %d\nNome: %s\nData Nascimento: %d/%d/%d\nCPF: %s\n",aux->matricula,aux->nome,aux->dt.dia, aux->dt.mes, aux->dt.ano,aux->cpf);

        if(aux->sexo == 'M')
            printf("Sexo: Masculino\n");
        if(aux->sexo == 'F')
            printf("Sexo: Feminino\n");
	

	
}

void listarDisciplinas(Disciplina* inicio){
	
    Disciplina* aux;
	aux = inicio->prox;

   if(inicio->prox == NULL ){

    printf("ERRO !!! NENHUMA DISCIPLINA MATRICULADA\n");
    printf("RETORNANDO PARA O MENU\n");

    return ;

  }
		
	printf("\n=========== Disciplinas Matriculadas ============== \n\n");			
	
	while(aux->prox != NULL)
	{
		printf("\nNome: %s\nCodigo: %s\nSemestre: %s\nNome do Professor: %s\nNome do Aluno Matriculado da Disciplina: %s\n",aux->nome,aux->codigo,aux->semestre,aux->prof.nome,aux->aluno.nome);
		
    aux = aux->prox;
	}
	
  printf("Nome da Disciplina: %sCodigo: %sSemestre: %sNome do Professor: %sNome do Aluno Matriculado da Disciplina: %s\n",aux->nome,aux->codigo,aux->semestre,aux->prof.nome,aux->aluno.nome);

	
}

void liberarAlunos(Aluno* inicio){
	
    Aluno* atual = inicio;
	Aluno* tmp;

	while(atual != NULL){

		tmp = atual->prox;

		free(atual);

		atual = tmp;
	}

}

void liberarProfessores(Professor* inicio){
	
    Professor* atual = inicio;
	Professor* tmp;

	while(atual != NULL){

		tmp = atual->prox;

		free(atual);

		atual = tmp;
	}

}

void liberarDisciplinas(Disciplina* inicio){
	
    Disciplina* atual = inicio;
	Disciplina* tmp;

	while(atual != NULL){

		tmp = atual->prox;

		free(atual);

		atual = tmp;
	}

}

int menu(void){

 int escolha;

 do{
 printf("\nEscolha uma opcao\n");
 printf("=>[0]. Sair\n");
 printf("=>[1]. Cadastrar Informacoes\n");
 printf("=>[2]. Apresentar Relatorio\n");
 printf("=>[3]. Atualizar Cadastro\n");
 //printf("=>[4]. Listar todas as informacoes dos Alunos\n");
 //printf("=>[5]. Listar todas as informacoes dos Professores\n");
// printf("=>[6]. Listar todas as informacoes das Disciplinas\n");


 	printf("ENTRADA: "); scanf("%d", &escolha);
  printf("\n");
 	if(escolha<0 || escolha>3){
 		printf("Opcao Invalida!!! Selecione uma opcao Valida.\n");
	 }
 }while(escolha<0 || escolha>3);

  return escolha;
}

int main(){
	
 // system("color A");

	int escolha = -1;
	
	Aluno* alunoInicio = (Aluno*) malloc(sizeof(Aluno));
	alunoInicio->prox = NULL;

    Professor* professorInicio = (Professor*) malloc(sizeof(Professor));
	professorInicio->prox = NULL;

    Disciplina* disciplinaInicio = (Disciplina*) malloc(sizeof(Disciplina));
	disciplinaInicio->prox = NULL;

	do
	{	
		escolha = menu();  
		
		switch(escolha)
		{
			case 0:
				{
					liberarAlunos(alunoInicio);
					liberarProfessores(professorInicio);
                    liberarDisciplinas(disciplinaInicio);
					printf("Programa finalizado com sucesso!!! \n");
                    escolha=0;
					break;
				}
			case 1:
            {
                    int cadastro;
                    do{
                    printf("\nEscolha uma opcao\n");
                    printf("=>[1]. Cadastrar Alunos\n");
                    printf("=>[2]. Cadastrar Professores\n");
                    printf("=>[3]. Cadastrar Disciplinas\n");

                        printf("ENTRADA: "); scanf("%d", &cadastro);
                    printf("\n");
                        if(escolha<0 || escolha>3){
                            printf("Opcao Invalida!!! Selecione uma opcao Valida.\n");
                        }
                    }while(escolha<0 || escolha>3);
                    
                    
                        switch(cadastro)
                        {
                            
                            case 1: 
                                {
                                    alocarAlunos(alunoInicio);
                                    break;
                                    
                                }
                                
                                
                            case 2: 
                                {
                                    alocarProfessores(professorInicio);
                                    break;
                                    
                                }
                                
                             case 3: 
                                {
                                    alocarProfessores(professorInicio);
                                    break;
                                    
                                }
                                
                            
                        }
                        
                // alocarAlunos(alunoInicio);
                break;
                        
				}
			case 2:
				{
                 
                    int relatorio;
                    do{
                    printf("\nEscolha uma opcao\n");
                    printf("=>[1]. Listar todas as informacoes dos Alunos\n");
                    printf("=>[2]. Listar todas as informacoes dos Professores\n");
                    printf("=>[3]. Listar todas as informacoes das Disciplinas\n");


                        printf("ENTRADA: "); scanf("%d", &relatorio);
                    printf("\n");
                        if(escolha<0 || escolha>3){
                            printf("Opcao Invalida!!! Selecione uma opcao Valida.\n");
                        }
                    }while(escolha<0 || escolha>3);
                    
                    
                    switch(relatorio)
                            {
                            
                                case 1: 
                                    {
                                        listarAlunos(alunoInicio);
                                        break;
                                        
                                    }
                                    
                                    
                                case 2: 
                                    {
                                        listarProfessores(professorInicio);
                                        break;
                                        
                                    }
                                    
                                case 3: 
                                    {
                                        listarDisciplinas(disciplinaInicio);
                                        break;
                                    
                                    }
                        
                    
                    
					//alocarProfessores(professorInicio);
                        
                            }
                    break;
                }
			/*case 3:
				{
                    alocarDisciplinas(disciplinaInicio);
					break;
				}
			case 4:
				{
					listarAlunos(alunoInicio);
					break;
				}
			case 5:
				{
					listarProfessores(professorInicio);
					break;
				}	
            case 6:
				{
					listarDisciplinas(disciplinaInicio);
					break;
				}*/	
		  }     
    }while(escolha!=0);

    return 0;
}
