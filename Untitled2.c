#include <stdio.h>

void combinacoes_backtracking(int numeros[], int tamanho, int soma_alvo, int combinacao[], int inicio, int soma_atual) {
    if (soma_atual == soma_alvo) {
        printf("{");
        for (int i = 0; i < tamanho; i++) {
            if (combinacao[i] == 1) {
                printf("%d ", numeros[i]);
            }
        }
        printf("}\n");
        return;
    }
    
    if (soma_atual > soma_alvo || inicio == tamanho) {
        return;
    }

    combinacao[inicio] = 1;
    combinacoes_backtracking(numeros, tamanho, soma_alvo, combinacao, inicio + 1, soma_atual + numeros[inicio]);

    combinacao[inicio] = 0;
    combinacoes_backtracking(numeros, tamanho, soma_alvo, combinacao, inicio + 1, soma_atual);
}

int main() {
    int numeros[] = {2, 4, 6, 8};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int alvo = 10;
    int combinacao[tamanho];

    // Inicializar o array combinacao com zeros
    for (int i = 0; i < tamanho; i++) {
        combinacao[i] = 0;
    }

    combinacoes_backtracking(numeros, tamanho, alvo, combinacao, 0, 0);

    return 0;
}
