[Co dodělat ]: #
[nic ]: #


# Vývojové prostředky

$${\color{#4682B4}A9 }$$

## Cíl

- Studenti se budou orientovat v problematice vývojových prostředků pro řídící jednotky postavených na vybraném MCU
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

    <details>
        <summary> :bulb: Tip: Návod na programování Raspberry pi pico </summary>
            <p><b>v Arduino IDE 2.x.x </b></p>
            <p>Programming Raspberry Pi Pico with Arduino IDE (Pico W compatible). Online. RandomNerdTutorials.com. Dostupné z: https://randomnerdtutorials.com/programming-raspberry-pi-pico-w-arduino-ide/. [cit. 2024-12-22].</p>
            <p><b>v Thony </b></p>
            <p>Getting Started with Raspberry Pi Pico (and Pico W). Online. RandomNerdTutorials.com. Dostupné z: https://randomnerdtutorials.com/getting-started-raspberry-pi-pico-w/. [cit. 2024-12-22].</p>
            <p><b>ve VS Code </b></p>
            <p>Programming Raspberry Pi Pico with VS Code and MicroPython. Online. RandomNerdTutorials.com. Dostupné z: https://randomnerdtutorials.com/raspberry-pi-pico-vs-code-micropython/. [cit. 2024-12-22].</p>
    </details>

    <details>
        <summary> :bulb: Tip: Problémy s IDE </summary>
            <p><b>Arduino IDE - chybí složka Arduino 15</b></p>
            <p>Open the Arduino15 folder. Online. WWW.ARDUINO.CC. June 3, 2024. Dostupné z: https://support.arduino.cc/hc/en-us/articles/360018448279-Open-the-Arduino15-folder. [cit. 2024-12-23].</p>
    </details>




```
# Micropython - viz VP02-strukturaProg.py

from machine import Pin
from time import ticks_ms

old_time = 0

pinLED = Pin(0, Pin.OUT)

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

```
// Arduino language (C++) - VP02-strukturaProg/VP02-strukturaProg.ino

// POZOR: Při nahrávání programu do Raspberry Pi pico je třeba:
// - podržet tlačítko boot
// - vypnout sériový monitor, jinak se nenaváže komunikace

// Tato knihovna je připojená přímo v programovacím prostředí, proto ji není třeba znovu připojovat. Zde je jen pro lepší představu o struktůře programů.
// #include <Arduino.h>

unsigned long old_time = 0;
bool state = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long new_time = millis();
  if ((new_time - old_time) > 500) {
    state = !state;
    digitalWrite(LED_BUILTIN, state);
    old_time = new_time;
    Serial.print("LED state = ");
    Serial.println(state);
    Serial.print("New time = ");
    Serial.println(new_time);
  }
}
```

2. Vyhledejte na internetu, případně použijte chat bota, co který řádek kódu dělá, včetně odborných termínů, jako je třída, knihovna, apod. (komu vyhovuje víc angličtina, vyhledejte si pojmy rovnou v angličtině).

3. Zobecněte zjištěné informace o programu a sepište základní strukturu programu. Tedy z jakých částí se obecně program pro dané MCU skládá, jak jdou tyto části za sebou a jaký je obecný zápis.

<details>
    <summary> :bulb: Tip: Knihovny </summary>
        Když v projektu připojíte knihovnu, je praktické si u ní v komentáři poznamenat verzi, případně odkaz na dokumentaci. Knihovny nejsou neměnné a verze nemusí být plně kompatibilní. Důvodem změn bývá hlavně oprava chyb a děr v zabezpečení, ale i přidávání dalších funkcionalit, apod.     
</details>


### 3. Hardwarové vývojové prostředky

1. Vyhledejte na internetu, co se rozumí v souvislosti s programováním MCU pod pojmy: vývojový kit, vývojová deska, vývojová platforma, modul a shield.

2. Vývoj hardwaru je často také o ověřování/kontrole správné funkčnosti. K tomu se používají různé měřící přípravky a přístroje. Zjistěte, co je to logická sonda, logický analyzátor a osciloskop. K čemu se tyto měřící přístroje používají?

3. Pomocí multimetru změřte:
    - Zda je propojovací vodič v pořádku, nebo je přerušený
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

> :key: **Chyby v programu**
>
> Nejčastěji se setkáme s chybami v syntaxi jazyka (zápis/gramatika programovacího jazyka). Vyhledává je při překladu kompilátor (překladač).
> Další problém bývá v tom, že program je syntakticky v pořádku, ale nepracuje, jak by měl. Některé chyby vedou i k zamrznutí, či zhavarování programu. V tomto případě se jedná o logické chyby, které musí vyhledat programátor, popřípadě tester. Používá se debugger, případně speciální testovací SW (případně i HW).
>
> Podrobněji:
>
> ITNETWORK S.R.O. Debugging: Úvod a terminologie. Online. WWW.ITNETWORK.CZ. Itnetwork.cz. Dostupné z: https://www.itnetwork.cz/javascript/debugging-vscode-webstorm/debugging-uvod-a-terminologie. [cit. 2024-12-21].
>
>
> Případně ještě:
>
> Softwarová chyba. Online. In: Wikipedia: the free encyclopedia. San Francisco (CA): Wikimedia Foundation, 2024, 16. 1. 2024 v 10:48. Dostupné z: https://cs.wikipedia.org/wiki/Softwarov%C3%A1_chyba. [cit. 2024-12-21].
> Syntaxe (programovací jazyk). Online. In: Wikipedia: the free encyclopedia. San Francisco (CA): Wikimedia Foundation, 2024, 20. 11. 2024 v 17:02. Dostupné z: https://cs.wikipedia.org/wiki/Syntaxe_(programovac%C3%AD_jazyk). [cit. 2024-12-12].
> Sémantika programovacích jazyků. Online. In: Wikipedia: the free encyclopedia. San Francisco (CA): Wikimedia Foundation, 2024, 16. 8. 2023 v 16:07. Dostupné z: https://cs.wikipedia.org/wiki/S%C3%A9mantika_programovac%C3%ADch_jazyk%C5%AF. [cit. 2024-12-21].

3. Zjistěte, do jakých kategorií a jakou mají historii jazyky Micropython a Arduino language. Z jakých jazyků jsou odvozeny a jak se liší od strukturovaných jazyků jako je např. ANSI C, nebo Pascal.


