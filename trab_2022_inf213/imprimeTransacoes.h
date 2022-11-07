//Voce devera utilizar essa funcao para a operacao imprimeTransacoes
//Ou seja, devera implementar um iterador (conforme abaixo) na classe Blockchain
//adicionalmente, sua classe Transaction devera ter um metodo "imprime"
//Se modificar algo aqui seu programa podera nao compilar no submitty 
//Este codigo nao precisa ser enviado (o submitty usara uma copia original dele)
void imprimeTransacoes(const Blockchain &bc) {
    for(Blockchain::TransactionIterator it = bc.transactionBegin();it!=bc.transactionEnd();it++) {
		(*it).imprime();
	}
}

//NAO MODIFIQUE NADA AQUI..
//NAO MODIFIQUE NADA AQUI..
//NAO MODIFIQUE NADA AQUI..
