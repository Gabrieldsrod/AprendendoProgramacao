/*
 * Nome: [Seu Nome Aqui]
 * RA: [Seu RA Aqui]
 * Programa: Ajuste de Curvas com Mínimos Quadrados e Eliminação de Gauss
 * Descrição: Calcula o polinômio que melhor se ajusta a um conjunto de dados utilizando
 *            o método dos mínimos quadrados e resolve o sistema linear por eliminação de Gauss.
 */

 #include <stdio.h>    // Inclusão da biblioteca padrão de entrada/saída
 #include <stdlib.h>   // Inclusão da biblioteca padrão para alocação dinâmica
 #include <math.h>     // Inclusão da biblioteca para funções matemáticas
 
 // Protótipos das funções
 void aloca(float **p, int tam);
 void recebeValores(float *x, float *fx, int tam);
 void calcula(float *x, float *fx, int pontos, int grau);
 void eliminacaoGauss(float **mat, float *res, int n);
 void imprimeSistema(float **mat, int n, const char *titulo);
 
 int main(void)
 {
     char continua = 's'; // Variável para controle do loop principal
     int pontos, grau;    // Quantidade de pontos e grau do polinômio
     float *valoresX = NULL, *valoresFX = NULL; // Vetores dinâmicos para armazenar os dados
 
     do {
         printf("Digite o grau do polinomio (1 ou 2): ");
         scanf("%d", &grau); // Leitura do grau
 
         if (grau != 1 && grau != 2) {
             printf("Erro: apenas grau 1 ou 2 sao permitidos.\n");
             continue; // Volta ao início do loop se o grau for inválido
         }
 
         printf("Digite o numero de pontos (maior que %d): ", grau);
         scanf("%d", &pontos); // Leitura do número de pontos
 
         if (pontos <= grau) {
             printf("Erro: o numero de pontos deve ser maior que o grau.\n");
             continue; // Volta ao início do loop se o número de pontos for inválido
         }
 
         aloca(&valoresX, pontos);    // Aloca dinamicamente o vetor X
         aloca(&valoresFX, pontos);   // Aloca dinamicamente o vetor f(X)
 
         recebeValores(valoresX, valoresFX, pontos); // Recebe os valores dos pontos
         calcula(valoresX, valoresFX, pontos, grau); // Calcula o polinômio ajustado
 
         printf("\nDeseja fazer o processo novamente? [S]im / [N]ao? ");
         scanf(" %c", &continua); // Leitura do controle de repetição
 
     } while (continua == 's' || continua == 'S'); // Repete enquanto o usuário quiser
 
     // Libera a memória alocada
     free(valoresX);
     free(valoresFX);
 
     return 0; // Fim do programa
 }
 
 // Função que aloca dinamicamente um vetor de float
 void aloca(float **p, int tam)
 {
     float *temp = (float *)realloc(*p, tam * sizeof(float)); // Realoca memória
     if (temp == NULL) {
         printf("Erro ao alocar memoria!\n");
         free(*p); // Libera memória antiga
         exit(1);  // Encerra o programa com erro
     }
     *p = temp; // Atualiza o ponteiro com o novo endereço
 }
 
 // Função para receber os valores de x e f(x)
 void recebeValores(float *x, float *fx, int tam)
 {
     for (int i = 0; i < tam; i++) {
         printf("Digite o valor de x[%d]: ", i);
         scanf("%f", &x[i]);
         printf("Digite o valor de f(x[%d]): ", i);
         scanf("%f", &fx[i]);
     }
 }
 
 // Função que realiza o cálculo do polinômio ajustado
 void calcula(float *x, float *fx, int pontos, int grau)
 {
     int n = grau + 1; // Tamanho da matriz (grau + 1)
     float **mat = (float **)malloc(n * sizeof(float *)); // Aloca a matriz do sistema
     for (int i = 0; i < n; i++)
         mat[i] = (float *)malloc((n + 1) * sizeof(float)); // Cada linha com n+1 colunas (inclui termo independente)
 
     float *coef = (float *)malloc(n * sizeof(float)); // Vetor dos coeficientes do polinômio
 
     // Montagem da matriz dos mínimos quadrados
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
             mat[i][j] = 0;
             for (int k = 0; k < pontos; k++)
                 mat[i][j] += pow(x[k], i + j); // Soma de potências de x
         }
         mat[i][n] = 0;
         for (int k = 0; k < pontos; k++)
             mat[i][n] += fx[k] * pow(x[k], i); // Soma dos produtos y*x^i
     }
 
     imprimeSistema(mat, n, "Sistema Linear Original"); // Exibe o sistema original
     eliminacaoGauss(mat, coef, n);                     // Resolve o sistema por Gauss
     imprimeSistema(mat, n, "Sistema Escalonado por Gauss"); // Exibe sistema escalonado
 
     // Impressão do polinômio ajustado
     printf("\nPolinomio ajustado:\nP(x) = ");
     for (int i = 0; i < n; i++) {
         printf("%.4f", coef[i]);
         if (i > 0) printf("x^%d", i);
         if (i < n - 1) printf(" + ");
     }
     printf("\n");
 
     for (int i = 0; i < n; i++) free(mat[i]); // Libera cada linha da matriz
     free(mat);  // Libera a matriz
     free(coef); // Libera os coeficientes
 }
 
 // Função que realiza a eliminação de Gauss
 void eliminacaoGauss(float **mat, float *res, int n)
 {
     for (int i = 0; i < n; i++) {
         int maxRow = i;
         for (int k = i + 1; k < n; k++) {
             if (fabs(mat[k][i]) > fabs(mat[maxRow][i]))
                 maxRow = k; // Encontra a linha com maior valor absoluto para pivô
         }
         if (maxRow != i) {
             for (int j = 0; j <= n; j++) {
                 float tmp = mat[i][j];
                 mat[i][j] = mat[maxRow][j];
                 mat[maxRow][j] = tmp; // Troca as linhas
             }
         }
 
         for (int k = i + 1; k < n; k++) {
             float fator = mat[k][i] / mat[i][i]; // Calcula o multiplicador
             for (int j = i; j <= n; j++)
                 mat[k][j] -= fator * mat[i][j]; // Elimina o elemento abaixo do pivô
         }
     }
 
     for (int i = n - 1; i >= 0; i--) {
         res[i] = mat[i][n];
         for (int j = i + 1; j < n; j++)
             res[i] -= mat[i][j] * res[j]; // Substituição retroativa
         res[i] /= mat[i][i];
     }
 }
 
 // Função que imprime o sistema linear
 void imprimeSistema(float **mat, int n, const char *titulo)
 {
     printf("\n%s:\n", titulo);
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++)
             printf("%10.4f ", mat[i][j]); // Coeficientes da equação
         printf("| %10.4f\n", mat[i][n]); // Termo independente
     }
 }
  