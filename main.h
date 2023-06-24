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

// zerar lista candidatos e declara
Candidato* listaCandidatos = 0;

// zerar lista eleitores aptos e declara
Eleitor* listaEleitoresAptos = 0;

// zera a lista dos votos e declara
Eleitor* listaEleitor = 0;

// zera a lista dos votos e declara
Voto* listaVotos = 0;
Voto* numeroCandidato = 0;
Eleitor* filaEleitores = NULL;


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
            cout << "| Nome: " << atual->nome << " | Numero: " << atual->numero << " |" << endl;
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


// Funcao para salvar os eleitores em arquivo
void salvarEleitores()
{
    ofstream arquivo("eleitor.txt");
    if (arquivo.is_open())
    {
        Eleitor *atual = filaEleitores;
        while (atual != NULL)
        {
            arquivo << atual->nome << " " << atual->numeroTitulo << endl;
            atual = atual->proximo;
        }
        arquivo.close();
        cout << "Eleitores carregadors com sucesso!" << endl;
    }
    else
    {
        cout << "Nao foi possivel carregar os eleitores!" << endl;
    }
}

// Função para exibir os votos registrados
void exibirVotosRegistrados() {
    ifstream arquivoVotos("votos.txt");
    if (arquivoVotos.is_open()) {
        string linha;
        while (getline(arquivoVotos, linha)) {
            cout << linha << endl;
        }
        arquivoVotos.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo de votos." << endl;
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
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }
}

// Funcao para liberar a memï¿½ria alocada pela lista de candidatos
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

// Funcao para inserir um eleitor apto na lista
void inserirEleitorApto()
{
    Eleitor *novoEleitor = new Eleitor;
    cout << "Nome do eleitor: ";
    cin >> novoEleitor->nome;
    cout << "Numero do titulo de eleitor: ";
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

// Funcao para carregar os candidatos do arquivo
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
            novoEleitor->proximo = NULL;

            if (filaEleitores == NULL)
            {
                filaEleitores = novoEleitor;
            }
            else
            {
                Eleitor *atual = filaEleitores;
                while (atual->proximo != NULL)
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
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }
}


// Funcao para verificar se um eleitor estï¿½ apto para votar pelo nï¿½mero do tï¿½tulo
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

// Funcao para liberar a memoria alocada pela lista de eleitores aptos
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

//registrar voto ja conferido se true na conferencia
void votacao() 
{
	int numeroTitulo;
	int numeroCandidato;
	cout << "Digite o numero do titulo de eleitor";
	cin >> numeroTitulo;
	
	if (!verificarEleitorApto(numeroTitulo)) {
                	cout << "Eleitor não apto para votar." << endl;
                return; 	
	}
	
	cout << "---------------------------------------------------";
	cout << "*************** Lista de candidatos ***************";
	cout << "---------------------------------------------------";
	Candidato* atual = listaCandidatos;
	
	while(atual != NULL){
		cout << "Digite o numero do candidato: ";
		cin >> numeroCandidato;		
	}
	
	Voto* novoVoto = new Voto;
	novoVoto->numeroTitulo = numeroTitulo;
	novoVoto->numeroCandidato = numeroCandidato;
	novoVoto->proximo = NULL;
	
	if(listaVotos == NULL){
		listaVotos = novoVoto;
	}else{
		Voto* atual = listaVotos;
		while (atual->proximo != NULL){
			atual = atual->proximo;
		}
		
	}
	atual = listaCandidatos;
	
	cout << "Voto efetuado com sucesso!";
}



//gravar relatorio votos
void salvarVotos(){
	ofstream arquivo("votos.txt");
	if(arquivo.is_open()){
		arquivo << "Relatorio de votos por candidatos:";
		Candidato* atualCandidato = listaCandidatos;
		while(atualCandidato != 0){
			arquivo << "| Numero: " << atualCandidato->numero << " | Nome: " << atualCandidato->nome << " | Votos: " << atualCandidato->numVotos << endl;
		}		
	}
	int totalVotos = 0;
	Voto* atualVoto = listaVotos;
	while (atualVoto != 0){
		totalVotos++;
		atualVoto = atualVoto->proximo;
	}
	arquivo << "Relatorio de Votos" << endl;
	arquivo << "Total de votos: " << totalVotos << endl;
	
	int totalEleitores = 0;
        int totalEleitoresAptos = 0;
        Eleitor* atualEleitorApto = listaEleitoresAptos;
        while (atualEleitorApto != NULL) {
            totalEleitoresAptos++;
            atualEleitorApto = atualEleitorApto->proximo;
        }
        Eleitor* atualEleitor = listaEleitor;
        while (atualEleitor != NULL) {
            totalEleitores++;
            atualEleitor = atualEleitor->proximo;
        }
        int eleitoresFaltantes = totalEleitoresAptos - totalEleitores;
        arquivo << "Relatório de eleitores faltantes:" << endl;
        arquivo << "Total de eleitores faltantes: " << eleitoresFaltantes << endl;

        arquivo.close();
        cout << "Relatório salvo com sucesso!" << endl;
    }

void exibirVotos() {
    ifstream arquivoVotos("votos.txt");
    if (arquivoVotos.is_open()) {
        string linha;
        while (getline(arquivoVotos, linha)) {
            cout << linha << endl;
        }
        arquivoVotos.close();
    } else {
        cout << "Nao foi possivel abrir o arquivo de votos." << endl;
    }
}


// blablabla
