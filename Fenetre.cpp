#include "Fenetre.hpp"

Fenetre::Fenetre() : caseCocher("Afficher le _titre", true) {
    set_border_width(10);
    set_title("Bouton à cocher");

    caseCocher.set_can_focus(false);

    //Lorsque l'utilisateur clique sur la case à cocher, appeler la fonction de rappel afficherTitre.
    caseCocher.signal_toggled().connect(sigc::mem_fun(*this, &Fenetre::afficherTitre));
    caseCocher.set_active(); //Activer la case à cocher.

    add(caseCocher);

    caseCocher.show();
}

void Fenetre::afficherTitre() {
    if(caseCocher.get_active()) { //Si la case est cochée.
        set_title("Bouton à cocher");
    }
    else { //Si elle n'est pas cochée.
        set_title("");
    }
}

