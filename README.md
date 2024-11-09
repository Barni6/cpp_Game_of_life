# Game of Life - C++ Implementáció

Ez a projekt a **Game of Life** játékszimuláció egy C++ nyelven megvalósított változata. A program Conway híres sejtautomata szabályain alapul, és különböző inicializációs lehetőségeket kínál a játék elindításához.

## Funkciók

- **Játékterület méretezése**:
  - Négyzetes és téglalap alakú rács támogatása.
- **Véletlenszerű inicializáció**:
  - Az élő sejtek valószínűsége megadható.
- **Minta inicializálása**:
  - Egyedi minták megadása a rács egy adott részére.
- **Szabályok**:
  - Egy élő sejt:
    - Életben marad, ha 2 vagy 3 élő szomszédja van.
    - Elpusztul, ha élő szomszédainak száma kevesebb mint 2 (magányosság) vagy több mint 3 (túlzsúfoltság).
  - Egy halott sejt:
    - Újjászületik, ha pontosan 3 élő szomszédja van.
- **Periódikus határfeltételek**:
  - A rács szélei "összeérnek", mintha egy torusz lenne.
  - 
## Technológiák

### Nyelv
- **C++**

### Algoritmus
- **Conway’s Game of Life**: A szabályokon alapuló sejtautomata, amely a sejtek szomszédsági viszonyait figyelembe véve szimulálja az élet és a halál ciklusait.


## Használati Útmutató

1. **Játék indítása**:
   - Alapértelmezett inicializációval:
     - Véletlenszerű élő sejtek négyzetes rácson.
   - Egyedi mintával:
     - Adott pozícióba elhelyezett sejtminták egyedi méretű rácson.

2. **Lépések futtatása**:
   - A játék minden lépése után a következő iterációhoz nyomd meg az ENTER-t.

3. **Paraméterek testreszabása**:
   - A `GameOfLife` osztály példányosításakor az alábbi paraméterek adhatók meg:
     - **Rács mérete** (`int size`).
     - **Élő sejtek valószínűsége** (`float probability`).
     - **Kezdőminta elhelyezése** (`std::vector<std::vector<bool>>`).

## Példa Használat

### Négyzetes Rács
```cpp
int height = 5;
int width = 8;
GameOfLife customGrid(height, width, 2, 3, { {1, 0, 1, 0, 1, 0, 1, 0} });
customGrid.play(100);


