/*
  I metodi in C++ sono siffatti:
  [virtual] type nomeMetodo(parametri) [const] [noexcept] [override] [=assignment]

  virtual:
  const: il metodo non può modificare le variabili della ClassName
  noexcept: già visto. Non può sollevare eccezioni pena l'aborto del programma
  override: il metodo sovrascrive un metodo nella gerarchia
  assignment: può essere:
              = 0: pure virtual. A questo livello l'implementazione di questo metodo non esiste
              = default: ammesso solo per cost. e dist. che dice di creare quelli di default
              =delete: elimina un metodo precedentemente scritto nella gerarchia

*/
