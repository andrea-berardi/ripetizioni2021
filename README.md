# Ripetizioni 2021

Repo degli esercizi per le ripetizioni date nel 2021.

## Esercizi per Recupero Estivo

[x] Esercizi risolti della cartella `recupero_estivo`

- [x] Esercizio 1
- [x] Esercizio 2
- [x] Esercizio 3
- [x] Esercizio 4
- [x] Esercizio 5
- [x] Esercizio 6
- [x] Esercizio 7
- [x] Esercizio 8
- [x] Esercizio 9
- [x] Esercizio 10
- [x] Esercizio 11
- [x] Esercizio 12

## NB (per gli alunni)

> Ossia Nota Bene, non Non Badare

Le soluzioni seguono in buona parte le richieste degli esercizi, ma le modalità di risoluzione potrebbero non essere le migliori (non definiamo mai una funzione - e invece...), oppure le più facili in assoluto, oppure potrebbero comprendere concetti al di fuori del programma.  
Non seguirle pari-pari!  

Spesso, piuttosto che avere a che fare con `malloc()` e simili è meglio dare una lunghezza fissa ad array etc... oppure usare C++ che rende alcuni aspetti più facili.  
Ho preferito usare C per pura comodità mia, a dispetto delle richieste degli esercizi che volevano C++.  

Non è nemmeno detto che le soluzioni corrispondano a ciò che ho spiegato durante la lezione, infatti spesso glisso riguardo all'allocazione dinamica.  
Tutti gli esercizi sono comunque ANSI C, per cui anche compilando con il compiler per C++ funzioneranno (in teoria, si spera).

Non fatemi mettere una licenza, per l'amor di Dio, riuscite a gestirvi anche senza.  
Per problemi riguardo agli esercizi aprite una Issue o fate una PR. Ma anche no, grazie.

## Mettiamo le mani avanti... ancora (per i prof.)

> Spieghiamo o ripetiamo il perché di alcune scelte estremamente discutibili

Come mai ho fatto questo piuttosto che quello? Beh, comodità e pigrizia, soprattutto.

Inoltre, mi è stato detto da alcuni ragazzi che certi prof. prediligono schifezze quali variabili globali, dichiarazioni di variabili nello stesso punto a inizio programma (anziché vicino al punto di utilizzo) e simili: ponendo sia vero ciò che mi è stato detto, in questi casi la cortesia di aderire alle richieste dei professori viene di gran lunga superata dalla necessità di evitare tali indecenze.

Comunque sia, iniziamo...

### Esercizio 01

Ho provato ad usare il dato del punto 1 nel punto 3 perdendo in chiarezza, probabilmente.

### Esercizio 02

Ho usato l'allocazione dinamica anziché creare fin da subito un array sufficientemente grande.

Non me ne pento ma diventa molto più complicato per un alunno delle superiori. A lezione non ho usato questo metodo, comunque.

### Esercizio 03

Vedi il punto sopra, e moltiplicalo per 100 volte.

### Esercizio 04

Tutto abbastanza normale qua.

### Esercizio 05

Qui, e anche in altri esercizi, ho riutilizzato lo stesso contatore per dati diversi.

Non che il valore precedente servisse ancora - è già stato stampato nel momento in cui viene sovrascritto, ma sicuramente è meno chiaro.

### Esercizio 06

Vedi punto 3, moltiplicalo per 200. Ho dovuto anche fare magheggi con la `scanf()` per far andare tutto.

Qui forse sarebbe stato più intelligente usare C++ come richiedevano gli esercizi, ma anche no.

### Esercizio 07

Tutto abbastanza normale.

### Esercizio 08

Tutto abbastanza normale anche qui.

### Esercizio 09

Bene anche qua.

### Esercizio 10

Anche qui usiamo la stessa variabile più volte, azzerandola, come nell'esercizio 5.

### Esercizio 11

Lasciamo perdere, dai.

Siccome il testo questa volta non specificava di usare degli array paralleli ho ben pensato di usare un array di `struct`.

Personalmente preferisco questo approccio agli array paralleli, anche per evitare di cadere nella _primitive obsession_.

In programmi così banali non sarebbe un problema, ma meglio non prendere l'abitudine, no?

In ogni caso a lezione uso per semplicità gli array paralleli, ma faccio sapere dell'alternativa.

### Esercizio 12

Vedi sopra

## Considerazioni finali

Pensavo inoltre che non ho la certezza che alcuni dei magheggi con la `scanf()` funzionino su ogni OS, ma non mi metto di certo a verificare.

Ogni esercizio _works on my machine_, che è ciò che importa, no? Testati su GNU/Linux.
