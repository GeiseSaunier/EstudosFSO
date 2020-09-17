### Questões Básicas

*Exercício disponível em:* http://www.brunoribas.com.br/so/2020-1/pratica/exercicios-basicos.html


1. Enumere e explique resumidamente as principais responsabilidades de um sistema operacional.

* Gerenciar o compartilhamento de recursos entre entidades concorrentes;
* Fornecer vários serviços comuns que torna as aplicações mais fáceis de se escrever;
* Servir como interface entre programas de aplicações e o hardware;
* Não é somente kernel;
* Conjunto de um ou mais programas que fornece um conjunto de serviços; * Gerenciar recursos;
* Atuar como provedor de serviços.

2. Qual é a diferença entre modo usuário e modo kernel? Por que esta distinção é feita?

**Modo kernel:** conhecido como privilegiado por ter acesso completo ao computador, a todas as partes do hardware.

**Modo usuário:** limita as ações para garantir a segurança e não comprometer nenhuma parte do próprio sistema. Neste modo é mais difícil de um aplicativo violar a privacidade de outro.

A razão para a distinção é que o kernel pode monitorar/controlar recursos critícos do sistema e proteger cada usuários dos outros.

3. Descreva como são implementados os seguintes eventos: **(i) chamada de sistema**, **(ii) tratamento de interrupção** e **(iii) tratamento de sinais**. Quais são as semelhanças e diferenças entre estes eventos?

**(i)** - As chamadas de sistemas são funções(interfaces) usadas pelos aplicativos para solicitar a execução de algum serviço ao kernel do sistema operacional.

**(ii)** - Para controlar entrada e saída de dados, não é interessante que a CPU tenha que ficar continuamente monitorando e verificando status de dispositivos cpmo discos ou teclados. O mecanismo de interrupções permite que o hardware "avise de alguma forma" a CPU quando há algo a ser feito.

**(iii)** - Um sinal é uma notificação assíncrona enviada a processos com o objetivo de notificar a ocorrência de um evento. Quando um sinal é enviado a um processo, o sistema operacional interrompe o seu fluxo normal de execução. A execução pode ser interrompida em qualquer operação que não seja atômica. Um processo pode registrar uma rotina de tratamento de sinal para tratar um determinado sinal, se não for desejado que a rotina padrão para este sinal seja executada.

4. Qual é a diferença entre um sistema monolítico e um baseado em camadas?

Em  um **sistema monolítico**, o SO inteiro é executado como um único programa no modo núcleo. Já no **baseado em camadas**, ele divide o sistema operacional em sistemas sobrepostos. Cada módulo oferece um conjunto de funções que pode ser usado por outros módulos.   



