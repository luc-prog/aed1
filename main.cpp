#include<iostream>//Biblioteca para manipulação fluxo de dados entrada e saída
#include<clocale>//Biblioteca especializada para manipular caracteres especiais de cada regiao
#include<fstream>//Biblioteca responsavel para fluxo de dados com arquivos entrada e saída
#include<cstdlib>//Biblioteca especializada em controle de processos do código
#include<sstream>//Biblioteca usada para converter variavel string para inteiro

using namespace std; //define as funçoes da biblioteca padrão

int contador(){//Soma as unidades no estoque da biblioteca

    fstream arqU;//Permite a manipulação de arquivos
    string uni[20];//Armazena as informações do arquivo
    int c,n,total=0;//variaveis de números inteiros
    c=n=total=0;// Atualização das variaveis para 0

    arqU.open("Unidades.txt",ios::in);//Abertura do arquivo com o comando de saida
    if(arqU.is_open()){//Verificação se o arquivo foi aberto
        while(!arqU.eof()){//Condição de parada quando chegar na utlima linha do arquivo
            getline(arqU,uni[c]);//Armazena as informações no vetor
            c++;//Variavel que permite a troca do indice do vetor
        }
        arqU.close();//fecha o arquivo
    }
    else{//Caso o arquivo não abra ira entrar neste bloco
            cout<<"Erro na abertura do programa!";
            return 1;//Retorna 1 para função caso de erro na abertura do aquivo
    }
    for(int i=0;i<c-1;i++){//loop para a soma dos valores no vetor
        stringstream geek(uni[i]);//Converte o string para um numero inteiro
        geek >> n;
        total= total+n;
    }
    return total;
}

