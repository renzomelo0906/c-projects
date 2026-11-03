# analisador-logs

> 🚧 **Enunciado:** este projeto ainda não foi implementado. Ao terminar, troque esta seção por uma descrição do que o programa faz.

## Objetivo

Escrever um programa em C que lê um arquivo de log de autenticação (no estilo do `/var/log/auth.log` do Linux), conta as **tentativas de login com falha por IP** e aponta os IPs suspeitos de ataque de força bruta.

## Arquivo de entrada

O arquivo [`auth.log`](auth.log) desta pasta serve para teste. As linhas que interessam têm este formato:

```
Nov  2 03:14:07 server sshd[1201]: Failed password for root from 185.220.101.4 port 52144 ssh2
Nov  2 03:15:40 server sshd[1213]: Failed password for invalid user admin from 45.95.147.12 port 40022 ssh2
Nov  2 08:02:11 server sshd[1450]: Accepted password for renzo from 192.168.0.15 port 51320 ssh2
```

O arquivo também tem linhas que **não** são de login (CRON, sudo, etc.). Elas devem ser ignoradas.

## Requisitos

1. O programa pede o **nome do arquivo** e o **limite de tentativas** (ex.: 5). Um IP com falhas **maior ou igual** ao limite é considerado suspeito.
2. Ler o arquivo linha por linha.
3. Para cada linha com `Failed password`, extrair o **IP** e o **usuário** tentado.
4. Guardar os dados num array de `struct`, com uma entrada por IP:
   ```c
   struct RegistroIP {
       char ip[16];
       int falhas;
       char ultimoUsuario[32];
   };
   ```
5. Contar também os logins com sucesso (`Accepted password`).
6. Mostrar um relatório no terminal (os números abaixo só ilustram o formato):
   ```
   Linhas lidas:        42
   Logins com sucesso:  3
   Logins com falha:    31
   IPs diferentes:      6

   IPs SUSPEITOS (>= 5 falhas):
   185.220.101.4     14 falhas   (ultimo usuario: root)
   45.95.147.12       9 falhas   (ultimo usuario: admin)
   ```
7. Salvar os IPs suspeitos num arquivo `suspeitos.txt`, um IP por linha. Esse é o formato de uma blocklist.

## Tratamento de erros (obrigatório)

- Arquivo que não existe → mensagem clara (use `perror` ou `errno`) e o programa encerra sem travar.
- Limite inválido (letras, zero ou negativo) → pedir de novo.
- Linha malformada (ex.: `Failed password` sem IP) → ignorar a linha, sem travar.
- Mais IPs do que cabem no array → avisar e parar de adicionar. Outra opção é usar `malloc`/`realloc` (veja os extras).
- Não pode haver estouro de buffer: usuário ou IP maior que o tamanho do campo deve ser cortado ou ignorado.

## Critérios de aceite

- [ ] Com o `auth.log` desta pasta e limite 5, o relatório bate com uma contagem manual.
- [ ] Linhas que não são de login não entram em nenhuma contagem.
- [ ] `suspeitos.txt` é criado e contém só os IPs suspeitos.
- [ ] Nenhuma entrada inválida faz o programa travar.
- [ ] Compila com `gcc -Wall -Wextra` sem warnings.

## Extras (opcionais)

- Usar `malloc`/`realloc` para o array crescer sem limite fixo.
- Ordenar os suspeitos do que tem mais falhas para o que tem menos.
- Receber o arquivo por argumento: `./analisador auth.log 5`.

## Conceitos praticados

`struct`, arrays, strings (`strstr`, `sscanf`, `strncpy`), leitura e escrita de arquivos, validação de entrada, tratamento de erros.
