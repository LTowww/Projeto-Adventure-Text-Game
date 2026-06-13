import time
import os
import random

vida = 100
nome = ""
vidaInimigoTroll = 110
vidaInimigoGoblin = 80

def main():
    apresentar()
    sala1_Comeco()


def banner():
    print("=====================")
    print("==A GRANDE AVENTURA==")
    print("=====================")

def verVida():
    print("\nSua vida atual é: "+str(vida)+"/100!")
    time.sleep(5)

def apresentar():
    global nome
    
    os.system('cls')
    banner()
    print("Bem-vindo(a), jogador(a)!!!")
    nome = str(input("Qual o seu nome?:  "))
    print("Prepare-se "+nome+", sua jornada começa agora!!!")
    time.sleep(5)

def sala1_Comeco():
    
    escolhaCaminho = ""
    
    os.system('cls')
    banner()
    print("\n"+nome+", você acorda e vê dois caminhos na sua frente;")
    print("\nUm é uma estrada que se adentra para a floresta;")
    print("\nO outro te leva para dentro de uma caverna escura!")
    print("\nQual você escolhe: ")
    print("\n[1] - Floresta    [2] - Caverna    [3] - Ver minha vida\n")
    
    escolhaCaminho = str(input("Digite a sua resposta: "))

    if escolhaCaminho == "1":
        sala2_Floresta()
    elif escolhaCaminho == "2":
        sala3_Caverna()
    elif escolhaCaminho == "3":
        verVida()
        sala1_Comeco()
    else:
        print("\nEssa opção não existe!!!")
        time.sleep(5)
        os.system('cls')
        sala1_Comeco()

def sala2_Floresta():
    escolhaCaminho = ""

    os.system('cls')
    banner()
    print("\n"+nome+", você escolheu o caminho que te leva para dentro da floresta!")
    print("\nVocê segue pelo caminho por um tempo, até que escuta barulhos vindos floresta a dentro;")
    print("\n"+nome+", o que você faz: ")
    print("\n[1] - Seguir o caminho e ignorar os barulhos")
    print("\n[2] - Parar e vasculhar ao redor")
    print("\n[3] - Voltar para trás\n")
    print("\n[4] - Ver minha vida")

    escolhaCaminho = str(input("\n"+nome+", o que você faz: "))

    if escolhaCaminho == "1":
        sala4_FimFloresta_InicioAldeia()
    elif escolhaCaminho == "2":
        batalha_CaminhoFloresta()
    elif escolhaCaminho == "3":
        sala1_Comeco()
    elif escolhaCaminho == "4":
        verVida()
        sala2_Floresta()
    else: 
        print("\nEssa opção não existe! ")
        time.sleep(5)
        os.system('cls')
        sala2_Floresta()

def sala3_Caverna():
    escolhaCaminho = ""

    os.system('cls')
    banner()
    print("\n"+nome+", você escolheu entrar dentro da caverna escura!")
    print("\nAssim que você entra e que seus olhos se acostumam com o escuro, ")
    print("\nvocê vê dois corredores a sua frente. ")
    print("\nO da esquerda, emite um cheiro muito forte e ruim de fedor.")
    print("\nO da direita, está quase totalmente escuro, mas emite uma luz bem fraca e bem longe!")
    print("\nQual corredor você escolhe: ")
    print("\n[1] - Corredor Fedido(esquerda)    [2] - Corredor da Luz(direita)    [3] - Ver minha vida\n")

    escolhaCaminho = str(input("Qual a sua escolha: "))

    if escolhaCaminho == "1":
        sala_CorredorFedido()
    elif escolhaCaminho == "2":
        sala_CorredorLuz()
    elif escolhaCaminho == "3":
        verVida()
        sala3_Caverna()
    else:
        print("\nEssa opção não existe!")
        time.sleep(5)
        sala3_Caverna()

def sala_CorredorFedido():
    os.system('cls')
    banner()
    print("\nVocê escolheu seguir pelo corredor que emitia um cheiro muito forte, ")
    print("\nconforme você avança, o cheiro vai ficando cada vez mais forte!")
    print("\nDe repente, você tropeça em uma pilha de ossos que está chão.")
    print("\nVocê se levanta, olha para frente e vê, na escuridão...")
    print("\ndois olhos, amarelos, te fitando no fundo da sua alma!")
    print("\nDe repente, um Troll enorme avança em sua direção!")
    print("\nVocê saca sua espada e se prepara para batalhar!")
    time.sleep(20)
    batalha_Caverna()

