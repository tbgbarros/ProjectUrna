#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estrutura para representar um candidato
struct Candidato {
    string nome;
    int numero;
    int numVotos;
    Candidato* proximo;
};

// Estrutura para representar um eleitor
struct Eleitor {
    string nome;
    int numeroTitulo;
    Eleitor* proximo;
};

// Variável para armazenar a lista de candidatos
Candidato* listaCandidatos = 0;

// Variável para armazenar a lista de eleitores aptos
Eleitor* listaEleitoresAptos = 0;

// Função para inserir um candidato na lista
void inserirCandidato() {
    Candidato* novoCandidato = new Candidato;
    cout << "Nome do candidato: ";
    cin >> novoCandidato->nome;
    cout << "Número do candidato: ";
    cin >> novoCandidato->numero;
    novoCandidato->numVotos = 0;
    novoCandidato->proximo = 0;

    if (listaCandidatos == 0) {
        listaCandidatos = novoCandidato;
    } else {
        Candidato* atual = listaCandidatos;
        while (atual->proximo != 0) {
            atual = atual->proximo;
        }
        atual->proximo = novoCandidato;
    }

    cout << "Candidato cadastrado com sucesso!" << endl;
}



// Função para listar os candidatos
void listarCandidatos() {
    if (listaCandidatos == 0) {
        cout << "Não há candidatos cadastrados." << endl;
    } else {
        cout << "Lista de candidatos:" << endl;
        Candidato* atual = listaCandidatos;
        while (atual != 0) {
            cout << "Nome: " << atual->nome << ", Número: " << atual->numero << endl;
            atual = atual->proximo;
        }
    }
}

// Função para salvar os candidatos em arquivo
void salvarCandidatos() {
    ofstream arquivo("candidatos.txt");
    if (arquivo.is_open()) {
        Candidato* atual = listaCandidatos;
        while (atual != 0) {
            arquivo << atual->nome << " " << atual->numero << " " << atual->numVotos << endl;
            atual = atual->proximo;
        }
        arquivo.close();
        cout << "Candidatos salvos com sucesso!" << endl;
    } else {
        cout << "Não foi possível abrir o arquivo." << endl;
    }
}

// Função para carregar os candidatos do arquivo
void carregarCandidatos() {
    ifstream arquivo("candidatos.txt");
    if (arquivo.is_open()) {
        string nome;
        int numero;
        int numVotos;
        while (arquivo >> nome >> numero >> numVotos) {
            Candidato* novoCandidato = new Candidato;
            novoCandidato->nome = nome;
            novoCandidato->numero = numero;
            novoCandidato->numVotos = numVotos;
            novoCandidato->proximo = 0;

            if (listaCandidatos == 0) {
                listaCandidatos = novoCandidato;
            } else {
                Candidato* atual = listaCandidatos;
                while (atual->proximo != 0) {
                    atual = atual->proximo;
                }
                atual->proximo = novoCandidato;
            }
        }
        arquivo.close();
        cout << "Candidatos carregados com sucesso!" << endl;
    } else {
        cout << "Não foi possível abrir o arquivo." << endl;
    }
}

// Função para liberar a memória alocada pela lista de candidatos
void liberarMemoriaCandidatos() {
    Candidato* atual = listaCandidatos;
    while (atual != 0) {
        Candidato* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

// Função para inserir um eleitor apto na lista
void inserirEleitorApto() {
    Eleitor* novoEleitor = new Eleitor;
    cout << "Nome do eleitor: ";
    cin >> novoEleitor->nome;
    cout << "Número do título de eleitor: ";
    cin >> novoEleitor->numeroTitulo;
    novoEleitor->proximo = 0;

    if (listaEleitoresAptos == 0) {
        listaEleitoresAptos = novoEleitor;
    } else {
        Eleitor* atual = listaEleitoresAptos;
        while (atual->proximo != 0) {
            atual = atual->proximo;
        }
        atual->proximo = novoEleitor;
    }

    cout << "Eleitor cadastrado com sucesso!" << endl;
}

// Função para verificar se um eleitor está apto para votar pelo número do título
bool verificarEleitorApto(int numeroTitulo) {
    Eleitor* atual = listaEleitoresAptos;
    while (atual != 0) {
        if (atual->numeroTitulo == numeroTitulo) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

// Função para liberar a memória alocada pela lista de eleitores aptos
void liberarMemoriaEleitoresAptos() {
    Eleitor* atual = listaEleitoresAptos;
    while (atual != 0) {
        Eleitor* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

// Restante do código...

int main() {
    int opcao;

    do {
        cout << "===== Sistema de Eleição =====" << endl;
        cout << "1 - Cadastro de candidatos" << endl;
        cout << "2 - Listar candidatos" << endl;
        cout << "3 - Salvar candidatos" << endl;
        cout << "4 - Carregar candidatos" << endl;
        cout << "5 - Cadastro de eleitores aptos" << endl;
        cout << "6 - Verificar eleitor apto" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserirCandidato();
                break;
            case 2:
                listarCandidatos();
                break;
            case 3:
                salvarCandidatos();
                break;
            case 4:
                carregarCandidatos();
                break;
            case 5:
                inserirEleitorApto();
                break;
            case 6:
                int numeroTitulo;
                cout << "Digite o número do título de eleitor: ";
                cin >> numeroTitulo;
                if (verificarEleitorApto(numeroTitulo)) {
                    cout << "Eleitor apto para votar." << endl;
                } else {
                    cout << "Eleitor não apto para votar." << endl;
                }
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

