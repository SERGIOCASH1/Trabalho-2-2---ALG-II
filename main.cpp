#include <iostream>
#include <time.h>
int opcaoJogador;

void imprimirTabuleiro(char tabuleiro[3][3]) {
	std::cout << "\n" << "\n";
	std::cout << tabuleiro[0][0] << "|" << tabuleiro[0][1] << "|" << tabuleiro[0][2]  << "\n";
	std::cout << "-----" << "\n";
	std::cout << tabuleiro[1][0] << "|" << tabuleiro[1][1] << "|" << tabuleiro[1][2] << "\n";
	std::cout << "-----" << "\n";
	std::cout << tabuleiro[2][0] << "|" << tabuleiro[2][1] << "|" << tabuleiro[2][2] << "\n";
	std::cout << "\n" << "\n";
}

bool tabuleiroCheio(char tabuleiro[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tabuleiro[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

char quemGanhou(char tabuleiro[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
			return tabuleiro[i][0];
		}

		if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
			return tabuleiro[0][i];
		}
	}
	if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
		return tabuleiro[0][0];
	}
	if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
		return tabuleiro[0][2];
	}

	return ' ';
}

bool deuVelha(char tabuleiro[3][3]) {
	if (tabuleiroCheio(tabuleiro)) {
		std::cout << "Deu Velha!\n";
		return true;
	}
	return false;
}

bool alguemGanhou(char tabuleiro[3][3]) {
	char ganhador = quemGanhou(tabuleiro);
	if (ganhador != ' ') {
		std::cout << ganhador << " Venceu!\n";
		return true;
	}

	return false;
}

void entradaJogador(char tabuleiro[3][3]) {
	while (true) {
		int x, y;
		std::cout << "Digite a linha e coluna da jogada (0 a 2):\n";
		std::cin >> x >> y;

		if (x > 2 || x < 0 || y > 2 || y < 0) {
			std::cout << "Os valores não são válidos\n";
			continue;
		}

		if (tabuleiro[x][y] != ' ') {
			std::cout << "Casa ocupada\n";
			continue;
		}
		else {
      if (opcaoJogador == 1){
        tabuleiro[x][y] = 'X';
			  return;
      }
      else{
        tabuleiro[x][y] = 'O';
			  return;
      }
			
		}

	}
}

int avaliacao(char tabuleiro[3][3]) {
	char ganhador = quemGanhou(tabuleiro);
	if (ganhador == ' ')
		return  0;
	if (ganhador == 'X')
		return  1;
	if (ganhador == 'O')
		return -1;
}

int min(char tabuleiro[3][3]) {

	int max(char tabuleiro[3][3]);

	if (quemGanhou(tabuleiro) != ' ' || tabuleiroCheio(tabuleiro)) {
		return avaliacao(tabuleiro);
	}

	int minJogada = 2;

  if (opcaoJogador == 1){
    for (int i = 0; i < 3; i++) {
		  for (int j = 0; j < 3; j++) {
			  if (tabuleiro[i][j] == ' ') {
				  tabuleiro[i][j] = 'O';
				  int jogada = max(tabuleiro);
				  tabuleiro[i][j] = ' ';
				  if (jogada < minJogada) {
					  minJogada = jogada;
				  }
			  }
		  }
	  }
  }
  else{
    for (int i = 0; i < 3; i++) {
		  for (int j = 0; j < 3; j++) {
			  if (tabuleiro[i][j] == ' ') {
				  tabuleiro[i][j] = 'X';
				  int jogada = max(tabuleiro);
				  tabuleiro[i][j] = ' ';
				  if (jogada < minJogada) {
					  minJogada = jogada;
				  }
			  }
		  }
	  }
  }

	return minJogada;
}

int max(char tabuleiro[3][3]) {

	if (quemGanhou(tabuleiro) != ' ' || tabuleiroCheio(tabuleiro)) {
		return avaliacao(tabuleiro);
	}

	int maxJogada = -2;

  if (opcaoJogador == 1){
    for (int i = 0; i < 3; i++) {
		  for (int j = 0; j < 3; j++) {
			  if (tabuleiro[i][j] == ' ') {
				  tabuleiro[i][j] = 'X';
				  int jogada = min(tabuleiro);
				  tabuleiro[i][j] = ' ';
				  if (jogada > maxJogada) {
					  maxJogada = jogada;
				  }
			  }
		  }
	  }
  }
  else{
    for (int i = 0; i < 3; i++) {
		  for (int j = 0; j < 3; j++) {
			  if (tabuleiro[i][j] == ' ') {
				  tabuleiro[i][j] = 'O';
				  int jogada = min(tabuleiro);
				  tabuleiro[i][j] = ' ';
				  if (jogada > maxJogada) {
					  maxJogada = jogada;
				  }
			  }
		  }
	  }
  }
	
	return maxJogada;
}

void oponenteDecisaoMinMax(char tabuleiro[3][3], int &x, int&y) {
	int minJogada = 2;

  if (opcaoJogador == 1){
    for (int i = 0; i < 3; i++) {
		  for (int j = 0; j < 3; j++) {
			  if (tabuleiro[i][j] == ' ') {
				  tabuleiro[i][j] = 'O';
				  int jogada = max(tabuleiro);
				  tabuleiro[i][j] = ' ';
				  if (jogada < minJogada) {
					  minJogada = jogada;
					  x = i;
					  y = j;
				  }
			  }
		  }
	  }
  }
  else{
    for (int i = 0; i < 3; i++) {
		  for (int j = 0; j < 3; j++) {
			  if (tabuleiro[i][j] == ' ') {
				  tabuleiro[i][j] = 'X';
				  int jogada = max(tabuleiro);
				  tabuleiro[i][j] = ' ';
				  if (jogada < minJogada) {
					  minJogada = jogada;
					  x = i;
					  y = j;
				  }
			  }
		  }
	  }
  }
	

	std::cout << "MIN: " << minJogada << "\n";
}

void oponenteDecisaoAleatoria(char tabuleiro[3][3], int &x, int&y) {
	x = rand() % 3;
	y = rand() % 3;
}

void oponenteMinMax(char tabuleiro[3][3], int &x, int&y) {
	x = rand() % 3;
	y = rand() % 3;
}

void jogadaOponente(char tabuleiro[3][3]) {
	for(int i = 0; i < 100; i++) {
		int x, y;
		oponenteDecisaoMinMax(tabuleiro, x, y);
		
		
		if (tabuleiro[x][y] != ' ') {
			continue;
		}
		else {
      if (opcaoJogador == 1){
        std::cout << "O oponente jogou em " << x << " " << y << "\n";
			  tabuleiro[x][y] = 'O';
			  return;
      }
      else{
        std::cout << "O oponente jogou em " << x << " " << y << "\n";
			  tabuleiro[x][y] = 'X';
			  return;
      }
			
		}

	}
}

int main()
{
	srand(time(NULL));
	char tabuleiro[3][3] = { {' ' , ' ', ' '}, {' ' , ' ', ' '}, {' ' , ' ', ' '} };
  std::cout << "Insira 1 se deseja jogar com X, qualquer número para O:\n ";
  std::cin >> opcaoJogador;
	
	while (!alguemGanhou((tabuleiro)) && !deuVelha(tabuleiro)) {
		entradaJogador(tabuleiro);
		if (alguemGanhou(tabuleiro) || deuVelha(tabuleiro)) {
			break;
		}
		jogadaOponente(tabuleiro);
		imprimirTabuleiro(tabuleiro);
	}

	imprimirTabuleiro(tabuleiro);
	
	int fim;
	std::cin >> fim;
}