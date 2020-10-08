### Aula 08: Threads

*Aula disponível em:* http://www.brunoribas.com.br/so/2020-1/pratica/lab_pthreads.pdf

#### Introdução

A linguagem  C  não  possui  nenhum  recurso  nativo  para  permitir  a  programacao concorrente. Contudo,  este problema pode ser contornado utilizando-se uma bibliteca que provê a abstracao de pthreads.  **Uma pthread seria uma nova linha de execução, ou seja, uma função que será executada concorrentemente com as outras pthreads/processos que existirem no sistema operacional.**

#### Definição de Thread

Uma thread é definida como sendo **um fluxo de execução independente.** Um processo pode conter uma ou mais threads, cada uma executando seu próprio código e compartilhando recursos com as demais threads localizadas no mesmo processo. **Cada thread é caracterizada por um código em execução e um pequeno contexto local, o chamado Thread Local Storage(TLS), composto pelos registradores do processador e uma área de pilha em memória, para que a thread possa armazenar variáveis locais e efetuar chamadas de funções.**

#### Compilação de programas concorrentes

A biblioteca pthreads precisa ser inserida ao compilar o programa fonte.cusando a opção **-l(library)gcc meu_programa.c -lpthreads -o meu_programa**

#### Criação das Threads 

A criação de uma thread necesseita de um identificador: pthread_t id. Todas as operações serão realizadas sobre este identificador. A função para criar uma thread  ́e: 
   
    **int  pthread_create(pthread_t *thread , const  pthread_attr_t *attr , void  *(* start_routine)(void *), void *arg);**

 O primeiro paraâmetro e a identificação da thread, o segundo são os atributos que podem ser deixados como NULL(atributos default), o próximo parâmetro  ́e o endereço da função alvo que será executada e o último parâmetro são os parâmetros desta função alvo.  Percebe-se que a função alvo deve ser uma função que retorna um ponteiro genérico(void *) e tem como parâmetro um ponteiro genérico também. 
        
    Exemplo: **pthread_create (&id, NULL, (void *) minha_thread,NULL);**

#### Terminação de uma Thread

Uma thread pode ser terminada com a função **pthread_exit(NULL);** o parâmetro desta função será o valor de retorno da thread.  Se a thread em questão fica num loop infinito, ela jamais terminará e assimn ̃ao precisa chamar **pthread_exit.**
Note ainda que quando as 2 threads foram disparadas na função main existem 3 linhas de execuçao. Uma para cada thread e outra da própria função main.  No exemplo, a função main fica num loop sem fim.  Se aquele loop não existisse, a função main chamaria return e terminaria o processo (matando todas as threads que estivessem executando). A função main pode ser codificada para ao invés de ficar num loop sem fim, aguardar o término de uma thread usando a função: **int pthread_join(pthread_t th, void thread_return);**
O primeiro parâmetro é a identificação da thread e o segundo parâmetro é o retorno que a tal thread fornece. Quando não existe interesse em verificar o retorno pode-se chamar **pthread_join( thread1, NULL);**

### Modelos de Threads

As threads contidas nos processos, definidas no espaço de usuário, devem ser gerenciadas pelo núcleo do sistema operacional. Essa gerência pode ser feita de diversas formas, sendo elas:

#### O modelo N:1

N threads dentro de um processo são mapeadas em uma única thread no núcleo.
O modelo de threads N:1 é muito utilizado, por ser leve e de fácil implementação. Como o núcleo somente vê uma thread, a carga de gerência imposta ao núcleo é pequena e não depende do número de threads dentro da aplicação. 

Por outro lado, temos alguns problemas:

* As operações de entrada/saída são realizadas pelo núcleo;  se uma thread de usuário  solicitar  uma  leitura  do  teclado,  por  exemplo,  a thread de  núcleo correspondente será suspensa até a conclusão da operação, bloqueando todas as threads daquele processo;
* o núcleo do sistema divide o tempo de processamento entre as threads de núcleo. Assim, um processo com 100 threads irá receber o mesmo tempo de processador que outro com apenas uma thread, ou seja, cada thread do primeiro processo irá receber 1/100 do tempo que recebe a thread única do outro processo;
* threads do  mesmo  processo  não  podem  executar  em  paralelo,  mesmo  se  o computador dispuser de vários processadores ou cores, porque o núcleo somente escalona as threads de núcleo nos processadores;

#### O modelo 1:1

Para cada thread de usuário foi então associado um thread correspondente dentro do núcleo, suprimindo com isso a necessidade de bibliotecas de threads.
O modelo 1:1 resolve vários problemas: caso uma thread de usuário solicite uma operação bloqueante, somente sua thread de núcleo correspondente será suspensa, sem afetar as demais threads do processo. Além disso, a distribuição de processamento entre as threads é mais justa e, caso o hardware tenha mais de um processador, mais threads do mesmo processo podem executar ao mesmo tempo, o que não era possível no modeloN:1.

#### O modelo N:M

Para resolver o problema de escalabilidade da abordagem 1:1, alguns sistemas operacionais implementam um modelo híbrido, que agrega características dos modelos anteriores. Nesse novo modelo, uma biblioteca gerencia um conjunto de N threads de usuário (dentro do processo), que é mapeado em M < N threads no núcleo.

O conjunto de threads de núcleo associadas a um processo, denominado thread pool, geralmente contém uma thread para cada thread de usuário bloqueada, mais uma thread para cada processador disponível; esse conjunto pode ser ajustado dinamicamente,conforme a necessidade da aplicação.

Ele alia as vantagens de maior interatividade do modelo 1:1 à maior escalabilidade do modelo N:1. 

Como desvantagens desta abordagem podem ser citadas sua complexidade de implementação e maior custo de gerência dos threads de núcleo, quando comparados ao modelo 1:1.