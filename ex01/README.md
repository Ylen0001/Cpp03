_________ EX01 __________

1 - L'héritage de classe

On crée une classe ScavTrap qui hérite des attributs/méthodes de la classe ClapTrap.

Son constructeur appelle le constructeur de ClapTrap pour ensuite faire appel au sien. Pour le destructeur c'est l'inverse, on détruit d'abord Scav, puis Clap.

2 - La surcharge de méthode 

Si on souhaite qu'une fonction de ScavTrap utilise une fonction de ClapTrap mais modifié, on peut surcharger cette fonction. On la redéclare dans ScavTrap en la modifiant.

3 - Attributs Protected

Dans ClapTrap, les attributs sont privés. Ils ne peuvent être modifié qu'au sein des méthodes de la classes. Elles sont donc inaccessible depuis les méthodes de ScavTrap. 
Pour palier à ça, sans abimer l'encapsulation, on peut passer ces attributs en protected. Ce qui signifie que les attributs sont accessibles uniquement depuis la classe, ainsi que ses enfants.