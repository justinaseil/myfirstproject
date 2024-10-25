# myfirstproject

# Testavimo sistema

## CPU
- **Modelis**: Intel(R) Xeon(R) CPU E5-2620 0 @ 2.00GHz
- **Architektūra**: x86_64
- **Branduolių skaičius**: 12
- **Dažnis**: 2.00 GHz

## RAM
- **Bendra**: 8 GiB
- **Naudojama**: 474 MiB
- **Laiva**: 6.5 GiB

## HHD
- **Magnetinis HHD**

### Pirmiausia buvo sukuriami failai, kad testavimas vyktu sklandžiai ir su tokiais pat duomenimis.

## Failų generavimas
- **1000 įrašų**: 0.0157 s
- **10000 įrašų**: 0.0622 s
- **100000 įrašų**: 0.7113 s
- **1000000 įrašų**: 6.7897 s
- **10000000 įrašų**: 52.1942 s

### Tada programa atliko failų, su skirtingu skaičiumi įrašų, testavimus, lentelių duomenims gauti kiekvienas failas buvo testuotas 3 kartus ir išvestas vidurkis.

## Testavimas su 1000 įrašų

|Testavimo įrašų skaičius                | Naudojant vector | Naudojant list | Kuris greitesnis? |
|----------------------------------------|------------------|----------------|-------------------|
|**Failo nuskaitymas**                   | 0.0116 s         | 0.6252 s       | vector            |
|**Rūšiavimas į dvi grupes**             | 0.0004 s         | 0.0001 s       | list              |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.15 ms          | 0.24 ms        | vector            |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.0004 s         | 0.99 ms        | list              |
|**Įrašymas į failą "kietetai.txt"**     | 0.0490 s         | 0.2377 s       | vector            |
|**Įrašymas į failą "vargšiukai.txt"**   | 0.0372 s         | 0.0523 s       | vector            |
|**Bendras**                             | 0.0989 s         | 0.9170 s       | vector            |


## Testavimas su 10000 įrašų

|Veiksmas                                | Naudojant vector | Naudojant list | Kuris greitesnis? |
|----------------------------------------|------------------|----------------|-------------------|
|**Failo nuskaitymas**                   | 0.0495 s         | 0.0599 s       | vector            |
|**Rūšiavimas į dvi grupes**             | 0.0039 s         | 0.0036 s       | list              |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.12 ms          | 0.15 ms        | vector            |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.0049 s         | 0.0011 s       | list              |
|**Įrašymas į failą "kietetai.txt"**     | 0.0189 s         | 0.0255 s       | vector            |
|**Įrašymas į failą "vargšiukai.txt"**   | 0.0696 s         | 0.0760 s       | vector            |
|**Bendras**                             | 0.1475 s         | 0.1673 s       | vector            |


## Testavimas su 100000 įrašų

|Veiksmas                                | Naudojant vector | Naudojant list |Kuris greitesnis? |
|----------------------------------------|------------------|----------------|-------------------|
|**Failo nuskaitymas**                   | 0.4247 s         | 0.4631 s       | vector            |
|**Rūšiavimas į dvi grupes**             | 0.0312 s         | 0.0409 s       | vector            |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.48 ms          | 0.12 ms        | list              |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.0627 s         | 0.0292 s       | list              |
|**Įrašymas į failą "kietetai.txt"**     | 0.0068 s         | 0.0089 s       | vector            |
|**Įrašymas į failą "vargšiukai.txt"**   | 0.4848 s         | 0.5488 s       | vector            |
|**Bendras**                             | 1.0146 s         | 1.1014 s       | vector            |

## Testavimas su 1000000 įrašų

|Veiksmas                                | Naudojant vector | Naudojant list |Kuris greitesnis? |
|----------------------------------------|------------------|----------------|-------------------|
|**Failo nuskaitymas**                   | 3.3561 s         | 4.3701 s       | vector            |
|**Rūšiavimas į dvi grupes**             | 0.2580 s         | 0.3001 s       | vector            |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.77 ms          | 0.11 ms        | list              |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.8367 s         | 0.2612 s       | list              |
|**Įrašymas į failą "kietetai.txt"**     | 0.0052 s         | 0.0069 s       | vector            |
|**Įrašymas į failą "vargšiukai.txt"**   | 4.0238 s         | 3.9485 s       | list              |
|**Bendras**                             | 8.3194 s         | 8.9556 s       | vector            |

## Testavimas su 10000000 įrašų

|Veiksmas                                | Naudojant vector | Naudojant list |Kuris greitesnis? |
|----------------------------------------|------------------|----------------|-------------------|
|**Failo nuskaitymas**                   | 35.0499 s        | 34.3609 s      | list              |
|**Rūšiavimas į dvi grupes**             | 3.3935 s         | 3.2657 s       | list              |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.36 ms          | 0.39 ms        | vector            |
|**Rūšiavimas "vargšiukų" pagal vardus** | 7.6706 s         | 3.5547 s       | list              |
|**Įrašymas į failą "kietetai.txt"**     | 0.0068 s         | 0.0046 s       | list              |
|**Įrašymas į failą "vargšiukai.txt"**   | 40.1192 s        | 39.257 s       | list              |
|**Bendras**                             | 86.5879 s        | 82.7185 s      | list              |

## Išvada

Matome, kad konteinerio vector sparta yra didesnė nei list, išskyrus testavimą su didžiausiu kiekiu duomenų (10000000 įrašų). "Vargšiukų" duomenų buvo daugiau nei "kietekų" ir galime matyti, kad rušiuojant didesnį kiekį duomenų geriau pasirodė konteineris list, ypač rūšiuojant pagal vardus. Todėl pagal šį testavimą galima padaryti išvadą, kad list greičiau tvarkosi su didesniu kiekiu duomenų, o vector su mažesniu, bet visgi vector yra greitesnis.


