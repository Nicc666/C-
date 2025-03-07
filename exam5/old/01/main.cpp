
#include "Warlock.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"

/*
int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}*/

int main()
{
    // Creazione di un Warlock
    Warlock merlin("Merlin", "the Wise");
    merlin.introduce();
    std::cout << std::endl;

    // Creazione di un bersaglio Dummy
    Dummy dummy;
    
    // Creazione di incantesimi
    Fwoosh *fwoosh = new Fwoosh();
    Fwoosh *fwooshClone = new Fwoosh();
    
    // Test: Aggiunta di incantesimi
    merlin.learnSpell(fwoosh);
    merlin.learnSpell(fwooshClone); // Dovrebbe evitare duplicati o gestirli correttamente
    
    // Test: Lancio dell'incantesimo conosciuto
    merlin.launchSpell("Fwoosh", dummy);
    
    // Test: Rimozione dell'incantesimo
    merlin.forgetSpell("Fwoosh");
    merlin.launchSpell("Fwoosh", dummy); // Non dovrebbe lanciare nulla
    
    // Test: Rimozione di un incantesimo non esistente
    merlin.forgetSpell("Fireball"); // Non dovrebbe causare errori
    
    // Test: Modifica del titolo del Warlock
    merlin.setTitle("the Grand Sorcerer");
    merlin.introduce();
    
    // Test: Creazione di un nuovo Warlock e copia
    Warlock morgana("Morgana", "the Enchantress");
    morgana.introduce();
    //morgana = merlin;
    //morgana.introduce(); // Dovrebbe mostrare le informazioni di Merlin
    
    return 0;
}
