<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B98-004482?style=for-the-badge&logo=cplusplus&logoColor=white" alt="C++98 badge">
  <img src="https://img.shields.io/badge/Inheritance-0A5F38?style=for-the-badge&logoColor=white" alt="Inheritance badge">
  <img src="https://img.shields.io/badge/Overrides-7C3AED?style=for-the-badge&logoColor=white" alt="Overrides badge">
  <img src="https://img.shields.io/badge/Diamond%20Shape-1D3557?style=for-the-badge&logoColor=white" alt="Diamond badge">
  <img src="https://img.shields.io/badge/Stateful%20Robots-B23A48?style=for-the-badge&logoColor=white" alt="State badge">
</p>

<h1 align="center">Module 03 — Inheritance & Specialization</h1>
<p align="center">ClapTrap family tree: base stats, tougher variants, and a diamond that mixes them.</p>

## From Previous Modules
- Same C++98 rules, no STL containers, no `using namespace`.
- Orthodox Canonical Form on every class; constructor/destructor logs stay for traceability.
- Stream-based output and explicit ownership checks (HP/EP gating) continue from Modules 00–02.

## What’s New Here
- Single inheritance: extend `ClapTrap` into `ScavTrap` and `FragTrap` with new stats/abilities.
- Multiple inheritance: merge both branches into `DiamondTrap`, pick which base behavior to call.
- Protected members in the base so derived classes can reuse and tweak `_name`, `_hitPoints`, `_energyPoints`, `_attackDamage`.

## Exercises (based on this codebase)

- **ex00 — ClapTrap** (`Module_03/ex00`): Base robot with defaults HP=10, EP=10, AD=0. Attack/repair each consume 1 EP; actions are blocked at 0 HP or 0 EP. Damage floors at 0 HP. Constructors/destructor print lifecycle lines.
  - Run: `make -C ex00 && ./ex00/ClapTrap`

- **ex01 — ScavTrap** (`Module_03/ex01`): Inherits `ClapTrap`, sets HP=100, EP=50, AD=20, overrides `attack` with a ScavTrap message, adds `guardGate()`. Uses protected base members directly. Copy/assign delegate to `ClapTrap`.
  - Run: `make -C ex01 && ./ex01/ScavTrap`

- **ex02 — FragTrap** (`Module_03/ex02`): Inherits `ClapTrap`, sets HP=120, EP=100, AD=30 (note: HP is 120 in this repo), adds `highFivesGuys()`. Lifecycle messages are FragTrap-specific; base logic reused for damage/repair.
  - Run: `make -C ex02 && ./ex02/FragTrap`

- **ex03 — DiamondTrap** (`Module_03/ex03`): Inherits both `ScavTrap` and `FragTrap`. Uses FragTrap stats (HP=120, AD=30) and ScavTrap energy (EP=50). Attack explicitly calls `ScavTrap::attack`. Keeps its own `_name` while `ClapTrap::_name` stores `<name>_clap_name`. `whoAmI()` prints both. Includes an energy-depletion loop using `getEnergyPoints()`. Makefile builds with `-Wshadow -Wno-shadow`.
  - Run: `make -C ex03 && ./ex03/DiamondTrap`

## Key Behaviors Shown in the Code
- **Action gating** (shared):  
```cpp
if (_hitPoints <= 0) { /* cannot act */ }
if (_energyPoints <= 0) { /* cannot act */ }
```
- **ScavTrap override**:  
```cpp
void ScavTrap::attack(const std::string &target) {
    _energyPoints--;
    std::cout << "ScavTrap " << _name
              << " ferociously attacks " << target
              << ", dealing " << _attackDamage << " damage! EP left: "
              << _energyPoints << std::endl;
}
```
- **FragTrap special**:  
```cpp
void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " requests a high five! ✋" << std::endl;
}
```
- **DiamondTrap identity & attack**:  
```cpp
DiamondTrap::DiamondTrap(const std::string &name)
 : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    _hitPoints = FragTrap::DEFAULT_HIT_POINTS;   // 120
    _energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS; // 50
    _attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE; // 30
}
void DiamondTrap::attack(const std::string &target) { ScavTrap::attack(target); }
void DiamondTrap::whoAmI() {
    std::cout << "My DiamondTrap name is " << _name
              << ", and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
```

## Build Notes
- Compile flags are `-Wall -Wextra -Werror -std=c++98`; ex03 adds `-Wshadow -Wno-shadow`.
- Constructors/destructors log creation and destruction to visualize chaining (base first, derived next; reverse on destruction).

## Forward Link
- Next up (Module 04): abstract bases and runtime polymorphism build on these inheritance and override patterns.
