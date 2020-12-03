/*
 * SPDX-FileCopyrightText: 2020 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

/* 
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int envoie_recois_message(int socketfd) {
  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));
  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, 1024, stdin);
  strcpy(data, "message: ");
  strcat(data, message);
  
  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));
  
  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);
 
  return 0;
}

//////////////////////////////////////

int envoie_operateur_numeros(int socketfd){
  // CETTE FONCTION PERMET DANS UN PREMIER TEMPS D'EMVOYER LES NOMBRES UTILISES POUR L'OPERATION ET DANS UN DEUXIEME TEMPS
  // DE LIRE LE RESULTAT DE L'OPERATION ENVOYE PAR LE SERVEUR.

// ECRITURE 

  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));
  
  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  printf("Quelle opération ");
  fgets(message, 1024, stdin);
  strcpy(data, "calcule: ");
  strcat(data, message);
  
  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);
 
  return 0;
}

////////////////////////////////////////////////////////////

int envoie_operateur_moyenne(int socketfd){
  // CETTE FONCTION PERMET DE LIRE LA MOYENNE CALCULEE PAR LE SERVEUR
  char data[1024];
// la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));
  char message[100];
  printf("Ce message sert a lancer le serveur, veuillez tapper et entrer n'importe quoi ");
  fgets(message, 1024, stdin);
  strcpy(data, "moyenne: ");
  strcat(data, message);
  
  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }
// COMME LE SERVEUR FAIT UN LISTEN IL DOIT RECEVOIR QUELQUECHOSE POUR POUVOIR SE METTRE EN MARCHE.

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));
  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }
  printf("Message recu: %s\n", data);
  return 0;
}


int main() {
  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  //demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if ( connect_status < 0 ) {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }

  // appeler la fonction pour envoyer un message au serveur
  //envoie_recois_message(socketfd); // lancement de l'exo 5.4
  //envoie_operateur_numeros(socketfd); // lancement de l'exo 5.5
  envoie_operateur_moyenne(socketfd); //lancement de l'exo 5.6
  close(socketfd);
}
