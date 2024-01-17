<h1>Entendendo o problema...</h1>
<h2>application.py</h2>
Abra application.py. No topo do arquivo estão várias importações, entre elas o módulo SQL do CC50 e algumas funções auxiliares. Mais sobre isso em breve.

Depois de configurar o Flask, observe como este arquivo desativa o cache de respostas (desde que você esteja no modo de depuração, que você está por padrão no IDE CS50), para que não faça uma alteração em algum arquivo, mas seu navegador não perceba. Observe a seguir como ele configura o Jinja com um “filtro” personalizado, usd , uma função (definida em helpers.py) que tornará mais fácil formatar valores como dólares americanos (USD). Em seguida, ele configura o Flask para armazenar sessões no sistema de arquivos local (ou seja, disco) em vez de armazená-las dentro de cookies (assinados digitalmente), que é o padrão do Flask. O arquivo então configura o módulo SQL do CC50 para usar finance.db, um banco de dados SQLite cujo conteúdo veremos em breve!

Depois disso, há um monte de rotas, das quais apenas duas estão totalmente implementadas: login e logout. Leia a implementação do login primeiro. Observe como ele usa db.execute (da biblioteca do CS50) para consultar finance.db . E observe como ele usa check_password_hash para comparar hashes de senhas de usuários. Finalmente, observe como o login “lembra” que um usuário está logado armazenando seu user_id, um INTEGER, na session. Dessa forma, qualquer uma das rotas desse arquivo pode verificar qual usuário, se houver, está logado. Enquanto isso, observe como o logout simplesmente limpa a session , efetivamente desconectando um usuário.

Observe como a maioria das rotas são “decoradas” com @login_required (uma função definida em helpers.py também). Esse decorador garante que, se um usuário tentar visitar qualquer uma dessas rotas, ele será redirecionado primeiro para fazer o login.

Observe também como a maioria das rotas oferece suporte a GET e POST. Mesmo assim, a maioria deles (por enquanto!) Simplesmente retorna um “pedido de desculpas”, uma vez que ainda não foram implementados.

<h2>helpers.py</h2>
Em seguida, dê uma olhada em helpers.py. Ah, aí está a implementação de apology. Observe como, em última análise, ele renderiza um modelo, apology.html. Ele também define dentro de si mesmo outra função, escape, que ele simplesmente usa para substituir caracteres especiais em apology. Ao definir escape dentro de apology , limitamos o primeiro apenas ao último; nenhuma outra função será capaz (ou precisará) chamá-lo.

O próximo no arquivo é login_required. Não se preocupe se este for um pouco enigmático, mas se você já se perguntou como uma função pode retornar outra função, aqui está um exemplo!

Em seguida, é lookup, uma função que, dado um symbol (por exemplo, NFLX), retorna uma cotação de ações para uma empresa na forma de um dictionary com três chaves: name , cujo valor é um str, o nome da empresa; price , cujo valor é um float ; e symbol , cujo valor é str , uma versão canônica (maiúscula) do símbolo de uma ação, independentemente de como esse símbolo foi capitalizado quando passou para o lookup .

O último no arquivo é usd , uma função curta que simplesmente formata um valor float como USD (por exemplo, 1234,56 é formatado como $ 1.234,56 ).

<h2>requirements.txt</h2>
A seguir, dê uma olhada rápida em requirements.txt. Esse arquivo simplesmente prescreve os pacotes dos quais este aplicativo dependerá.

<h2>static/</h2>
Dê uma olhada também em static/, dentro do qual está styles.css. É aí que residem alguns CSS iniciais. Você pode alterá-lo como achar necessário.

<h2>templates/</h2>
Agora olhe em templates/. Em login.html tem, essencialmente, apenas um formulário HTML, estilizado com Bootstrap. Em apology.html , entretanto, esta um modelo para um pedido de desculpas. Lembre-se de que o apology em helpers.py recebeu dois argumentos: message , que foi passada para render_template como o valor de bottom e, opcionalmente, code , que foi passado para render_template como valor de top . Observe em apology.html como esses valores são finalmente usados! E aqui está o porquê 0 :-)

O último é layout.html . É um pouco maior do que o normal, mas principalmente porque vem com uma “navbar” (barra de navegação) sofisticada e otimizada para dispositivos móveis, também baseada no Bootstrap. Observe como ele define um bloco, main , dentro do qual os modelos (incluindo apology.html e login.html ) devem ir. Também inclui suporte para flash de mensagem do Flask para que você possa retransmitir mensagens de uma rota para outra para o usuário ver.

<h1>Especificação</h1>
<h2>register</h2>

Concluir a implementação do register de forma a permitir ao utilizador o registo de uma conta através de um formulário.

Exigir que um usuário insira um nome de usuário, implementado como um campo de texto cujo name é username . Peça desculpas se o input do usuário estiver em branco ou se o nome de usuário já existir.
Exigir que um usuário insira uma senha, implementada como um campo de texto cujo name é password e, em seguida, essa mesma senha novamente, implementada como um campo de texto cujo nome é confirmação . Peça desculpas se a entrada estiver em branco ou se as senhas não corresponderem.
Envie a entrada do usuário via POST para /register .
INSERT o novo usuário em users , armazenando um hash da senha do usuário, não a senha em si. Hash a senha do usuário com generate_password_hash As chances são de você querer criar um novo modelo (por exemplo, register.html ) que é bastante semelhante ao login.html .
Depois que o usuário estiver registrado, você pode fazer login automaticamente no usuário ou levá-lo a uma página onde ele mesmo possa fazer o login.
Depois de implementar o register corretamente, você deve ser capaz de registrar uma conta e fazer o login (já que o login e o logout já funcionam)! E você deve ser capaz de ver suas linhas via sqlite3 ou phpLiteAdmin.

