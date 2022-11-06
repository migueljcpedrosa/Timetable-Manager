# HorarioVF
LEIC-FEUP, 2nd Year, AED

Timetable management program.

O programa está organizado em várias classes. 
A classe Estudante, que guarda os atributos de do estudante, bem como um vetor de todas as aulas (UcClasses) em que o estudante está inscrito. 
A classe Slot, guarda os atributos correspondentes ao horário de cada UcClass (aula): dia da semana, hora de início, duração e tipo de aula (teórica e teórico-prática). 
A classe UcTurma, guarda o número máximo de estudantes numa UcTurma(aula)
A classe Pedido guarda informações sobre o pedido de alteração de horário/turma/aula: código do estudante cujo horário/turma/aulas pretendemos alterar; código Up da UcClass que pretendemos adicionar/remover/trocar; código Class da UcClass que pretendemos adicionar/remover/trocar; tipo de pedido de alteração (“add”, “remove”, “change”).
A classe BaseMenu que tem um método de display do menu principal e chama a função de display de cada um dos menus secundários, dependendo do input do utilizador.
A classe ListingMenu, que tem um método de display do menu de listagens.
A classe ChangeMenu, que tem um método de display do menu de alterações e que guarda todos os pedidos numa queue, para serem executados mais tarde. Os  pedidos não executados serão guardados numa outra queue de pedidos falhados, para depois serem executados ou revistos. Por fim, as alterações são escritas num ficheiro  (students_classes_updated.csv)
As funções que não incluímos em nenhuma das classes foram colocadas num namespace TTM 

Usamos as seguintes estruturas:
Um vetor de objetos do tipo Estudante (cada estudante tem o seu objeto, construído durante a leitura do ficheiro).
Decidimos usar dois map, por serem internamente representados como “binary search trees”, tornando a pesquisa mais eficiente.
Um mapUcClassTimeSlot, que faz corresponder a cada UcClass ( par (ucCode, classCode) (aula)  ) o Slot correspondente.
Um mapUcClassNumberStudents, que faz corresponder a cada UcClass ( par (ucCode, classCode) (aula)  ) o número de estudantes inscritos.
Uma queuePedido (FIFO), que armazena objetos do tipo Pedido (com os inputs inseridos pelo utilizador) para executar mais tarde.
Um queue PedidoFailed, (FIFO) que armazena os objetos do tipo Pedido (com os inputs inseridos pelo utilizador) que se encontravam anteriormente na queuePedido e que não foram executados.

Funcionalidades:
Leitura:
1.	Leitura dos ficheiros csv
Escrita:
1.	Leitura de um novo ficheiros csv com as alterações
Listagens:
1.	Display de todos os estudantes ordenados por alfabeticamente.
2.	Display do horário ordenado de um estudantes.
3.	Display de todos os estudantes inscritos em mais de n aulas (UcClasses)
4.	Display de todos os estudantes numa aulas (UcClass)
5.	Display de todos os estudantes num certo ano.
Alterações:
1.	Remover estudante de turma.
2.	Adicionar estudante a turma, tendo em conta as condições enunciadas.
3.	Mudar estudante de turma, tendo em conta as condições enunciadas.

Funções importantes:
addStudentToClass()
1.	Imprime as turmas em que o estudante estava inscrito antes da alteração
2.	Percorre  a lista de UcClasses do estudante para verificar se ele já estava inscrito nessa aula.
3.	Se o estudante ainda não estiver inscrito nessa aula:
  a.	Verifica se a operação não vai exceder a capacidade da turma
  b.	Verifica se a operação não vai provocar desequilíbrio na turma
    i.	Vê o número de estudantes na turma da UC com menos estudantes. 
    ii.	Vê o número de estudantes na turma da UC com mais estudantes.
    iii.	Subtrai o número mínimo de estudantes ao numero máximo; verifica se a diferença é maior ou igual a 4
4.	Imprime  as turmas em que o estudante está inscrito após a alteração.
5.	Caso a alteração não possa ser executada imprime uma mensagem de erro.

csvStudentsReader()
1.	Lê cada linha do ficheiro students_classes.csv, descartando a primeira.
2.	Por cada linha que lê cria um objeto correspondente ao estudante (se ele ainda não existir), inicializa os seus atributos com a informação lida e insere-o no vectorEstudantes.
3.	Atualiza também os contadores do número de estudantes em cada UcClass (aula) no mapUcClassesNumberStudents.
4.	Caso não consiga abrir o ficheiro, uma mensagem de erro é impressa.
