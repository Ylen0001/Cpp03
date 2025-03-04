_____ EX03 _____

1 - Le Diamond Problem

       ClapTrap
        /    \
   ScavTrap  FragTrap
        \    /
      DiamondTrap

2 - Wshadow / Wno-shadow flags

Wshadow est un flag qui permet d'afficher un avertissement si un shadowing est détecté :

	void setValue(int value) {  // ⚠️ Shadowing : le paramètre masque l'attribut
		value = value;  // Cette ligne ne fait rien !
	}

	void correctSetValue(int value) {
		this->value = value;  // ✅ Utilisation correcte avec `this->`
	}

	Wno-shadow désactive les avertissements liés au shadowing.

3 - Virtual Destructor

Lorsque l'on utilise une classe qui hérite d'une autre, et qu'on alloue une instance dynamiquement sur la heap, si le destructeur de la classe mère n'a pas son destructeur en virtual, seul le destructeur de la classe enfant sera appelé, ce qui causera une fuite de mémoire.

Donc dans le cas d'une classe mère / d'héritages, on va donc passer le destructeur de cette classe en virtual. Ce qui veut dire que les héritiers n'hériteront pas de ce destructeur. 

4 - Using

Diamond hérite de certains attributs de FragTrap, et d'autres de Scav. Afin de déterminer de qui il va hérité la méthode "attack", on utilise le keyword "using".

using ScavTrap::attack; // On garde l'attack de ScavTrap

5 - Bien comprendre l'héritage

Reprenons du début. 

Lorsque l'on a crée plus tôt une instance de FragTrap, elle est constituée d'une instance de ClapTrap, donc de ses attributs/méthodes, à laquelle elle ajoute via son constructeur ses propres attributs/méthodes. D'où l'importance de faire appel aux deux destructeurs.

Donc dans le cas de DiamondTrap on a :

📝 Résumé des composants de DiamondTrap
Classe	Contenu
ClapTrap	name, hitPoints, energyPoints, attackDamage
ScavTrap	Ajoute guardGate()
FragTrap	Ajoute highFivesGuys()
DiamondTrap	Ajoute name propre et whoAmI()

6 - L'ordre dans la liste d'initialisation 

Lorsqu'on initialise une instance qui hérite d'autres classes, on utilise une liste d'initialisation.
Dans notre cas on a donc :

DiamondTrap qui construit dans l'ordre :

- Un clapTrap (Avec ses attributs)
- ClapTrap est ensuite polymorphé en ScavTrap (Donc les attributs de Scav sont rajouté a Clap, ceux en communs comme name sont écrasés)
- Scav est polymorphé en Frag
- Frag est polymorphé en Diamond

Donc, dans l'exemple suivant :

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)

ClapTrap::name n'est plus "Diamond_clap_name", puisqu'il a été écrasé par Scav, puis ensuite par Frag.
IMPORTANT -> name(name) n'écrasera pas le nom de l'instance de clapTrap, puisque Diamond a son propre attribut privé "name".
Par conséquent, on peut accéder depuis DiamondTrap à l'attribut name de cette instance, puis également à l'attribut name de l'instance de ClapTrap, polymorphé en Scav puis en Frag.

REMARQUE IMPORTANTE:

Dans notre cas de figure, Frag et Scav n'ont pas d'attribut "name" dans leur classe. Ils héritent de celle de Clap. 
Ce qui fait que Diamond a donc accès a deux attributs "name", le sien + celui de l'instance de Clap.
Cependant, si on ajoute un attribut private "name" dans Frag et Scav, on pourrait potentiellement avoir accès à 4 "name" depuis Diamond. 

7 - Ordre de la liste d'initialisation BIS

On a un souci. Dans notre cas, il faut que DiamondTrap ait son attribut energyPoint a la valeur de l'energyPoint de Scavtrap.
Problème, dans notre initialisation, on prend bien la valeur de son energyPoint, mais ensuite cette valeur est écrasée par le polymorphisme en Fragtrap.
On a donc DiamondTrap qui a les valeur d'un FragTrap. Etrangement, on ne peut donc pas les modifier dans le constructeur comme suit :

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name)
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;

	std::cout << C_PASTEL_BLUE "DiamondTrap " << this->name << " is born!" << C_RESET << std::endl;
}

Les valeurs des attributs sont celle de FragTrap, puisque c'est le dernier polymorphisme appliqué. Il a écrasé les valeur de Scav.
On va être obligé de set energyPoint manuellement avec un setter. 
