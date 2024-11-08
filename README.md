# myfirstproject

# Programos naudojimosi instrukcija

Paleidus koda yra klausiama, ar norima testuoti spartą. Atsakius taip galima pasirinkti, ar norima generuoti naujus failus, ar testuoti jau sugeneruotus ir programa pradeda testavima tiek su vector tiek su list konteineriais. Pasirinkę, kad nenorime testuoti failo, prieinama prie tolimesnės programos, kuri leidžia pasirinkti, ar norime nuskaityti duomenis iš failo, jeigu ne, ar norime generuoti failus. Ši programa leidia įrašyti studentų pažymius ir egzamino rezultatus arba juo automatiškai generuoti ir pasirinkti, ar galutinį balą skaičiuoti su mediana, ar vidurkiu. Galutinis rezultatas yra surūšiuojamas į vargšiukų failą, kuriame patenka mokiniai turintys mažesnį galutinį įvertinimą nei 5 arba į kietekų failą, kurių įvertinimai ne mažesnis nei 5.

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


# Testavimas pagal strategijas 

## 1 strategija v1.0.1

Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "vargšiukų" ir "kietekų". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų (vargšiukai arba kietekai)

## 1 strategijos testavimas

Testavimai buvo atlikti išvedant 4 skirtingu testavimų su tais pačiais failais vidurkį

## Testavimas su 1000 įrašų

|Veiksmas                           | Naudojant vector | Naudojant list |
|-----------------------------------|------------------|----------------|
|**Rūšiavimas į dvi grupes**        | 0,000629631 s    | 0,000152593 s  |
|**Bendras**                        | 0,0303778 s      | 0,84537075 s   |

## Testavimas su 10000 įrašų

|Veiksmas                           | Naudojant vector | Naudojant list |
|-----------------------------------|------------------|----------------|
|**Rūšiavimas į dvi grupes**        | 0,005090088 s    | 0,003865693 s  |
|**Bendras**                        | 0,12921475 s     | 0,11952325 s   |

## Testavimas su 100000 įrašų

|Veiksmas                           | Naudojant vector | Naudojant list |
|-----------------------------------|------------------|----------------|
|**Rūšiavimas į dvi grupes**        | 0,03443775 s     | 0,038936575 s  |
|**Bendras**                        | 1,0530575 s      | 0,98273975 s   |

## Testavimas su 1000000 įrašų

|Veiksmas                           | Naudojant vector | Naudojant list |
|-----------------------------------|------------------|----------------|
|**Rūšiavimas į dvi grupes**        | 0,29472 s        | 0,3636755 s    |
|**Bendras**                        | 9,76644 s        | 9,406325 s     |

## Testavimas su 10000000 įrašų

|Veiksmas                           | Naudojant vector | Naudojant list |
|-----------------------------------|------------------|----------------|
|**Rūšiavimas į dvi grupes**        | 3,7298975 s      | 4,2699075 s    |
|**Bendras**                        | 93,78405 s       | 86,233425 s    |


Naudojant 1 stretegiją greičiausiai į dvi grupes susirušiuoja su vector, kai duomenų yra daugiau, o kai mažiau greičiau rūšiuoja su list.


## 2 strategija

Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Tokiu būdu, jei studentas yra vargšiukas, jį turime įkelti į naująjį "vargšiukų" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik kietekai. 

## 2 strategijos testavimas v1.0.2

Testavimai buvo atlikti išvedant 4 skirtingu testavimų su tais pačiais failais vidurkį

## Testavimas su 1000 įrašų

|Veiksmas                           | Naudojant vector | Naudojant list |
|-----------------------------------|------------------|----------------|
|**Rūšiavimas į dvi grupes**        | 0,011540375 s    | 0,000179277 s  |
|**Bendras**                        | 0,81983675 s     | 0,02681985 s   |

## Testavimas su 10000 įrašų

|Veiksmas                           | Naudojant vector | Naudojant list |
|-----------------------------------|------------------|----------------|
|**Rūšiavimas į dvi grupes**        | 1,1513765 s      | 0,00137074 s   |
|**Bendras**                        | 1,273715 s       | 0,122352 s     |


## Testavimas su 100000 įrašų

|Veiksmas                           | Naudojant vector | Naudojant list |
|-----------------------------------|------------------|----------------|
|**Rūšiavimas į dvi grupes**        | 119,305 s        | 0,01378835 s   |
|**Bendras**                        | 120,12025 s      | 1,049332 s     |

## Testavimas su 1000000 įrašų

|Veiksmas                           | Naudojant vector | Naudojant list |
|-----------------------------------|------------------|----------------|
|**Rūšiavimas į dvi grupes**        | daugiau nei 5min | 0,096404575 s  |
|**Bendras**                        | daugiau nei 5min | 8,7514725 s    |

## Testavimas su 10000000 įrašų

|Veiksmas                           | Naudojant vector | Naudojant list |
|-----------------------------------|------------------|----------------|
|**Rūšiavimas į dvi grupes**        | daugiau nei 5min | 0,96048525 s   |
|**Bendras**                        | daugiau nei 5min | 85,6233 s      |

Naudojant 2 strategiją, greičiau rūšiuojama buvo su list konteineriu.


## Dvieju strategijų palyginimas 1.0.2

## Testavimas su 1000 įrašų