int atualizacao(string uni[],int i,int c,string nom){//função especializada na atualização das unidades de obras no acervo

    fstream arqU;
    int vetUni[20];

    for(int n=0;n<c-1;n++){//roda o vetor de unidades e tranformar os números string em inteiros
        stringstream geek(uni[n]);//função geek responsavel por conveter os dados dos arquivos string para um inteiro caso possivel
        geek>>vetUni[n];//vetor recebe no determinado índice o valor convertido
    }
    if(vetUni[i]==0){//verifica se o livro esta com unidades 0 ou seja não possui exemplares para doação
        system("CLS");
        cout<<"\n=========Livro esgotado!"<<endl;
        system("pause");//caso pausa o programa ate ser apertado alguma tecla
    }
    else{//caso possuir mais de 0 unidades
        vetUni[i]=vetUni[i]-1;//ira dimiuir 1 no valor do vetor
        arqU.open("Unidades.txt",ios::out);//abre o arquivo no modo trunc ou seja ira reescrever os dados contidos nele
        if(arqU.is_open()){//verifica se foi aberto
            for(int n=0;n<c-1;n++){//laço de repetição para armazenar os dados atualizados no arquivo
                arqU<<vetUni[n]<<"\n";
            }
            arqU.close();//fecha o arquivo
        }
        else{//caso nçao abra o arquivo
            cout<<"Erro ao abrir arquivo!"<<endl;
            return 1;//caso de erro na execução retornara esse valor
        }
    system("CLS");
    cout<<endl;
    cout<<"===="<<nom<<" obrigado por fazer parte da comunidade Zaratustra!"<<endl;
    cout<<"Esperamos que tenha longas aventuras com o seu novo livro!"<<endl<<endl;
    }
    system("pause");
    return 0;//caso ocorra tudo certo retornara esse valor
}
void cadPedido(string livro[],string autor[],string editora[],string cod[],string nom,string uni[],int c){//procedimento especilizado na sáida dos dados dos vetores e na chamda da função para alterar a unidade da obra escolhida

    system ("CLS");
    int i;

        cout<<" ====>Escolha algum livro<===="<<endl<<endl;
        for(i=0;i<c-1;i++){//mostra os dados lidos do arquivo
                cout<<i<<" - Obra: "<<livro[i]<<endl;
                cout<<"- Autor: "<<autor[i]<<endl;
                cout<<"- Editora: "<<editora[i]<<endl;
                cout<<"- Código: "<<cod[i]<<endl<<endl;
    }
        i=0;
       cout<<"Digite o número da obra: ";
       cin >> i;//le o índice para alterar os dados contido nele
       atualizacao(uni,i,c,nom);//chama a função que altera o valor dos indices
}
int pedido(string nom){//função destinada na doção da obra escolhida pelo usuário

    system ("CLS");

    string livro[20],autor[20],editora[20],cod[20],uni[20];//vetores que irao carregar os dados dos arquivos
    fstream arqL,arqA,arqE,arqC,arqU;
    int c=0;

    arqL.open("Livros.txt",ios::in);//abertura dos arquivos com modo de saída de dados
    arqA.open("Autor.txt",ios::in);
    arqE.open("Editora.txt",ios::in);
    arqC.open("Codigo.txt",ios::in);
    arqU.open("Unidades.txt",ios::in);
    if(arqL.is_open() &arqA.is_open() &arqE.is_open() &arqC.is_open() &arqU.is_open()){//verifica se foram abertos
        while(!arqL.eof()){
            getline(arqL,livro[c]);//armazena os dados da linha no vetor correspondente
            getline(arqA,autor[c]);
            getline(arqE,editora[c]);
            getline(arqC,cod[c]);
            getline(arqU,uni[c]);
            c++;
        }
        arqL.close();//fecha o arquivo
        arqA.close();
        arqE.close();
        arqC.close();
        arqU.close();
    }else{
        cout<<"Arquivo não aberto!\n";
        return 1;
    }
    cadPedido(livro,autor,editora,cod,nom,uni,c);//chama a função que ira mostrar os livros disponiveis a serem escolhidos carregando as informações nos vetores
    return 0;
}
int livros(){//mostra os livros no estoque do acervo

    system ("CLS");

    fstream arqL,arqA,arqE,arqC;
    char opc='n';
    int c=0;
    string livro[20],autor[20],editora[20],cod[20];

    while(opc=='n'||opc=='N'){
        arqL.open("Livros.txt",ios::in);//abre os arquivos correspondentes
        arqA.open("Autor.txt",ios::in);
        arqE.open("Editora.txt",ios::in);
        arqC.open("Codigo.txt",ios::in);

            if(arqL.is_open() &arqA.is_open() &arqE.is_open() &arqC.is_open()){//verifica a abertura dos arquivos
                cout<<"======Obras disponiveis====="<<endl<<endl;
                while(!arqL.eof()){//enquanto nçao chegar no final da linha
                    getline(arqL,livro[c]);//ira armazanr os dados de cada linha no vetor declarado com determinado índice
                    getline(arqA,autor[c]);
                    getline(arqE,editora[c]);
                    getline(arqC,cod[c]);
                    c++;//variavel contadora índice do vetor
                }
                arqL.close();//fecha o arquivo
                arqA.close();
                arqE.close();
                arqC.close();
                for(int i=0;i<c-1;i++){//mostra os livros cadastrados no acervo
                    cout<<i<<" - Obra: "<<livro[i]<<endl;
                    cout<<"- Autor: "<<autor[i]<<endl;
                    cout<<"- Editora: "<<editora[i]<<endl;
                    cout<<"- Código: "<<cod[i]<<endl<<endl;;
                }
            }else{
                cout<<"Erro Desconhecido!\n";
                return 1;
            }
            cout<<"\nPara voltar: [s]";
            cin >> opc;
        }
        return 0;
}
void menusuario(string nom){//um menu que ira permitir o usuário fazer modificações no programa

    int opc=1;//condição de parada
    char opc2='a';//para acessar outros procedimentos e funções
    int limit=0;//um limitador de entrada por vez de execução

    while(opc!=0){
        system ("CLS");
        cout<<"====O acervo Zaratustra conta com um total de "<<contador()<<" obras!====="<<endl;//chama função de contadora de unidades
        cout<<endl;
        cout<<"====>Olá "<<nom<<" :)"<<endl<<endl;//mostra o nome do usuário cadastrado
        cout<<"   ====>Escolha a opção<===="<<endl;
        cout<<"     1 - Mostrar livros"<<endl;
        cout<<"     2 - Pegar livro "<<endl;
        cout<<"     0 - Voltar"<<endl;
        cout<<"========================"<<endl;
        cin >> opc;

        switch(opc){//veirifica o caso escolhido e entra no laço correpondente
            case 1:
                cout<<"=====Continuar?[s/n]";
                cin>>opc2;
                if(opc2=='S'||opc2=='s'){
                    livros();//chama a função livro onde sao mostrados
                }
                break;
            case 2:
                if(limit==0){
                    cout<<"=====Continuar?[s/n]";
                    cin>>opc2;
                    if(opc2=='S'||opc2=='s'){
                        pedido(nom);//chama a função destinada na doação do livro
                        limit=1;//o usuário so pode acessar essa alternativa uma unica vez logado na seccão
                    }
                }else{
                    system("CLS");
                    cout<<nom<<" Leia o seu livro para buscar outro :)"<<endl<<endl;
                    system("pause");
                }
                break;
            case 0:
                cout<<"Voltando..."<<endl;
                break;
            default:
                cout<<"Opção inválida!"<<endl;
                break;
        }
    }
}
int usuario(){//função que verifica os arquivos usuario.txt para liberar o "login" no programa

    system("CLS");

    fstream arq;
    string vetN[10],vetS[10];//vetor que ira armazenar os nomes e a senhas dos usuários cadastrados
    string nom,senha;
    int c,s;

    arq.open("cadastro.txt",ios::in);
    if(arq.is_open()){
        c=0;
        while(!arq.eof()){
            getline(arq,vetN[c]);
            getline(arq,vetS[c]);
            c++;
        }
        arq.close();
        cout<<"=====Login====="<<endl;
        cout<<"Nome: ";
        cin.ignore();
        getline(cin,nom);
        cout<<"Senha: ";
        cin >> senha;
        for (int i=0;i<c-1;i++){
            if(nom==vetN[i]&&senha==vetS[i]){//veirifica se o nome e a senha digitado pelo usáriario é coerente com os encotrados no arquivo
                menusuario(nom);//chama o procedimento e leva o nome do usário como referencia
                s=-2;
            }
        }
        if(s!=-2){
            cout<<"Usuário não encontrado!"<<endl;
            system("Pause");
        }
    }
    else{
        cout<<"Erro ao abrir arquivo!";
        return 1;
    }
    return 0;
}

