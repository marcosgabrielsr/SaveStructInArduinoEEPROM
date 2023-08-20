//==============================================================================================================================================
//
//  Autor: Marcos Gabriel
//
//  Data de última atualização: 20/08/2023
//
//==============================================================================================================================================

//Incluindo bibliotecas
#include <Arduino.h>
#include <EEPROM.h>

//Definindo limite de itens do array
#define MAX 5

//Definindo endereço da EEPROM onde serão salvos os dados
#define addresEEPROM 0

//Mapeando hardware
#define btn1 2
#define btn2 3
#define btn3 4

//struct de dados
struct Dados{
  int8_t codigo;
  char id;
  float dados[MAX];
  bool salvo;
};

//Declarando funções
void verifySave(Dados &dados);
bool clickBtn(int porta, int id);
void randomDados(Dados &dados);
void showDados(Dados dados);
void saveDados(const Dados &dados);

//Criando uma variável do tipo Dados
Dados dados;

void setup() {
  Serial.begin(9600);                                                                       //Inicializando monitor serial

  pinMode(btn1, INPUT_PULLUP);                                                              //Definindo btn1 como entrada
  pinMode(btn2, INPUT_PULLUP);                                                              //Definindo btn2 como entrada
  pinMode(btn3, INPUT_PULLUP);                                                              //Definindo btn3 como entrada

  verifySave(dados);                                                                       //verifica se há dados salvos na memória

  randomSeed(analogRead(A0));                                                              //Embaralhando biblioteca random
}

void loop() {
  if(clickBtn(btn1, 0)){                                                                   //Se clickBtn(btn1, 0) retornar true...
    randomDados(dados);                                                                    //É chamada a função randomDados para dados
  }

  if(clickBtn(btn2, 1)){                                                                  //Se clickBtn(btn2, 1) retorna true...
    showDados(dados);                                                                     //É chamada a função showDados para dados
  }

  if(clickBtn(btn3, 2)){                                                                  //Se clickBtn(btn3, 2) retorna true...
    saveDados(dados);                                                                     //É chamada a função savedados para dados
  }
}


//Função que verifica se os dados estão salvos e se eles foram carregados na struct que será utilizada
void verifySave(Dados &dados){
  dados.salvo = false;                                                                     //Inicializa dados.salvo como false

  EEPROM.get(addresEEPROM, dados);                                                                    //Pega os dados da memoria e carrega na variável dados

  if(dados.salvo == false){                                                                //Se dados.salvo == falso... não tinha dados na memoria
    Serial.println("Nao a nada salvo na memoria");
    dados.codigo = 1;                                                                      //inicializa dados.codigo = 1...
    dados.id = 65;                                                                         //inicializa dados.id = 2...
    for(int i = 0; i < MAX; i++){                                                         //inicializa todas as posições dados.dados = 0.1
      dados.dados[i] = 0.1;
    }
    dados.salvo = true;                                                                   //no final inicializa dados.salvo = true
  }
}

//Função que verifica se o usuário clicou o botão passado por parametro com seu id(indice que vai de 0 a 2)
bool clickBtn(int porta, int id){
  bool k = false;                                                                         //Inicializa k = false
  bool stateBtn = digitalRead(porta);                                                     //Pega a leitura do botão
  static bool antState[3] = {true, true, true};                                           //Incializa os estados anteriores como verdadeiros
  static unsigned long time = 0;                                                          //Inicializa time com zero

  if((millis() - time) > 150){                                                            //Verifica se passou um intervalo em mls
    if(!stateBtn && antState[id]){                                                        //Se o botão foi clicado...
      time = millis();                                                                    //resetamos o time
      k = true;                                                                           //k fica verdadeiro
    }
    antState[id] = stateBtn;                                                              //atualiza estado anterior para o valor do stateBtn
  }

  return k;                                                                               //retorna k
}

//Função que gera dados aleatórios para uma struct do tipo dados
void randomDados(Dados &dados){
  dados.codigo = random(0, 10);                                                           //Gera valores aleatórios do intervalo [0,9]
  dados.id = random(65, 91);                                                              //Gera valores aleatórios do intervalo [65, 90] ou [A,Z]

  for(int i = 0; i < MAX; i++){                                                           //Gera um valor aleatório para cada posição do array
    dados.dados[i] = random(0, 100);                                                      //gera valores aleatórios no intervalo [0,99]
  }
  dados.salvo = true;                                                                     //Atualiza dados.salvo para true
}

//Função que apresenta os dados atuais da struct passada com parametro
void showDados(Dados dados){
  Serial.println("");                                                                     //Pula uma linha
  Serial.print("dados.codigo: "); Serial.println(dados.codigo);                           //Imprime dados.codigo
  Serial.print("dados.id: ");   Serial.println(dados.id);                                 //Imprime dados.id
  Serial.print("dados.dados["); Serial.print(MAX); Serial.print("] = { ");                //Imprime todos os valores do array dados(for abaixo)

  for(int i = 0; i < MAX; i++){
    Serial.print(dados.dados[i]);
    if(i != MAX - 1){
      Serial.print(", ");
    }
  }

  Serial.println("}");
}

//Função que salva uma struct dados passada por parâmetro
void saveDados(const Dados &dados){
  EEPROM.put(addresEEPROM, dados);                                                        //Utiliza o endereço informado no inicio do código
}