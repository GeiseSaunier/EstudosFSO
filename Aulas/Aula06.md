### Aula 06: Criando processos, chamadas de sistema FORK 

*Aula disponível em:* https://www.youtube.com/watch?v=KE1wb9uvTuk&list=PLzZut2slkqyyO_FUNxbcKIYmGK6dZNbkV&index=8

https://www.youtube.com/watch?v=7Ag2raA18bo&list=PLzZut2slkqyyO_FUNxbcKIYmGK6dZNbkV&index=9

**Criação de processos:**

Hierarquia de processos:

* Processo cria um outro processo = processo pai cria um processo filho (clone do pai);
* Processos filhos podem criar outros processos filhos;
* Podem executar concorrente (pais e filhos);
* Processo pai pode esperar o filho terminar
    * wait()

Endereçamento
* Filho é uma duplicada do pai
* Filho tem programa carregado do pai (substituição)

Criar o processo

* Fork()
    * Função que retorna 2 vezes (retorna uma vez no pai e uma vez no filho)
    * Se ele retornar 0 - está no filho
    * Se ele retornar um valor > 0 - está no pai e o número é o PID do filho
    * Se ele retornar um valor negativo - o fork() falhou (-1)
    * O fork pode falhar se for extrapolado o número de processos 

**OBS:** se o processo filho morre, mas o pai não pega o retorno disso, o processo vira um "zumbi" e não da pra matar esse processo. Se o processo pai morre antes do processo filho, o processo anterior passa a ser o pai desse filho.

**Atenção:** O que acontece quando o processo pai morre e o filho vai devolver o valor? 
* CASO ESPECIAL!
* O processo pai do filho passa a ser o INIT. (O INIT evita a existência de novos zumbis)

**Prática**

pstree - mostra os processos em execução.