def sala_CorredorLuz():
    global vida
    
    opcao = ""
    escolhaCaminho = ""

    os.system('cls')
    banner()
    print("\nVocê segue em direção a luz fraca distante...")
    print("\nConforme você vai andando, você percebe que a luz vem de cristais, ")
    print("\nque estão nas paredes da caverna!")
    print("\nEm uma pequena câmara na caverna, você encontra um baú no chão!")
    print("\nO quê você faz: ")
    print("\n[1] - Abrir o baú    [2] - Ignorar o baú e seguir em frente    [3] - Ver minha vida")

    opcao = str(input("O que você faz?: "))

    if opcao == "1":
        print("\nVocê abre o baú com cuidado...")
        print("\nDentro, você vê uma poção de cura!!! Sua vida é restaurada para 100!!!")
        vida = 100
        print("\nAlém disso, há uma saída no fundo da câmara que leva para a Floresta!")
        print("\nO que você deseja fazer: ")
        print("\n[1] - Seguir até a saída que leva para a Floresta")
        print("\n[2] - Voltar para a entrada da Caverna\n")

        escolhaCaminho = str(input("O que você faz?: "))

        if escolhaCaminho == "1":
            sala4_FimFloresta_InicioAldeia()
        elif escolhaCaminho == "2":
            sala3_Caverna()
        else:
            print("\nEssa opção é inválida")
            time.sleep(5)
            sala_CorredorLuz()

def batalha_Caverna():
    
    os.system('cls')
    banner()

    global vida
    global vidaInimigoTroll
    
    opcao = ""
    danoDado = 0
    danoRecebido = 0

    while (vida > 0 and vidaInimigoTroll > 0):
        print("\n=============================================")
        print("\nSEU TURNO:")
        print("\nSua Vida - "+str(vida)+"    Troll - "+str(vidaInimigoTroll))
        print("\nO que você deseja fazer: ")
        print("\n[1] - Atacar    [2] - Fugir    [3] - Ver minha vida\n")

        opcao = str(input("O que deseja fazer?: "))
        
        if opcao == "1":
            danoDado = random.randint(5, 15)
            vidaInimigoTroll -= danoDado
            print("\nVocê deu "+str(danoDado)+" de dano no Troll!!!")
            time.sleep(5)
            print("\n=============================================")
            print("\nTURNO DO INIMIGO: ")
            danoRecebido = random.randint(4, 10)
            vida -= danoRecebido
            print("\nTroll te deu "+str(danoRecebido)+" de dano!!!")
            time.sleep(5)
        elif opcao == "2":
            print("\nVocê corre de volta pelo corredor, na esperança de que o Troll não venha atrás!!")
            print("\nVocê volta para a entrada da caverna!")
            time.sleep(5)
            sala3_Caverna()
            return
        elif opcao == "3":
            verVida()
        else:
            print("\nEssa opção não existe!")
            time.sleep(3)
    
    if vida <= 0:
        gameOver()
    else:
        print("\nIncrível, você derrotou o Troll!!!")
        print("\nNo fundo do corredor há uma saída que te leva a floresta!")
        time.sleep(5)
        sala4_FimFloresta_InicioAldeia()

def sala4_FimFloresta_InicioAldeia():
    escolhaCaminho = ""
    os.system('cls')
    banner()

    print("\nVocê anda por mais um tempo, até que você percebe que a mata está ficando menos densa, ")
    print("\nVocê anda mais um pouco e chega ao final da floresta, onde você vê uma espécie de aldeia!")
    print("\nO quê você faz: ")
    print("\n[1] - Seguir e ir até a aldeia")
    print("\n[2] - Voltar para trás\n")
    print("\n[3] - Ver minha vida")

    escolhaCaminho = str(input("O que você faz?: "))

    if escolhaCaminho == "1":
        naAldeia_Final()
    elif escolhaCaminho == "2":
        sala2_Floresta()
    elif escolhaCaminho == "3":   
        verVida()
        sala4_FimFloresta_InicioAldeia()
    else:
        print("\nEssa opção não existe! ")
        time.sleep(5)
        os.system('cls')
        sala4_FimFloresta_InicioAldeia()

