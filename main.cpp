#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
using namespace std;



int main() {
	setlocale(LC_ALL,"Portuguese");
	
    int opcao;

    do {
        cout << "===== Sistema de Eleição =====" << endl;
        cout << "1 - Cadastro de candidatos" << endl;
        cout << "2 - Listar candidatos" << endl;
        cout << "3 - Inserir eleitor apto" << endl;
        cout << "4 - Inicio da votação" << endl;
        cout << "5 - Relatorio Votacao" << endl;
        cout << "6 - ------------" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
            	carregarCandidatos();
                inserirCandidato();
                salvarCandidatos();
                //liberarMemoriaCandidatos();
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
                cout << "Digite o número do título de eleitor: ";
                cin >> numeroTitulo;
                if (verificarEleitorApto(numeroTitulo)) {
                	
                    //cout << "Eleitor apto para votar." << endl;
                } else {
                    cout << "Eleitor não apto para votar." << endl;
                }
                break;               
            case 5:
                votacao();
                salvarEleitores();
                exibirVotosRegistrados();
                break;
            case 6:
            	exibirVotos();
            	break;
            case 0:
                // Liberar a memória alocada pelos candidatos e eleitores aptos antes de sair
                liberarMemoriaCandidatos();
                liberarMemoriaEleitoresAptos();
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }

        cout << endl;
    } while (opcao != 0);

    return 0;
}