<h2>quote</h2>

Conclua a implementação de quote de forma que permita ao usuário consultar o preço atual de uma ação.

Exigir que um usuário insira um símbolo de ação, implementado como um campo de texto cujo name é symbol .
Envie a entrada do usuário via POST para /quote .
Você provavelmente vai querer criar dois novos modelos (por exemplo, quote.html e quoted.html ). Quando um usuário visita /quote via GET, renderiza um desses modelos, dentro do qual deve estar um formulário HTML que é submetido a /quote via POST. Em resposta a um POST, o quote pode renderizar aquele segundo template, incorporando nele um ou mais valores de lookup .
<h2>buy</h2>

Concluir a implementação de buy de forma que permita ao usuário comprar ações.

Exigir que um usuário insira um símbolo de ação, implementado como um campo de texto cujo name é symbol . Peça desculpas se a entrada estiver em branco ou se o símbolo não existir (de acordo com o valor de retorno de lookup ).
Exigir que um usuário insira um número de ações, implementado como um campo de texto cujo name é shares . Peça desculpas se a entrada não for um número inteiro positivo.
Envie a entrada do usuário via POST para /buy .
Provavelmente, você vai querer chamar lookup para consultar o preço atual de uma ação.
Provavelmente, você vai querer SELECT quanto dinheiro o usuário tem atualmente em users .
Adicione uma ou mais novas tabelas a finance.db por meio das quais você pode controlar a compra. Armazene informações suficientes para saber quem comprou o quê, a que preço e quando.
Use os tipos SQLite apropriados.
Defina índices UNIQUE (unicos) em quaisquer campos que devam ser exclusivos.
Defina índices (não-UNIQUE ) em quaisquer campos pelos quais você fará a pesquisa (como por meio de SELECT com WHERE ).
Peça desculpas, sem concluir a compra, se o usuário não puder pagar o número de ações no preço atual.
Quando a compra for concluída, redirecione o usuário de volta à página de index .
Você não precisa se preocupar com as condições de corrida (ou usar transações).
Depois de implementar buy corretamente, você poderá ver as compras dos usuários em sua(s) nova(s) tabela(s) via sqlite3 ou phpLiteAdmin.

index

Conclua a implementação de index de forma que exiba uma tabela HTML resumindo, para o usuário atualmente conectado, quais ações o usuário possui, o número de ações que possui, o preço atual de cada ação e o valor total de cada ação (ou seja, ações vezes preço). Também exibe o saldo de caixa atual do usuário junto com um total geral (ou seja, o valor total das ações mais dinheiro).

É provável que você queira executar vários SELECT s. Dependendo de como você implementar sua (s) tabela (s), você pode achar GROUP BY HAVING SUM e / ou WHERE de interesse.
Provavelmente, você deseja chamar lookup para cada ação.
<h2>sell</h2>

Conclua a implementação de sell de tal forma que permita a um usuário vender ações (que ele ou ela possui).

Exigir que um usuário insira um símbolo de ação, implementado como um menu de select cujo name é symbol . Peça desculpas se o usuário deixar de selecionar uma ação ou se (de alguma forma, uma vez enviada) o usuário não possui nenhuma ação dessa empresa.
Exigir que um usuário insira um número de ações, implementado como um campo de texto cujo name é shares . Peça desculpas se a entrada não for um número inteiro positivo ou se o usuário não possuir tantas ações do estoque.
Envie a entrada do usuário via POST para /sell.
Quando a venda for concluída, redirecione o usuário de volta à página de index .
Você não precisa se preocupar com as condições de corrida (ou usar transações).
<h2>history</h2>

Conclua a implementação do histórico de tal forma que exiba uma tabela HTML resumindo todas as transações de um usuário, listando linha por linha cada compra e cada venda.

Para cada linha, deixe claro se uma ação foi comprada ou vendida e inclua o símbolo da ação, o preço (de compra ou venda), o número de ações compradas ou vendidas e a data e hora em que a transação ocorreu.
Pode ser necessário alterar a tabela criada para buy ou complementá-la com uma tabela adicional. Tente minimizar redundâncias.
<h2>toque pessoal</h2>

Implemente pelo menos um toque pessoal de sua escolha:

Permitir que os usuários alterem suas senhas.
Permitir que os usuários adicionem dinheiro em suas contas.
Permite que os usuários comprem mais ações ou vendam ações que já possuem através do próprio index , sem ter que digitar os símbolos das ações manualmente.
Exigir que as senhas dos usuários tenham um certo número de letras, números e/ou símbolos.
Implemente algum outro recurso de escopo comparável.

PARA USAR ESSE PROGRAMA, PEGUE UMA API KEY SE REGISTRANDO EM:iexcloud.io/cloud-login#/register/.

DEPOIS ACESSE:https://iexcloud.io/console/tokens