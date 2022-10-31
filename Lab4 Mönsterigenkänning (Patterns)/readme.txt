/**********************************************************************
 *  Mönsterigenkänning readme.txt
 **********************************************************************/

 Ungefärligt antal timmar spenderade på labben (valfritt): 3 timmar

/**********************************************************************
 * Empirisk analys
 *
 * Fyll i tabellen nedan med riktiga körtider i sekunder när det känns
 * vettigt att vänta på hela beräkningen.
 * Ge uppskattningar av körtiden (baserat på tidskomplexiteten)
 * i övriga fall.
 *
 **********************************************************************/
    Om ingen annat ges står siffrorna i sekunder
      N       brute       sortering
 ----------------------------------
    150		0,005	    0,053
    200		0,048	    0,055
    300		0,067	    0,109
    400		0,165	    0,152
    800		0,613	    0,207
   1600		4,393	    0,564
   3200		33,773	    2,063
   6400		276,624	    8,933
  12800		2208,382    39,734


/**********************************************************************
 * Teoretisk analys
 *
 * Ge ordo-uttryck för värstafallstiden för programmen som en funktion
 * av N. Ge en kort motivering.
 *
 * Matchar brute-lösningen sitt värstafall i praktiken, eller har den
 * ett medelfall som är bättre?
 *
 **********************************************************************/
Brute ordo uttryck = O(N^3)

fast ordo uttryck = O(N^2log(N))

Brute:I värsta fall kommer brute att ha O(n^4) om den hittar en linje men oftast
kommer den bara har O(n^3). Det kan man märka om man tittar på tiderna ovanför
Om vi hade en grid som inhöll massa linjer så skulle vi får mycket större tidskomplexitet

Sortering:Sortering därmemot kommer ha ungefär samma tidskomplexitet i och med att den kommer pusha in alla i vector. Lättare sagt n(n+nlog(n)+n) som är värsta
fallet kommer i slutändan försummas till O(n^2*log(n)), precis som n(n+nlog(n)+n) som
är det normala faller. Det enda som skiljer sig är att operaetionenfunktionen  efter sista
if satsen kommer inte görautföras vilket är orelevant för tidskomplexiteten då den funktionen inte har loopar i sig.


/**********************************************************************
 * Energianvändning
 *
 * Antag att du använder mönsterigenkänningsprogrammet för att analysera
 * data från en kamera. Kameran sitter i en byggnad och tar en bild
 * på stommen av byggnaden var 30:e minut. Bilden förbehandlas sedan
 * lite, innan punkter som representerar stommen skickas till
 * mönsterigenkänningsprogrammet. Hittas inte tillräckligt många raka
 * linjer så betyder det att något håller på att gå sönder, och
 * att byggnaden behöver noggrannare inspektion.
 *
 * Hur mycket energi sparar du på ett år om du använder din snabbare
 * sorteringslösning i stället för brute-lösningen? Du kan anta följande:
 * - Systemet körs 24/7 under hela året.
 * - Inget annat körs på det här systemet.
 * - Systemet drar 8 W när det inte gör något (idle)
 * - Systemet drar 36 W när det arbetar (med 1 kärna)
 * - Räkna med att ditt program körs var 30:e minut (= 2 gånger/timme)
 * - För- och efterbehandling är snabba, så vi kan bortse från dem
 * - Indata till programmet innehåller ca 6400 punkter
 * - Det är inte skottår (= 365 dagar)
 *
 * Att jämföra med drar en kombinerad kyl/frys ca 200 kWh per år
 * (enligt Energimyndigheten).
 *
 * Kom ihåg: energi mäts ofta i kWh, vilket är:
 *  energi (kWh) = effekt (kW) * tid (h)
 *
 * Tips: ett sätt att räkna på är att först räkna förbrukningen av
 * ett system som inte gör något på ett helt år, sedan lägga till
 * den extra förbrukningen (36 W - 8 W = 28 W) för tiden som systemet
 * är aktiv.
 *
 * (Siffrorna är löst baserade på en Intel i9-9900K, vi räknar bara på
 * CPU:n för enkelhets skull, besparingarna blir sannolikt större om
 * vi räknar på större delar av systemet, även om andra komponenter
 * också drar ström i "idle".)
 *
 **********************************************************************/

Förbrukning av brute på ett år: 37,6 + 70,08  = 107,7 kWh

Förbrukning av sotering på ett år: 70,08 + 0.0511 = 70,1311 kWh

Skillnad: 2041,08 kWh

