using namespace std;

// struct candidato
struct Candidato {
    string nome;
    int numero;
    int numVotos;
    Candidato* proximo;
};

// struct eleitor
struct Eleitor {
    string nome;
    int numeroTitulo;
    Eleitor* proximo;
};

// zerar lista candidatos
Candidato* listaCandidatos = 0;

// zerar lista eleitores aptos
Eleitor* listaEleitoresAptos = 0;

// cadastro candidatos ponteiro e instaciando novo candidato
void inserirCandidato() {
    Candidato* novoCandidato = new Candidato;
    cout << "Nome do candidato: ";
    cin >> novoCandidato->nome;
    cout << "N�mero do candidato: ";
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
    //delete new candidato
}



// listar os candidatos
void listarCandidatos() {
    if (listaCandidatos == 0) {
        cout << "| N�o h� candidatos cadastrados.| " << endl;
    } else {
    	cout << "-------------------------------------------" << endl;
        cout << "Lista de candidatos:" << endl;
        Candidato* atual = listaCandidatos;
        while (atual != 0) {
        	cout << "-------------------------------------------" << endl;
            cout << "| Nome: " << atual->nome << ", N�mero: " << atual->numero  << " |" << endl;
            atual = atual->proximo;
            cout << "-------------------------------------------" << endl;
        }
    }
}

// Fun��o para salvar os candidatos em arquivo achei melhor 
// separar por causa dos loops que gravavam muitos dados
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
        cout << "N�o foi poss�vel abrir o arquivo." << endl;
    }
}

// Fun��o para carregar os candidatos do arquivo
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
        cout << "N�o foi poss�vel abrir o arquivo." << endl;
    }
}

// Fun��o para liberar a mem�ria alocada pela lista de candidatos
void liberarMemoriaCandidatos() {
    Candidato* atual = listaCandidatos;
    while (atual != 0) {
        Candidato* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

// Fun��o para inserir um eleitor apto na lista
void inserirEleitorApto() {
    Eleitor* novoEleitor = new Eleitor;
    cout << "Nome do eleitor: ";
    cin >> novoEleitor->nome;
    cout << "N�mero do t�tulo de eleitor: ";
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

// Fun��o para verificar se um eleitor est� apto para votar pelo n�mero do t�tulo
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

// Fun��o para liberar a mem�ria alocada pela lista de eleitores aptos
void liberarMemoriaEleitoresAptos() {
    Eleitor* atual = listaEleitoresAptos;
    while (atual != 0) {
        Eleitor* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

// Restante do c�digo...
