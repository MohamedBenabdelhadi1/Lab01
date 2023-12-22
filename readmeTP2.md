# Lab02
![33](https://github.com/MohamedBenabdelhadi1/Lab01/assets/152403377/73d5e866-aaf9-4251-9460-325806f7c0fc)

on a tester la connextion au serveur info1 de l'école et on a récupérer le ficher test et aussi le upload d'un fichier de notre pc

![34](https://github.com/MohamedBenabdelhadi1/Lab01/assets/152403377/4fbd98e5-160d-4d59-9056-b0574c9bf3f1)

![35](https://github.com/MohamedBenabdelhadi1/Lab01/assets/152403377/219b87c6-22e4-44e7-9dab-aa64cf3ff188)

on a utiliser le netcat pour voir les packets comme indiquer dans la doc 

## question 1

on a créer un code pour tester si le nombre d'argument entrer est égale à 3 sinon il affiche un msg en fonction du nombre d'arguments rentré

## question 2

on a créer une fonction pour l'obtention des information du serveur donner dans le 2eme arguments 

Après l'affichage de ces resultats sous forme d'addrese ip et le port 69

## question 3

### cette question est validé par le professeur 

dans cette question on a créé un socket pour pouvoir nous connecter au serveur.

![question 3](https://github.com/MohamedBenabdelhadi1/Lab01/assets/152403377/1f69c648-c3f2-4c8e-88d6-5d1adfc7fe39)

on a aussi visualiser les trames de connection sur Wireshark 

![question 3 1](https://github.com/MohamedBenabdelhadi1/Lab01/assets/152403377/10763053-4cde-46d1-876a-fa083a98aeb2)

## question 4

### cette question est validé par le professeur 

#### cette question vous pouver remarquer que la structure de notre code est changé puisque c'est mon binome Nouhaila qui a fait le code de cette partie et qu'il a travaillé le code à l'intérieur du main contrairement à mes codes des premiers questions

La fonction getFile initialise une requête de lecture (RRQ), envoie la requête au serveur, puis réceptionne et écrit les blocs de données dans un fichier local jusqu'à la fin du transfert.

La fonction main analyse les arguments de la ligne de commande, crée un socket, établit la connexion avec le serveur, et appelle la fonction getFile.

on a tester de recevoir un fichier perdu.txt de taille 400 BYTES

![question 4](https://github.com/MohamedBenabdelhadi1/Lab01/assets/152403377/ad5795a3-19b3-4f54-8517-f96a84194465)

