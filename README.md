**Autor:** Marcos Gabriel  
**Data de Última Atualização:** 20/08/2023

### Descrição do Projeto

Este projeto consiste em um programa desenvolvido em Arduino que cria e manipula uma estrutura de dados chamada `Dados`, gerando informações aleatórias e permitindo a exibição e armazenamento desses dados. O programa utiliza botões para interagir com as diferentes funcionalidades. Este projeto foi desenvolvido na IDE Platform IO, entretanto pode ser compilado e carregado em uma placa por meio da Arduino IDE, bastando apenas copiar o código do arquivo main e cola-lá em um arquvio .ino.

### Funcionalidades Principais

1. **Geração de Dados Aleatórios:** O programa é capaz de gerar dados aleatórios para a estrutura `Dados`, incluindo um código, um identificador alfanumérico e um array de valores de ponto flutuante. A geração é ativada por meio de um botão.

2. **Exibição de Dados:** Os dados armazenados na estrutura `Dados` podem ser exibidos na saída serial. A exibição inclui o código, o identificador e os valores contidos no array.

3. **Armazenamento em EEPROM:** Os dados da estrutura `Dados` podem ser salvos na memória EEPROM do Arduino. Isso permite que os dados gerados sejam preservados mesmo após o desligamento do dispositivo.

### Componentes Utilizados

- Arduino Nano (ou similar)
- Botões conectados nas portas de saída digital 2, 3 e 4
- Memória EEPROM para armazenamento dos dados

## Circuito

<img src="https://media.discordapp.net/attachments/1112460925547581622/1142853978988740669/image.png?width=737&height=554" />

### Estrutura do Código

O código é organizado da seguinte maneira:

- Inclusão das bibliotecas necessárias (`Arduino.h` e `EEPROM.h`).
- Definição de constantes como `MAX` (limite de itens no array) e `addresEEPROM` (endereço na EEPROM para armazenamento).
- Mapeamento das portas dos botões (`btn1`, `btn2` e `btn3`).
- Definição da estrutura `Dados` que armazena as informações geradas.
- Declaração das funções utilizadas no programa.
- Função `setup()` que inicializa a configuração do Arduino.
- Função `loop()` que verifica os botões pressionados e executa as funcionalidades correspondentes.

### Funcionalidades Detalhadas

- **Verificação de Dados Salvos:** A função `verifySave` verifica se existem dados salvos na EEPROM. Se não houver dados salvos, a estrutura `Dados` é inicializada com valores padrão.

- **Detecção de Cliques nos Botões:** A função `clickBtn` detecta cliques nos botões e retorna `true` quando um clique é detectado.

- **Geração de Dados Aleatórios:** A função `randomDados` gera dados aleatórios para a estrutura `Dados`, preenchendo o código, o identificador e o array de valores com informações aleatórias.

- **Exibição dos Dados:** A função `showDados` exibe os dados armazenados na estrutura `Dados` na saída serial. Os valores do array também são exibidos.

- **Armazenamento na EEPROM:** A função `saveDados` armazena a estrutura `Dados` na memória EEPROM, permitindo que os dados sejam recuperados após o desligamento do dispositivo.

### Conclusão

Este projeto demonstra a utilização de um Arduino para gerar, exibir e armazenar dados aleatórios, ilustrando a capacidade de interação com botões e utilização da memória EEPROM, principalmente a opção de salvar structs na mesma. A estrutura do código e as funcionalidades implementadas são exemplos de como criar projetos interativos e versáteis utilizando a plataforma Arduino.
