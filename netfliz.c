#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char admin[100];
char admin_psw[20];

#define CONTRA "10"

int num_usuarios=-1;
int usu_isesion;
int temp=0;


struct{
  char titulo[100];
  char genero[50];
  char duracion[10];
  char anio[6];
  int seleccion;
}pelis[20];
struct fecha_nac{
  int dia,mes,anio;
};
struct pelis_rentadas{
  char titulo[100];
  struct fecha_nac dia_i;
  struct fecha_nac dia_f;
};

struct usuario{
  char nombre[100];
  char direccion[100];
  char email[30];
  char nom_usu[50];
  char usu_psw[10];
  struct fecha_nac nacimiento;
  struct pelis_rentadas peli1;
  struct pelis_rentadas peli2;
  struct pelis_rentadas peli3;
  int t_pelis;
  int activo;
};

struct usuario t[30];
struct usuario usuarios[30];

void informe_baja(void);
void popular(void);
void interfaz_admin(void);
void menu1(void);
void menu_usuario(void);
void menu_admin(void);
void menu_registro(void);
void isesion_usuario(void);
void interfaz_usuario(void);
void perfil(int x);
void timer(void);
void catalogo(int x);
int num_pelis(void);
void informe_alta(void);

int main(int argc, char* argv[]){
  FILE* archivo;
  FILE* manual_usu;
  FILE* peliculas;
  char arg[200];
  char* c;
  char linea[200];
  int a=argc,i,j;
  //código para sacar la fecha
  time_t currentTime;
  time(&currentTime);
  struct tm* myTime=localtime(&currentTime);
  //
  c=arg;
  strcpy(admin,"admin");
  strcpy(admin_psw,"10");
  archivo=fopen("usuarios.txt","rt");
  if(archivo!=NULL){
    while(!feof(archivo)){
      fgets(linea,50,archivo);
      if(feof(archivo)){
        break;}
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        strcpy(usuarios[num_usuarios+1].nombre,linea);
      }
      fgets(linea,80, archivo);
      if(feof(archivo)){
        break;}
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        strcpy(usuarios[num_usuarios+1].direccion,linea);
      }
      fgets(linea,20,archivo);
      if(feof(archivo)){
        break;}
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        sscanf(linea, "%d %d %d",&usuarios[num_usuarios+1].nacimiento.dia,&usuarios[num_usuarios+1].nacimiento.mes, &usuarios[num_usuarios+1].nacimiento.anio);
      }
      fgets(linea,50, archivo);
      if(feof(archivo)){
        break;}
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        strcpy(usuarios[num_usuarios+1].email,linea);
      }
      fgets(linea,50, archivo);
      if(feof(archivo)){
        break;}
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        strcpy(usuarios[num_usuarios+1].nom_usu,linea);
      }
      fgets(linea,50, archivo);
      if(feof(archivo)){
        break;}
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        strcpy(usuarios[num_usuarios+1].usu_psw,linea);
      }

      fgets(linea,50, archivo);
      if(feof(archivo)){
        break;}
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        strcpy(usuarios[num_usuarios+1].peli1.titulo,linea);
      }
      fgets(linea,20,archivo);
      if(feof(archivo)){
        break;
      }
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        sscanf(linea, "%d %d %d", &usuarios[num_usuarios+1].peli1.dia_i.dia,&usuarios[num_usuarios+1].peli1.dia_i.mes,&usuarios[num_usuarios+1].peli1.dia_i.anio);
      }

      fgets(linea,20,archivo);
      if(feof(archivo)){
        break;
      }
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        sscanf(linea, "%d %d %d", &usuarios[num_usuarios+1].peli1.dia_f.dia,&usuarios[num_usuarios+1].peli1.dia_f.mes,&usuarios[num_usuarios+1].peli1.dia_f.anio);
      }
      fgets(linea,50, archivo);
      if(feof(archivo)){
        break;}
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        strcpy(usuarios[num_usuarios+1].peli2.titulo,linea);
      }
      fgets(linea,20 ,archivo);
      if(feof(archivo)){
        break;
      }
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
          sscanf(linea, "%d %d %d", &usuarios[num_usuarios+1].peli2.dia_i.dia,&usuarios[num_usuarios+1].peli2.dia_i.mes,&usuarios[num_usuarios+1].peli2.dia_i.anio);
      }

      fgets(linea,20,archivo);
      if(feof(archivo)){
        break;
      }
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        sscanf(linea, "%d %d %d", &usuarios[num_usuarios+1].peli2.dia_f.dia,&usuarios[num_usuarios+1].peli2.dia_f.mes,&usuarios[num_usuarios+1].peli2.dia_f.anio);
      }
      fgets(linea,50, archivo);
      if(feof(archivo)){
        break;}
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        strcpy(usuarios[num_usuarios+1].peli3.titulo,linea);
      }
      fgets(linea,20,archivo);
      if(feof(archivo)){
        break;
      }
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        sscanf(linea, "%d %d %d", &usuarios[num_usuarios+1].peli3.dia_i.dia,&usuarios[num_usuarios+1].peli3.dia_i.mes,&usuarios[num_usuarios+1].peli3.dia_i.anio);
      }

      fgets(linea,20,archivo);
      if(feof(archivo)){
        break;
      }
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        sscanf(linea, "%d %d %d", &usuarios[num_usuarios+1].peli3.dia_f.dia,&usuarios[num_usuarios+1].peli3.dia_f.mes,&usuarios[num_usuarios+1].peli3.dia_f.anio);
      }
      fgets(linea,8,archivo);
      if(feof(archivo)){
        break;
      }
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        sscanf(linea,"%d", &usuarios[num_usuarios+1].t_pelis);
      }
      fgets(linea,8,archivo);
      if(feof(archivo)){
        break;
      }
      if(strlen(linea)>0){
        linea[strlen(linea)-1]='\0';
        sscanf(linea,"%d", &usuarios[num_usuarios+1].activo);
      }
      num_usuarios++;
    }
    fclose(archivo);
  }
  if(a==1){
    system("clear");
    printf("       ***NETFLIZ***\n");
    puts("Creado por:");
    puts("::::::::Sergio Medina::::::::");
    puts("::::::::Gustavo Luna:::::::::");
    puts("::::::::Carlos de la Rosa::::::::");
    timer();
    timer();
    menu1();
  }
  else if(a>1){
    strcpy(arg,argv[1]);
    if(c[0]=='-'&&c[1]=='h'){
      system("clear");
      manual_usu=fopen("manual_usuario.txt","rt");
      if(manual_usu!=NULL){
        while(!feof(manual_usu)){
          fgets(arg,200,manual_usu);
          if(feof(manual_usu)){
            break;
          }
          if(strlen(arg)>0){
            arg[strlen(arg)-1]='\0';
            printf("%s\n",arg);
          }
        }
      }
      fclose(manual_usu);
    }
    if(c[0]=='-' && c[1]=='m'){
      i=0;
      peliculas=fopen("peliculas.txt","rt");
      if(peliculas!=NULL){
        while(!feof(peliculas)){
          fgets(arg,50, peliculas);
          if(feof(peliculas)){
            break;
          }
          if(strlen(arg)>0){
            arg[strlen(arg)-1]='\0';
            strcpy(pelis[i].titulo,arg);
          }
          fgets(arg,50,peliculas);
          if(feof(peliculas)){
            break;
          }
          if(strlen(arg)>0){
            arg[strlen(arg)-1]='\0';
            strcpy(pelis[i].genero,arg);
          }
          fgets(arg,20,peliculas);
          if(feof(peliculas)){
            break;
          }
          if(strlen(arg)>0){
            arg[strlen(arg)-1]='\0';
            strcpy(pelis[i].duracion,arg);
          }
          fgets(arg,10,peliculas);
          if(feof(peliculas)){
            break;
          }
          if(strlen(arg)>0){
            arg[strlen(arg)-1]='\0';
            strcpy(pelis[i].anio,arg);
          }
          fgets(arg,5,peliculas);
          if(feof(peliculas)){
            break;
          }
          if(strlen(arg)>0){
            arg[strlen(arg)-1]='\0';
            sscanf(arg,"%d",&pelis[i].seleccion);
          }
          i++;
        }
      }
      fclose(peliculas);
      puts("        ***Películas de acción***");
      for(j=0;j<i;j++){
        if(strcmp(pelis[j].genero, "Accion")==0){
          printf("%s\n", pelis[j].titulo);
          printf("%s\n", pelis[j].genero);
          printf("%s mins\n", pelis[j].duracion);
          printf("%s\n", pelis[j].anio);
        }
      }
      puts("\n    ***Películas de terror***");
      for(j=0;j<i;j++){
        if(strcmp(pelis[j].genero, "Terror")==0){
          printf("%s\n", pelis[j].titulo);
          printf("%s\n", pelis[j].genero);
          printf("%s mins\n", pelis[j].duracion);
          printf("%s\n", pelis[j].anio);
        }
      }
    }
    if(c[0]=='-' && c[1]=='u'){
      printf("*USUARIOS ACTIVOS*\n");
      for(i=0;i<=num_usuarios;i++){
        if(usuarios[i].activo==1){
          printf("%d. %s\n",i+1,usuarios[i].nombre);
        }
      }
      printf("*USUARIOS DESACTIVADOS*\n");
      for(i=0;i<=num_usuarios;i++){
        if(usuarios[i].activo!=1){
          printf("%d. %s\n",i+1,usuarios[i].nombre);
        }
      }
    }
  }//fin de else if
  if(a==1){
    archivo=fopen("usuarios.txt","wt");
    for(i=0;i<=num_usuarios;i++){
      if((usuarios[i].peli1.dia_f.dia>=myTime->tm_mday)&& (usuarios[i].peli1.dia_f.mes>=myTime->tm_mon)&&(usuarios[i].peli1.dia_f.anio>=myTime->tm_year-100)){
        strcpy(usuarios[i].peli1.titulo,"-1");
        usuarios[i].peli1.dia_i.dia=-1;
        usuarios[i].peli1.dia_i.mes=-1;
        usuarios[i].peli1.dia_i.anio=-1;
        usuarios[i].peli1.dia_f.dia=-1;
        usuarios[i].peli1.dia_f.mes=-1;
        usuarios[i].peli1.dia_f.anio=-1;
      }
      if((usuarios[i].peli2.dia_f.dia>=myTime->tm_mday)&& (usuarios[i].peli2.dia_f.mes>=myTime->tm_mon)&&(usuarios[i].peli2.dia_f.anio>=myTime->tm_year-100)){
        strcpy(usuarios[i].peli1.titulo,"-1");
        usuarios[i].peli2.dia_i.dia=-1;
        usuarios[i].peli2.dia_i.mes=-1;
        usuarios[i].peli2.dia_i.anio=-1;
        usuarios[i].peli2.dia_f.dia=-1;
        usuarios[i].peli2.dia_f.mes=-1;
        usuarios[i].peli2.dia_f.anio=-1;
      }
      if((usuarios[i].peli3.dia_f.dia>=myTime->tm_mday)&& (usuarios[i].peli3.dia_f.mes>=myTime->tm_mon)&&(usuarios[i].peli3.dia_f.anio>=myTime->tm_year-100)){
        strcpy(usuarios[i].peli1.titulo,"-1");
        usuarios[i].peli3.dia_i.dia=-1;
        usuarios[i].peli3.dia_i.mes=-1;
        usuarios[i].peli3.dia_i.anio=-1;
        usuarios[i].peli3.dia_f.dia=-1;
        usuarios[i].peli3.dia_f.mes=-1;
        usuarios[i].peli3.dia_f.anio=-1;
      }
      if((usuarios[i].nacimiento.anio<=2000)){
        fprintf(archivo, "%s\n", usuarios[i].nombre);
        fprintf(archivo, "%s\n", usuarios[i].direccion);
        fprintf(archivo, "%d %d %d\n", usuarios[i].nacimiento.dia,usuarios[i].nacimiento.mes,usuarios[i].nacimiento.anio);
        fprintf(archivo, "%s\n", usuarios[i].email);
        fprintf(archivo, "%s\n", usuarios[i].nom_usu);
        fprintf(archivo, "%s\n", usuarios[i].usu_psw);
        fprintf(archivo, "%s\n", usuarios[i].peli1.titulo);
        fprintf(archivo, "%d %d %d\n", usuarios[i].peli1.dia_i.dia, usuarios[i].peli1.dia_i.mes, usuarios[i].peli1.dia_i.anio);
        fprintf(archivo, "%d %d %d\n", usuarios[i].peli1.dia_f.dia, usuarios[i].peli1.dia_f.mes, usuarios[i].peli1.dia_f.anio);
        fprintf(archivo, "%s\n", usuarios[i].peli2.titulo);
        fprintf(archivo, "%d %d %d\n", usuarios[i].peli2.dia_i.dia, usuarios[i].peli2.dia_i.mes, usuarios[i].peli2.dia_i.anio);
        fprintf(archivo, "%d %d %d\n", usuarios[i].peli2.dia_f.dia, usuarios[i].peli2.dia_f.mes, usuarios[i].peli2.dia_f.anio);
        fprintf(archivo, "%s\n", usuarios[i].peli3.titulo);
        fprintf(archivo, "%d %d %d\n", usuarios[i].peli3.dia_i.dia, usuarios[i].peli3.dia_i.mes, usuarios[i].peli3.dia_i.anio);
        fprintf(archivo, "%d %d %d\n", usuarios[i].peli3.dia_f.dia, usuarios[i].peli3.dia_f.mes, usuarios[i].peli3.dia_f.anio);
        fprintf(archivo, "%d\n", usuarios[i].t_pelis);
        fprintf(archivo, "%d\n", usuarios[i].activo);
      }
    }
    fclose(archivo);

  }
  return 0;
}//fin de main

