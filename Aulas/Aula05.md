### Aula 05: Estado dos Processos

*Aula disponível em:* https://www.youtube.com/watch?v=qVYqE4Ov8ms&list=PLzZut2slkqyyO_FUNxbcKIYmGK6dZNbkV&index=6

**Programa vs Processo**

* Programa: é o arquivo binário, que tá no disco não faz nada.
* Processo: programa em execução, carrega na memória.

**Chamadas de sistema:**

* fork() - 
* exit() - finaliza processo
* open() - abre um arquivo
* read() - faz leitura de dados do arquivo
* write() - faz a gravação de dados no arquivo

**Estados do Processo:**
    * 1. Executando
    * 2. Bloqueado
    * 3. Pronto

**Tabela de processos:**

    Possui informações sobre os processos
        * Registradores salvos
        * Estado do processo
        * ID do processo (PID)
        * ID do proprietário
        * ID do grupo
        * Prioridade
        * Utilização e mapeamento de memória
        * Status dos arquivos abertos
**CISC**

* Significa um conjunto de instruções complexas. Instrução que salva os dados de todos os registradores.

**RISC**

* Significa um conjunto de instruções reduzidas. Reserva alguns registradores para o SO.

**Troca de contexto**

* Custo direto
    * Copiar os valores dos registradores
    * Escalonador: escolher o próximo processo
* Custos indiretos
    * Invalidação dos caches
    * Espera as instruções no PIPELINE terminar
