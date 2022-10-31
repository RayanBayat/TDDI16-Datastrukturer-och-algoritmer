/**********************************************************************
 *  Knäcka lösenord readme.md
 **********************************************************************/

 Ungefärligt antal timmar spenderade på labben (valfritt): 20 timmar

/**********************************************************************
 *  Ge en högnivå beskrivning av ditt program decrypt.c.
 **********************************************************************/
Vi utnyttjar meet in the middle metoden. Först hashar vi de halva
första bitarna och stoppar in dem i en container, nämligen
unordered_map och därefter letar vi efter en  matchning när vi
subtraherar hash värdet av hög signifikanta bitar från godtycklig
lösenords hash värde. Om vi får en matchning skriver vi ut den
samtidigt som vi adderar tillbaka hög signifikanta bitarna.

/**********************************************************************
 *  Beskriv symbol tabellen du använt för decrypt.c.
 **********************************************************************/
Det heter unordered_map och är en Unordered associative 
container. Den tar in en hashfunktion som parameter där den 
använder hash funktionen för att placera data i minnet.

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla lösenord med 8 och 10
 *  bokstäver i uppgiften du lyckades knäca med DIN kod.
 **********************************************************************/


8 bokstäver         			10 bokstäver
-----------        			------------
xwtyjjin = congrats,ibqfehan		h554tkdzti = completely,nbryjimvrd	
rpb4dnye = mqubzd45,youfound		oykcetketn = unbreakabl
kdidqv4i = theright			bkzlquxfnt = cryptogram
m5wrkdge = aeiqrsd4,solution		wixxliygk1 = ormaybenot


/****************************************************************************
 *  Hur lång tid använder brute.c för att knäcka lösenord av en viss storlek?
 *  Ge en uppskattning (baserad på tidskomplexiteten)  markerad med en asterisk
 *  om det tar längre tid än vad du orkar vänta. Ge en kort motivering för
 *  dina uppskattningar.
 ***************************************************************************/


Char     Brute     
--------------
 4  0 sekunder
 5  3 sekunder
 6  139 sekunder
 8  *109 951 sekunder

Tiden som behövs är beroende av antal operationer och de är 2^N där N är antalet bitar. t.ex för char 4 är den 20
och char 8 är den 40. 

/******************************************************************************
 *  Hur lång tid använder decrypt.c för att knäcka lösenord av en viss storlek?
 *  Hur mycket minne använder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar längre tid än vad
 *  du orkar vänta. Ge en kort motivering för dina uppskattningar.
 ******************************************************************************/

Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6   0			 2,315,968 bytes 
8   1			 73,227,336 bytes	
10  68			 2,935,185,776 bytes
12  *966		*117,407,431,040 bytes
Minnesanvändningen verkar öka väldigt mycket varje gång man lägger till 2 bitar
nämligen  ungefär 40 gånger, om man räknar på miniräknaren blir svaret 117gb.

Tiden har jag också uppskattat eftersom det var för dyr att köra 12 siffrig.
Jag har då tänkt att 2^N/2 gånger försöker vi spara subsetsum i vår unordered_map
där vi sedan går genom en annan for loop som ytterligare iterar över alla charactarer
alltså C gånger och slutligen gör vi en 2^N/2 räkning för höga bitarna. Men
riktiga tiden är förmogligen mer i och med att olika datorer är olika belastad.

/*************************************************************************
 * Hur många operationer använder brute.c för ett N-bitars lösenord?
 * Hur många operationer använder din decrypt.c för ett N-bitars lösenord?
 * Använd ordo-notation.
 *************************************************************************/
O(2^N)  

O(C*(2^N/2) + (2^N/2) + N/2)och kanske lite fler små loopar vilket kan 
avrundas till O(2^N)


/*************************************************************************
 * Vilka egenskaper skulle ni leta efter i en hashfunktion för att
 * försäkra er om att den är "säker"?
 *************************************************************************/
Att den skiftar bitarna bl.a eller gör flera operationer som gör att
den returnerar ett unik värde för varje nyckel. Målet är att få så lite
kollisioner så möjligt. Det ska vara opraktisk att räkna fram datat genom
datorberäkningar så som brute gör. 

