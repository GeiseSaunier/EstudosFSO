### Aula 07: Wait () e Tratamento de sinais

*Aula disponível em:* https://www.youtube.com/watch?v=wEMWSbgnJSA&list=PLzZut2slkqyyO_FUNxbcKIYmGK6dZNbkV&index=10

https://www.youtube.com/watch?v=bkmi09L98-g&list=PLzZut2slkqyyO_FUNxbcKIYmGK6dZNbkV&index=11

#### Wait
* man wait
* Entra no estado de bloqueado até que um filho termine
* O processo pai espera o processo filho morrer, para logo depois morrer também
* Se o processo pai tiver mais que um filho, é preciso rodar um wait para cada filho

**Função específica:**
* WEXITSTATUS(wstatus): retorna o status/código de saída do processo filho. Consiste nos últimos 8 bits menos significativos do argumento de status.

#### Sinais
* kill() - chamada de processos que envia sinais
* São notificações assíncronas entre processos
* "Interrupções por software"
* Cada signal corresponde a uma constante inteira
* Alguns sinais são pré-definidos (função ou uso pré-determinados)
* Existem sinais cuja funcionalidade pode ser definida por programas de usuários
* Sinais podem vir de um mesmo processo ou ser "enviados" de um processo para outro:
    * root manda para qualquer um, usuário manda para usuário
* É possível definir procedimentos (funções) em programas que serão executados quando o processo for notificado por algum sinal.
  