//Blocos destinados para realizar funçoes na area do bibliotecario

int  exclusaoC(string usuario2[],string senha[],int c){//Funçao para excluir usuarios cadastrados

    fstream  arqL;
    int  n;

    cout<<"Digite um número do usuário a ser excluído: ";
    cin>>n;
    arqL.open("cadastro.txt",ios::out);
        if(arqL.is_open()){
            for(int i=0;i<c-1;i++){
                if(usuario2[i]!=usuario2[n]){
                    arqL<<usuario2[i]<<"\n";
                    arqL<<senha[i]<<"\n";
                }
            }
        }
        else{
            cout<<"Erro ao abrir arquivo!"<<endl;
            return 1;
        }
        arqL.close();
        cout<<"Exclusão Feita!"<<endl;
    return 0;
}
int edClient(string usuario2[],string senha[],int c){//depedente do procedimento edicaoclient usado para modificar os arquivos que contem os dados do cliente

    fstream arqL;

    char opc;
    int i,opc2;

    for(i=0;i<c-1;i++){
        cout<<i<<" - Usuário: "<<usuario2[i]<<endl;
        cout<<"- Senha: "<<senha[i]<<endl<<endl;
    }
    cout<<"Deseja Editar algo?[s/n]"<<endl;
    cin >> opc;
    while(opc=='s'||opc=='S'){
        cout<<"=====>Escolha opção<====="<<endl;
        cout<<"    1 - Editar usuário"<<endl;
        cout<<"    2 - Excluir usuário"<<endl;
        cout<<"    0 - Voltar"<<endl;
        cout<<"======================="<<endl;
        cin>>opc2;

        switch(opc2){
            case 1:
                i=0;
                cout<<"\nInforme o número do cliente a ser editado: ";
                cin>> i;
                system("CLS");
                cout<<"  \n======Informe os novos dados======= "<<endl;
                cout<<"Nome: ";
                cin.ignore();
                getline(cin,usuario2[i]);
                cout<<"Senha: ";
                getline(cin,senha[i]);

                arqL.open("cadastro.txt",ios::out);
                if(arqL.is_open()){
                    for(i=0;i<c-1;i++){
                        arqL<<usuario2[i]<<"\n";
                        arqL<<senha[i]<<"\n";
                    }
                    cout<<"Edição Concluida!"<<endl;
                }
                else{
                    cout<<"Erro ao abrir arquivo!"<<endl;
                    return 1;
                }
                arqL.close();
                break;
            case 2:
                exclusaoC(usuario2,senha,c);
                break;
            case 0:
                opc='n';
                break;
            default:
                cout<<"Não encontrei essa opçao!"<<endl;
                break;
        }
        opc='n';
    }
    return 0;
}
void edicaoclient(){//procedimento que ira chamar a função que modifica os dados dos usuários no arquivo

    system ("CLS");

    fstream arqL;
    string usuario2[20],senha[20];
    char opc='n';
    int c=0;

    while(opc=='n'||opc=='N'){
        arqL.open("cadastro.txt",ios::in);
        if(arqL.is_open()){
            cout<<"======Edição=====\n"<<endl;
            while(!arqL.eof()){
                getline(arqL,usuario2[c]);
                getline(arqL,senha[c]);
                c++;
            }
            arqL.close();
        }else{
            cout<<"Arquivo não aberto!\n";
        }
            edClient(usuario2,senha,c);//chama a função e carrega os vetores com os dados sobrepostos
            cout<<"\nPara voltar: [s]";
            cin >> opc;
    }
}
int cadClient(string matU[][1]){//função que ira armazenar os cadastro dos usuários

    fstream arq;

    arq.open("cadastro.txt",ios::app|ios::out);//abre o arquivo com modo de entrada de dados e usa a função para ser escrito linha em baixo de linha
    if(arq.is_open()){//verifica se o arquivo foi aberto
        arq<<matU[0][0]<<"\n";//armazena os dados
        arq<<matU[1][0]<<"\n";
    }
    else{//caso de erro na abertura do arquivo
        cout<<"Erro ao abrir Arquivo"<<endl;
        return 1;
    }
    arq.close();//fecha o arquivo
    return 0;
}
void client(){//procedimento que cadastra usuários no arquivo

    system ("CLS");//limpa terminal

    char s = 'n';//condição de parada
    string matU[2][1];

    cout<<"=======Cadastro de usuários========="<<endl;
    while(s=='n'||s=='N'){
        cout<<"Informe o nome do usuário: ";
        cin.ignore();//caso se de um ( ESPAÇO) ele lê toda a linha
        getline(cin,matU[0][0]);
        cout<<"Informe a senha: ";
        cin>>matU[1][0];

        cadClient(matU);// chama a função, e manda a matriz com os dados que serão armazenados nos arquivos
        cout<<"Cadastro realizado com sucesso!"<<endl;
        cout<<"Deseja sair?[s/n]";
        cin>>s;
    }
}

