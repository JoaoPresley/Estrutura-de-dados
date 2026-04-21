# LISTA ENCADEADA

Hoje estava realizando alguns exercicios e fixando os aprendizados em estrutura de dados.
Dessa vez foi o momento de mergulhar nas listas simplemente e duplamente encadeada.

Como é costume de todo estudande utilizar a IA para auxiliar nos estudos, assim també fez esse humilde estudante.
Até que o codigo bugou, no momento de mostrar a lista ele estava colocando um lixo no meio:
    ```Lista encadeada: id: 14 id: 2 id: 3 id: -57849578 id: 3 id: 99 id: 1```
Observe o id negativo (id: -57849578) claramente um lixo que o C++ coloca. 
Então tentei analisar por conta, e falhei. Pedi para o Gemini ajudar, as respostas não estavam coerentes e nem resolvendo o problema.
E agora como resolver esse problema sem um professor do lado!!
São momentos como esse que nos traz os melhores aprendizados que podemos ter. CHEGOU A HORA DE DEBUGARR!!!
Foi quando coloquei a seguinte saida para o meu terminal:
      cout << "variaveis iniciais: \n tam: " << tam << "\n start: " << start << endl;
E entao me mostrou que as variaveis nao estavam sendo definidas, eram literalmente lixo.
Foi então que a IN(inteligencia natural mais conhecido como eu) levou esse dado para a IA que me mostrou uma peculariada C++ e C.
Quando se usa o typedef para declarar o nome no fim da estrutura (struct) ele passa primeiro por dentro da struct e depois a nomeia.
Plimmm ta ai o erro, o constructor nao esta funcionando pq a struct esta sem nome!!!
Solucao: Colocar o nome logo no inicio do codigo, com essa estrutura: struct nome{ ... }.
E ai sabia desse bizu de confusões C e C++?
Já passou por algum problema que a IA não conseguiu te ajudar?
