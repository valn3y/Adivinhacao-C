#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	printf("\n\n");
	printf("    /\\                                                        /\\     \n");
	printf("   |  |                                                      |  |      \n");
	printf("  /----\\                       Bem vindo                    /----\\   \n");
	printf(" [______]                Jogo de adivinhação               [______]    \n");
	printf("  |    |         _____                        _____         |    |     \n");
	printf("  |[]  |        [     ]                      [     ]        |  []|     \n");
	printf("  |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |     \n");
	printf("  |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |     \n");
	printf("  |             |     |/'    ____..____    '\\|     |             |    \n");
	printf("   \\ []         |     |    /'    ||    '\\   |     |        []   /    \n");
	printf("    |      []   |     |   |o     ||     o|   |     |  []       |       \n");
	printf("    |           |  _  |   |     _||_     |   |  _  |           |       \n");
	printf("    |   []      | (_) |   |    (_||_)    |   | (_) |       []  |       \n");
	printf("    |           |     |   |     (||)     |   |     |           |       \n");
	printf("    |           |     |   |      ||      |   |     |           |       \n");
	printf("  /''           |     |   |o     ||     o|   |     |           ''\\    \n");
	printf(" [_____________[_______]--'------''------'--[_______]_____________]    \n");
	printf("\n\n");

	int seconds = time(0);
	srand(seconds);
	int bigNumber = rand();

	int secretNumber = bigNumber % 100;
	int guess;
	int tries = 0;
	double score = 1000;

	int level;
	printf("Qual o nível de dificuldade?\n");
	printf("(1) Fácil (2) Médio (3) Difícel\n");
	printf("Escolha: ");
	scanf("%d", &level);
	printf("\n");

	int numberTries;
	switch(level) {
		case 1:
			numberTries = 20;
			break;
		case 2:
			numberTries = 15;
			break;
		default:
			numberTries = 6;
			break;
	}

	int correct;

	for(int i = 1; i <= numberTries; i++){
		printf("Tentativa %d\n", tries + 1);
		printf("Qual é o seu chute? ");
		scanf("%d", &guess);
		printf("Seu chute foi: %d\n", guess);

		if(guess < 0) {
			printf("Você não pode chutar número negativos!\n\n");
			continue;
		}

		correct = (guess == secretNumber);
		int major = guess > secretNumber;

		if(correct) {
			break;
		} else if(major) {
			printf("Seu chute foi maior que o número secreto\n\n");
		} else {
			printf("Seu chute foi menor que o número secreto\n\n");
		}

		tries++;

		double scoreLosed = (double) (guess - secretNumber) / (double) 2;
		score = score - abs(scoreLosed);
	}

	if(correct) {
		printf("\n");
		printf("             OOOOOOOOOOO               \n");
        printf("         OOOOOOOOOOOOOOOOOOO           \n");
        printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
        printf("    OOOOOO      OOOOO      OOOOOO      \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
        printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
        printf("         OOOOOO         OOOOOO         \n");
        printf("             OOOOOOOOOOOO              \n");
        printf("\nParabéns! Você acertou!\n");
        printf("Você acertou em %d tentativas\n", tries);
        printf("Você fez %.2f pontos. Até a próxima!\n\n", score);
	} else {
		printf("\n");
		printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");
        printf("\nVocê perdeu! Tente novamente!\n\n");
	}

	printf("Fim de Jogo!!!\n");
}