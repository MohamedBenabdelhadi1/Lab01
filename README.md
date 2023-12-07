# Lab01
# question 1
Affichage d’un message d’accueil, suivi d’un prompt simple :
deux fonction write  et read sont utilisées pour la lecture et l'écriture de données

# question 2
Exécution de la commande saisie et retour au prompt (REPL : read–eval–print loop) :
1-Télechargement du Fortune :
sudo apt-get install fortune
2- La fonction fork retourne deux fois :
Dans le processus parent, attendre le fils pour finir.
Dans le processus fils, exécution de la command.

# question 3
 Gestion de la sortie du shell avec la commande “exit” 
On a créer une boucle if qui test si la command = EXIT pour afficher bye bye et sortir du shell 

# question 4
Affichage du code de retour (ou du signal) de la commande précédente dans le prompt :
On a utiliser les deux fonctions WIFEXITED(status) pour le exit et WIFSIGANNLED(status) pour le signal  
 	WIFEXITED(status) == true si le fils s’est terminé normalement (exit ou return depuis le main()).
                              WEXITSTATUS(status) renvoie dans ce cas la valeur de sortie du fils.
 	WIFSIGNALED(status) == true si le fils s’est terminé à cause d’un signal. 
                              WTERMSIG(status) renvoie alors le numéro du signal qui a causé la fin du fils.
                              
On a declarer deux variables pour stocker le status de exit et le signal int exit_res, signal_res
apres on a utilisé les boucles if pour tester si le procesus est terminer par un exit ou un signal
apres on a afficher la valeur du retour 
Remarque on ne savait pas qu'on est censé utiliser sprintf donc on a crée un code dans la qestion 5 qui affiche les int avec write (qui nous a pris beaucoup de temps XD)
pour lz question 4 c'est la meme methode mais elle est inclue dans la boucle d'affichage 


# question 5
on a calculer le temps d'execution des processus par les commande de clock MONOTIC
apres on a converti ce temps en miliseconde pour l'afficher avec la methode qu'on a ajouté write-int

# question 6
dans cette question on a transformer les arguments en tokens individuels à l'aide de la fonction strtok et les stocke dans le tableau args  
on a créé une limite pour les arguments pour ne pas dépasser 10 
enfin on éxecute la commande avec les arguments par execvp