int exclusao(string livro[],string autor[],string editora[],string uni[],string cod[],int c){
    fstream arqL,arqA,arqE,arqU,arqC;
    int i;

        cout<<"\nInforme o número do dado a ser excluido: ";
        cin>>i;//leitura do indice do vetor
        livro[i]="0";

        arqL.open("Livros.txt",ios::out);//abre o arquivo com modo de entrada e com modo trunc apaga os dados contidos no arquivo e reescreve novos
        arqA.open("Autor.txt",ios::out);
        arqE.open("Editora.txt",ios::out);
        arqU.open("Unidades.txt",ios::out);
        arqC.open("Codigo.txt",ios::out);
        if(arqL.is_open() &arqA.is_open() &arqE.is_open() &arqU.is_open() &arqC.is_open()){//verifica se arquivo foi aberto
            for(i=0;i<c-1;i++){
                if(livro[i]!="0"){
                    arqL<<livro[i]<<"\n";//alimenta o arquivo com os dados modificados
                    arqA<<autor[i]<<"\n";
                    arqE<<editora[i]<<"\n";
                    arqU<<uni[i]<<"\n";
                    arqC<<cod[i]<<"\n";
                }
            }
        }
        else{//caso de erro na abertura dos arquivos
            cout<<"Erro ao abrir arquivo!"<<endl;
            return 1;
        }
        arqL.close();//fecha arquivo
        arqA.close();
        arqE.close();
        arqU.close();
        arqC.close();
        system("CLS");
        return 0;
}
int edArqUni(string uni[],int c){//depedente da função edArq usada apenas para alterar unidades de livros

    fstream arqU;
    int i;

    cout<<"\nInforme o número do dado a ser editado as unidades: ";
    cin>>i;//pega o índice do vetor
    system("CLS");
    cout<<"  \n======Informe os novos dados======= "<<endl;
    cout<<"Unidades: ";
    cin>>uni[i];//reescreve com as novas unidades

    arqU.open("Unidades.txt",ios::out);//abre o arquivo com modo de entrada e trunc, apaga e reescreve os dados
    if(arqU.is_open()){//verifica se o arquivo foi aberto
        for(i=0;i<c-1;i++){//armazena os dados varivel c é usada nos blocos anteriores para contar as linhas e a quantidade de dados anteriomente armazenados
            arqU<<uni[i]<<"\n";
        }
    }
    else{
        cout<<"Erro ao abrir arquivo!"<<endl;
        return 1;//retorno 1 caso de erro
    }
    arqU.close();//fecha o arquivo
    return 0;//retorna 0 caso ocorra tudo certo
}
int edArq(string livro[],string autor[],string editora[],string uni[],string cod[],int c){//função depedente do procedimento edição realiza modifiaçoes no aquivo.txt

    fstream arqL,arqA,arqE,arqU,arqC;
    int i,opc2;
    char opc;


    i=0;
    cout<<"Deseja editar algo?[s/n]"<<endl;//verificação para entrar no laço de repetição
    cin >> opc;
    while(opc=='s'||opc=='S'){
        cout<<"=========>Escolha a opção<========="<<endl;
        cout<<"     1 - Alterar um dado por completo"<<endl;
        cout<<"     2 - Alterar apenas as unidades"<<endl;
        cout<<"     3 - Excluir algum dado"<<endl;
        cout<<"     0 - voltar"<<endl;
        cout<<"================================="<<endl;
        cin>>opc2;//leitura do caso para ser usado no switch
        system("CLS");
        for( i=0;i<c-1;i++){//mostra o indice do vetor para ser escolhido
            cout<<i<<" - Obra: "<<livro[i]<<endl;
            cout<<"- Autor: "<<autor[i]<<endl;
            cout<<"- Editora: "<<editora[i]<<endl;
            cout<<"- Unidades: "<<uni[i]<<endl;
            cout<<"- Código: "<<cod[i]<<endl<<endl;;
        }
        switch(opc2){
            case 1:
                cout<<"\nInforme o número do dado a ser editado: ";
                cin>>i;//leitura do indice do vetor
                system("CLS");
                cout<<"  \n======Informe os novos dados======= "<<endl;
                cout<<"Digite o nome da obra: ";//ira modificar o indice escolhido do vetor ou seja os dados contidos nele
                cin.ignore();
                getline(cin,livro[i]);
                cout<<"Autor: ";
                getline(cin,autor[i]);
                cout<<"Editora: ";
                getline(cin,editora[i]);
                cout<<"Unidades: ";
                cin>>uni[i];
                cout<<"Código: ";
                cin>>cod[i];// ate nesse ponto

                arqL.open("Livros.txt",ios::out);//abre o arquivo com modo de entrada e com modo trunc apaga os dados contidos no arquivo e reescreve novos
                arqA.open("Autor.txt",ios::out);
                arqE.open("Editora.txt",ios::out);
                arqU.open("Unidades.txt",ios::out);
                arqC.open("Codigo.txt",ios::out);
                if(arqL.is_open() &arqA.is_open() &arqE.is_open() &arqU.is_open() &arqC.is_open()){//verifica se arquivo foi aberto
                    for(i=0;i<c-1;i++){
                        if(uni[i]!="0"){
                            arqL<<livro[i]<<"\n";//alimenta o arquivo com os dados modificados
                            arqA<<autor[i]<<"\n";
                            arqE<<editora[i]<<"\n";
                            arqU<<uni[i]<<"\n";
                            arqC<<cod[i]<<"\n";
                        }
                    }
                }
                else{//caso de erro na abertura dos arquivos
                    cout<<"Erro ao abrir arquivo!"<<endl;
                    return 1;
                }
            arqL.close();//fecha arquivo
            arqA.close();
            arqE.close();
            arqU.close();
            arqC.close();
            break;
        case 2:
            edArqUni(uni,c);//chama a função que apenas altera as unidades dos livros
            break;
        case 3:
            exclusao(livro,autor,editora,uni,cod,c);
        case 0:
                opc='n';
            break;
        default:
            cout<<"Opção invalida!"<<endl;
        }
        opc='n';
    }
    return 0;
}
void edicao(){//procedimento que ira editar os dados dos arquivos livros

    system ("CLS");

    fstream arqL,arqA,arqE,arqU,arqC;
    string livro[20],autor[20],editora[20],uni[20],cod[20];
    char opc='n';
    int c=0;

    while(opc=='n'||opc=='N'){
        arqL.open("Livros.txt",ios::in);//abre o arquivo no modo de saída de dados
        arqA.open("Autor.txt",ios::in);
        arqE.open("Editora.txt",ios::in);
        arqU.open("Unidades.txt",ios::in);
        arqC.open("Codigo.txt",ios::in);
        if(arqL.is_open() &arqA.is_open() &arqE.is_open() &arqU.is_open() &arqC.is_open()){
            cout<<"============Edição===========\n"<<endl;
            while(!arqL.eof()){
                getline(arqL,livro[c]);
                getline(arqA,autor[c]);
                getline(arqE,editora[c]);
                getline(arqU,uni[c]);
                getline(arqC,cod[c]);
                c++;
            }
            arqL.close();
            arqA.close();
            arqE.close();
            arqU.close();
            arqC.close();
        }else{
            cout<<"Arquivo não aberto!\n";
        }
        edArq(livro,autor,editora,uni,cod,c);//chama função para edição do arquivo os vetores carregam os dados lidos do arq correspondente
        cout<<"Concluido!"<<endl;
        cout<<"Para voltar: [s]";
        cin >> opc;
    }
}
void saidaDados(){//Procedimento especializado na leitura do arquivo livros.txt

      system ("CLS");//limpa terminal

     fstream arqL,arqA,arqE,arqU,arqC;
     string livro[20],autor[20],editora[20],uni[20],cod[20];//serão usados para armazenar os dados dos arquivos
    char opc='n';//condição de parada
    int c=0;//atualização variável

    while(opc=='n'||opc=='N'){
        arqL.open("Livros.txt",ios::in);//abertura do arquivo correspondente
        arqA.open("Autor.txt",ios::in);
        arqE.open("Editora.txt",ios::in);
        arqU.open("Unidades.txt",ios::in);
        arqC.open("Codigo.txt",ios::in);
        if(arqL.is_open() &arqA.is_open() &arqE.is_open() &arqU.is_open() &arqC.is_open()){//verifica se o arquivo foi aberto
            cout<<"======Obras cadastradas====="<<endl;
            while(!arqL.eof()){//Enquanto o arquivo não chegar na ultima linha
                getline(arqL,livro[c]);//le e manda os dados escrito para os vetores em  suas pocições
                getline(arqA,autor[c]);
                getline(arqE,editora[c]);
                getline(arqU,uni[c]);
                getline(arqC,cod[c]);
                c++;//varivel contadora
            }
            arqL.close();//fecha o arquivo
            arqA.close();
            arqE.close();
            arqU.close();
            arqC.close();
            for(int i=0;i<c-1;i++){//saida dos dados salvos nos vetores
                cout<<i<<" - Obra: "<<livro[i]<<endl;
                cout<<"- Autor: "<<autor[i]<<endl;
                cout<<"- Editora: "<<editora[i]<<endl;
                cout<<"- Unidades: "<<uni[i]<<endl;
                cout<<"- Código: "<<cod[i]<<endl<<endl;;
            }
        }else{//caso de erro na abertura do arquivo
            cout<<"Erro Desconhecido!\n";
        }
        cout<<"\nPara voltar: [s]";//verifica a condição de parada
        cin >> opc;
    }
}
int cadArq(string matDados[][5]){//Funçao depedente do procedimento entradaDados usada para cadastar novas obras no arquivo

    fstream arqL,arqA,arqE,arqU,arqC;//declaração das variáveis para manipular os arqueivos

    arqL.open("Livros.txt",ios::app|ios::out);//abre o .txt correspondente com a função de entrada de dados, e com o modo de escrita embaixo do \n
    arqA.open("Autor.txt",ios::app|ios::out);
    arqE.open("Editora.txt",ios::app|ios::out);
    arqU.open("Unidades.txt",ios::app|ios::out);
    arqC.open("Codigo.txt",ios::app|ios::out);
    if(arqL.is_open() &arqA.is_open() &arqE.is_open() &arqU.is_open() &arqC.is_open()){//verifica se o arquivo doi aberto
        arqL<<matDados[0][0]<<"\n";//armazena os dados no arqueivo correspondente
        arqA<<matDados[0][1]<<"\n";
        arqE<<matDados[0][2]<<"\n";
        arqU<<matDados[0][3]<<"\n";
        arqC<<matDados[0][4]<<"\n";
    }
    else{//caso o arquivo não abra
        cout<<"Erro ao abrir arquivo!"<<endl;
        return 1;//retorna 1 caso de erro
    }
    arqL.close();//fecha o arquivo
    arqA.close();
    arqE.close();
    arqU.close();
    arqC.close();
    return 0;//se a função funcionar corretamente ira retornar 0

}
void entradaDados(){//Procedimento especializado no preenchimento do arquivo livros.txt

    system("CLS");//limpa terminal do windows

    string matDados[1][5];//matriz que ira carregar os dados para o arquivo
    char opc='s';//variavel para cond de parada

    while(opc=='s'||opc=='S'){//laço de repetição
        cout<<"===Cadastro de Livros===\n";
        cout<<"Digite o nome da obra: ";
        cin.ignore();
        getline(cin,matDados[0][0]);//carrega o nome do livro
        cout<<"Autor: ";
        getline(cin,matDados[0][1]);//autor
        cout<<"Editora: ";
        getline(cin,matDados[0][2]);//Editora
        cout<<"Unidades: ";
        cin>>matDados[0][3];//Unidades
        cout<<"Código: ";
        cin>>matDados[0][4];//Código

        cadArq(matDados);//chama e função e manda os dados na matriz
        cout<<"\nCadastar nova obra?[s/n]";
        cin >> opc;//Verificação da cond de parada
        system("CLS");//limpa terminal
    }
}
void menuAcervo(){//menu para realizar modificaçoes

    system("CLS");//Limpa terminal do windows

    string senha;//varivel para entrar no laço if

    //cout<<"=====>Informe a senha do acervo para liberar: ";
    //cin >> senha;
    //if(senha=="1234"){//Para entrar nesta condição digite a senha 1234
        int opc;//Condição de parada
        char opc2='Z';//Para verificar se  o caso deve continuar o processo

        while(opc!=0){
            system("CLS");//limpa terminal do windows
            cout<<"====>Possuimos um total de "<<contador()<<" obras!"<<endl;//Chama a função especializada na contagem  dos livros
            cout<<"==============================="<<endl;
            cout<<"     Acervo Zaratustra"<<endl;//Saída com o nome da biblioteca
            cout<<"==============================="<<endl;
            cout<<" =====>Escolha a opção<=====\n";
            cout<<"   1 - Cadastro de livros\n";
            cout<<"   2 - Livros cadastrados\n";
            cout<<"   3 - Edição do acervo\n";
            cout<<"   4 - Cadastro de usuários\n";
            cout<<"   5 - Edição de usuários\n";
            cout<<"   0 - Voltar\n";
            cout<<"=============================="<<endl;
            cin >> opc;

            switch(opc){//verifica o valor da varivel entra no caso correspondente
                case 1:
                    cout<<"=====Continuar?[s/n]";
                    cin>>opc2;
                    if(opc2=='S'||opc2=='s'){
                        entradaDados(); //Chama o procedimento especilizado em cadastro
                    }
                    break;
                case 2:
                    cout<<"=====Continuar?[s/n]";
                    cin>>opc2;
                    if(opc2=='S'||opc2=='s'){
                       saidaDados() ;//Chama o procedimento especilizado na leitura das obras
                    }
                    break;
                case 3:
                    cout<<"=====Continuar?[s/n]";
                    cin>>opc2;
                    if(opc2=='S'||opc2=='s'){
                       edicao() ;//Chama o procedimento especilizado na edição dos livros
                    }
                    break;
                case 4:
                    cout<<"=====Continuar?[s/n]";
                    cin>>opc2;
                    if(opc2=='S'||opc2=='s'){
                       client() ;//Chama o procedimento especilizado no cadastro de usuários
                    }
                    break;
                case 5:
                     cout<<"=====Continuar?[s/n]";
                    cin>>opc2;
                    if(opc2=='S'||opc2=='s'){
                        edicaoclient();//cham o procedimento especializado na edição dos usuários
                    }
                case 0:
                    cout<<"Estou voltando...";
                    break;
                default:
                    cout<<"Opção invalida!";
                    system("Pause");//pausa o programa ate ser digitado uma tecla
                break;
            //}
        }
    }
    //else{//caso a senha 1234 seja errada
      //  cout<<"Senha invalida!"<<endl;
        //system("pause");
    //}
}

void menuInicial(){//procidimento inicial do programa

    int opc=1;//Variavel especializada na condicao de parada

    while(opc!=0){
        system ("CLS");//Limpa terminal do windows
        cout<<"============================" <<endl;
        cout<<"         Acervo Zaratustra"<<endl;
        cout<<"============================"<<endl;
        cout<<" ====> Escolha a opção <===="<<endl;
        cout<<"     1 - Área usuários"<<endl;
        cout<<"     2 - Área Bibliotecário"<<endl;
        cout<<"     0 - Encerrar"<<endl;
        cout<<"==========================="<<endl;
        cin >> opc;//Atualização de condição de parada

        switch(opc){
            case 1:
                usuario();
                break;
            case 2:
                menuAcervo();//Chama o procedimento do Acervo
                break;
            case 0:
                cout<<"Estou Saindo..."<<endl;
                break;
            default:
                cout<<"Não encontrei essa opção!"<<endl;
                system ("pause");
                break;
        }
    }
}

int main(){//Função principal

    setlocale(LC_ALL,"Portuguese");//Define caracteres para regiao da lingua portuguesa
    menuInicial();//Chamada do procedimento inicial
    return 0;
}
