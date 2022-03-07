
<h1 align=center>
	<b> MINISHELL - 42</b>
</h1>

//demo

---
## Sujet 

→ L'objectif de Minishell est ... 🥁 de créer un petit shell ! Pour plus de clarté, je vous partage la définition d'un shell : 

``` Le shell (ou interface système en français) est un programme qui reçoit des commandes informatiques données par un utilisateur à partir de son clavier pour les envoyer au système d’exploitation qui se chargera de les exécuter.```

TADAM !

---
## Comment ça marche ? 

1. ```git clone https://github.com/clbouche/minishell.git```

2. ```make```  -> On a utilisé le MAGNIFIQUE [Genmake](https://github.com/arthur-trt/genMake) de notre Arthur national !

3. run ./minishell -> crée un prompt, à vos commandes ! 😃 

---
## Plan du projet

#### Comprendre le shell


#### Parsing

1. Pipe 
2. Redirections
	2.1. A penser 
	- Les multiples redirections 
	- 
4. Quotes
5. Expand


#### Execution 
Je ne vais pas parler de cette partie puisque je ne m'en suis pas occupée ! Good luck 🤡 

#### Builtins
  - cd 
  - echo 
  - exit
  - export
  - pwd
  - unset
  
---
#### Les cas tricky/relous


---
## Notes

---
## Ressources

- http://i.paysdu42.fr/?page=minishell.c → principe de minishell et son fonctionnement. 

- http://www.zeitoun.net/articles/communication-par-tuyau/start → les pipes. 

- https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html → Le manuel de Bash, et ouiiii ! Je vous conseille : 
	- 3.1.1. Shell operations → vous donnera les étapes par lesquelles passer pour traiter les informations dans le bon ordre. 
	Permet d'éviter de gérer de nombreux cas particuliers a la fin du projet. 
	- 3.6 Redirections → comprendre leurs fonctionnements et comment les utiliser. 

- https://www.geeksforgeeks.org/signals-c-language/ → les signaux. 

- https://github.com/iciamyplant/Minishell#i---quest-ce-que-minishell- → un Readme plus que complet sur la partie parsing !! 

- https://shapeshed.com/unix-exit-codes/ → sortie d'erreurs et code erreur posix. 

- https://ix-56h.github.io/how-to-make-a-tokenizer/  → un tuto que l'on a finalement pas suivi mais qui rend un parsing solide comme du beton alors je vous le conseille vivement ! 

---
### 🎉 Final Grade 🎉 
100/100

Créé par [Lucrèce](https://github.com/Tart3mpion) & moi ! 

--- 
🍄 ENJOY 🍄