|Veiksmas                           | Naudojant vector 1 | Naudojant list 1 | Naudojant vector 2 | Naudojant list 2 |
|-----------------------------------|--------------------|------------------|--------------------|------------------|
|**Rūšiavimas į dvi grupes**        | 0,000629631 s      | 0,000152593 s    | 0,011540375 s      | 0,000179277 s    |
|**Bendras**                        | 0,0303778 s        | 0,84537075 s     | 0,81983675 s       | 0,02681985 s     |

## Testavimas su 10000 įrašų

|Veiksmas                           | Naudojant vector 1 | Naudojant list 1 | Naudojant vector 2 | Naudojant list 2 |
|-----------------------------------|--------------------|------------------|--------------------|------------------|
|**Rūšiavimas į dvi grupes**        | 0,005090088 s      | 0,003865693 s    | 1,1513765 s        | 0,00137074 s     |
|**Bendras**                        | 0,12921475 s       | 0,11952325 s     | 1,273715 s         | 0,122352 s       |

## Testavimas su 100000 įrašų

|Veiksmas                           | Naudojant vector 1 | Naudojant list 1 | Naudojant vector 2 | Naudojant list 2 |
|-----------------------------------|--------------------|------------------|--------------------|------------------|
|**Rūšiavimas į dvi grupes**        | 0,03443775 s       | 0,038936575 s    | 119,305 s          | 0,01378835 s     |
|**Bendras**                        | 1,0530575 s        | 0,98273975 s     | 120,12025 s        | 1,049332 s       |

## Testavimas su 1000000 įrašų

|Veiksmas                           | Naudojant vector 1 | Naudojant list 1 | Naudojant vector 2 | Naudojant list 2 |
|-----------------------------------|--------------------|------------------|--------------------|------------------|
|**Rūšiavimas į dvi grupes**        | 0,29472 s          | 0,3636755 s      | daugiau nei 5min   | 0,096404575 s    |
|**Bendras**                        | 9,76644 s          | 9,406325 s       | daugiau nei 5min   | 8,7514725 s      |

## Testavimas su 10000000 įrašų

|Veiksmas                           | Naudojant vector 1 | Naudojant list 1 | Naudojant vector 2 | Naudojant list 2 |
|-----------------------------------|--------------------|------------------|--------------------|------------------|
|**Rūšiavimas į dvi grupes**        | 3,7298975 s        | 4,2699075 s      | daugiau nei 5min   | 0,96048525 s     |
|**Bendras**                        | 93,78405 s         | 86,233425 s      | daugiau nei 5min   | 85,6233 s        |


Pagal rezultatus matome, kad vector geriau veikia su 1 strategija, o su list konteineriu geriau veikia 2 strategija.

## 3 strategija

Pažvelgus į išvadas galime matyti, kad greičiau veikia 2 strategija, todėl ją reikėtų patobulinti, kad veiktų sparčiai ir su vector ir patikrinti, ar tikrai suveikė.

## 3 strategijos testavimas v1.0.3

## Testavimas su 1000 įrašų

|Veiksmas                           | Naudojant vector 1 | Naudojant vector 2 | Naudojant vector 3 |
|-----------------------------------|--------------------|--------------------|--------------------|
|**Rūšiavimas į dvi grupes**        | 0,000629631 s      | 0,011540375 s      | 0,000272755 s      |
|**Bendras**                        | 0,0303778 s        | 0,81983675 s       | 0,04578875 s       |


## Testavimas su 10000 įrašų

|Veiksmas                           | Naudojant vector 1 | Naudojant vector 2 | Naudojant vector 3 |
|-----------------------------------|--------------------|--------------------|--------------------|
|**Rūšiavimas į dvi grupes**        | 0,005090088 s      | 1,1513765 s        | 0,00224726 s       |
|**Bendras**                        | 0,12921475 s       | 1,273715 s         | 0,12082525 s       |


## Testavimas su 100000 įrašų

|Veiksmas                           | Naudojant vector 1 | Naudojant vector 2 | Naudojant vector 3 |
|-----------------------------------|--------------------|--------------------|--------------------|
|**Rūšiavimas į dvi grupes**        | 0,03443775 s       | 119,305 s          | 0,02452585 s       |
|**Bendras**                        | 1,0530575 s        | 120,12025 s        | 0,977035 s         |


## Testavimas su 1000000 įrašų

|Veiksmas                           | Naudojant vector 1 | Naudojant vector 2 | Naudojant vector 3 |
|-----------------------------------|--------------------|--------------------|--------------------|
|**Rūšiavimas į dvi grupes**        | 0,29472 s          | daugiau nei 5min   | 0,22691425 s       |
|**Bendras**                        | 9,76644 s          | daugiau nei 5min   | 9,169675 s         |


## Testavimas su 10000000 įrašų

|Veiksmas                           | Naudojant vector 1 | Naudojant vector 2 | Naudojant vector 3 |
|-----------------------------------|--------------------|--------------------|--------------------|
|**Rūšiavimas į dvi grupes**        | 3,7298975 s        | daugiau nei 5min   | 2,41553 s          |
|**Bendras**                        | 93,78405 s         | daugiau nei 5min   | 90,86225 s         |

Matome, kad optimizavus kodą, rūšiavimas ir bendrai visa programa vyksta sparčiau. 



