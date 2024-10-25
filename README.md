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

## Failų generavimas
- **1000 įrašų**: 0.0157 s
- **10000 įrašų**: 0.0622 s
- **100000 įrašų**: 0.7113 s
- **1000000 įrašų**: 6.7897 s
- **10000000 įrašų**: 52.1942 s

## Testavimas su 1000 įrašų

|Testavimo įrašų skaičius                | Naudojant vector | Naudojant list |
|----------------------------------------|------------------|----------------|
|**Failo nuskaitymas**                   | 0.0116 s         | 0.6252 s       |
|**Rūšiavimas į dvi grupes**             | 0.0004 s         | 0.0001 s       | 
|**Rūšiavimas "kietekų" pagal vardus**   | 0.15 ms          | 0.24 ms        | 
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.0004 s         | 0.99 ms        |
|**Įrašymas į failą "kietetai.txt"**     | 0.0490 s         | 0.2377 s       |
|**Įrašymas į failą "vargšiukai.txt"**   | 0.0372 s         | 0.0523 s       |
|**Bendras**                             | 0.0989 s         | 0.9170 s       |


## Testavimas su 10000 įrašų

|Veiksmas                                | Naudojant vector | Naudojant list |
|----------------------------------------|------------------|----------------|
|**Failo nuskaitymas**                   | 0.0495 s         | 0.0599 s       |
|**Rūšiavimas į dvi grupes**             | 0.0039 s         | 0.0036 s       |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.12 ms          | 0.15 ms        |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.0049 s         | 0.0011 s       |
|**Įrašymas į failą "kietetai.txt"**     | 0.0189 s         | 0.0255 s       |
|**Įrašymas į failą "vargšiukai.txt"**   | 0.0696 s         | 0.0760 s       |
|**Bendras**                             | 0.1475 s         | 0.1673 s       |


## Testavimas su 100000 įrašų

|Veiksmas                                | Naudojant vector | Naudojant list |
|----------------------------------------|------------------|----------------|
|**Failo nuskaitymas**                   | 0.4247 s         | 0.4631 s       |
|**Rūšiavimas į dvi grupes**             | 0.0312 s         | 0.0409 s       |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.48 ms          | 0.12 ms        |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.0627 s         | 0.0292 s       |
|**Įrašymas į failą "kietetai.txt"**     | 0.0068 s         | 0.0089 s       |
|**Įrašymas į failą "vargšiukai.txt"**   | 0.4848 s         | 0.5488 s       |
|**Bendras**                             | 1.0146 s         | 1.1014 s       |

## Testavimas su 1000000 įrašų

|Veiksmas                                | Naudojant vector | Naudojant list |
|----------------------------------------|------------------|----------------|
|**Failo nuskaitymas**                   | 3.3561 s         | 4.3701 s       |
|**Rūšiavimas į dvi grupes**             | 0.2580 s         | 0.3001 s       |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.77 ms          | 0.11 ms        |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.8367 s         | 0.2612 s       |
|**Įrašymas į failą "kietetai.txt"**     | 0.0052 s         | 0.0069 s       |
|**Įrašymas į failą "vargšiukai.txt"**   | 4.0238 s         | 3.9485 s       |
|**Bendras**                             | 8.3194 s         | 8.9556 s       |

## Testavimas su 10000000 įrašų

|Veiksmas                                | Naudojant vector | Naudojant list |
|----------------------------------------|------------------|----------------|
|**Failo nuskaitymas**                   | 35.0499 s        | 35.3609 s      |
|**Rūšiavimas į dvi grupes**             | 3.3935 s         | 3.8722 s       |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.36 ms          | 0.39 ms        |
|**Rūšiavimas "vargšiukų" pagal vardus** | 7.6706 s         | 3.5547 s       |
|**Įrašymas į failą "kietetai.txt"**     | 0.0068 s         | 0.0081 s       |
|**Įrašymas į failą "vargšiukai.txt"**   | 40.1192 s        | 39.257 s       |
|**Bendras**                             | 86.5879 s        | 82.7185 s      |

