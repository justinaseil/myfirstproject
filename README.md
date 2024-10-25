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

|Testavimo įrašų skaičius                | Naudojant vector |
|----------------------------------------|------------------|
|**Failo nuskaitymas**                   | 0.0116 s         |
|**Rūšiavimas į dvi grupes**             | 0.0004 s         |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.15 ms          |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.0004 s         |
|**Įrašymas į failą "kietetai.txt"**     | 0.0490 s         |
|**Įrašymas į failą "vargšiukai.txt"**   | 0.0372 s         |
|**Bendras**                             | 0.0989 s         |


## Testavimas su 10000 įrašų

|Veiksmas                                | Naudojant vector | 
|----------------------------------------|------------------|
|**Failo nuskaitymas**                   | 0.0495 s         |
|**Rūšiavimas į dvi grupes**             | 0.0039 s         |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.12 ms          |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.0049 s         |
|**Įrašymas į failą "kietetai.txt"**     | 0.0189 s         |
|**Įrašymas į failą "vargšiukai.txt"**   | 0.0696 s         |
|**Bendras**                             | 0.1475 s         |


## Testavimas su 100000 įrašų

|Veiksmas                                | Naudojant vector | 
|----------------------------------------|------------------|
|**Failo nuskaitymas**                   | 0.4247 s         |
|**Rūšiavimas į dvi grupes**             | 0.0312 s         |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.48 ms          |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.0627 s         |
|**Įrašymas į failą "kietetai.txt"**     | 0.0068 s         |
|**Įrašymas į failą "vargšiukai.txt"**   | 0.4848 s         |
|**Bendras**                             | 1.0146 s         |

## Testavimas su 1000000 įrašų

|Veiksmas                                | Naudojant vector | 
|----------------------------------------|------------------|
|**Failo nuskaitymas**                   | 3.3561 s         |
|**Rūšiavimas į dvi grupes**             | 0.2580 s         |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.77 ms          |
|**Rūšiavimas "vargšiukų" pagal vardus** | 0.8367 s         |
|**Įrašymas į failą "kietetai.txt"**     | 0.0052 s         |
|**Įrašymas į failą "vargšiukai.txt"**   | 4.0238 s         |
|**Bendras**                             | 8.3194 s         |

## Testavimas su 10000000 įrašų

|Veiksmas                                | Naudojant vector | 
|----------------------------------------|------------------|
|**Failo nuskaitymas**                   | 35.0499 s        |
|**Rūšiavimas į dvi grupes**             | 3.3935 s         |
|**Rūšiavimas "kietekų" pagal vardus**   | 0.36 ms          |
|**Rūšiavimas "vargšiukų" pagal vardus** | 7.6706 s         |
|**Įrašymas į failą "kietetai.txt"**     | 0.0068 s         |
|**Įrašymas į failą "vargšiukai.txt"**   | 40.1192 s        |
|**Bendras**                             | 86.5879 s        |

