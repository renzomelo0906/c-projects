# verificador-senhas

> 🚧 **Enunciado:** este projeto ainda não foi implementado. Ao terminar, troque esta seção por uma descrição do que o programa faz.

## Objetivo

Escrever um programa em C que avalia a **força de uma senha** com base em regras de composição e numa **lista de senhas vazadas/comuns**, e explica ao usuário por que a senha é fraca.

## Arquivo de entrada

O arquivo [`senhas-comuns.txt`](senhas-comuns.txt) desta pasta tem uma senha por linha. São senhas que aparecem com frequência em vazamentos.

## Requisitos

1. No início, carregar `senhas-comuns.txt` na memória com `malloc`. Cada senha é uma string alocada, e a quantidade de linhas não é conhecida de antemão.
2. Em loop, pedir uma senha ao usuário até ele digitar `sair`.
3. Verificar cada regra separadamente:
   | Regra | Pontos |
   | --- | --- |
   | 8 caracteres ou mais | +1 |
   | 12 caracteres ou mais | +1 |
   | Tem letra minúscula | +1 |
   | Tem letra maiúscula | +1 |
   | Tem dígito | +1 |
   | Tem símbolo (ex.: `!@#$%`) | +1 |
   | Está na lista de senhas comuns (sem diferenciar maiúsculas) | **nota = 0**, independente do resto |
   | Tem 3 ou mais caracteres iguais seguidos (`aaa`, `111`) | −1 |
4. Classificar: 0–2 **Fraca**, 3–4 **Média**, 5–6 **Forte**.
5. Mostrar a nota **e o motivo de cada ponto perdido**:
   ```
   Senha: ********
   Nota: 3/6  ->  MEDIA
   [ok]  8+ caracteres
   [--]  12+ caracteres
   [ok]  minuscula
   [--]  maiuscula
   [ok]  digito
   [--]  simbolo
   ```
6. Ao sair, mostrar quantas senhas foram testadas e liberar **toda** a memória alocada com `free`.

## Tratamento de erros (obrigatório)

- `senhas-comuns.txt` não encontrado → avisar e continuar sem a verificação de lista. O programa não pode encerrar por isso.
- `malloc` retornou `NULL` → mensagem de erro e encerrar de forma limpa.
- Senha vazia → pedir de novo.
- Senha maior que o buffer (ex.: 64 caracteres) → recusar a senha e **limpar o resto da entrada**, para que a próxima leitura não receba lixo.
- Remover o `\n` que o `fgets` deixa no final da string.

## Critérios de aceite

- [ ] `123456`, `password` e `Password` dão nota 0, porque estão na lista.
- [ ] `aB3$aB3$aB3$` dá nota 6 (Forte).
- [ ] `aaaB3$xyz` perde 1 ponto pela repetição.
- [ ] Uma senha com 200 caracteres não trava o programa nem afeta a próxima leitura.
- [ ] Todo `malloc` tem um `free` correspondente.
- [ ] Compila com `gcc -Wall -Wextra` sem warnings.

## Extras (opcionais)

- Esconder a senha na tela (não mostrar o texto digitado).
- Detectar sequências como `abc`, `123` e `qwerty`.
- Estimar o tempo de quebra por força bruta a partir do tamanho do alfabeto usado e do comprimento da senha.

## Conceitos praticados

Alocação dinâmica (`malloc`, `realloc`, `free`), ponteiros, strings, `ctype.h` (`islower`, `isupper`, `isdigit`), leitura de arquivo, validação de entrada, tratamento de erros.
