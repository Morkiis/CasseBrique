#include "header.h"

void InitBriques(brique Briques[15][15]){

    int i;
    int j;

    for (i=0;i<15;i++){
        for (j=0;j<15;j++){

            Briques[i][j].hauteur=24;
            Briques[i][j].largeur=64;
            Briques[i][j].position.x=32+i*Briques[i][j].largeur; //16 pour le side
            Briques[i][j].position.y=j*Briques[i][j].hauteur;

        }
    }


}

void AfficheBriques(game *myGame,gameState state, brique Briques[15][15]){


        int i;
        int j;

        SDL_Rect rectangleDest;
        SDL_Rect rectangleSource;


        myGame->g_surface = IMG_Load("./assets/bricks.png");//Chargement de l'image bitmap

         if(!myGame->g_surface) {
            fprintf(stdout,"IMG_Load: %s\n", SDL_GetError());
            // handle error
        }

        if(myGame->g_surface){

                 myGame->g_texture = SDL_CreateTextureFromSurface(myGame->g_pRenderer,myGame->g_surface); // Préparation du sprite
                 SDL_FreeSurface(myGame->g_surface); // Libération de la ressource occupée par le sprite

                if(myGame->g_texture){



                    for (i=0;i<15;i++){
                        for (j=0;j<15;j++){

                            //gestion des animations
                            rectangleSource.x=64; //x=0 y=0 => rouge    x=64 y=0 =>jaune     x=0 y=24 => vert   x=64 y=24 =>bleu
                            rectangleSource.y=0;
                            rectangleSource.w=Briques[i][j].largeur;
                            rectangleSource.h=Briques[i][j].hauteur;



                            //Définition du rectangle dest pour dessiner Bitmap
                            rectangleDest.x=Briques[i][j].position.x;//debut x
                            rectangleDest.y=Briques[i][j].position.y;//debut y
                            rectangleDest.w=rectangleSource.w; //Largeur
                            rectangleDest.h=rectangleSource.h; //Hauteur

                            SDL_RenderCopy(myGame->g_pRenderer,myGame->g_texture,&rectangleSource,&rectangleDest);
                        }
                    }

                }

                else{
                        fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
                }



        }else{
            fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
        }

    destroyTexture(myGame);


}


//faire un random pour changer, faire un si random = 1 et 2 pour changer la couleur
//faire collision avec briques

