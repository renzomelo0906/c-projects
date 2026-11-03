# cifras

> 🚧 **Enunciado:** este projeto ainda não foi implementado. Ao terminar, troque esta seção por uma descrição do que o programa faz.

## Objetivo

Escrever um programa em C que **cifra e decifra arquivos de texto** com as cifras de **César** e **Vigenère**, e que **quebra uma cifra de César por força bruta**.

> Estas cifras são históricas e **não são seguras**. O objetivo é entender a ideia de chave, cifrar/decifrar e ataque por força bruta, conceitos que voltam em criptografia moderna.

## Como as cifras funcionam

- **César:** cada letra anda `k` posições no alfabeto. Com `k = 3`, `A → D` e `Z → C` (o alfabeto dá a volta).
- **Vigenère:** igual à César, mas o deslocamento muda a cada letra, seguindo uma palavra-chave. Com a chave `LIMAO`, a 1ª letra anda 11 (L), a 2ª anda 8 (I), a 3ª anda 12 (M), e assim por diante, repetindo a chave.
- Só letras são cifradas. Maiúsculas continuam maiúsculas, minúsculas continuam minúsculas, e números, espaços e pontuação ficam iguais.

## Requisitos

1. Menu:
   ```
   1. Cifrar arquivo (Cesar)
   2. Decifrar arquivo (Cesar)
   3. Cifrar arquivo (Vigenere)
   4. Decifrar arquivo (Vigenere)
   5. Quebrar Cesar por forca bruta
   0. Sair
   ```
2. Opções 1 a 4: pedir arquivo de entrada, arquivo de saída e a chave, e gravar o resultado no arquivo de saída.
3. Opção 5: ler o arquivo cifrado e mostrar as **25 tentativas** (k = 1 a 25), com os primeiros 60 caracteres de cada uma, para o usuário identificar qual é a certa.
4. Cada cifra fica numa **função própria**, por exemplo:
   ```c
   char cesar_letra(char c, int k);
   void vigenere_texto(char *texto, const char *chave, int decifrar);
   ```
5. Usar o [`mensagem.txt`](mensagem.txt) desta pasta para testar. O [`secreto.txt`](secreto.txt) foi cifrado com César e uma chave desconhecida. Descubra a chave com a opção 5.

## Tratamento de erros (obrigatório)

- Opção do menu inválida (letra, número fora do menu) → mensagem de erro e mostrar o menu de novo.
- Chave de César fora de 1–25 ou que não é número → pedir de novo.
- Chave de Vigenère vazia ou com caracteres que não são letras → pedir de novo.
- Arquivo de entrada não existe → mensagem clara com `perror`.
- Arquivo de entrada igual ao de saída → recusar, porque apagaria o original.
- Todo arquivo aberto precisa ser fechado com `fclose`, inclusive nos caminhos de erro.

## Critérios de aceite

- [ ] Cifrar e depois decifrar `mensagem.txt` com a mesma chave gera um arquivo idêntico ao original.
- [ ] `ABC xyz!` com César k = 3 vira `DEF abc!`.
- [ ] `ATACARBASESUL` com Vigenère e chave `LIMAO` vira `LBMCOCJMSSDCX`.
- [ ] A opção 5 revela o conteúdo de `secreto.txt`.
- [ ] Nenhuma entrada inválida faz o programa travar.
- [ ] Compila com `gcc -Wall -Wextra` sem warnings.

## Extras (opcionais)

- Na opção 5, sugerir a chave mais provável automaticamente, contando qual letra aparece mais. Em português, costuma ser `A` ou `E`.
- Aceitar a chave por argumento: `./cifras -c 3 entrada.txt saida.txt`.

## Conceitos praticados

Funções, ponteiros e strings, aritmética com `char` e operador `%`, leitura e escrita de arquivos, menus com validação, tratamento de erros.