void menu1(void){
  //menu para empezar programa en donde el usuario elige entre entrar a la cuenta de admin o de usuario o si quiere terminar el programa.
  system("clear");
  int o;
  printf("               ***BIENVENIDO A NETFLIZ***\n");
  printf("\n---->presiona 1 si eres usuario\n");
  printf("---->presiona 2 si eres administrador\n");
  printf("---->presiona 3 si quieres salir\n");
  scanf("%d",&o);
  if(o==1){
    printf("Menú usuario...\n");
    menu_usuario();
  }
  else if(o==2){
    printf("Menú admin...\n");
    menu_admin();
  }
  else if(o==3){
    system("clear");
    printf("Gracias por usar Netfliz\n" );
  }
}
void menu_usuario(void){
  int o;
  system("clear");
  printf("               ***MENÚ DE USUARIO***\n");
  printf("\n---->presiona 1 si eres usuario registrado\n");
  printf("---->presiona 2 si quieres registrarte\n");
  printf("---->presiona 3 si quieres regresar al menú anterior\n");
  scanf("%d",&o);
  if(o==1){
    printf("Usuario registrado\n");
    isesion_usuario();
  }
  else if(o==2){
    printf("Regístrate\n");
    menu_registro();
  }
  else if(o==3){
    menu1();
  }
}
void menu_admin(void){
  int o, verificar_psw;
  char user[100];
  char psw_user[20];
  system("clear");
  printf("    ***INICIO DE SESIÓN ADMINISTRADOR***\n");
  printf("---->Presiona 3 si quieres volver al menú anterior, de lo contario presiona 1\n");
  scanf("%d",&o);
  if(o==3){
    menu1();
  }
  else if(o==1){
    getchar();
    printf("\n---->Introduce tu nombre de usuario\n");
    printf("---->");
    gets(user);
    printf("---->Introduce tu contraseña\n");
    printf("---->");
    gets(psw_user);
    if((strcmp(user,admin)==0) && strcmp(psw_user, admin_psw)==0){
      puts("Has ingresado con éxito. Espera un momento en lo que te redirigimos.");
      timer();
      interfaz_admin();
    }
    else{
      printf("!!!!!!!!Usuario o contraseña incorrectos!!!!!!!!\n");
      timer();
      menu_admin();
    }
  }
}
void menu_registro(void){
  int o, verificador=0,i,j;
  char linea[120];
  do{
    system("clear");
    printf("      ***REGISTRO***\n");
    printf("---->Presiona 3 si quieres volver al menú anterior, de lo contario presiona cualquier otro número.\n");
    scanf("%d",&o);
    if(o==3){
      break;
    }
    getchar();
    printf("\n---->Introduce tu nombre completo\n");
    printf("---->");
    gets(t[temp].nombre);

    printf("---->Introduce tu dirección\n");
    printf("---->");
    gets(t[temp].direccion);

    printf("---->Día de nacimiento\n");
    printf("---->");
    gets(linea);
    if(strcmp(linea,"")==0){
      t[temp].nacimiento.dia=-1;
    }
    sscanf(linea,"%d",&t[temp].nacimiento.dia);

    printf("---->Mes de nacimiento\n");
    printf("---->");
    gets(linea);
    if(strcmp(linea,"")==0){
      t[temp].nacimiento.mes=-1;
    }
    sscanf(linea,"%d",&t[temp].nacimiento.mes);

    printf("---->Año de nacimiento\n");
    printf("---->");
    gets(linea);
    if(strcmp(linea,"")==0){
      t[temp].nacimiento.anio=-1;
    }
    sscanf(linea,"%d",&t[temp].nacimiento.anio);

    printf("---->Introduce tu email\n");
    printf("---->");
    gets(&t[temp].email);

    printf("---->Introduce tu nombre de usuario\n");
    printf("---->");
    gets(t[temp].nom_usu);
  }while(o!=3 && ((strcmp(t[temp].nombre,"")==0) || (strcmp(t[temp].direccion,"")==0) || (t[temp].nacimiento.dia<=0)||(t[temp].nacimiento.mes<=0)|| (t[temp].nacimiento.anio<=0) || (strcmp(t[temp].email,"")==0)||(strcmp(t[temp].nom_usu,"")==0)));
  if(o==3){
    menu1();
  }
  else{
    strcpy(t[temp].usu_psw, CONTRA);
    strcpy(t[temp].peli1.titulo,"-1");
    t[temp].peli1.dia_i.dia=-1;
    t[temp].peli1.dia_i.mes=-1;
    t[temp].peli1.dia_i.anio=-1;
    t[temp].peli1.dia_f.dia=-1;
    t[temp].peli1.dia_f.mes=-1;
    t[temp].peli1.dia_f.anio=-1;
    strcpy(t[temp].peli2.titulo,"-1");
    t[temp].peli2.dia_i.dia=-1;
    t[temp].peli2.dia_i.mes=-1;
    t[temp].peli2.dia_i.anio=-1;
    t[temp].peli2.dia_f.dia=-1;
    t[temp].peli2.dia_f.mes=-1;
    t[temp].peli2.dia_f.anio=-1;
    strcpy(t[temp].peli3.titulo,"-1");
    t[temp].peli3.dia_i.dia=-1;
    t[temp].peli3.dia_i.mes=-1;
    t[temp].peli3.dia_i.anio=-1;
    t[temp].peli3.dia_f.dia=-1;
    t[temp].peli3.dia_f.mes=-1;
    t[temp].peli3.dia_f.anio=-1;
    t[temp].t_pelis=0;
    t[temp].activo=0;
    if(t[temp].nacimiento.anio<=2000){
      strcpy(usuarios[num_usuarios+1].nombre,t[temp].nombre);
      strcpy(usuarios[num_usuarios+1].direccion,t[temp].direccion);
      usuarios[num_usuarios+1].nacimiento.dia=t[temp].nacimiento.dia;
      usuarios[num_usuarios+1].nacimiento.mes=t[temp].nacimiento.mes;
      usuarios[num_usuarios+1].nacimiento.anio=t[temp].nacimiento.anio;
      strcpy(usuarios[num_usuarios+1].email,t[temp].email);
      strcpy(usuarios[num_usuarios+1].nom_usu,t[temp].nom_usu);
      strcpy(usuarios[num_usuarios+1].usu_psw,t[temp].usu_psw);
      strcpy(usuarios[num_usuarios+1].peli1.titulo,t[temp].peli1.titulo);
      usuarios[num_usuarios+1].peli1.dia_i.dia=-1;
      usuarios[num_usuarios+1].peli1.dia_i.mes=-1;
      usuarios[num_usuarios+1].peli1.dia_i.anio=-1;
      usuarios[num_usuarios+1].peli1.dia_f.dia=-1;
      usuarios[num_usuarios+1].peli1.dia_f.mes=-1;
      usuarios[num_usuarios+1].peli1.dia_f.anio=-1;
      strcpy(usuarios[num_usuarios+1].peli2.titulo,t[temp].peli2.titulo);
      usuarios[num_usuarios+1].peli2.dia_i.dia=-1;
      usuarios[num_usuarios+1].peli2.dia_i.mes=-1;
      usuarios[num_usuarios+1].peli2.dia_i.anio=-1;
      usuarios[num_usuarios+1].peli2.dia_f.dia=-1;
      usuarios[num_usuarios+1].peli2.dia_f.mes=-1;
      usuarios[num_usuarios+1].peli2.dia_f.anio=-1;
      strcpy(usuarios[num_usuarios+1].peli3.titulo,t[temp].peli3.titulo);
      usuarios[num_usuarios+1].peli3.dia_i.dia=-1;
      usuarios[num_usuarios+1].peli3.dia_i.mes=-1;
      usuarios[num_usuarios+1].peli3.dia_i.anio=-1;
      usuarios[num_usuarios+1].peli3.dia_f.dia=-1;
      usuarios[num_usuarios+1].peli3.dia_f.mes=-1;
      usuarios[num_usuarios+1].peli3.dia_f.anio=-1;
      usuarios[num_usuarios+1].t_pelis=0;
      usuarios[num_usuarios+1].activo=1;
      num_usuarios++;
      printf("Has quedado registrado con éxito\n");
      printf("Serás redireccionado al menu anterior\n" );
    }
    else{
      printf("Lo sentimos, esta aplicación es solo para mayores de 18\n");
    }

    timer();
    menu_usuario();
  }
}
void interfaz_usuario(void){
  int o;
  system("clear");
  printf("      ***BIENVENIDO %s***\n\n",usuarios[usu_isesion].nombre);
  printf("Si quieres salir de tu sesión, presiona 3. De lo contrario, presiona 1.\n" );
  scanf("%d",&o);
  if(o==3){
    menu1();
  }
  else{
    puts("Presiona 1 si quieres ver el catálogo.");
    puts("Presiona 2 si quieres ver tu perfil");
    scanf("%d",&o);
    if(o==1){
      catalogo(usu_isesion);
    }
    if(o==2){
      perfil(usu_isesion);
    }
  }
}
void isesion_usuario(void){
  int o, i, j, v=0;
  char user[80];
  char psw[10];
  system("clear");
  puts("    ***INICIO DE SESIÓN USUARIO***");
  printf("---->Presiona 3 si quieres volver al menú anterior, de lo contario presiona cualquier otro número\n");
  scanf("%d",&o);
  if(o==3){
    menu_usuario();
  }
  else{
    getchar();
    puts("\n---->Introduce tu nombre de usuario");
    printf("---->");
    gets(user);
    puts("\n---->Contraseña");
    printf("---->");
    gets(psw);
    for(i=0;i<=num_usuarios;i++){
      if((strcmp(user,usuarios[i].nom_usu)==0) && (strcmp(psw, usuarios[i].usu_psw)==0) && (usuarios[i].activo==1)){
        v=1;
        usu_isesion=i;
      }
    }
    if(v==1){
      puts("Has ingresado de manera exitosa. Espera un momento en lo que te redirigimos.");
      timer();
      interfaz_usuario();
    }
    else if(v==0){
      puts("!!!!!!!!! Datos proporcionados incorrectos !!!!!!!!!!");
      timer();
      isesion_usuario();
    }
  }
}
void catalogo(int x){
  FILE* peliculas;
  char linea[100];
  int i,j,o, movies=0;
  char arg[100];
  //código para sacar la fecha
  time_t currentTime;
  time(&currentTime);
  struct tm* myTime=localtime(&currentTime);
  //
  system("clear");
  peliculas=fopen("peliculas.txt","rt");
  if(peliculas!=NULL){
    i=0;
    while(!feof(peliculas)){
      fgets(arg,50, peliculas);
      if(feof(peliculas)){
        break;
      }
      if(strlen(arg)>0){
        arg[strlen(arg)-1]='\0';
        strcpy(pelis[i].titulo,arg);
      }
      fgets(arg,50,peliculas);
      if(feof(peliculas)){
        break;
      }
      if(strlen(arg)>0){
        arg[strlen(arg)-1]='\0';
        strcpy(pelis[i].genero,arg);
      }
      fgets(arg,20,peliculas);
      if(feof(peliculas)){
        break;
      }
      if(strlen(arg)>0){
        arg[strlen(arg)-1]='\0';
        strcpy(pelis[i].duracion,arg);
      }
      fgets(arg,10,peliculas);
      if(feof(peliculas)){
        break;
      }
      if(strlen(arg)>0){
        arg[strlen(arg)-1]='\0';
        strcpy(pelis[i].anio,arg);
      }
      fgets(arg,5,peliculas);
      if(feof(peliculas)){
        break;
      }
      if(strlen(arg)>0){
        arg[strlen(arg)-1]='\0';
        sscanf(arg,"%d",&pelis[i].seleccion);
      }
      i++;
    }
  }
  fclose(peliculas);
  puts("    ***Catálogo***\n");
  getchar();
  do{
    printf("Si quieres dejar de busar películas, presiona 3. De lo contrario, sigue las instrucciones.\n");
    printf("Escribe el título de la película el o género que quieras buscar\n");

    gets(linea);

    if(strcmp(linea,"3")==0){
      break;
    }
    if(strcmp(linea,"Accion")==0){
      puts("        ***Películas de acción***");
      for(j=0;j<i;j++){
        if(strcmp(pelis[j].genero, "Accion")==0){
          printf("Título: %s\n", pelis[j].titulo);
          printf("Género: %s\n", pelis[j].genero);
          printf("Duración: %s\n", pelis[j].duracion);
          printf("Año de publicación: %s\n", pelis[j].anio);
        }
      }
      linea[strlen(linea)-1]='\0';
    }
    if(strcmp(linea, "Terror")==0){
      puts("\n    ***Películas de terror***");
      for(j=0;j<i;j++){
        if(strcmp(pelis[j].genero, "Terror")==0){
          printf("Título: %s\n", pelis[j].titulo);
          printf("Género: %s\n", pelis[j].genero);
          printf("Duración: %s\n", pelis[j].duracion);
          printf("Año de publicación: %s\n", pelis[j].anio);
        }
      }
      linea[strlen(linea)-1]='\0';
    }
    if(strcmp(linea, "Accion")!=0 && strcmp(linea,"Terror")!=0){
      for(j=0;j<=i;j++){
        if(strcmp(linea, pelis[j].titulo)==0){
          printf("Título: %s\n", pelis[j].titulo);
          printf("Género: %s\n", pelis[j].genero);
          printf("Duración: %s\n", pelis[j].duracion);
          printf("Año de publicación: %s\n\n", pelis[j].anio);
        }
      }
      linea[strlen(linea)-1]='\0';
    }

  }while(strcmp(linea,"33")!=0);
  printf("\n\nSi quieres rentar alguna película, presiona 1, de lo contrario, presiona 3 para volver al menú anterior\n" );
  scanf("%d",&o );
  if(o==1){
    if(strcmp(usuarios[x].peli1.titulo,"-1")!=0){
      movies++;
    }
    if(strcmp(usuarios[x].peli2.titulo,"-1")!=0){
      movies++;
    }
    if(strcmp(usuarios[x].peli3.titulo,"-1")!=0){
      movies++;
    }
    if(movies<3){
      while(o!=3){
        printf("ESCRIBE el nombre de la película que quieras rentar: ");
        getchar();
        gets(linea);
        for(j=0;j<i;j++){
          if(strcmp(linea, pelis[j].titulo)==0){
            pelis[j].seleccion++;
            printf("%d",pelis[j].seleccion);
            if(strcmp(usuarios[x].peli1.titulo,"-1")==0){
              strcpy(usuarios[x].peli1.titulo,linea);
              usuarios[x].peli1.dia_i.dia=myTime->tm_mday;
              usuarios[x].peli1.dia_i.mes=myTime->tm_mon+1;
              usuarios[x].peli1.dia_i.anio=myTime->tm_year-100;
              usuarios[x].peli1.dia_f.dia=myTime->tm_mday+30;
              usuarios[x].peli1.dia_f.mes=myTime->tm_mon+1;
              usuarios[x].peli1.dia_f.anio=myTime->tm_year-100;
              if(usuarios[x].peli1.dia_f.dia>30){
                usuarios[x].peli1.dia_f.mes++;
                usuarios[x].peli1.dia_f.dia-=30;
              }
              if(usuarios[x].peli1.dia_f.mes>12){
                usuarios[x].peli1.dia_f.anio++;
                usuarios[x].peli1.dia_f.mes=1;
              }
              usuarios[x].t_pelis++;
              movies++;
            }

            else if(strcmp(usuarios[x].peli2.titulo,"-1")==0){
              strcpy(usuarios[x].peli2.titulo,linea);
              usuarios[x].peli2.dia_i.dia=myTime->tm_mday;
              usuarios[x].peli2.dia_i.mes=myTime->tm_mon+1;
              usuarios[x].peli2.dia_i.anio=myTime->tm_year-100;
              usuarios[x].peli2.dia_f.dia=myTime->tm_mday+30;
              usuarios[x].peli2.dia_f.mes=myTime->tm_mon+1;
              usuarios[x].peli2.dia_f.anio=myTime->tm_year-100;
              if(usuarios[x].peli2.dia_f.dia>30){
                usuarios[x].peli2.dia_f.mes++;
                usuarios[x].peli2.dia_f.dia-=30;
              }
              if(usuarios[x].peli2.dia_f.mes>12){
                usuarios[x].peli2.dia_f.anio++;
                usuarios[x].peli2.dia_f.mes=1;
              }
              usuarios[x].t_pelis++;
              movies++;
            }
            else if(strcmp(usuarios[x].peli3.titulo,"-1")==0){
              strcpy(usuarios[x].peli3.titulo,linea);
              usuarios[x].peli3.dia_i.dia=myTime->tm_mday;
              usuarios[x].peli3.dia_i.mes=myTime->tm_mon+1;
              usuarios[x].peli3.dia_i.anio=myTime->tm_year-100;
              usuarios[x].peli3.dia_f.dia=myTime->tm_mday+30;
              usuarios[x].peli3.dia_f.mes=myTime->tm_mon+1;
              usuarios[x].peli3.dia_f.anio=myTime->tm_year-100;
              if(usuarios[x].peli3.dia_f.dia>30){
                usuarios[x].peli3.dia_f.mes++;
                usuarios[x].peli3.dia_f.dia-=30;
              }
              if(usuarios[x].peli3.dia_f.mes>12){
                usuarios[x].peli3.dia_f.anio++;
                usuarios[x].peli3.dia_f.mes=1;
              }
              usuarios[x].t_pelis++;
              movies++;
            }
          }
        }
        if(movies>2){
          break;
        }
        printf("\n¿Quieres seguir rentando? Presiona 1 si sí, 3 si quieres salir.\n");
        scanf("%d",&o);
        if(o==3){
          interfaz_usuario();
        }
      }
    }
    if(movies==3){
      printf("\nHas llegado al límite de películas que puedes rentar. Serás redireccionado al menú anterior, donde podrás ver tu informe y entregar películas.\n");
      timer();
      timer();
      timer();
      timer();
      interfaz_usuario();
    }
  }
  else if(o==3){
    interfaz_usuario();
  }

}
void perfil(int x){
  int i,j,o,movies=0,e;
  system("clear");
  printf("      :::%s:::\n", usuarios[x].nombre);
  printf("Nombre de usuario: %s\n",usuarios[x].nom_usu);
  printf("Correo electrónico: %s\n",usuarios[x].email );
  printf("Dirección: %s\n",usuarios[x].direccion);
  printf("\n------Películas rentadas------\n");
  if(strcmp(usuarios[x].peli1.titulo,"-1")!=0){
    printf("1. Título: %s\n",usuarios[x].peli1.titulo);
    printf("Día rentada: %d/%d/%d\n", usuarios[x].peli1.dia_i.dia,usuarios[x].peli1.dia_i.mes,usuarios[x].peli1.dia_i.anio);
    printf("Día máximo de entrega: %d/%d/%d\n", usuarios[x].peli1.dia_f.dia,usuarios[x].peli1.dia_f.mes,usuarios[x].peli1.dia_f.anio);
  }
  else{
    printf("1. No hay registro.\n");
  }
  if(strcmp(usuarios[x].peli2.titulo,"-1")!=0){
    printf("2. Título: %s\n",usuarios[x].peli2.titulo);
    printf("Día rentada: %d/%d/%d\n", usuarios[x].peli2.dia_i.dia,usuarios[x].peli2.dia_i.mes,usuarios[x].peli2.dia_i.anio);
    printf("Día máximo de entrega: %d/%d/%d\n", usuarios[x].peli2.dia_f.dia,usuarios[x].peli2.dia_f.mes,usuarios[x].peli2.dia_f.anio);
  }
  else{
    printf("2. No hay registro.\n");
  }
  if(strcmp(usuarios[x].peli3.titulo,"-1")!=0){
    printf("3. Título: %s\n",usuarios[x].peli3.titulo);
    printf("Día rentada: %d/%d/%d\n", usuarios[x].peli3.dia_i.dia,usuarios[x].peli3.dia_i.mes,usuarios[x].peli3.dia_i.anio);
    printf("Día máximo de entrega: %d/%d/%d\n", usuarios[x].peli3.dia_f.dia,usuarios[x].peli3.dia_f.mes,usuarios[x].peli3.dia_f.anio);
  }
  else{
    printf("3. No hay registro.\n");
  }
  puts("\n¿Deseas entregar alguna película?");
  puts("Presiona 1 si quieres entregar una película, presiona 3 si quieres volver al menú anterior");
  scanf("%d",&o);
  if(o==1){
    printf("Presiona el número de película que quieras eliminar: ");
    scanf("%d",&e);
    if(e==1){
      strcpy(usuarios[x].peli1.titulo,"-1");
      usuarios[x].peli1.dia_i.dia=-1;
      usuarios[x].peli1.dia_i.mes=-1;
      usuarios[x].peli1.dia_i.anio=-1;
      usuarios[x].peli1.dia_f.dia=-1;
      usuarios[x].peli1.dia_f.mes=-1;
      usuarios[x].peli1.dia_f.anio=-1;
    }
    else if(e==2){
      strcpy(usuarios[x].peli2.titulo,"-1");
      usuarios[x].peli2.dia_i.dia=-1;
      usuarios[x].peli2.dia_i.mes=-1;
      usuarios[x].peli2.dia_i.anio=-1;
      usuarios[x].peli2.dia_f.dia=-1;
      usuarios[x].peli2.dia_f.mes=-1;
      usuarios[x].peli2.dia_f.anio=-1;
    }
    else if(e==3){
      strcpy(usuarios[x].peli3.titulo,"-1");
      usuarios[x].peli3.dia_i.dia=-1;
      usuarios[x].peli3.dia_i.mes=-1;
      usuarios[x].peli3.dia_i.anio=-1;
      usuarios[x].peli3.dia_f.dia=-1;
      usuarios[x].peli3.dia_f.mes=-1;
      usuarios[x].peli3.dia_f.anio=-1;
    }
    perfil(x);
  }
  else{
    interfaz_usuario();
  }
}
void interfaz_admin(void){
  int i,j,o, movies=0;
  FILE* archivo;
  system("clear");
  puts("    ***BIENVENIDO ADMINISTRADOR***\n\n");
  printf("Total de películas en renta al momento: %d\n",num_pelis());
  puts("Para cerrar sesión, presiona 3, de lo contrario, presiona 1.");
  scanf("%d",&o);
  if(o==3){
    menu_admin();
  }
  else{
    puts("¿Qué quieres hacer?");
    puts("Presiona 1 si quieres ver un informe de los usuarios dados de alta.");
    puts("Presiona 2 si quieres dar de baja usuarios inactivos.");
    puts("Presiona 3 si quieres obtener el género y título más popular.");
    puts("Presiona 4 para ver la ayuda.");
    printf("Presiona 5 si quieres salir al menú principal.\n");
    getchar();
    scanf("%d",&o);
    if(o==1){
      informe_alta();
    }
    else if(o==2){
      informe_baja();
    }
    else if(o==3){
      popular();
    }
    else if(o==4){
      puts("    ***Ayuda administrador***");
    }
    else if(o==5){
      menu1();
    }
  }
}
int num_pelis(void){
  int i;
  int movies=0;
  for(i=0;i<=num_usuarios;i++){
    if(strcmp(usuarios[i].peli1.titulo,"-1")!=0){
      movies++;
    }
    if(strcmp(usuarios[i].peli2.titulo,"-1")!=0){
      movies++;
    }
    if(strcmp(usuarios[i].peli3.titulo,"-1")!=0){
      movies++;
    }
  }
  return movies;
}
void informe_alta(void){
  int i, j, movies,o;
  struct usuario temp;
  system("clear");
  printf("    ***Clientes activos***\n\n");
  for(i=0;i<num_usuarios;i++){
    for(j=0;j<num_usuarios;j++){
      if(strcmp(usuarios[j].nombre,usuarios[j+1].nombre)>0){
        temp=usuarios[j];
        usuarios[j]=usuarios[j+1];
        usuarios[j+1]=temp;
      }
    }
  }

  for(i=0;i<=num_usuarios;i++){
    if(usuarios[i].activo==1){
      movies=0;
      if(strcmp(usuarios[i].peli1.titulo,"-1")!=0){
        movies++;
      }
      if(strcmp(usuarios[i].peli2.titulo,"-1")!=0){
        movies++;
      }
      if(strcmp(usuarios[i].peli3.titulo,"-1")!=0){
        movies++;
      }
      printf("Nombre de cliente: %s\n",usuarios[i].nombre);
      printf("Nombre de usuario: %s\n",usuarios[i].nom_usu);
      printf("Películas en renta: %d\n\n",movies);
    }
  }
  printf("\nPresiona 3 cuando quieras volver al menú anterior\n");
  scanf("%d",&o);
  if(o==3){
    interfaz_admin();
  }
}
void popular(void){
  int i,j,k,o,terror=0,accion=0,m,t;
  FILE* peliculas;
  char arg[100];
  system("clear");
  i=0;
  peliculas=fopen("peliculas.txt","rt");
  if(peliculas!=NULL){
    while(!feof(peliculas)){
      fgets(arg,50, peliculas);
      if(feof(peliculas)){
        break;
      }
      if(strlen(arg)>0){
        arg[strlen(arg)-1]='\0';
        strcpy(pelis[i].titulo,arg);
      }
      fgets(arg,50,peliculas);
      if(feof(peliculas)){
        break;
      }
      if(strlen(arg)>0){
        arg[strlen(arg)-1]='\0';
        strcpy(pelis[i].genero,arg);
      }
      fgets(arg,20,peliculas);
      if(feof(peliculas)){
        break;
      }
      if(strlen(arg)>0){
        arg[strlen(arg)-1]='\0';
        strcpy(pelis[i].duracion,arg);
      }
      fgets(arg,10,peliculas);
      if(feof(peliculas)){
        break;
      }
      if(strlen(arg)>0){
        arg[strlen(arg)-1]='\0';
        strcpy(pelis[i].anio,arg);
      }
      fgets(arg,5,peliculas);
      if(feof(peliculas)){
        break;
      }
      if(strlen(arg)>0){
        arg[strlen(arg)-1]='\0';
        sscanf(arg,"%d",&pelis[i].seleccion);
      }
      i++;
    }
  }
  for(j=0;j<=num_usuarios;j++){
    for(k=0;k<=i;k++){
      if(strcmp(usuarios[j].peli1.titulo,pelis[k].titulo)==0){
        pelis[k].seleccion++;
        if(strcmp(pelis[k].genero,"Accion")==0){
          accion++;
        }
        else{
          terror++;
        }
      }
      if(strcmp(usuarios[j].peli2.titulo,pelis[k].titulo)==0){
        pelis[k].seleccion++;
        if(strcmp(pelis[k].genero,"Accion")==0){
          accion++;
        }
        else{
          terror++;
        }
      }
      if(strcmp(usuarios[j].peli3.titulo,pelis[k].titulo)==0){
        pelis[k].seleccion++;
        if(strcmp(pelis[k].genero,"Accion")==0){
          accion++;
        }
        else{
          terror++;
        }
      }
    }
  }

  m=pelis[0].seleccion;
  for(j=1;j<=i;j++){
    if(pelis[j].seleccion>m){
      m=pelis[j].seleccion;
      t=j;
    }
  }
  printf("    ***Estadísticas de títulos y géneros de películas al momento***\n\n");
  printf("Películas de acción: %d\n",accion);
  printf("Películas de terror: %d\n",terror);
  printf("La película más popular es: %s\n",pelis[t].titulo);
  printf("Presiona 3 cuando quieras regresar al menú anterior\n");
  scanf("%d",&o);
  if(o==3){
    interfaz_admin();
  }
}
void informe_baja(void){
  int i,j,o,c=0,x;
  char linea[100];
  FILE* bitacora;
  //código para sacar la fecha
  time_t currentTime;
  time(&currentTime);
  struct tm* myTime=localtime(&currentTime);
  //
  system("clear");
  puts("      ***Informe de baja***\n");
  printf("Presiona 1 si quieres continuar, de lo contrario, presiona 3 para volver.\n");
  scanf("%d",&o);
  if(o==3){
    interfaz_admin();
  }
  else if(o==1){
    printf("\n----Usuarios dados de baja----\n");
    for(i=0;i<=num_usuarios;i++){
      if(usuarios[i].activo==0){
        printf("Nombre: %s\n", usuarios[i].nombre);
        printf("Nombre de cuenta: %s\n", usuarios[i].nom_usu);
        printf("Número de películas rentadas: %d\n",usuarios[i].t_pelis);
        c++;
      }
    }
    printf("\nHay %d usuarios de baja, ¿quieres ver si es posible dar alguno de baja?\n",c);
    printf("Presiona 1 si sí lo deseas, de lo contrario, presiona 3 para volver al menú anterior.\n");
    scanf("%d",&o);
    if(o==3){
      interfaz_admin();
    }
    else if(o==1){
      c=1;
      for(i=0;i<=num_usuarios;i++){
        if((strcmp(usuarios[i].peli1.titulo,"-1")==0) && (strcmp(usuarios[i].peli2.titulo,"-1")==0) && (strcmp(usuarios[i].peli3.titulo,"-1")==0)&&usuarios[i].activo!=0){
          printf("\n%d. Nombre: %s\n",c,usuarios[i].nombre);
          printf("Nombre de usuario: %s\n\n",usuarios[i].nom_usu);
          c++;
        }
      }
      printf("¿Quieres dar de baja a algún usuario?\n");
      printf("Presiona 1 si sí lo deseas, de lo contrario, presiona 3 para volver al menú anterior.\n");
      scanf("%d",&o);
      if(o==3){
        interfaz_admin();
      }
      else if(o==1){
        printf("Escribe el nombre de usuario que quieras dar de baja: ");
        getchar();
        gets(linea);
        for(i=0;i<=num_usuarios;i++){
          if(strcmp(linea, usuarios[i].nom_usu)==0){
            usuarios[i].activo=0;
            x=i;
          }
        }
        if(usuarios[x].activo==0){
          printf("\nBaja exitosa!\n");
          bitacora=fopen("bitacora.txt","a");
          fprintf(bitacora, "Fecha y hora de ingreso: %d/%d/%d %d:%d\n",myTime->tm_mday,myTime->tm_mon,myTime->tm_year,myTime->tm_hour,myTime->tm_min );
          fprintf(bitacora, "Nombre: %s\n",usuarios[x].nombre);
          fprintf(bitacora, "Nombre de usuario: %s\n",usuarios[x].nom_usu );
          fprintf(bitacora, "Total de películas rentadas: %d\n",usuarios[x].t_pelis );
          fclose(bitacora);
        }
        else{
          printf("\nNo se pudo completar la baja\n");
        }
        printf("¿Quieres volver a hacer todo el proceso otra vez para dar de baja a otro usuario?\n");
        printf("Presiona 1 si sí lo deseas, de lo contrario, presiona 3 para volver al menú anterior.\n");
        scanf("%d",&o);
        if(o==3){
          interfaz_admin();
        }
        else if(o==1){
          informe_baja();
        }
      }
    }
  }
}
void timer(void){
  int i,j;
  for(i=0;i<=30000;i++){
    for(j=0;j<=30000;j++){}
  }
}
