[Co dodělat ]: #
[nic ]: #



# Vývojové prostředky

## Cíl

-	Studenti se budou orientovat v problematice vývojových prostředků pro řídící jednotky postavených na vybraném MCU
-   Včetně programovacích jazyků
-   Dále budou umět připojit vývojovou desku s příslušným MCU k počítači a tzv. ji oživit, tedy nahrát zkušební program
-   A popíší strukturu tohoto programu


## Ověření cílů

Vývojové prostředky

1. Základní SW a HW vývojové prostředky
2. Rozdělení programovacích jazyků pro programování vybraných řídících jednotek
3. Struktura programu (knihovny, nastavení, nekonečná smyčka)
4. Příklad oživení vybrané řídící jednotky a ladění jednoduchého programu


## Úlohy

### 1. Ahoj světe

1. Nainstalujte si vývojové prostředí.
2. Připojte vývojovou destičku s MCU k počítači.
3. Nastavte komunikaci ve vývojovém prostředí. Pokud programujete v micropythonu, je třeba ověřit, zda je nahraný intepret, případně je potřeba jej do MCU nahrát.
4. Většina desek má integrovanou LED, která se hodí pro odzkoušení funkčnosti desky a komunikace s vývojovým prostředím. Pokud ne, připoj externí LED na jeden z digitálních výstupů a zem (GND). Poté napište jednoduchý program na rozsvícení/rozblikání této LED. V Arduino IDE jsou i příklady programů, které lze přímo použít. 

Pozn.: Pokud jste zapojili externí LED bez předřadného rezistoru, krátkodobě by to neměl být problém, ale z dlouhodobého provozu se výrazně zkrátí její životnost. 


### 2. Struktura programu

1. Následující program nahrajte do MCU a odzkoušejte.

'''
Micropython

Program, který bude blikat s LED a posílat nějakou zprávu do konzole.
Je potřeba, aby byla připojena nějaká knihovna.
'''

'''
Arduino language (C++)

Program, který bude blikat s LED a posílat nějakou zprávu do konzole.
Je potřeba, aby byla připojena nějaká knihovna.
'''
2. Vyhledejte na internetu, případně použijte chat bota, co který řádek kódu dělá, včetně odborných termínů, jako je třída, knihovna, apod. (komu vyhovuje víc angličtina, vyhledejte si pojmy rovnou v angličtině).

3. Zobecněte zjištěné informace o programu a sepište základní strukturu programu. Tedy z jakých částí se obecně program pro dané MCU skládá, jak jdou tyto části za sebou a jaký je obecný zápis.


### 3. Hardwarové vývojové prostředky

1. 


