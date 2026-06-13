programa
{
	inclua biblioteca Util --> u
	inteiro vida = 100
	cadeia nome
	inteiro vidaInimigoTroll = 110
	inteiro vidaInimigoGoblin = 80

	funcao banner(){
		escreva("=====================")
		escreva("\n==A GRANDE AVENTURA==")
		escreva("\n=====================")
	}

	funcao verVida(){
		escreva("\nSua vida atual é: "+vida+"/100!")
		u.aguarde(5000)
	}

	
	funcao apresentar(){
		limpa()
		banner()
		escreva("\nBem vindo, jogador(a)!!!")
		escreva("\nQual o seu nome? ")
		leia(nome)
		escreva("\nPrepare-se "+nome+", sua jornada começa agora!!!")
		u.aguarde(5000)
	}

	funcao sala1_comeco(){
		limpa()
		banner()
		inteiro escolha_Caminho
		escreva("\n"+nome+", você acorda e vê dois caminhos na sua frente;")
		escreva("\nUm é uma estrada que se adentra para a floresta;")
		escreva("\nO outro te leva para dentro de uma caverna escura!")
		escreva("\nQual você escolhe: ")
		escreva("\n[1] - Floresta    [2] - Caverna    [3] - Ver minha vida\n")
		escreva("Digite a sua resposta: ")
		leia(escolha_Caminho)

		se (escolha_Caminho == 1) {
			sala2_Floresta()
		}
		senao se (escolha_Caminho == 2) {
			sala3_Caverna()
		}
		senao se (escolha_Caminho == 3) {
			verVida()
			sala1_comeco()
		}
		senao {
			escreva("\nEssa opção não existe!!!")
			u.aguarde(5000)
			limpa()
			sala1_comeco()
		}
		
	}

	funcao sala2_Floresta(){
		inteiro escolha_Caminho
		limpa()
		banner()
		escreva("\n"+nome+", você escolheu o caminho que te leva para dentro da floresta!")
		escreva("\nVocê segue pelo caminho por um tempo, até que escuta barulhos vindos floresta a dentro;")
		escreva("\n"+nome+", o que você faz: ")
		escreva("\n[1] - Seguir o caminho e ignorar os barulhos")
		escreva("\n[2] - Parar e vasculhar ao redor")
		escreva("\n[3] - Voltar para trás\n")
		escreva("\n[4] - Ver minha vida")
		leia(escolha_Caminho)

		se (escolha_Caminho == 1) {
			sala4_FimFloresta_InicioAldeia()
		}
		senao se(escolha_Caminho == 2) {
			batalha_CaminhoFloresta()
		}
		senao se(escolha_Caminho == 3) {
			sala1_comeco()
		}
		senao se(escolha_Caminho == 4) {
			verVida()
			sala2_Floresta()
		}
		senao {
			escreva("\nEssa opção não existe! ")
			u.aguarde(5000)
			limpa()
			sala2_Floresta()
		}
		
	}

	funcao sala3_Caverna(){
			inteiro escolha_Caminho
			limpa()
			banner()
			escreva("\n"+nome+", você escolheu entrar dentro da caverna escura!")
			escreva("\nAssim que você entra e que seus olhos se acostumam com o escuro, ")
			escreva("\nvocê vê dois corredores a sua frente. ")
			escreva("\nO da esquerda, emite um cheiro muito forte e ruim de fedor.")
			escreva("\nO da direita, está quase totalmente escuro, mas emite uma luz bem fraca e bem longe!")
			escreva("\nQual corredor você escolhe: ")
			escreva("\n[1] - Corredor Fedido(esquerda)    [2] - Corredor da Luz(direita)    [3] - Ver minha vida\n")
			leia(escolha_Caminho)

			se (escolha_Caminho == 1) {
				sala_CorredorFedido()
			}
			senao se ( escolha_Caminho == 2 ) {
				sala_CorredorLuz()
			}
			senao se (escolha_Caminho == 3) {
				verVida()
				sala3_Caverna()
			}
			senao {
				escreva("\nEssa opção não existe!")
        			u.aguarde(5000)
        			sala3_Caverna()
			}
	}

	funcao sala_CorredorFedido(){
		limpa()
		banner()
		escreva("\nVocê escolheu seguir pelo corredor que emitia um cheiro muito forte, ")
		escreva("\nconforme você avança, o cheiro vai ficando cada vez mais forte!")
		escreva("\nDe repente, você tropeça em uma pilha de ossos que está chão.")
		escreva("\nVocê se levanta, olha para frente e vê, na escuridão...")
		escreva("\ndois olhos, amarelos, te fitando no fundo da sua alma!")
		escreva("\nDe repente, um Troll enorme avança em sua direção!")
		escreva("\nVocê saca sua espada e se prepara para batalhar!")
		u.aguarde(20000)
		batalha_Caverna()
	}

	funcao sala_CorredorLuz(){
		limpa()
		banner()
		inteiro opcao
		inteiro escolha_Caminho
		escreva("\nVocê segue em direção a luz fraca distante...")
		escreva("\nConforme você vai andando, você percebe que a luz vem de cristais, ")
		escreva("\nque estão nas paredes da caverna!")
		escreva("\nEm uma pequena câmara na caverna, você encontra um baú no chão!")
		escreva("\nO quê você faz: ")
		escreva("\n[1] - Abrir o baú    [2] - Ignorar o baú e seguir em frente    [3] - Ver minha vida")
		leia(opcao)

		se (opcao == 1) {
			escreva("\nVocê abre o baú com cuidado...")
			escreva("\nDentro, você vê uma poção de cura!!! Sua vida é restaurada para 100!!!")
			vida = 100
			escreva("\nAlém disso, há uma saída no fundo da câmara que leva para a Floresta!")
			escreva("\nO que você deseja fazer: ")
			escreva("\n[1] - Seguir até a saída que leva para a Floresta")
			escreva("\n[2] - Voltar para a entrada da Caverna\n")
			leia(escolha_Caminho)

			se (escolha_Caminho == 1) {
				sala4_FimFloresta_InicioAldeia()
			}
			senao se( escolha_Caminho == 2) {
				sala3_Caverna()
			}
			senao {
				escreva("\nEssa opção não existe!")
				u.aguarde(5000)
				sala_CorredorLuz()
			}
			
		}
		senao se(opcao == 2){
			escreva("\nVocê escolhe ignorar o baú e seguir pela saída ao fundo da câmara!")
			escreva("\nEla te leva devolta para a Floresta!")
			u.aguarde(5000)
			sala4_FimFloresta_InicioAldeia()
		}
		senao se(opcao == 3) {
			verVida()
			sala_CorredorLuz()
		}
		senao {
			escreva("\nEssa opção é inválida")
			u.aguarde(5000)
			sala_CorredorLuz()
		}
	}

	funcao batalha_Caverna(){
		limpa()
		banner()
		
		inteiro opcao
		inteiro danoDado
		inteiro danoRecebido

		enquanto ( vida > 0 e vidaInimigoTroll > 0 ) {
			escreva("\n=============================================")
			escreva("\nSEU TURNO:")
			escreva("\nSua Vida - "+vida+"    Troll - "+vidaInimigoTroll)
			escreva("\nO que você deseja fazer: ")
			escreva("\n[1] - Atacar    [2] - Fugir    [3] - Ver minha vida\n")
			leia(opcao)

			se (opcao == 1) {
				danoDado = u.sorteia(5, 15)
				vidaInimigoTroll = vidaInimigoTroll - danoDado
				escreva("\nVocê deu "+danoDado+" de dano no Troll!!!")
				u.aguarde(5000)
				escreva("\n=============================================")
				escreva("\nTURNO DO INIMIGO:")
				danoRecebido = u.sorteia(4, 10)
				vida = vida - danoRecebido
				escreva("\nTroll te deu "+danoRecebido+" de dano!!!")
				u.aguarde(5000)
			}
			senao se (opcao == 2) {
				escreva("\nVocê corre de volta pelo corredor, na esperança de que o Troll não venha atrás!!")
				escreva("\nVocê volta para a entrada da caverna!")
				u.aguarde(5000)
				sala3_Caverna()
				retorne
			}
			senao se (opcao == 3) {
				verVida()
			}
			senao {
				escreva("\nEssa opção não existe!")
				u.aguarde(3000)
			}
			
		}

		se (vida <= 0){
			gameOver()
		}

		senao {
			escreva("\nIncrível, você derrotou o Troll!!!")
			escreva("\nNo fundo do corredor há uma saída que te leva a floresta!")
			u.aguarde(5000)
			sala4_FimFloresta_InicioAldeia()
		}
		
	}
	
	funcao sala4_FimFloresta_InicioAldeia(){
		inteiro escolha_Caminho
		limpa()
		banner()
		escreva("\nVocê anda por mais um tempo, até que você percebe que a mata está ficando menos densa, ")
		escreva("\nVocê anda mais um pouco e chega ao final da floresta, onde você vê uma espécie de aldeia!")
		escreva("\nO quê você faz: ")
		escreva("\n[1] - Seguir e ir até a aldeia")
		escreva("\n[2] - Voltar para trás\n")
		escreva("\n[3] - Ver minha vida")
		leia(escolha_Caminho)

		se (escolha_Caminho == 1) {
			naAldeia_Final()
		}
		senao se (escolha_Caminho == 2){
			sala2_Floresta()
		}
		senao se (escolha_Caminho == 3){
			verVida()
			sala4_FimFloresta_InicioAldeia()
		}
		senao{
			escreva("\nEssa opção não existe! ")
			u.aguarde(5000)
			limpa()
			sala4_FimFloresta_InicioAldeia()
		}
	}

	funcao batalha_CaminhoFloresta(){
		limpa()
		banner()
		escreva("\nVocê escolhe investigar os barulhos.")
		escreva("\nVocê se aproxima da vegetação de onde escutou barulhos de folhas mexendo, gravetos quebrando e uma espécie de grunhidos.")
		escreva("\nVocê vai se aproximando lentamente, até que...")
		escreva("\nVocê vê, em um reflexo, uma figura verde pula em você, você desvia e quando volta ao seu estado normal, ")
		escreva("\nvocê vê que a criatura verde era um Goblin!!!")
		escreva("\nVocê saca a sua espada e se prepara para batalhar...")
		u.aguarde(20000)
		batalha()
		
	}

	funcao batalha(){
		limpa()
		banner()
		
		inteiro opcao
		inteiro danoDado
		inteiro danoRecebido
		inteiro escolha_Caminho
		
		enquanto (vida > 0 e vidaInimigoGoblin > 0) {
			escreva("\n=============================================")
			escreva("\nSEU TURNO:")
			escreva("\nSua vida - "+vida+"    Goblin - "+vidaInimigoGoblin)
			escreva("\nO que você deseja fazer: ")
			escreva("\n[1] - Atacar    [2] - Fugir    [3] - Ver minha vida\n")
			leia(opcao)

			se (opcao == 1){
				danoDado = u.sorteia(5, 15)
				vidaInimigoGoblin = vidaInimigoGoblin - danoDado
				escreva("\nVocê deu "+danoDado+" de dano no Goblin!")
				u.aguarde(5000)
				escreva("\n=============================================")
				escreva("\nTURNO DO INIMIGO:")
				danoRecebido = u.sorteia(5, 10)
				vida = vida - danoRecebido
				escreva("\nGoblin te deu "+danoRecebido+" de dano!")
				u.aguarde(5000)
				}

			senao se (opcao == 2){
				escreva("\nVocê escolheu fugir!")
				escreva("\nVocê volta para a Floresta!")
				sala2_Floresta()
				retorne
			} 
			senao se (opcao == 3) {
				verVida()
			}
			senao {
				escreva("\nEssa opção não existe!")
				u.aguarde(5000)
				limpa()
			}
		}
		se (vida <= 0) {
			gameOver()
		}
		senao {
			escreva("\nParabéns!!! Você venceu o Goblin!")
			escreva("\nVocê continua sua jornada pelo caminho da Floresta, ")
			escreva("\nVocê anda mais um pouco e chega ao final da floresta, onde você vê uma espécie de aldeia!")
			escreva("\nO quê você faz: ")
			escreva("\n[1] - Seguir e ir até a aldeia")
			escreva("\n[2] - Voltar para trás\n")
			leia(escolha_Caminho)

			se (escolha_Caminho == 1) {
			naAldeia_Final()
			}
			senao se (escolha_Caminho == 2){
			sala2_Floresta()
			}
			senao{
			escreva("\nEssa opção não existe! ")
			u.aguarde(5000)
			limpa()
			sala4_FimFloresta_InicioAldeia()
			}
		}
		
	
	}

	funcao naAldeia_Final(){
		escreva("\nMuito bem "+nome+", você encontrou a Aldeia, nela você se sente acolhido e a salvo!")
		escreva("\nVocê se sente bem e decide continuar sua vida nela!")
		escreva("\nParabéns "+nome+", você terminou o jogo!!!")
		escreva("\nVolte daqui algum tempo, para mais atualizações na aventura!!!")
	}

	funcao gameOver(){
		 limpa()
    		 escreva("==========================")
    		 escreva("\n======= GAME OVER ======")
     	 escreva("\n========================")
      	 escreva("\n\nVocê foi derrotado, "+nome+"...")
    		 escreva("\nSua vida chegou a 0 e você caiu no chão.")
    		 escreva("\nQue pena! Mas toda aventura tem seus riscos...")
    		 escreva("\n\nObrigado por jogar, "+nome+"!")
    		 escreva("\nTente novamente para completar a aventura!")
    		 u.aguarde(20000)
    		 vida = 100
    		 vidaInimigoTroll = 110
	      vidaInimigoGoblin = 80
    		 inicio()
	}


	funcao inicio()
	{
		apresentar()
		sala1_comeco()	
	}

	
}
