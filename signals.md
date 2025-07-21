# Signals

### void (*signal(int sig, void (*func)(int)))(int)
La fonction signal permet de définir le gestionnaire de signal à invoquer en cas de réception d'un signal particulier.

### int sigemptyset(sigset_t *set);
Vide l'ensemble de signaux fourni par set, tous les signaux étant exclus de cet ensemble. 

### int sigaddset(sigset_t *set, int signum);
Ajoutent le signal signum de l'ensemble set. 

### int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
L'appel système sigaction() sert à modifier l'action effectuée par un processus à la réception d'un signal spécifique. 
### int kill(pid_t pid, int sig);
L'appel système kill() peut être utilisé pour envoyer n'importe quel signal à n'importe quel processus ou groupe de processus. 
### pid_t getpid(void); 
Renvoie l'identifiant du processus appelant. Ceci est souvent utilisé par des routines qui créent des fichiers temporaires uniques.