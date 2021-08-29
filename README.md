# Ripetizioni 2021

Repo degli esercizi per le ripetizioni date nel 2021.

## Esercizi sparsi

Esercizi scelti a caso dal libro _C++. Teoria e ambiente di programmazione_ (**ISBN-10**: `8826816743`, **ISBN-13**: `978-8826816746`) di Agostino Lorenzi e Vittorio Moriggia.

Siccome non ho voglia di studiarmi come funziona la SIAE per queste cose mi limiterò a pubblicare le soluzioni e **non** il testo degli esercizi. Chi non avesse il libro in questione può acquistarlo, prenderlo in prestito in biblioteca o piratarlo... però suvvia, seriamente, non fate i morti di fame, su Amazon lo si trova usato a 5€.

Ho scelto questo testo perché... nulla, è quello usato nelle classi degli alunni che seguo. Per carità, libro ben fatto e tutto quello che vuoi, ma non penso che alle superiori spiegheranno mai come implementare una lista collegata o un albero binario, per cui nella realtà è abbastanza overkill per il suo scopo, difatti vedo spesso il libro intonso, comprato "tanto per".

- test

## Esercizi per Recupero Estivo

Esercizi risolti della cartella `recupero_estivo` - tutti.

+ [x] Esercizio 1
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
Tutti gli esercizi sono comunque ANSI C, ~per cui anche compilando con il compiler per C++ funzioneranno (in teoria, si spera)~.
**Rimossa compatbilità con C++**: rimossi tutti i cast alle `malloc()` non necessari in C ma richiesti in C++. Vedi [Issue #2](https://github.com/andrea-berardi/ripetizioni2021/issues/2#issuecomment-905052323).

Non fatemi mettere una licenza, per l'amor di Dio, riuscite a gestirvi anche senza.  
Per problemi riguardo agli esercizi aprite una Issue o fate una PR. Ma anche no, grazie.

## Mettiamo le mani avanti... ancora (per i prof.)

> Spieghiamo o ripetiamo il perché di alcune scelte estremamente discutibili

Come mai ho fatto questo piuttosto che quello? Beh, comodità e pigrizia, soprattutto.

Inoltre, mi è stato detto da alcuni ragazzi che certi prof. prediligono schifezze quali variabili globali, dichiarazioni di variabili nello stesso punto a inizio programma (anziché vicino al punto di utilizzo) e simili: ponendo sia vero ciò che mi è stato detto, in questi casi la cortesia di aderire alle richieste dei professori viene di gran lunga superata dalla necessità di evitare tali indecenze.

## Considerazioni finali

Pensavo inoltre che non ho la certezza che alcuni dei magheggi con la `scanf()` funzionino su ogni OS, ma non mi metto di certo a verificare.

Ogni esercizio _works on my machine_, che è ciò che importa, no? Testati su GNU/Linux.
