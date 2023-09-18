A5="sup" -> priradí string do A5 - "" sú povinné
A5=3 -> priradí číslo do A5
A5:=A5*2 -> priradí formulu do A5

Povolené operátory:

číselné operátory:
+ - * / % -> chce dve čísla
unárne mínus funguje tiež

stringové operátory:
"hello"&"world" -> spojí dva stringy
"Hello"^3 -> opakuje string 3x, komutativita platí

funkcie:
LOG(base, n) -> logaritmus čísla n
POW(base, exp) -> mocnina base^exp
ROOT(x,y) -> xtá odmocnina z y
ABS(x) -> absolútna hodnota


Ostatné commands:
IMPORT "filename" -> importne ti commandy zo súboru; uvodzovky technically nie sú povinné
EXPORT "filename" -> exportne ti hodnoty do súboru; uvodzovky technically nie sú povinné
EXPORT RAW "filename" -> same shit ale ak je niečo formula tak to exportne ten vzorec nie tú hodnotu

PRINT A1 -> Vytlačí konkrétnu bunku
PRINT A1:D5 ->Vytlači bunky z tohoto rozsahu
PRINT RAW <adresa/rozsah> -> same shit ale namiesto výsledku vytlačí vzorec
PRINT ALL -> naschval nefunguje, použi DUMP ALL

DUMP ALL -> Vypíše úplne všetky bunky.
DUMP RAW -> you get it by now

CLEAR A1 -> Vymaže A1
CLEAR A1:D14 -> Vymaže všetky z rozsahu
CLEAR ALL -> Vymaže celú tabuľku

EXIT -> exitne

Všetko je case sensitive (teda všetko píš). Jediné čo môže byť lowercase je string constant a filename
