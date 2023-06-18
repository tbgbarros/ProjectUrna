using namespace std;

// struct candidato
struct Candidato
{
    string nome;
    int numero;
    int numVotos;
    Candidato *proximo;
};

// struct eleitor
struct Eleitor
{
    string nome;
    int numeroTitulo;
    Eleitor *proximo;
};

//struct voto
struct Voto {
    int numeroTitulo;
    int numeroCandidato;
    Voto* proximo;
};

// zera a lista dos votos e declara
Eleitor *listaEleitor = 0;

// zera a lista eleitores e declara
Eleitor *listaEleitor = 0;

// zerar lista candidatos e declara
Candidato *listaCandidatos = 0;

// zerar lista eleitores aptos e declara
Eleitor *listaEleitoresAptos = 0;

// cadastro candidatos ponteiro e instaciando novo candidato
void inserirCandidato()
{
    Candidato *novoCandidato = new Candidato;
    cout << "Nome do candidato: ";
    cin >> novoCandidato->nome;
    cout << "Numero do candidato: ";
    cin >> novoCandidato->numero;
    novoCandidato->numVotos = 0;
    novoCandidato->proximo = 0;

    if (listaCandidatos == 0)
    {
        // primeiro candidato
        listaCandidatos = novoCandidato;
    }
    else
    {
        Candidato *atual = listaCandidatos;
        while (atual->proximo != 0)
        {
            atual = atual->proximo;
        }
        atual->proximo = novoCandidato;
    }
    cout << "Candidato cadastrado com sucesso!" << endl;
    delete novoCandidato;
}

// listar os candidatos
void listarCandidatos()
{
    if (listaCandidatos == 0)
    {
        cout << "| Nao ha candidatos cadastrados.| " << endl;
    }
    else
    {
        cout << "-------------------------------------------" << endl;
        cout << "Lista de candidatos:" << endl;
        Candidato *atual = listaCandidatos;
        while (atual != 0)
        {
            cout << "-------------------------------------------" << endl;
            cout << "| Nome: " << atual->nome << ", N�mero: " << atual->numero << " |" << endl;
            atual = atual->proximo;
            cout << "-------------------------------------------" << endl;
        }
    }
}

// Funcao para salvar os candidatos em arquivo achei melhor
// separar por causa dos loops que gravavam muitos dados
void salvarCandidatos()
{
    // fechar arquivo
    ofstream arquivo("candidatos.txt");
    if (arquivo.is_open())
    {
        Candidato *atual = listaCandidatos;
        while (atual != 0)
        {
            // separados no txt com espaco
            arquivo << atual->nome << " " << atual->numero << " " << atual->numVotos << endl;
            atual = atual->proximo;
        }
        arquivo.close();
        cout << "Candidatos salvos com sucesso!" << endl;
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }
}

// Funcao para carregar os candidatos do arquivo
void carregarCandidatos()
{
    // abre arquivos
    ifstream arquivo("candidatos.txt");
    if (arquivo.is_open())
    {
        string nome;
        int numero;
        int numVotos;
        while (arquivo >> nome >> numero >> numVotos)
        {
            Candidato *novoCandidato = new Candidato;
            novoCandidato->nome = nome;
            novoCandidato->numero = numero;
            novoCandidato->numVotos = numVotos;
            novoCandidato->proximo = 0;

            if (listaCandidatos == 0)
            {
                listaCandidatos = novoCandidato;
            }
            else
            {
                Candidato *atual = listaCandidatos;
                while (atual->proximo != 0)
                {
                    atual = atual->proximo;
                }
                atual->proximo = novoCandidato;
            }
            // delete novoCandidato;
        }
        arquivo.close();
        cout << "Candidatos carregados com sucesso!" << endl;
    }
    else
    {
        cout << "N�o foi poss�vel abrir o arquivo." << endl;
    }
}

// Fun��o para liberar a mem�ria alocada pela lista de candidatos
void liberarMemoriaCandidatos()
{
    Candidato *atual = listaCandidatos;
    while (atual != 0)
    {
        Candidato *proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

// Fun��o para inserir um eleitor apto na lista
void inserirEleitorApto()
{
    Eleitor *novoEleitor = new Eleitor;
    cout << "Nome do eleitor: ";
    cin >> novoEleitor->nome;
    cout << "N�mero do t�tulo de eleitor: ";
    cin >> novoEleitor->numeroTitulo;
    novoEleitor->proximo = 0;

    if (listaEleitoresAptos == 0)
    {
        listaEleitoresAptos = novoEleitor;
    }
    else
    {
        Eleitor *atual = listaEleitoresAptos;
        while (atual->proximo != 0)
        {
            atual = atual->proximo;
        }
        atual->proximo = novoEleitor;
    }

    cout << "Eleitor cadastrado com sucesso!" << endl;
}

// Fun��o para carregar os candidatos do arquivo
void carregarEleitor()
{
    ifstream arquivo("eleitor.txt");
    if (arquivo.is_open())
    {
        string nome;
        int numeroTitulo;
        // ler a linha inteira com os parametros e >> para separar em variaveis
        while (arquivo >> nome >> numeroTitulo)
        {
            Eleitor *novoEleitor = new Eleitor;
            novoEleitor->nome = nome;
            novoEleitor->numeroTitulo = numeroTitulo;
            novoEleitor->proximo = 0;

            if (listaEleitor == 0)
            {
                listaEleitor = novoEleitor;
            }
            else
            {
                Eleitor *atual = listaEleitor;
                while (atual->proximo != 0)
                {
                    atual = atual->proximo;
                }
                atual->proximo = novoEleitor;
            }
        }
        arquivo.close();
        cout << "Eleitores carregados com sucesso!" << endl;
    }
    else
    {
        cout << "N�o foi poss�vel abrir o arquivo." << endl;
    }
}

// Fun��o para salvar os eleitores em arquivo
void salvarEleitores()
{
    ofstream arquivo("eleitor.txt");
    if (arquivo.is_open())
    {
        Eleitor *atual = listaEleitor;
        while (atual != 0)
        {
            arquivo << atual->nome << " " << atual->numeroTitulo << " " << endl;
            atual = atual->proximo;
        }
        arquivo.close();
        cout << "Eleitores carregadors com sucesso!" << endl;
    }
    else
    {
        cout << "N�o foi poss�vel carregar os eleitores!" << endl;
    }
}

// Fun��o para verificar se um eleitor est� apto para votar pelo n�mero do t�tulo
bool verificarEleitorApto(int numeroTitulo)
{
    Eleitor *atual = listaEleitoresAptos;
    while (atual != 0)
    {
        if (atual->numeroTitulo == numeroTitulo)
        {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

// Fun��o para liberar a mem�ria alocada pela lista de eleitores aptos
void liberarMemoriaEleitoresAptos()
{
    Eleitor *atual = listaEleitoresAptos;
    while (atual != 0)
    {
        Eleitor *proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
}

// blablabla
