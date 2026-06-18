#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define LIMPAR "cls"
#define SLEEP(x) Sleep((x) * 1000)

int vida = 100;
char nome[100];
int vidaInimigoTroll = 110;
int vidaInimigoGoblin = 80;

void main_jogo();
void banner();
void verVida();
void apresentar();
void sala1_Comeco();
void sala2_Floresta();
void sala3_Caverna();
void sala_CorredorFedido();
void sala_CorredorLuz();
void batalha_Caverna();
void sala4_FimFloresta_InicioAldeia();
void batalha_CaminhoFloresta();
void batalha();
void naAldeia_Final();
void gameOver();

int aleatorio(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void banner(){
    system(LIMPAR);
    printf("\n=====================\n");
    printf("==A GRANDE AVENTURA==\n");
    printf("=====================\n");
}

void verVida() {
    printf("\nSua vida atual é %d/100!", vida);
    SLEEP(3);
}

void apresentar(){
    banner();
    printf("\nBem-vindo(a), jogador(a)!!!");
    printf("\nQual o seu nome?: ");
    scanf("%s", &nome);
    printf("\nPrepare-se %s, sua jornada começa agora!!!");
    SLEEP(5);
}

void sala1_Comeco(){
    char escolhaCaminho;

    banner();
    printf("\n %s, você acorda e vê dois caminhos na sua frente", nome);
    printf("\nUm é uma estrada que se adentra para a floresta");
    printf("\nO outro te leva para dentro de uma caverna escura!");
    printf("\nQual você escolhe: ");
    printf("\n[1] - Floresta    [2] - Caverna    [3] - Ver minha vida\n");
    printf("Digite a sua resposta: ");
    scanf("%c", &escolhaCaminho);

    if (escolhaCaminho == '1'){
        sala2_Floresta();
    } else if (escolhaCaminho == '2'){
        sala3_Caverna();
    } else if (escolhaCaminho == '3'){
        verVida();
        sala1_Comeco();
    } else {
        printf("\nEssa opção não existe!");
        SLEEP(3);
        system(LIMPAR);
        sala1_Comeco();
    }

}

void sala2_Floresta(){
    char escolhaCaminho;

    system(LIMPAR);
    banner();
    printf("\n%s, voce escolheu o caminho que te leva para dentro da floresta!\n", nome);
    printf("\nVoce segue pelo caminho por um tempo, ate que escuta barulhos vindos floresta a dentro;\n");
    printf("\n%s, o que voce faz:\n", nome);
    printf("\n[1] - Seguir o caminho e ignorar os barulhos\n");
    printf("\n[2] - Parar e vasculhar ao redor\n");
    printf("\n[3] - Voltar para tras\n");
    printf("\n[4] - Ver minha vida\n\n");
    printf("\n%s, o que voce faz:\n", nome);
    scanf("%c", &escolhaCaminho);

    if (escolhaCaminho == '1') {
        sala4_FimFloresta_InicioAldeia();
    } else if (escolhaCaminho == '2'){
        batalha_CaminhoFloresta();
    } else if (escolhaCaminho == '3'){
        sala1_Comeco();
    } else if (escolhaCaminho == '4'){
        verVida();
        sala2_Floresta();
    } else {
        printf("\nEssa opção não existe!");
        SLEEP(3);
        system(LIMPAR);
        sala2_Floresta();
    }
}

void sala3_Caverna(){
    char escolhaCaminho;

    system(LIMPAR);
    banner();
    printf("\n%s, voce escolheu entrar dentro da caverna escura!\n", nome);
    printf("\nAssim que voce entra e que seus olhos se acostumam com o escuro,\n");
    printf("\nvoce ve dois corredores a sua frente.\n");
    printf("\nO da esquerda, emite um cheiro muito forte e ruim de fedor.\n");
    printf("\nO da direita, esta quase totalmente escuro, mas emite uma luz bem fraca e bem longe!\n");
    printf("\nQual corredor voce escolhe:\n");
    printf("\n[1] - Corredor Fedido (esquerda)    [2] - Corredor da Luz (direita)    [3] - Ver minha vida\n\n");
    printf("Qual a sua escolha: ");

    scanf("%c", &escolhaCaminho);
    
    if (escolhaCaminho == '1'){
        sala_CorredorFedido();
    } else if (escolhaCaminho == '2'){
        sala_CorredorLuz();
    } else if (escolhaCaminho == '3'){
        verVida();
        sala3_Caverna();
    } else {
        printf("\nEssa opção não existe!");
        system(LIMPAR);
        sala3_Caverna();
    }
}

void sala_CorredorFedido(){
    system(LIMPAR);
    banner();
    printf("\nVoce escolheu seguir pelo corredor que emitia um cheiro muito forte,\n");
    printf("\nconforme voce avanca, o cheiro vai ficando cada vez mais forte!\n");
    printf("\nDe repente, voce tropeca em uma pilha de ossos que esta no chao.\n");
    printf("\nVoce se levanta, olha para frente e ve, na escuridao...\n");
    printf("\ndois olhos, amarelos, te fitando no fundo da sua alma!\n");
    printf("\nDe repente, um Troll enorme avanca em sua direcao!\n");
    printf("\nVoce saca sua espada e se prepara para batalhar!\n");

    SLEEP(5);
    batalha_Caverna();
}

void sala_CorredorLuz(){
    char opcao;
    char escolhaCaminho;

    system(LIMPAR);
    banner();
    printf("\nVoce segue em direcao a luz fraca distante...\n");
    printf("\nConforme voce vai andando, voce percebe que a luz vem de cristais,\n");
    printf("\nque estao nas paredes da caverna!\n");
    printf("\nEm uma pequena camara na caverna, voce encontra um bau no chao!\n");
    printf("\nO que voce faz:\n");
    printf("\n[1] - Abrir o bau    [2] - Ignorar o bau e seguir em frente    [3] - Ver minha vida\n\n");
    printf("O que voce faz?: ");
    scanf("%c", &opcao);

    if (opcao == '1'){
        printf("\nVoce abre o bau com cuidado...\n");
        printf("\nDentro, voce ve uma pocao de cura!!! Sua vida e restaurada para 100!!!\n");
        vida = 100;
        printf("\nAlem disso, ha uma saida no fundo da camara que leva para a Floresta!\n");
        printf("\nO que voce deseja fazer:\n");
        printf("\n[1] - Seguir ate a saida que leva para a Floresta\n");
        printf("\n[2] - Voltar para a entrada da Caverna\n\n");
        printf("O que voce faz?: ");
        scanf("%c", &escolhaCaminho);

        if (escolhaCaminho == '1'){
            sala4_FimFloresta_InicioAldeia();
        } else if (escolhaCaminho == '2'){
            sala3_Caverna();
        } else {
            printf("\nEssas opção não existe!");
            SLEEP(3);
            sala_CorredorLuz();
        }
    } else if (opcao == '2') {
        printf("\nVoce ignora o bau e segue em frente...\n");
        printf("\nVoce encontra uma saida que te leva de volta para a Floresta!\n");
        SLEEP(3);
        sala4_FimFloresta_InicioAldeia();
    } else if ( opcao == '3') {
        verVida();
        sala_CorredorLuz();
    } else {
        printf("\nEssa opção não existe!");
        SLEEP(3);
        sala_CorredorLuz();
    }
}

void batalha_Caverna(){
    system(LIMPAR);
    banner();

    char opcao;
    int danoDado = 0;
    int danoRecebido = 0;

    while (vida > 0 && vidaInimigoTroll > 0) {
        printf("\n=============================================\n");
        printf("\nSEU TURNO:\n");
        printf("\nSua Vida - %d    Troll - %d\n", vida, vidaInimigoTroll);
        printf("\nO que voce deseja fazer:\n");
        printf("\n[1] - Atacar    [2] - Fugir    [3] - Ver minha vida\n\n");
        printf("O que deseja fazer?: ");
        scanf("%c", &opcao);

        if (opcao == '1') {
            danoDado = aleatorio(5, 15);
            vidaInimigoTroll -= danoDado;
            printf("\nVoce deu %d de dano no Troll!!!\n", danoDado);
            SLEEP(2);
            printf("\n=============================================\n");
            printf("\nTURNO DO INIMIGO:\n");
            danoRecebido = aleatorio(4,10);
            vida -= danoRecebido;
            printf("\nTroll te deu %d de dano!!!\n", danoRecebido);
            SLEEP(2);
        } else if (opcao == '2'){
            printf("\nVoce corre de volta pelo corredor, na esperanca de que o Troll nao venha atras!!\n");
            printf("\nVoce volta para a entrada da caverna!\n");
            SLEEP(3);
            sala3_Caverna();
            return;
        } else if ( opcao == '3'){
            verVida();
        } else {
            printf("\nEssa opção não existe!");
        }

        if (vida <= 0) {
            gameOver();
        } else {
            printf("\nIncrivel, voce derrotou o Troll!!!\n");
            printf("\nNo fundo do corredor ha uma saida que te leva a floresta!\n");
            SLEEP(3);
            sala4_FimFloresta_InicioAldeia();
        }
    }
}

void sala4_FimFloresta_InicioAldeia(){
    char escolhaCaminho;

    system(LIMPAR);
    banner();
    printf("\nVoce anda por mais um tempo, ate que voce percebe que a mata esta ficando menos densa,\n");
    printf("\nVoce anda mais um pouco e chega ao final da floresta, onde voce ve uma especie de aldeia!\n");
    printf("\nO que voce faz:\n");
    printf("\n[1] - Seguir e ir ate a aldeia\n");
    printf("\n[2] - Voltar para tras\n");
    printf("\n[3] - Ver minha vida\n\n");
    printf("O que voce faz?: ");
    scanf("%c", &escolhaCaminho);

    if (escolhaCaminho == '1'){
        naAldeia_Final();
    } else if (escolhaCaminho == '2'){
        sala2_Floresta();
    } else if (escolhaCaminho == '3'){
        verVida();
        sala4_FimFloresta_InicioAldeia();
    } else {
        printf("\nEssa opcao nao existe!\n");
        SLEEP(3);
        system(LIMPAR);
        sala4_FimFloresta_InicioAldeia();
    }
}

void batalha_CaminhoFloresta() {
    system(LIMPAR);
    banner();
    printf("\nVoce escolhe investigar os barulhos.\n");
    printf("\nVoce se aproxima da vegetacao de onde escutou barulhos de folhas mexendo, gravetos quebrando e uma especie de grunhidos.\n");
    printf("\nVoce vai se aproximando lentamente, ate que...\n");
    printf("\nVoce ve, em um reflexo, uma figura verde pula em voce, voce desvia e quando volta ao seu estado normal,\n");
    printf("\nvoce ve que a criatura verde era um Goblin!!!\n");
    printf("\nVoce saca a sua espada e se prepara para batalhar...\n");
    SLEEP(5);
    batalha();
}

void batalha(){
    system(LIMPAR);
    banner();

    char opcao;
    char escolhaCaminho;
    int danoDado = 0;
    int danoRecebido = 0;

    while (vida > 0 && vidaInimigoGoblin > 0) {
        printf("\n=============================================\n");
        printf("\nSEU TURNO:\n");
        printf("\nSua vida - %d    Goblin - %d\n", vida, vidaInimigoGoblin);
        printf("\nO que voce deseja fazer:\n");
        printf("\n[1] - Atacar    [2] - Fugir    [3] - Ver minha vida\n\n");
        printf("O que voce deseja fazer?: ");

        scanf("%c", &opcao);

        if (opcao == '1'){
            danoDado = aleatorio(5,15);
            vidaInimigoGoblin -= danoDado;
            printf("\nVoce deu %d de dano no Goblin!\n", danoDado);
            SLEEP(2);
            printf("\n=============================================\n");
            printf("\nTURNO DO INIMIGO:\n");
            danoRecebido = aleatorio(5, 10);
            vida -= danoRecebido;
            printf("\nGoblin te deu %d de dano!\n", danoRecebido);
            SLEEP(2);
        } else if (opcao == '2'){
            printf("\nVoce escolheu fugir!\n");
            printf("\nVoce volta para a Floresta!\n");
            SLEEP(3);
            sala2_Floresta();
            return;
        } else if (opcao == '3') {
            verVida();
        } else {
            printf("\nEssa opção não existe!");
            SLEEP(2);
            system(LIMPAR);
        }
    }

    if (vida <= 0) {
        gameOver();
    } else {
        printf("\nParabens!!! Voce venceu o Goblin!");
        printf("\nVoce continua sua jornada pelo caminho da Floresta,");
        printf("\nVoce anda mais um pouco e chega ao final da floresta, onde voce ve uma especie de aldeia!");
        printf("\nO que voce faz:");
        printf("\n[1] - Seguir e ir ate a aldeia");
        printf("\n[2] - Voltar para tras");
        printf("O que voce faz?: ");

        scanf("%c", &escolhaCaminho);

        if (escolhaCaminho == '1'){
            naAldeia_Final();
        } else if (escolhaCaminho == '2'){
            sala2_Floresta();
        } else {
            printf("\nEssa opção não existe!");
            SLEEP(3);
            system(LIMPAR);
            sala4_FimFloresta_InicioAldeia();
        }
    }
}

void naAldeia_Final(){
    printf("\nMuito bem %s, voce encontrou a Aldeia, nela voce se sente acolhido e a salvo!", nome);
    printf("\nVoce se sente bem e decide continuar sua vida nela!");
    printf("\nParabens %s, voce terminou o jogo!!!", nome);
    printf("\nVolte daqui algum tempo, para mais atualizacoes na aventura!!!");
    SLEEP(5);
}

void gameOver(){
    system(LIMPAR);
    printf("==========================\n");
    printf("\n======= GAME OVER ======\n");
    printf("\n==========================\n");
    printf("\n\nVoce foi derrotado, %s...\n", nome);
    printf("\nSua vida chegou a 0 e voce caiu no chao.\n");
    printf("\nQue pena! Mas toda aventura tem seus riscos...\n");
    printf("\nObrigado por jogar, %s!\n", nome);
    printf("\nTente novamente para completar a aventura!\n");
    SLEEP(5);

    vida = 100;
    vidaInimigoTroll = 110;
    vidaInimigoGoblin = 80;

    main_jogo();
}

void main_jogo(){
    apresentar();
    sala1_Comeco();
}

int main(){
    srand(time(NULL));
    main_jogo();
    return 0;
}
