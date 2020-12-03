/*
 * SPDX-FileCopyrightText: 2020 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <sys/types.h> 
#include <sys/socket.h>
//include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "serveur.h"
#include "lire_fichier.h"




 int recois_numeros_calcule(int num1,int num2,char* op){
   // CETTE FONCTION PERMET SELON LE CHOIX DE L'OPERATION RETOURNER LE RESULTAT DE CETTE DERNIERE
    float resultat;
    switch ((char)*op) { // on utilise la valeur
        case '+' :
            resultat = num1 + num2;
            return resultat;
            break;
            
        case '-' :
            resultat = num1 - num2;
            return resultat;
            break;
            
        case '*' :
            resultat = num1*num2;
            return resultat;
            break;
            
        case '/' :
            resultat = num1/num2;
            return resultat;
            break;
            
        case '%' :
            resultat = num1 % num2;
            return resultat;
            break;
            
        case '&' :
            resultat = num1 & num2;
            return resultat;
            break;
            
        case '|' :
            resultat = num1 | num2;
            return resultat;
            break;
            
        case '~' :
            resultat = ~num1;
            return resultat;
            break;
            
    }
        

 
 }

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data) {
  int data_size = write (client_socket_fd, (void *) data, strlen(data));
      
  if (data_size < 0) {
    perror("erreur ecriture");
    return(EXIT_FAILURE);
  }
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd) {
  struct sockaddr_in client_addr , server_addr;
  char data[1024];
  

  int client_addr_len = sizeof(client_addr);
 

 
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  //lecture de données envoyées par un client
  int data_size = read (client_socket_fd, (void *) data, sizeof(data));
      
  if (data_size < 0) {
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
  
  /*
   * extraire le code des données envoyées par le client. 
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */
  printf ("Message recu: %s\n", data);
  char code[10];
  sscanf(data, "%s:", code);

  //Si le message commence par le mot: 'message:' 
  if (strcmp(code, "message:") == 0) { // CETTE PARTIE CORRESPOND A L'EXO 5.4
    char message[100];
    printf("Message a envoyer ");
    fgets(message, 1024, stdin);
    strcpy(data, "message: ");
    strcat(data, message);
    renvoie_message(client_socket_fd, data); // envoie du message vers le client
  }
  if (strcmp(code, "calcule:") == 0) { // CETTE PARTIE CORRESPOND A L'EXO 5.5
      float num1,num2;
      char* op; // format pointeur pour la fonction malloc
      op =  malloc(sizeof(op)); // jutilise malloc parce que le pc ne me laisse par reserver de lespace de maniere
// permanent pour op, c'est le fameux segmentation 11, de ce fait je fais appel une allocation dynamique
      sscanf(data,"%*s %s %f %f",op,&num1,&num2);// a partir d'un tableau de donnee, j'extrait les donnees qui m'interesse
      // que jaffecte sur chaque variable, un peu comme le sprintf sauf que c'est le cas contraire. 
      float add = recois_numeros_calcule(num1,num2,op);
      strcpy(data, "calcule: ");
      sprintf(data,"%f",add);
      renvoie_message(client_socket_fd, data);
      free(op); // je l'libere l'espace
      }

  if (strcmp(code, "moyenne:") == 0) { // CETTE PARTIE CORRESPOND A LEXO 5.6
      char fichier1[150] = "note1.txt"; //ON ECRIT LES CHEMINS DES FICHIERS QUI SONT DANS LE DOSSIER
      char* ptr1 = fichier1;
      char fichier2[150] = "note2.txt";
      char* ptr2 = fichier2;
      char fichier3[150] = "note3.txt";
      char* ptr3 = fichier3;
      char fichier4[150] = "note3.txt"; 
      char* ptr4 = fichier4;
      char fichier5[150] = "note3.txt";
      char* ptr5 = fichier5;
      float note1,note2,note3,note4,note5,somme,moyenne;
      note1 = lire_fichier(ptr1); // ON UTILISE LA FONCTION LIRE_FICHIER
      note2 = lire_fichier(ptr2);
      note3 = lire_fichier(ptr3);
      note4 = lire_fichier(ptr4);
      note5 = lire_fichier(ptr5);
      printf("Les notes sont %f ,%f , %f, %f ,%f \n ", note1 , note2 ,note3,note4,note5);
      somme = note1 + note2 + note3 + note4 + note5;
      moyenne = somme/5;
      printf("La moyenne est %f" , moyenne);
      strcpy(data, "moyenne: ");
      sprintf(data,"%f",moyenne);
      renvoie_message(client_socket_fd, data);

      }
close(socketfd);
}



int main() {

  int socketfd;
  int bind_status;
  int client_addr_len;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Relier l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if (bind_status < 0 ) {
    perror("bind");
    return(EXIT_FAILURE);
  }
 
  // Écouter les messages envoyés par le client
  listen(socketfd, 10);

  //Lire et répondre au client

  recois_envoie_message(socketfd);

  return 0;
}
