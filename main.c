#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LITTLE NIGHTMARES SOMBRA - PS3 INDIE
// Fase 1: Quarto | Fase 2: Corredor | Fase 3: Fuga

int player_x = 2, player_y = 5;
int monster_x = 15, monster_y = 5;
int key_x = 10, key_y = 2, has_key = 0;
int door_x = 18, door_y = 5;
int level = 1;
int life = 3;

void draw() {
    printf("\n=== LITTLE NIGHTMARES SOMBRA - FASE %d ===\n", level);
    printf("Vida: %d | Chave: %s | Use WASD pra andar\n", life, has_key ? "SIM" : "NAO");
    for(int y=0; y<8; y++) {
        for(int x=0; x<20; x++) {
            if(x==player_x && y==player_y) printf("S"); // Six
            else if(x==monster_x && y==monster_y) printf("M"); // Monstro
            else if(x==key_x && y==key_y && !has_key) printf("K"); // Chave
            else if(x==door_x && y==door_y) printf("D"); // Porta
            else if(y==0 || y==7 || x==0 || x==19) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    printf("S=Six M=Monstro K=Chave D=Porta\n");
}

int main() {
    char cmd;
    printf("LITTLE NIGHTMARES SOMBRA CARREGADO...\n");
    printf("Fuja do monstro, pegue a chave e chegue na porta!\n");
    while(1) {
        draw();
        printf("Move (w/a/s/d): ");
        scanf(" %c", &cmd);
        if(cmd=='a' && player_x>1) player_x--;
        if(cmd=='d' && player_x<18) player_x++;
        if(cmd=='w' && player_y>1) player_y--;
        if(cmd=='s' && player_y<6) player_y++;

        // Monstro persegue
        if(monster_x < player_x) monster_x++;
        else if(monster_x > player_x) monster_x--;
        if(monster_y < player_y && rand()%2) monster_y++;
        else if(monster_y > player_y && rand()%2) monster_y--;

        // Pegou chave?
        if(player_x==key_x && player_y==key_y) {
            has_key=1;
            printf("PEGASTE A CHAVE!\n");
        }
        // Chegou na porta?
        if(player_x==door_x && player_y==door_y && has_key) {
            level++;
            printf("PASSASTE DE FASE! FASE %d\n", level);
            if(level>3) {
                printf("ZERASTE! TU FUGISTE DO PESADELO!\n");
                break;
            }
            player_x=2; player_y=5; monster_x=15; monster_y=5; has_key=0;
            key_x = 5 + level*2; door_x = 18;
        }
        // Monstro pegou?
        if(player_x==monster_x && player_y==monster_y) {
            life--;
            printf("O MONSTRO TE PEGOU! Vida: %d\n", life);
            player_x=2; player_y=5;
            if(life<=0) {
                printf("GAME OVER - O PESADELO TE PEGOU...\n");
                break;
            }
        }
    }
    return 0;
}