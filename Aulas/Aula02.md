### Aula 02: O que é um Sistema Operacional?

*Aula disponível em:* https://www.youtube.com/watch?v=WRo09dUMkEY&list=PLzZut2slkqyyO_FUNxbcKIYmGK6dZNbkV&index=3

**Sistema Operacional:** conjunto de um ou mais programas que fornecem um conjunto de serviços e cria uma interface entre aplicações e o hardware do computador, alocando recursos compartilhados entre os processos.

De forma mais simples, im SO é um conjunto de programas, cujo objetivo é gerenciar os recursos disponibilizados por um ou mais computadores.

    * Gerencia o compartilhamento de recursos entre entidades concorrentes;
    * Fornece vários serviços comuns que torna as aplicações mais fáceis de se escrever;
    * Serve como interface entre programas de aplicações e o hardware;
    * Não é somente kernel;
    * Conjunto de um ou mais programas que fornece um conjunto de serviços;
    * Gerencia recursos;
    * Atua como provedor de serviços.

**Áreas de responsabilidade de um SO:**

* Processos 
    * Criar 
    * Destruir 
    * Alterar prioridade
    * Mecanismo de comunicação
    * Mecanismo de sincronização

* Memória
    * Solicitar memória adicional 
    * Solicitar memória indiretamente 
    * Liberar memória para o SO
    * Solicitar áreas de memória para serem compartilhadas entre processos

* Dispositivos de entrada/saída
    * Abrir um dispositivo ou associar a um processo
    * Ler dados do dispositivo 
    * Gravar dados no dispositivo
    * Fechar ou liberar 
    * Fornecer acesso exclusivo a dispositivos apropriados

* Sistemas de Arquivos
    * Abrir um arquivo
    * Ler um arquivo
    * Gravar em um arquivo
    * Fechar um arquivo
    * Ler metadados (quem criou, data de criação, permissões)
    * Modificar os metadados

* Segurança
    * Configurar políticas (quem acessa o quê)
    * Procurar políticas
    * Autenticação
    * Criptografar e descriptografar mensagens

* Redes
    * Estabelecer uma conexão
    * Atenda conexões
    * Envie mensagens
    * Receba mensagens
    * Fechar uma conexão

* Interface com o usuário

**Técnicas de Organização do sistema**

* Monolítico: Um sistema monolítico é construído como uma coleção de rotinas onde cada uma pode chamar qualquer outra. 
* Camadas: tem níveis de abstração em relação ao kernel;
* Microkernel: cria um kernel muito pequeno e depois pendura outros módulos em cima do kernel, isto é, possui separação de funções chamadas servidores.
    * Minix
    * GNU Hurd
    * Mach (roda na apple)


