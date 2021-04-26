# Meccanismo di spinta
Il programma ho lo scopo di creare un meccanismo di spinta, normale o deviato, tramite parametri inseriti dall'utente.

## Codice
Il codice e' stato scritto in modo da poter permettere di utilizzare singolarmente ogni device di cui e' composto il meccanismo, infatti ogni devace e' messo in una libreria diversa con le sue funzioni.

### Pistone 
Parte del meccanismo che scorre in orizzontale. E' possibile imporre la posizione e la lunghezza della base, gli altri parametri vengono ricavati automaticamente. Le informazioni vengono salvare in una struttura detta Pistone.
Sono presenti 4 funzioni:

-pist_init: crea la truttura contenente i dati del pistone

-pist_svg: crea un stringa in svg della struttura pistone che stova in ingresso

-pist_new: crea una nuova struttura di un pistone letta da una stringa

-pist_del: pulisce lo spazio occupato dalla truttura del pistone

### Biella 
Parte del meccanismo che collega la manovella ed il pistone. Puo' essere creada specificando la posizione, la lunghezza e la rotazione. Anche in questo caso i dati sono salvati all'interno di una struct detta Biella. Sono presenti le stesse 4 funzini del pistone adattate per la biella.

### Manovella
Parte del meccanismo che gira attorno ad un punto fisso. Puo' essere creada specificando la posizione, la lunghezza e la rotazione. I dati vengono salvati all'interno di una struttura detta Manovella. Le funzioni sono le stesse presenti nelle due librerie precedenti.

### Svg
In questa libreria sono presenti le funzioni che permettono di salvare o di caricare su un file il codice svg.
Le funzioni presenti sono:

-svg: riceve in ingresso il codice svg dei componenti e crea una stringa pronta per essere salvata su file 

-svg_to_file: riceve in ingresso una stringa e la salva su un file

-svg_read: legge un file e salva in una stringa il codice svg



### Meccanismo
