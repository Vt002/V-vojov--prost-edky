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


```
Micropython - viz VP02-strukturaProg.py

from machine import Pin
from time import ticks_ms

old_time = 0

pinLED = Pin(00, Pin.OUT)

while True:
    new_time = ticks_ms()
    if((new_time - old_time) > 500):
        pinLED.toggle()
        old_time = new_time
        print("LED state = {}".format(pinLED.value()))
        # print("LED state = ", pinLED.value())
        print("New time = {} ms".format(new_time))
        # print("New time = ", new_time)
```
<!--
```
Arduino language (C++)

Program, který bude blikat s LED a posílat nějakou zprávu do konzole.
Je potřeba, aby byla připojena nějaká knihovna.
```
-->

2. Vyhledejte na internetu, případně použijte chat bota, co který řádek kódu dělá, včetně odborných termínů, jako je třída, knihovna, apod. (komu vyhovuje víc angličtina, vyhledejte si pojmy rovnou v angličtině).

3. Zobecněte zjištěné informace o programu a sepište základní strukturu programu. Tedy z jakých částí se obecně program pro dané MCU skládá, jak jdou tyto části za sebou a jaký je obecný zápis.


### 3. Hardwarové vývojové prostředky

1. Vyhledejte na internetu, co se rozumí v souvislosti s programováním MCU pod pojmy: vývojový kit, vývojová deska, vývojová platforma, modul a shield.

2. Vývoj hardwaru je často také o ověřování/kontrole správné funkčnosti. K tomu se používají různé měřící přípravky a přístroje. Zjistěte, co je to logická sonda, logický analizátor a osciloskop. A k čemu se tyto měřící přístroje používají.

3. Pomocí multimetru změřte:
    - Zda je propojovací vodič vpořádku, nebo je přerušený
    - Napájecí napětí na svorkách Vcc a GND (o kolik se liší od deklarované hodnoty?)
    - Hodnotu předloženého rezistoru
    - Jak jsou zapojeny piny předloženého tlačítka
    - Zkontrolujte, zda je proražená LED


### 4. Softwarové vývojové prostředky a programovací jazyky

1. Vyhledejte, z jakých programů/částí/nástrojů je složené vývojové prostředí pro daný MCU.

> :key: **IDE**
>
> Integrované vývojové prostředí (Integrated Development Environment)
> Vývojové prostředí. Online. In: Wikipedia: the free encyclopedia. San Francisco (CA): Wikimedia Foundation, 2024, 30. 5. 2023 v 19:26. Dostupné z: https://cs.wikipedia.org/wiki/V%C3%BDvojov%C3%A9_prost%C5%99ed%C3%AD. [cit. 2024-12-11].

2. Níže jsou uvedeny dva typy chyb v kódu, zjistěte, kdo/co je vyhledá a kdo/co je opraví.

> :key: **Syntaktická chyba**
>
> ...

> :key: **Logická chyba**
>
> ...

3. Zjistěte, do jakých kategorií a jakou mají historii jazyky Micropython a Arduino language. Z jakých jazyků jsou odvozeny a jak se liší od strukturovaných jazyků jako je např. ANSI C, nebo Pascal.