def batalha_CaminhoFloresta():
    os.system('cls')
    banner()

    print("\nVocê escolhe investigar os barulhos.")
    print("\nVocê se aproxima da vegetação de onde escutou barulhos de folhas mexendo, gravetos quebrando e uma espécie de grunhidos.")
    print("\nVocê vai se aproximando lentamente, até que...")
    print("\nVocê vê, em um reflexo, uma figura verde pula em você, você desvia e quando volta ao seu estado normal, ")
    print("\nvocê vê que a criatura verde era um Goblin!!!")
    print("\nVocê saca a sua espada e se prepara para batalhar...")    
    time.sleep(20)
    batalha()

def batalha():
    os.system('cls')
    banner()

    global vida
    global vidaInimigoGoblin
    opcao = ""
    escolhaCaminho = ""
    danoDado = 0
    danoRecebido = 0

    while (vida > 0 and vidaInimigoGoblin > 0):
        print("\n=============================================")
        print("\nSEU TURNO:")
        print("\nSua vida - "+str(vida)+"    Goblin - "+str(vidaInimigoGoblin))
        print("\nO que você deseja fazer: ")
        print("\n[1] - Atacar    [2] - Fugir    [3] - Ver minha vida\n")

        opcao = str(input("O que você deseja fazer?: "))

        if opcao == "1":
            danoDado = random.randint(5, 15)
            vidaInimigoGoblin -= danoDado
            print("\nVocê deu "+str(danoDado)+" de dano no Goblin!")
            time.sleep(5)
            print("\n=============================================")
            print("\nTURNO DO INIMIGO:")
            danoRecebido = random.randint(5, 10)
            vida -= danoRecebido
            print("\nGoblin te deu "+str(danoRecebido)+" de dano!")
            time.sleep(5)
        elif opcao == "2":
            print("\nVocê escolheu fugir!")
            print("\nVocê volta para a Floresta!")
            sala2_Floresta()
            return
        elif opcao == "3":
            verVida()
        else:
            print("\nEssa opção não existe!")
            time.sleep(5)
            os.system('cls')

    if vida <= 0:
        gameOver()
    else:
        print("\nParabéns!!! Você venceu o Goblin!")
        print("\nVocê continua sua jornada pelo caminho da Floresta, ")
        print("\nVocê anda mais um pouco e chega ao final da floresta, onde você vê uma espécie de aldeia!")
        print("\nO quê você faz: ")
        print("\n[1] - Seguir e ir até a aldeia")
        print("\n[2] - Voltar para trás\n")

        escolhaCaminho = str(input("\nO que você faz?: "))

        if escolhaCaminho == "1":
            naAldeia_Final()
        elif escolhaCaminho == "2":
            sala2_Floresta()
        else:
            print("\nEssa opção não existe!")
            time.sleep(5)
            os.system('cls')
            sala4_FimFloresta_InicioAldeia()

def naAldeia_Final():
    print("\nMuito bem "+nome+", você encontrou a Aldeia, nela você se sente acolhido e a salvo!")
    print("\nVocê se sente bem e decide continuar sua vida nela!")
    print("\nParabéns "+nome+", você terminou o jogo!!!")
    print("\nVolte daqui algum tempo, para mais atualizações na aventura!!!")

def gameOver():
    os.system('cls')
    print("==========================")
    print("\n======= GAME OVER ======")
    print("\n========================")
    print("\n\nVocê foi derrotado, "+nome+"...")
    print("\nSua vida chegou a 0 e você caiu no chão.")
    print("\nQue pena! Mas toda aventura tem seus riscos...")
    print("\nObrigado por jogar, "+nome+"!")
    print("\nTente novamente para completar a aventura!")
    time.sleep(20)

    global vida
    global vidaInimigoTroll
    global vidaInimigoGoblin

    vida = 100
    vidaInimigoTroll = 110
    vidaInimigoGoblin = 80
    main()

if __name__ == '__main__':
    main()
    
