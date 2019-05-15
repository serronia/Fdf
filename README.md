<h1 align="center">
Fdf 
</h1>

<h3> Description </h3>
<p>Tous les programmes que vous avez écris jusqu'à maintenant s'exécutaient uniquement en mode texte dans votre terminal.
Découvrons maintenant quelque chose de plus excitant : comment ouvrir une fenêtre graphique et dessiner dedans ?
Pour commencer votre voyage au pays de la programmation graphique,
FdF vous propose de représenter le maillage en "fils de fer" d'un terrain en 3D.</p></br>

<p><b>Objectif :</b> Représenter un terrain 3D</p>
<p><b>Langage :</b> C</p>
<p><b>Fonctions autorisées :</b> open, read, write, close, malloc, free, perror, strerror, exit, Toutes les fonctions de la lib math (-lm et man 3 math), Toutes les fonctions de la miniLibX.</p>

<h3> But du jeu </h3>

Ce projet consiste à créer graphiquement la representation schématique (en “fils de
fer” ou “wireframe” en anglais) d’un terrain en relief en reliant différents points (x, y,
z) par des segments. Les coordonnées du terrain seront stockées dans un fichier passé en
paramètre. Chaque nombre correspond à un point dans l’espace :</br>
• La position horizontale correspond à son abscisse.</br>
• La position verticale correspond à son ordonnée.</br>
• La valeur correspond à son altitude.</br>
