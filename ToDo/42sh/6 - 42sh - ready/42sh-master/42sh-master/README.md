# 42sh
Création d'un shell complet en langage C gérant toutes les fonctionnalitées décrites ci-dessous. Projet de l'école 42 soumis à la norme de celle-ci.

## Fonctionnalitées

Affichage et édition de ligne :
* Affichage d’un prompt.
* Lecture de la ligne de commande.
* Gestion correcte des espaces et des tabulations.
* Ecrire et éditer une commande sur plusieurs lignes.
* Utiliser les flèches du haut et du bas pour naviguer dans l’historique des commandes.
* Page-Up et Page-Down permettent de passer d’une ligne à l’autre de la commande en restant sur la même colonne.
* Aller directement au début et à la fin d’une ligne avec home et end.
* Mode sélection (Alt-M) qui permet de copier (Alt-C) ou couper (Alt-X) ou coller (Alt-V).
* Se déplacer par "mot" vers la gauche et vers la droite avec Alt+LEFT et Alt-RIGHT.

Les builtins suivantes avec toutes leurs options si elles en ont (au strict minimum les options dictées par le standard POSIX) :
* cd
* echo
* exit
* env
* setenv
* unsetenv

Exécution de commandes simples avec leurs paramètres et gestion du PATH :
* Gestion des erreurs et de la valeur de retour des commandes
* Les opérateurs de redirection suivants : ">", ">>", "<" et "|".
* Les opérateurs logiques "&&" et "||".
* Le séparateur ";".

Features supplémentaires :
* Les inhibiteurs """ (double quote), "’" (simple quote) et "\" (backslash).
* Les redirections avancées : l’aggrégation des sorties de fichier et le heredoc "<<".
* Les variables locales (setvar) et les builtin unset et export.
* L’historique des commandes et les builtins history et "!" avec toutes leurs options
si elles en ont.
* Complétion dynamique.

## Tests

Pour lancer les tests contenus dans le dossier "tests", lancez la commande suivante :
```
make check
```

## Contributeurs :
* **Jérémy Camhi** - [Jeremshy](https://github.com/JeremShy)
* **Vivien Steffen** - [vsteffen](https://github.com/vsteffen)
* **Anna Dominguez** - [Vesta-nna](https://github.com/Vesta-nna)
* **Julien Balestra** - [JulienBalestra](https://github.com/JulienBalestra)
