#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
using namespace std;



int main() {
	setlocale(LC_ALL,"Portuguese");
	
    int opcao;

    do {
        cout << "===== Sistema de Elei��o =====" << endl;
        cout << "1 - Cadastro de candidatos" << endl;
        cout << "2 - Listar candidatos" << endl;
        cout << "3 - Inserir eleitor apto" << endl;
        cout << "4 - Inicio da vota��o" << endl;
        cout << "5 - Relatorio quem ganhou a Votacao" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
            	carregarCandidatos();
                inserirCandidato();
                salvarCandidatos();        
                break;
            case 2:            	
            	carregarCandidatos();
                listarCandidatos();
                break;
            case 3:
            	carregarEleitor();
                inserirEleitorApto();
                salvarEleitores();
                break;
            case 4:
            	carregarEleitor();
                int numeroTitulo;
                cout << "Digite o n�mero do t�tulo de eleitor: ";
                cin >> numeroTitulo;
                votacao(numeroTitulo);  
				resultado();            
            case 5:
                exibirVotosRegistrados();
                break;
            case 0:
                break;
            default:
                cout << "Op��o inv�lida." << endl;
                break;
        }

        cout << endl;
    } while (opcao != 0);

    return 0;
}


