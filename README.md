# arvore-de-processos

A ordem de execução de N1, N2, N3 e N4 não é determinística.
O que acontece no programa é:

## P1 (pai) cria dois filhos: F1 e F2.
### F1 cria os processos:

- N1 → executa /bin/date
- N2 → executa /bin/pwd

### F2 cria os processos:

- N3 → executa /bin/ls
- N4 → executa /usr/bin/whoami

## Pontos importantes:

- O escalonador do SO decide qual processo roda primeiro, então:
  - N1 não é garantido executar antes de N2, nem o contrário.
  - O mesmo vale para N3 e N4.
- Também não existe ordem garantida entre os grupos:
  -(N1, N2) vs (N3, N4)

- O wait() não define ordem de execução, apenas garante que:
  -F1 espere N1 e N2 terminarem
  -F2 espere N3 e N4 terminarem
  -P1 espere F1 e F2 terminarem

<img width="740" height="555" alt="unnamed" src="https://github.com/user-attachments/assets/491c5e9b-2187-42f8-ab0f-1d0e40469c50" />
