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
        cout << "4 - Carregar candidatos" << endl;
        cout << "5 - Cadastro de eleitores aptos" << endl;
        cout << "6 - Verificar eleitor apto" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma op��o: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
            	carregarCandidatos();
                inserirCandidato();
                salvarCandidatos();
                liberarMemoriaCandidatos();
                //Limpeza de memoria
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
                int numeroTitulo;
                cout << "Digite o n�mero do t�tulo de eleitor: ";
                cin >> numeroTitulo;
                if (verificarEleitorApto(numeroTitulo)) {
                    cout << "Eleitor apto para votar." << endl;
                } else {
                    cout << "Eleitor n�o apto para votar." << endl;
                }
                break;
                break;
            case 5:
                inserirEleitorApto();
                break;
            case 6:
                int numeroTitulo;
                cout << "Digite o n�mero do t�tulo de eleitor: ";
                cin >> numeroTitulo;
                if (verificarEleitorApto(numeroTitulo)) {
                    cout << "Eleitor apto para votar." << endl;
                } else {
                    cout << "Eleitor n�o apto para votar." << endl;
                }
                break;
            case 0:
                // Liberar a mem�ria alocada pelos candidatos e eleitores aptos antes de sair
                liberarMemoriaCandidatos();
                liberarMemoriaEleitoresAptos();
                break;
            default:
                cout << "Op��o inv�lida." << endl;
                break;
        }

        cout << endl;
    } while (opcao != 0);

    return 0;
}

